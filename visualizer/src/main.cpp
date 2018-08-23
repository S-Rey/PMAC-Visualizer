#include <nanogui/opengl.h>
#include <nanogui/screen.h>
#include <nanogui/common.h>
#include <nanogui/label.h>
#include <nanogui/slider.h>
#include <nanogui/layout.h>
#include <nanogui/textbox.h>
#include <nanogui/glcanvas.h>

#include <iostream>

#if defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
#if defined(_WIN32)
#  pragma warning(push)
#  pragma warning(disable: 4457 4456 4005 4312)
#endif

#if defined(_WIN32)
#  pragma warning(pop)
#endif
#if defined(_WIN32)
#  if defined(APIENTRY)
#    undef APIENTRY
#  endif
#  include <windows.h>
#endif



class PMACVisualizerApplication : public nanogui::Screen {
public:
    PMACVisualizerApplication() : nanogui::Screen(Eigen::Vector2i(1080, 1080), "PMAC Visualizer") {
        using namespace nanogui;

        m_panel = new Widget(this);
        m_panel->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 10, 10));

        new Label(m_panel, "Time : ", "sans-bold");
        m_slider = new Slider(m_panel);
        m_slider->setValue(0.f);
        m_slider->setFixedWidth(Screen::width() - 140);

        m_textBox = new TextBox(m_panel);
        m_textBox->setFixedSize(Vector2i(60, 25));
        m_textBox->setValue("0");
        m_textBox->setUnits("µs");

        m_slider->setCallback([this](float value) {
            m_textBox->setValue(std::to_string((int) (value)));
            m_time = value * m_totalTime;
            Vector3f xAxis = Vector3f::UnitX();
            setupRotation(modRotMat, xAxis, m_time);
            std::cout << modRotMat << std::endl;
        });
        m_slider->setFinalCallback([&](float value) {
            //std::cout << "Final m_slider value: " << (int) (value * 100) << std::endl;
            m_textBox->setValue(std::to_string((int) (value)));
        });

        m_panel->setSize(Vector2i(Screen::width() - 200 ,50));
        m_panel->setPosition(
            Vector2i(0, mSize.y() - m_panel->size().y()));
        performLayout();

        /* Draw the main windows */
        mShader.init(
            /* An identifying name */
            "a_simple_shader",

            /* Vertex shader */
            "#version 330\n"
            "uniform mat4 modelViewProj;\n"
            "in vec3 position;\n"
            "in vec3 color;\n"
            "out vec4 frag_color;\n"
            "void main() {\n"
            "    frag_color = 3.0 * modelViewProj * vec4(color, 1.0);\n"
            "    gl_Position = modelViewProj * vec4(position, 1.0);\n"
            "}",

            /* Fragment shader */
            "#version 330\n"
            "out vec4 color;\n"
            "in vec4 frag_color;\n"
            "void main() {\n"
            "    color = frag_color;\n"
            "}"
        );

        MatrixXu indices(3, 12); /* Draw a cube */
        indices.col( 0) << 0, 1, 3;
        indices.col( 1) << 3, 2, 1;
        indices.col( 2) << 3, 2, 6;
        indices.col( 3) << 6, 7, 3;
        indices.col( 4) << 7, 6, 5;
        indices.col( 5) << 5, 4, 7;
        indices.col( 6) << 4, 5, 1;
        indices.col( 7) << 1, 0, 4;
        indices.col( 8) << 4, 0, 3;
        indices.col( 9) << 3, 7, 4;
        indices.col(10) << 5, 6, 2;
        indices.col(11) << 2, 1, 5;

        MatrixXf positions(3, 8);
        positions.col(0) << -1,  1,  1;
        positions.col(1) << -1,  1, -1;
        positions.col(2) <<  1,  1, -1;
        positions.col(3) <<  1,  1,  1;
        positions.col(4) << -1, -1,  1;
        positions.col(5) << -1, -1, -1;
        positions.col(6) <<  1, -1, -1;
        positions.col(7) <<  1, -1,  1;

        MatrixXf colors(3, 12);
        colors.col( 0) << 1, 0, 0;
        colors.col( 1) << 0, 1, 0;
        colors.col( 2) << 1, 1, 0;
        colors.col( 3) << 0, 0, 1;
        colors.col( 4) << 1, 0, 1;
        colors.col( 5) << 0, 1, 1;
        colors.col( 6) << 1, 1, 1;
        colors.col( 7) << 0.5, 0.5, 0.5;
        colors.col( 8) << 1, 0, 0.5;
        colors.col( 9) << 1, 0.5, 0;
        colors.col(10) << 0.5, 1, 0;
        colors.col(11) << 0.5, 1, 0.5;

        mShader.bind();
        mShader.uploadIndices(indices);

        mShader.uploadAttrib("position", positions);
        mShader.uploadAttrib("color", colors);

        // Model matrix
        modelMat.setIdentity();
        // View matrix
        viewMat.setIdentity();
        // Projection matrix
        projectionMat.setIdentity();
        setupProjection(projectionMat);
    }

    ~PMACVisualizerApplication() {
        mShader.free();
    }


    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers) {
        if (Screen::keyboardEvent(key, scancode, action, modifiers))
            return true;
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            setVisible(false);
            return true;
        }
        return false;
    }

    virtual void draw(NVGcontext *ctx) {
        Screen::draw(ctx);
    }

    // Handle the resizing of the window to change the perspective matrix
    virtual bool resizeEvent(const nanogui::Vector2i& size){
        //std::cout << size << std::endl;
        m_slider->setFixedWidth(Screen::width() - 140);
        m_panel->setSize(nanogui::Vector2i(Screen::width() - 200 ,50));
        m_panel->setPosition(nanogui::Vector2i(0, mSize.y() - m_panel->size().y()));
        performLayout();

        // Adjust the projection matrix
        projectionMat.setIdentity();
        setupProjection(projectionMat);
        return true;
    }


    void orthographicProjection(nanogui::Matrix4f &mat,
                                float l, float r, float b,
                                float t, float n, float f) {
        assert(r > l);
        assert(f > n);
        assert(t > b);
        mat.col(0) << 2.f/(r-l), 0.f, 0.f, 0.f;
        mat.col(1) << 0.f, 2.f/(t-b), 0.f, 0.f;
        mat.col(2) << 0.f, 0.f, -2.f/(f-n),0.f;
        mat.col(3) << -(r+l)/(r-l), -(t+b)/(t-b), -(f+n)/(f-n), 1.f;
    }

    void setupProjection(nanogui::Matrix4f &mat) {
        float top = 1.f;
        float right = (float)Screen::width() / (float)Screen::height() * top;
        //std::cout << right << std::endl;
        if (orthographic) {
            orthographicProjection(mat, -right, right, -top, top, -10.f, 10.f);
            //std::cout << mat << std::endl;
        }
    }

    void setupRotation(Eigen::Matrix4f &rotMat, Eigen::Vector3f &axis, float angle) {
        axis.normalize();
        rotMat.setIdentity();
        rotMat.topLeftCorner<3,3>() = Eigen::AngleAxisf(angle, axis).toRotationMatrix();
    }

    virtual void drawContents() {
        using namespace nanogui;

        mShader.bind();

        //float fTime = (float)glfwGetTime();
        //mvp.setIdentity();
        //mvp.topLeftCorner<3,3>() = Eigen::Matrix3f(Eigen::AngleAxisf(mRotation[0]*fTime, Vector3f::UnitX()) *
        //                                           Eigen::AngleAxisf(mRotation[1]*fTime,  Vector3f::UnitY()) *
        //                                           Eigen::AngleAxisf(mRotation[2]*fTime, Vector3f::UnitZ())) * 0.25f;

        mvp = projectionMat * viewMat * modelMat;
        mShader.setUniform("modelViewProj", mvp); 
        glEnable(GL_DEPTH_TEST);
        /* Draw 12 triangles starting at index 0 */
        mShader.drawIndexed(GL_TRIANGLES, 0, 12);
        //glLineWidth(100);
        //mShader.drawIndexed(GL_LINES, 0, 12);
        glDisable(GL_DEPTH_TEST);
    }
