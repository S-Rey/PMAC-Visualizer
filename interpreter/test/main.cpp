#include <gtest/gtest.h>

#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/PMACLexer.h"
#include "antlr4-runtime/PMACParser.h"
#include <interpreter/Visitor.h>


::testing::AssertionResult IsBetweenInclusive(double val, double a, double b)
{
    if((val >= a) && (val <= b))
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure()
               << val << " is outside the range " << a << " to " << b;
}


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
TEST(Visitor, assignment) {
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

TEST(Visitor, functions) {
    std::string program =
        // Standard functions
        // EXP
        "\n"    "M1 = EXP(0)"
        "\n"    "M2 = EXP(1)"
        "\n"    "M3 = EXP(-1)"
        "\n"    "M4 = EXP(LN(0))"
        // LN
        "\n"    "M5 = LN(1)"
        "\n"    "M6 = LN(EXP(1))"
        // SQRT
        "\n"    "M7 = SQRT(0)"
        "\n"    "M8 = SQRT(1)"
        "\n"    "M9 = SQRT(2)"
        // ABS
        "\n"    "M10 = ABS(0)"
        "\n"    "M11 = ABS(-1)"
        // INT
        "\n"    "M12 = INT(0.5)"
        "\n"    "M13 = INT(-0.5)"
        //
        // Trigonometric functions
        //
        // SIN
        "\n"    "M14 = SIN(0)"
        "\n"    "M15 = SIN(-90)"
        // COS
        "\n"    "M16 = COS(0)"
        "\n"    "M17 = COS(-90)"
        // TAN
        "\n"    "M18 = TAN(0)"
        "\n"    "M19 = TAN(180)"
        // ASIN
        "\n"    "M20 = ASIN(0)"
        "\n"    "M21 = ASIN(-1)"
        // ACOS
        "\n"    "M22 = ACOS(0)"
        "\n"    "M23 = ACOS(-1)"
        // ATAN
        "\n"    "M24 = ATAN(0)"
        "\n"    "M25 = ATAN(1)"
        // ATAN2
        "\n"    "Q30 = -0.707"
        "\n"    "Q31  = -0.707"
        "\n"    "Q0  = Q30"
        "\n"    "Q33  = ATAN2(Q31)"

        // In radians
        "\n"    "I15 = 1"
        "\n"    "M28 = SIN(0)"
        "\n"    "M29 = SIN(Q800/2)"
    ;

    Visitor visitor = Visitor();
    runProgram (visitor, program);

    // Standard functions
    // EXP
    EXPECT_EQ(visitor.env.getValue("M1"), 1.0);
    EXPECT_EQ(visitor.env.getValue("M2"), exp(1.0));
    EXPECT_EQ(visitor.env.getValue("M3"), exp(-1.0));
    EXPECT_EQ(visitor.env.getValue("M4"), 0.0);
    // LN
    EXPECT_EQ(visitor.env.getValue("M5"), 0.0);
    EXPECT_EQ(visitor.env.getValue("M6"), 1.0);
    // SQRT
    EXPECT_EQ(visitor.env.getValue("M7"), 0.0);
    EXPECT_EQ(visitor.env.getValue("M8"), 1.0);
    EXPECT_EQ(visitor.env.getValue("M9"), sqrt(2.0));
    // ABS
    EXPECT_EQ(visitor.env.getValue("M10"), 0.0);
    EXPECT_EQ(visitor.env.getValue("M11"), 1.0);
    // INT
    EXPECT_EQ(visitor.env.getValue("M12"), 0.0);
    EXPECT_EQ(visitor.env.getValue("M13"), -1.0);
    //
    // Trigonometric functions
    //
    // SIN
    EXPECT_EQ(visitor.env.getValue("M14"), 0.0);
    EXPECT_EQ(visitor.env.getValue("M15"), -1.0);
    // COS
    EXPECT_EQ(visitor.env.getValue("M16"), 1.0);
    EXPECT_TRUE(IsBetweenInclusive(visitor.env.getValue("M17"), -1.0e-16, 1.0e-16));
    // TAN
    EXPECT_EQ(visitor.env.getValue("M18"), 0.0);
    EXPECT_TRUE(IsBetweenInclusive(visitor.env.getValue("M19"), -1.0e-15, 1.0e-15));
    // ASIN
    EXPECT_EQ(visitor.env.getValue("M20"), 0.0);
    EXPECT_EQ(visitor.env.getValue("M21"), -90);
    // ACOS
    EXPECT_EQ(visitor.env.getValue("M22"), 90);
    EXPECT_EQ(visitor.env.getValue("M23"), 180);
    // ATAN
    EXPECT_EQ(visitor.env.getValue("M24"), 0);
    EXPECT_EQ(visitor.env.getValue("M25"), 45);
    // ATAN2
    //EXPECT_EQ(visitor.env.getValue("M26"), 0);
    EXPECT_EQ(visitor.env.getValue("Q33"), -135);
    //
    // In radians (Just check if conversion deg->rad is done with one example)
    //
    // SIN
    EXPECT_EQ(visitor.env.getValue("M28"), 0.0);
    EXPECT_EQ(visitor.env.getValue("M29"), 1.0);
}

TEST(Visitor, ifStatement) {
    std::string program =
        // One line if statement
        "\n"    "M1 = 1"
        "\n"    "IF (M1 = 1) M1 = 2"
        "\n"    "IF (M1 != 2) M1 = 3"
        "\n"    "M2 = 1"
        "\n"    "IF (M2 !> 2)"
        "\n"    "M2 = 3"
        "\n"    "ENDIF"
        "\n"
        "\n"    "IF (M3 = 1)"
        "\n"    "M3 = 2"
        "\n"    "ELSE M3 = 3"
        "\n"    "ENDIF"
        "\n"
        "\n"    "IF (M4 = 1)"
        "\n"    "M4 = 2"
        "\n"    "ELSE"
        "\n"    "IF (M4 = 0) M4 = 4"
        "\n"    "ENDIF"
    ;

    Visitor visitor = Visitor();
    runProgram (visitor, program);

    EXPECT_EQ(visitor.env.getValue("M1"), 2);
    EXPECT_EQ(visitor.env.getValue("M2"), 3);
    EXPECT_EQ(visitor.env.getValue("M3"), 3);
    EXPECT_EQ(visitor.env.getValue("M4"), 4);
}

TEST(Visitor, whileStatement) {
    std::string program =
        "\n"    "WHILE (M1 !> 10)"
        "\n"    "M1 = M1 + 2"
        "\n"    "M2 = M2 + 1"
        "\n"    "ENDWHILE"
        "\n"    "WHILE (M3 !< -4) M3 = M3 - 1"
    ;

    Visitor visitor = Visitor();
    runProgram (visitor, program);

    EXPECT_EQ(visitor.env.getValue("M1"), 12);
    EXPECT_EQ(visitor.env.getValue("M2"), 6);
    EXPECT_EQ(visitor.env.getValue("M3"), -5);
}


TEST(Visitor, compoundCondition) {
    std::string program =
        "\n"    "WHILE (M1 !> 10) AND M2 < 2"
        "\n"    "M1 = M1 + 2"
        "\n"    "M2 = M2 + 1"
        "\n"    "ENDWHILE"

        /// If M3 != M4
        "\n"    "IF (M3 = 0)"
        "\n"    "AND (M4 = 1)"
        "\n"    "OR (M3 = 1)"
        "\n"    "AND (M4 = 0)"
        "\n"    "M3 = 1"
        "\n"    "M4 = 1"
        "\n"    "ENDIF"

        // If M5 == M6
        "\n"    "IF (M5 = 1)"
        "\n"    "AND (M6 = 1)"
        "\n"    "OR (M5 = 0)"
        "\n"    "AND (M6 = 0)"
        "\n"    "M5 = 1"
        "\n"    "M6 = 1"
        "\n"    "ENDIF"
    ;

    Visitor visitor = Visitor();
    runProgram (visitor, program);

    EXPECT_EQ(visitor.env.getValue("M1"), 4);
    EXPECT_EQ(visitor.env.getValue("M2"), 2);
    EXPECT_EQ(visitor.env.getValue("M3"), 0);
    EXPECT_EQ(visitor.env.getValue("M4"), 0);
    EXPECT_EQ(visitor.env.getValue("M5"), 1);
    EXPECT_EQ(visitor.env.getValue("M6"), 1);
}


TEST(Visitor, condition) {
    std::string program =
        "\n"    "M1 = -1"
        "\n"    "M2 = -1"
        "\n"    "M3 = 1"
        // =
        "\n"    "IF (M1 = M2) M4 = 1"
        "\n"    "IF (M1 = M3) M4 = -1"
        // !=
        "\n"    "IF (M1 != M3) M5 = 1"
        "\n"    "IF (M1 != M2) M6 = -1"
        // <
        "\n"    "IF (M1 < M3) M6 = 1"
        "\n"    "IF (M1 < M2) M6 = -1"
        // >
        "\n"    "IF (M3 > M1) M7 = 1"
        "\n"    "IF (M2 > M1) M7 = -1"
        // !<
        "\n"    "IF (M1 !< M2) M8 = 1"
        "\n"    "IF (M1 !< M3) M8 = -1"
        // !>
        "\n"    "IF (M1 !> M2) M9 = 1"
        "\n"    "IF (M3 !> M2) M9 = -1"
        ;
    Visitor visitor = Visitor();
    runProgram (visitor, program);

    EXPECT_EQ(visitor.env.getValue("M4"), 1);
    EXPECT_EQ(visitor.env.getValue("M5"), 1);
    EXPECT_EQ(visitor.env.getValue("M6"), 1);
    EXPECT_EQ(visitor.env.getValue("M7"), 1);
    EXPECT_EQ(visitor.env.getValue("M8"), 1);
    EXPECT_EQ(visitor.env.getValue("M8"), 1);
    EXPECT_EQ(visitor.env.getValue("M9"), 1);
}

TEST(Visitor, expression){
    std::string program =
        // Test precedence of operations
        "\n"    "M1 = 0 + -1"
        "\n"    "M2 = -1 * 2 + 1 * 2"
        "\n"    "M3 = -1 / 2 + 4 % 2"
        ;
    Visitor visitor = Visitor();
    runProgram (visitor, program);
    EXPECT_EQ(visitor.env.getValue("M1"), -1);
    EXPECT_EQ(visitor.env.getValue("M2"), 0);
    EXPECT_EQ(visitor.env.getValue("M3"), -0.5);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

