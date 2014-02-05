#include "MinimizerOptions.h"

class MinimizerOptionsTest : public ::testing::Test
{
 protected:
    MinimizerOptionsTest(){}
    virtual ~MinimizerOptionsTest(){}

};


TEST_F(MinimizerOptionsTest, InitialState)
{
    MinimizerOptions options;
    EXPECT_EQ(0.01, options.getTolerance());
    EXPECT_EQ(-1, options.getPrecision());
    EXPECT_EQ(0, options.getMaxIterations());
    EXPECT_EQ(0, options.getMaxFunctionCalls());

    ASSERT_THROW(options.setValue("some_value",1.0), LogicErrorException);
}


TEST_F(MinimizerOptionsTest, SetValues)
{
    MinimizerOptions options;

    options.setTolerance(0.02);
    options.setPrecision(2);
    options.setMaxIterations(10);
    options.setMaxFunctionCalls(100);
    EXPECT_EQ(0.02, options.getTolerance());
    EXPECT_EQ(2, options.getPrecision());
    EXPECT_EQ(10, options.getMaxIterations());
    EXPECT_EQ(100, options.getMaxFunctionCalls());

    options.addValue("some_int",1);
    options.addValue("some_double",9.9);
    options.addValue("some_string","xxx");

    ASSERT_THROW(options.addValue("some_int",1), LogicErrorException);
    EXPECT_EQ(options.getIntValue("some_int"), 1);
    EXPECT_EQ(options.getRealValue("some_double"), 9.9);
    EXPECT_EQ(options.getNamedValue("some_string"), "xxx");

    ASSERT_THROW(options.getIntValue("some_int2"), LogicErrorException);

    MinimizerOptions opt2 = options;
    EXPECT_EQ(0.02, opt2.getTolerance());
    EXPECT_EQ(2, opt2.getPrecision());
    EXPECT_EQ(10, opt2.getMaxIterations());
    EXPECT_EQ(100, opt2.getMaxFunctionCalls());
    EXPECT_EQ(opt2.getIntValue("some_int"), 1);
    EXPECT_EQ(opt2.getRealValue("some_double"), 9.9);
    EXPECT_EQ(opt2.getNamedValue("some_string"), "xxx");
}

