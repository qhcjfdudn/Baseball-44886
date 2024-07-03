#include <string>
#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	Baseball(const string& question)
		: question_{ question } {}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		if (guessNumber == question_)
			return { true, 3, 0 };

		return { false, 0, 0 };
	}
	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("Must be three letters.");

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9')
				continue;
			throw invalid_argument("Must be number.");
		}

		if (isDuplicatedNumber(guessNumber))
			throw invalid_argument("Must not have the same number.");
	}
	bool isDuplicatedNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

private:
	string question_;
};