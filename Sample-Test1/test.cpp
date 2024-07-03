#include "pch.h"
#include "../DAY8-Baseball/baseball.cpp"
#include <string>
using namespace std;

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };

	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception& e) {
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument(string("12"));	// length_error
	assertIllegalArgument(string("12s"));	// invalid_argument
	assertIllegalArgument(string("121"));	// invalid_argument
}
TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}
TEST_F(BaseballFixture, ReturnUnsolvedResultIf2Strikes0Ball) {
	GuessResult result = game.guess("125");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}
TEST_F(BaseballFixture, ReturnUnsolvedResultIf1Strikes2Ball) {
	GuessResult result = game.guess("132");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}