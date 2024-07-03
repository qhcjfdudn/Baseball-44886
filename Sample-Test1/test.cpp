#include "pch.h"
#include "../DAY8-Baseball/baseball.cpp"
#include <string>
using namespace std;

TEST(Baseball, ThrowExceptionWhenInputLengthIsUnmached) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}
TEST(Baseball, ThrowExceptionWhenInvalidChar) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}