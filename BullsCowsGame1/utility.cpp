#include <iostream>
#include "utility.h"
#include <string>
#include <algorithm>



FUtility::FUtility()
{
}


FUtility::~FUtility()
{
}

void FUtility::ProcessWord(std::string &GuessedWord)
{
	std::transform(GuessedWord.begin(), GuessedWord.end(), GuessedWord.begin(), ::tolower);
}

bool FUtility::PlayAgain()
{
	char choice = 'n';
	FText Message = "Play Again Fellow Person";
	PrintOnScreenInfo(Message);
	std::cin >> choice;
	std::cin.ignore();
	tolower(choice);
	if (choice == 'y'||choice =='Y')
	{
		return true;
	}
	else if (choice == 'n'||choice =='N')
		return false;
	else
	{
		FText NewMessage = "Wrong choice person Enter y/n";
		PrintOnScreenInfo(NewMessage);
		PlayAgain();
	}
}