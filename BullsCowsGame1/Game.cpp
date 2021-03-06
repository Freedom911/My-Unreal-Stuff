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


void FBullsGame::ResetGame()
{
	//Reset State first
	//Initialize Words
	OCowsAndBulls.Reset();
	InitializeWords();

}
//Plays a single game
void FBullsGame::Play()
{
	FText CurrentWord = OCowsAndBulls.GetNextWord();
	FText WordGuessed;

	int32 length = CurrentWord.length();
	int32 trytotal = OCowsAndBulls.GetMaxTry();
	int32 currentTry = OCowsAndBulls.GetCurrentTry();
	FUtility::PrintOnScreenInfo("Can You Guess a " ,length , " letter isogram Word");

	//Run the game while chances are left and the game is not won
	while (currentTry <= OCowsAndBulls.GetMaxTry() && OCowsAndBulls.GetState() != EGameState::Won)
	{
		
		FUtility::PrintOnScreenInfo("Try No.", currentTry, " of ",OCowsAndBulls.GetMaxTry());
		FUtility::PrintOnScreenInfo("\nYour Guess:");
		std::getline(std::cin, WordGuessed);

		//Convert to lower Case String
		FUtility::ProcessWord(WordGuessed);

		//Check if Word entered is valid
		EWordState WordState = OCowsAndBulls.CheckValidGuess(WordGuessed);

		switch (WordState)
		{
		case EWordState::OK:
		{
			//Count and Return number of Bulls and Cows
			FBullCowCount obj = OCowsAndBulls.CountBullsCows(WordGuessed);
			FUtility::PrintOnScreenInfo(obj.bulls, "Bulls And ", obj.cows, " Cows\n");
		}
		break;

		//if word contains characters other than alphabets
 		case EWordState::Invalid:
			FUtility::PrintOnScreenInfo("No Special Character allowed\n");
			break;
    
		case EWordState::Not_isogram:
			FUtility::PrintOnScreenInfo("Enter word not containing same letter !!!\n ");
			break;

		case EWordState::NotValidLength:
			FUtility::PrintOnScreenInfo("Guessed Word Length is too short or too long \n");
			break;
		}

		//Get Current Try increments tries
		currentTry = OCowsAndBulls.GetCurrentTry();
				
	}
	if (OCowsAndBulls.GetState() == EGameState::Lost)
			FUtility::PrintOnScreenInfo("Sorry You Lost :|");

	else if (OCowsAndBulls.GetState() == EGameState::Won)
		FUtility::PrintOnScreenInfo("You Won the Game with ", OCowsAndBulls.GetMaxTry() - currentTry + 1, "left");
}

void FBullsGame::StartGame()
{
	FBullsGame  OGameobject;

	

	bool bWantsToPlayAgain = false;
	do
	{
		FUtility::PrintOnScreenInfo("Welcome To Bulls and Cows Game \n\n");
		OGameobject.ResetGame();
		OGameobject.Play();
		bWantsToPlayAgain = FUtility::PlayAgain();

	} while (bWantsToPlayAgain);

	//exit the game
}
