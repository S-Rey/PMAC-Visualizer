#include <iostream>

#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/PMACLexer.h"
#include "antlr4-runtime/PMACParser.h"
#include <interpreter/Visitor.h>

using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open("input.PMAC");

    ANTLRInputStream input(stream);
    PMACLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    PMACParser parser(&tokens);

    PMACParser::ProgramContext* tree = parser.program();

    Visitor visitor = Visitor();
    visitor.visitProgram(tree);

    return 0;
}
