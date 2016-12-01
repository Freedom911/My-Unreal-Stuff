#include <iostream>
#include <string>
#include <time.h>
#include "bullsCows.h"


BullsCows::BullsCows(int Try):MaxTry(Try)
{
	PreInitialize();
}

void BullsCows::PreInitialize()
{
	srand(time(NULL));
	Words.push_back("red");
	Words.push_back("orange");
	Words.push_back("blue");
	Words.push_back("black");

}
void BullsCows::PrintPreInfo()
{
	std::cout << "Welcome to Bulls And Cows Game " << std::endl;
	std::cout << "Press any Key To start" << std::endl;
	std::cin.get(); 

}

bool BullsCows::PlayAgain()
{
	char choice ='n';
	std::cout << "Play Again Fellow Person?" << std::endl;
	std::cin >> choice;
	std::cin.ignore();
	tolower(choice);
	if (choice == 'y')
		return true;
	else if (choice == 'n')
		return false;
	else
	{
		std::cout << "Wrong choice person Enter y/n" << std::endl;
		PlayAgain();
	}
}

void BullsCows::CheckWord(std::string GuessedWord,std::string CorrectWord, int &iBulls, int &iCows)
{
	for (int i = 0; i < CorrectWord.length(); i++)
	{
		for (int j = 0; j < GuessedWord.length(); j++)
		{
			if (CorrectWord[i] == GuessedWord[j])
			{
				if (i != j)
					iCows++;
				else
					iBulls++;
			}
		}
	}
}

std::string BullsCows::getNextWord()
{
	//Get random number from 0 to Words size -1
	int index = rand() % Words.size();
	return Words[index];
}

void BullsCows::PlayGame()
{
	bool bWantsToPlayAgain = false;
	do
	{
		std::string CurrentWord = getNextWord();
		int length = CurrentWord.length();
		int trytotal = MaxTry;
		int iBulls = 0;
		int iCows = 0;
		bool bWon = true;
		std::string WordGuessed;
		std::cout << "Word Length is " << length << std::endl;

		while (trytotal > 0)
		{
			trytotal--;
			std::cout << "Enter an isogram Word to guess." << std::endl;
			std::getline(std::cin, WordGuessed);
		
			std::cout << "Try " << MaxTry - trytotal <<std::endl;

			//Win Condition
			if (WordGuessed == CurrentWord)
			{
				std::cout << length << "Bulls " << " 0 Cows " << std::endl;
				std::cout << "Player Won the Game With " <<  trytotal << " left " << std::endl;
				bWon = true;
				break;
			}

			//Lose Condition
		    CheckWord(WordGuessed,CurrentWord,iBulls,iCows);
			std::cout << iBulls << "Bulls " << iCows <<" Cows " << std::endl;

		}
		if (!bWon && trytotal <= 0)
			std::cout << "Sorry Brother You Lost :|" << std::endl;
		bWantsToPlayAgain = PlayAgain();

	} while (bWantsToPlayAgain);

}


void BullsCows::StartGame()
{

	PrintPreInfo();
	
	PlayGame();

	

}

BullsCows::~BullsCows()
{

}
