/*
It implements the logic of the game
This acts as a view in MVC pattern
It is responsible for all user interation
*/


#include "Game.h"
#include "utility.h"
#include <iostream>
#include <string>
#include <time.h>




FBullsGame::FBullsGame()
{
	
}

void FBullsGame::InitializeWords()
{

	OCowsAndBulls.AddWords("red");
	OCowsAndBulls.AddWords("orange");
	OCowsAndBulls.AddWords("blue");
	OCowsAndBulls.AddWords("black");
	OCowsAndBulls.AddWords("gray"); 
}


void FBullsGame::ResetGame(int MaximumTry)
{
	//Reset State first
	//Initialize Words
	//Set Maximum Try Amount
	OCowsAndBulls.Reset();
	OCowsAndBulls.SetMaxTry(MaximumTry);
	InitializeWords();

}

void FBullsGame::Play()
{
		FText CurrentWord = OCowsAndBulls.GetNextWord();
		FText WordGuessed;

		int32 length = CurrentWord.length();
		int32 trytotal = OCowsAndBulls.GetMaxTry();
		int32 currentTry = OCowsAndBulls.GetCurrentTry();
		while ( currentTry < OCowsAndBulls.GetMaxTry() )
		{

			FUtility::PrintOnScreenInfo("Try No.", currentTry);
			FUtility::PrintOnScreenInfo("Enter an isogram Word to guess that I am thinking of ",length, " Length");
			std::getline(std::cin, WordGuessed);
			FUtility::ProcessWord(WordGuessed);
			EWordState WordState = OCowsAndBulls.GuessWord(WordGuessed);
			
			if (WordState == EWordState::OK)
			{
				FBullCowCount obj = OCowsAndBulls.CountBullsCows(WordGuessed);
				FUtility::PrintOnScreenInfo(obj.bulls, "Bulls And ", obj.cows, " Cows");

				//Win Condition
				if (OCowsAndBulls.GetState() == EGameState::Won)
				{
					FUtility::PrintOnScreenInfo("You Won the Game with ", OCowsAndBulls.GetMaxTry() - currentTry, "left");
					break;
				}
			}
			else if (WordState == EWordState::Invalid)
			{
				FUtility::PrintOnScreenInfo("Not a Valid Choice .No Special Character allowed");
			}
			else if (WordState == EWordState::Not_isogram)
			{
				FUtility::PrintOnScreenInfo("Not a valid choice. Enter word not containing same letter !!! ");
			}
			else if (WordState == EWordState::NotValidLength)
			{
				FUtility::PrintOnScreenInfo("Guessed Word Length is too short or too long ");
			}
		}
		if (OCowsAndBulls.GetState() == EGameState::Lost)
			FUtility::PrintOnScreenInfo("Sorry You Lost :|");
		
		currentTry = OCowsAndBulls.GetCurrentTry();
	
}

void FBullsGame::StartGame()
{
	FBullsGame  OGameobject;

	bool bWantsToPlayAgain = false;
	do
	{
	OGameobject.ResetGame(5);
	OGameobject.Play();
	bWantsToPlayAgain = FUtility::PlayAgain();

	} while (bWantsToPlayAgain);


}

FBullsGame::~FBullsGame()
{

}