private:
    nanogui::Slider *m_slider = nullptr;
    nanogui::TextBox *m_textBox= nullptr;
    nanogui::Widget *m_panel = nullptr;
    float m_time = 0.f;
    float m_totalTime = 100.f;

    // OpenGl
    nanogui::GLShader mShader;
    nanogui::Matrix4f mvp;
    nanogui::Matrix4f modelMat;
    nanogui::Matrix4f viewMat;
    nanogui::Matrix4f projectionMat;
    nanogui::Matrix4f modRotMat;
    nanogui::Matrix4f modTransMat;
    nanogui::Matrix4f modCompMat;
    Eigen::Vector3f mRotation = nanogui::Vector3f(0.25f, 0.5f, 0.33f);
    //Eigen::Vector3f mRotation = nanogui::Vector3f(0.25f, 0.5f, 0.33f);
    bool orthographic = true;
};

int main() {
    try {
        nanogui::init();

        /* scoped variables */ {
            nanogui::ref<PMACVisualizerApplication> app = new PMACVisualizerApplication();
            app->drawAll();
            app->setVisible(true);
            nanogui::mainloop();
        }

        nanogui::shutdown();
    } catch (const std::runtime_error &e) {
        std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
        #if defined(_WIN32)
            MessageBoxA(nullptr, error_msg.c_str(), NULL, MB_ICONERROR | MB_OK);
        #else
            std::cerr << error_msg << std::endl;
        #endif
        return -1;
    }
}

