#include "pch.h"
#include "../DAY8-Baseball/baseball.cpp"
#include <string>
using namespace std;

class BaseballFixture : public testing::Test {
public:
	Baseball game;

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
}