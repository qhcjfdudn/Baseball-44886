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

		if (guessNumber != question_)
			return getUnsolvedScore(guessNumber);
		
		return getSolvedScore();
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

	const GuessResult& getUnsolvedScore(const std::string& guessNumber)
	{
		int strikes = countStrikes(guessNumber);
		int balls = countBalls(guessNumber);
		return { false, strikes, balls };
	}
	int countStrikes(const string& guessNumber) {
		int result = 0;

		for (int i = 0; i < QUESTION_LENGTH; ++i) {
			if (guessNumber[i] != question_[i])
				continue;

			result++;
		}

		return result;
	}
	int countBalls(const string& guessNumber) {
		int result = 0;

		for (int i = 0; i < QUESTION_LENGTH; ++i) {
			for (int j = 0; j < QUESTION_LENGTH; ++j) {
				if (i == j
					|| guessNumber[i] != question_[j])
					continue;

				result++;
				break;
			}
		}

		return result;
	}
	
	const GuessResult& getSolvedScore()
	{
		return { true, QUESTION_LENGTH, 0 };
	}
private:
	const int QUESTION_LENGTH = 3;
	string question_;
};