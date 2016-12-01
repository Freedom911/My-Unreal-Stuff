#pragma once
#include<string>
#include<vector>
class BullsCows
{

private:

	const int MaxTry;

	std::vector<std::string>Words;

	void PreInitialize();

	void PrintPreInfo();

	bool PlayAgain();

	void PlayGame();

	void CheckWord(std::string GuessedWord, std::string CorrectWord, int &iBulls, int &iCows);

	std::string getNextWord();

public:
	BullsCows(int MaxLength);
	~BullsCows();

	/*Starts the game*/
	void StartGame();
};

