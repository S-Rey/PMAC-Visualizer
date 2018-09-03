//
//#include <visualizer/grid.h>
//
//Grid::Grid() {
//    Grid(2.f, 2.f, 0.2f);
//}
//
//Grid::Grid(float x, float y, float step) {
//    assert(x > 0);
//    assert(y > 0);
//    assert(step > 0);
//    this->x = x;
//    this->y = y;
//    this->step = step;
//
//    mShader.init(
//        /* An identifying name */
//        "a_simple_shader",
//
//        /* Vertex shader */
//        "#version 330\n"
//        "uniform mat4 modelViewProj;\n"
//        "in vec3 position;\n"
//        "in vec3 color;\n"
//        "out vec4 frag_color;\n"
//        "void main() {\n"
//        //"    frag_color = 3.0 * modelViewProj * vec4(color, 1.0);\n"
//        "    frag_color = 3.0 * modelViewProj * vec4(color, 1.0);\n"
//        "    gl_Position = modelViewProj * vec4(position, 1.0);\n"
//        "}",
//
//        /* Fragment shader */
//        "#version 330\n"
//        "out vec4 color;\n"
//        "void main() {\n"
//        "    color = vec4(1.0, 0.0, 0.0, 0.0);\n"
//        "}"
//    );
//
//
//    setupGrid();
//
//    mShader.bind();
//    mShader.uploadIndices(mIndices);
//    mShader.uploadAttrib("position", mPositions);
//}
//
//void Grid::setupGrid() {
//    size_t nXPLines = floor(x/2.f/step);
//    size_t nYPLines = floor(y/2.f/step);
//    size_t nXLines = floor(x/step);
//    size_t nYLines = floor(y/step);
//    size_t nLines = nXLines + nYLines;
//
//    // Setup Matrices
//    mPositions = nanogui::MatrixXf(3, 2*(nLines+2));
//    mIndices   = nanogui::MatrixXu(2, nLines+2);
//
//    // X axis
//    for (size_t i = 0; i < nXPLines; ++i) {
//        size_t vInd = 4*i;
//        // Positive part
//        mPositions.col(vInd+0) << i*step,  y/2.f, 0.f;
//        mPositions.col(vInd+1) << i*step, -y/2.f, 0.f;
//        mIndices.col(i) << vInd+0, vInd+1;
//
//        // Negative part
//        mPositions.col(vInd+2) << -i*step,  y/2.f, 0.f;
//        mPositions.col(vInd+3) << -i*step, -y/2.f, 0.f;
//        mIndices.col(i+1) << vInd+2, vInd+3;
//    }
//
//    // Y axis
//    for (size_t i = 0; i < nYPLines; ++i) {
//        size_t vInd = 4*i+nXPLines;
//        // Positive part
//        mPositions.col(vInd+0) <<  x/2.f, i*step, 0.f;
//        mPositions.col(vInd+1) << -x/2.f, i*step, 0.f;
//        mIndices.col(i+nXPLines) << vInd+0, vInd+1;
//
//        // Negative part
//        mPositions.col(vInd+2) <<  x/2.f, -i*step, 0.f; 
//        mPositions.col(vInd+3) << -x/2.f, -i*step, 0.f; 
//        mIndices.col(i+1+nXPLines) << vInd+2, vInd+3;
//    }
//
//    // Center Axis: X = 0 and Y = 0
//    // X
//    mPositions.col(nLines+0) << 0.f,  y/2.f, 0.f;
//    mPositions.col(nLines+1) << 0.f, -y/2.f, 0.f;
//    mIndices.col(nLines+0) << nLines+0, nLines+1;
//    // Y 
//    mPositions.col(nLines+2) <<  x/2.f, 0.f, 0.f;
//    mPositions.col(nLines+3) << -x/2.f, 0.f, 0.f;
//    mIndices.col(nLines+1) << nLines+2, nLines+3;
//}
//
//
//
//void Grid::draw(const nanogui::Matrix4f &mvp) {
//    this->mvp = mvp;
//    mShader.bind();
//    glEnable(GL_DEPTH_TEST);
//
//    glLineWidth(100);
//    mShader.drawIndexed(GL_LINES, 0, floor(x/step)+floor(y/step)+2);
//
//    glDisable(GL_DEPTH_TEST);
//}



