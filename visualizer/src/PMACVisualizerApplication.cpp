#include <visualizer/PMACVisualizerApplication.h>

PMACVisualizerApplication::PMACVisualizerApplication() : nanogui::Screen(Eigen::Vector2i(1080, 1080), "PMAC Visualizer") {
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
        mModel.rotation = rotate(Vector3f::UnitX(), m_time);
        mModel.update();
        updateMVP();
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

    mModel.scale = nanogui::scale(Vector3f(0.25f, 0.25f, 0.25f));
    mModel.update();

    // Projection matrix
    projectionMat.setIdentity();
    setupProjection(projectionMat);

    updateMVP();
}

PMACVisualizerApplication::~PMACVisualizerApplication() {
    mShader.free();
}


bool PMACVisualizerApplication::keyboardEvent(int key, int scancode, int action, int modifiers) {
    if (Screen::keyboardEvent(key, scancode, action, modifiers))
        return true;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        setVisible(false);
        return true;
    }
    if (key == GLFW_KEY_1 && key == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        nanogui::Matrix4f upScaleMat;
        //scaleMat(1.25f, upScaleMat);
        modScaleMat = upScaleMat * modScaleMat;
    };
    if (key == GLFW_KEY_MINUS  && action == GLFW_PRESS) {
        nanogui::Matrix4f upScaleMat;
        //scaleMat(0.75f, upScaleMat);
        modScaleMat = upScaleMat * modScaleMat;
    };

    return false;
}

void PMACVisualizerApplication::draw(NVGcontext *ctx) {
    Screen::draw(ctx);
}

// Handle the resizing of the window to change the perspective matrix
bool PMACVisualizerApplication::resizeEvent(const nanogui::Vector2i& size){
    //std::cout << size << std::endl;
    m_slider->setFixedWidth(Screen::width() - 140);
    m_panel->setSize(nanogui::Vector2i(Screen::width() - 200 ,50));
    m_panel->setPosition(nanogui::Vector2i(0, mSize.y() - m_panel->size().y()));
    performLayout();

    // Adjust the projection matrix
    setupProjection(projectionMat);

    updateMVP();

    return true;
}

void PMACVisualizerApplication::setupProjection(nanogui::Matrix4f &mat) {
    float top = 1.f;
    float right = (float)Screen::width() / (float)Screen::height() * top;
    //std::cout << right << std::endl;
    if (orthographic) {
        mat = nanogui::ortho(-right, right, -top, top, -10.f, 10.f);
    }
}

void PMACVisualizerApplication::updateMVP() {
    mvp = projectionMat * mCamera.lookAt * mModel.composition;
}


nanogui::Matrix4f PMACVisualizerApplication::rotate(const nanogui::Vector3f &axis, float angle) {
    return Eigen::Affine3f(Eigen::AngleAxisf(angle, axis)).matrix();
}


void PMACVisualizerApplication::drawContents() {
    using namespace nanogui;

    mShader.bind();
    mShader.setUniform("modelViewProj", mvp);
    glEnable(GL_DEPTH_TEST);
    /* Draw 12 triangles starting at index 0 */
    mShader.drawIndexed(GL_TRIANGLES, 0, 12);
    //glLineWidth(100);
    //mShader.drawIndexed(GL_LINES, 0, 12);
    glDisable(GL_DEPTH_TEST);
}
