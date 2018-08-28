#include <nanogui/opengl.h>
#include <nanogui/screen.h>
#include <nanogui/common.h>
#include <nanogui/label.h>
#include <nanogui/slider.h>
#include <nanogui/layout.h>
#include <nanogui/textbox.h>
#include <nanogui/glcanvas.h>

//#include <visualizer/matop.h>


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
    struct Camera {
        nanogui::Vector3f origin;
        nanogui::Vector3f target;
        nanogui::Vector3f up;
        nanogui::Matrix4f lookAt;

        Camera() :  origin(0.f, 0.f, 0.f),
                    target(0.f, 0.f, -1.f),
                    up(0.f, 1.f, 0.f),
                    lookAt(nanogui::lookAt(origin,target,up)) {};
    };

    struct Model {
        nanogui::Matrix4f scale;
        nanogui::Matrix4f rotation;
        nanogui::Matrix4f translation;
        nanogui::Matrix4f composition;

        Model() {
            scale.setIdentity();
            rotation.setIdentity();
            translation.setIdentity();
            update();
        };

        void update() {
            composition = translation * rotation * scale;
        }
    };

    PMACVisualizerApplication();

    ~PMACVisualizerApplication();

    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers);

    virtual void draw(NVGcontext *ctx);

    // Handle the resizing of the window to change the perspective matrix
    virtual bool resizeEvent(const nanogui::Vector2i& size);

    void setupProjection(nanogui::Matrix4f &mat);

    void updateMVP();

    nanogui::Matrix4f rotate(const nanogui::Vector3f &axis, float angle);

    virtual void drawContents();

private:
    nanogui::Slider *m_slider = nullptr;
    nanogui::TextBox *m_textBox= nullptr;
    nanogui::Widget *m_panel = nullptr;
    float m_time = 0.f;
    float m_totalTime = 100.f;

    // OpenGl
    nanogui::GLShader mShader;
    // Camera
    Camera mCamera;
    // Model
    Model  mModel;
    // Projection matrix
    nanogui::Matrix4f projectionMat;
    bool orthographic = true;
    // MVP matrix
    nanogui::Matrix4f mvp;

    nanogui::Matrix4f modelMat;
    nanogui::Matrix4f modRotMat;
    nanogui::Matrix4f modScaleMat;
    nanogui::Matrix4f modTransMat;
    nanogui::Matrix4f modCompMat;
    nanogui::Vector3f mRotation = nanogui::Vector3f(0.f, 0.f, 0.f);
    //Eigen::Vector3f mRotation = nanogui::Vector3f(0.25f, 0.5f, 0.33f);
};
