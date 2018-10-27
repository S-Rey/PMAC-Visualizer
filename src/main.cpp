#include <iostream>
#include <visualizer/PMACVisualizerApplication.h>
#include <interpreter/Visitor.h>
#include <antlr4-runtime/antlr4-runtime.h>
#include <antlr4-runtime/PMACLexer.h>
#include <antlr4-runtime/PMACParser.h>



int main() {

    std::ifstream stream;
    stream.open("input.PMAC");

    antlr4::ANTLRInputStream input(stream);
    PMACLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    PMACParser parser(&tokens);

    PMACParser::ProgramContext* tree = parser.program();

    Visitor visitor = Visitor();
    visitor.visitProgram(tree);
    std::vector<Lazer::MoveCmd> moveCmds = visitor.env.lazer.getMoveCmds();


    try {
        nanogui::init();

        /* scoped variables */ {
            nanogui::ref<PMACVisualizerApplication> app = new PMACVisualizerApplication();
            app->setMoveCmds(moveCmds);
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

