#include <nanogui/opengl.h>
#include <nanogui/screen.h>
#include <nanogui/common.h>
#include <nanogui/label.h>
#include <nanogui/slider.h>
#include <nanogui/layout.h>
#include <nanogui/textbox.h>
#include <nanogui/glcanvas.h>

#include <visualizer/grid.h>


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

    struct DragView {
        DragView() {
            mActive = false;
            mLastPos(0.f, 0.f);
            mTrans(0.f, 0.f);
            mIncr(0.f, 0.f);
        }

        void button(nanogui::Vector2i pos, bool pressed) {
            //std::cout << mTranslation << std::endl;
            mActive = pressed;
            mLastPos = pos.cast<float>();
            if (!mActive)
                mTrans = mIncr + mTrans;
            mIncr.Zero();
        }
        bool motion(nanogui::Vector2i pos) {
            if (!mActive)
                return false;
            mIncr(0) = speedFactor * (-(mLastPos.x() - pos.x()));
            mIncr(1) = speedFactor * (mLastPos.y() - pos.y());
            return true;
        }

        nanogui::Matrix4f matrix() const {
            nanogui::Matrix4f result2 = nanogui::Matrix4f::Identity();
            result2.block<2,1>(0, 3)  = mIncr + mTrans;
            return result2;
        }
    protected:
        /// Whether or not this DragView is currently active.
        bool mActive;
        /// The last click position (which triggered the DragView to be active / non-active).
        nanogui::Vector2f mLastPos;
        /// Sate
        nanogui::Vector2f mTrans;
        nanogui::Vector2f mIncr;
        /// Speed factor
        float speedFactor = 0.001f;
    };

    PMACVisualizerApplication();

    ~PMACVisualizerApplication();

    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers);

    virtual bool mouseButtonEvent(const nanogui::Vector2i &p, int button, bool down, int modifiers);

    virtual bool mouseMotionEvent(const nanogui::Vector2i &p, const nanogui::Vector2i &rel, int button, int modifiers);

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

    // Arcball
    nanogui::Arcball mArcball;
    // DragView
    DragView mDragView;
    // OpenGl
    nanogui::GLShader mShader;
    // Camera
    Camera mCamera;
    // Model
    Model  mModel;
    // grid
    Grid mGrid;
    // Projection matrix
    nanogui::Matrix4f projectionMat;
    bool orthographic = true;
    // MVP matrix
    nanogui::Matrix4f mvp;
};
