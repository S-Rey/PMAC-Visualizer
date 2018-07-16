#include <iostream>

#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/PMACLexer.h"
#include "antlr4-runtime/PMACParser.h"
#include "PMACVisitor.h"

using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open("input.scene");
    
    ANTLRInputStream input(stream);
    PMACLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    PMACParser parser(&tokens);
    
    PMACParser::FileContext* tree = parser.file();

    ImageVisitor visitor;
    Scene scene = visitor.visitFile(tree);
    scene.draw();	

    return 0;
}
