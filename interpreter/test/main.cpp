#include <gtest/gtest.h>

#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/PMACLexer.h"
#include "antlr4-runtime/PMACParser.h"
#include <interpreter/Visitor.h>

// Run the Visitor on the Abstract Syntax Tree
void runProgram(Visitor &visitor, std::string program) {
    antlr4::ANTLRInputStream input(program);

    PMACLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    PMACParser parser(&tokens);

    PMACParser::ProgramContext* tree = parser.program();

    visitor.visitProgram(tree);

    return;
};


// Test the assagnment of variable
TEST(Interpreter, assignment) {
    std::string program = 
        "\n"    "P0 = 1"
        "\n"    "Q0 = -1"
        "\n"    "I0 = (-12 / 4) + 1"
    ;

    Visitor visitor = Visitor();
    runProgram (visitor, program);

    EXPECT_EQ(visitor.env.getValue("P0"), 1);
    EXPECT_EQ(visitor.env.getValue("Q0"), -1);
    EXPECT_EQ(visitor.env.getValue("I0"), -2);

    // Test reserved variables
    EXPECT_EQ(visitor.env.getValue("Q800"), M_PI);
    EXPECT_EQ(visitor.env.getValue("I15"), 0);
}

TEST(Interpreter, functions) {
    std::string program = 
        "\n"    "I15 = 1; Test in radian"
        "\n"    "M1 = SIN(0)"
        "\n"    "M2 = SIN(Q800)"
        "\n"    "M3 = COS(Q800 / 2)"
    ;

    Visitor visitor = Visitor();
    runProgram (visitor, program);

    EXPECT_EQ(visitor.env.getValue("M1"), sin(0));
    EXPECT_EQ(visitor.env.getValue("M2"), sin(M_PI));
    EXPECT_EQ(visitor.env.getValue("M3"), cos(M_PI/2.0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
