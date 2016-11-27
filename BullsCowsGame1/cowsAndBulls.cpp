#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include <functional>
#include <cctype>
#include "cowsAndBulls.h"


FCowsAndBulls::FCowsAndBulls()
{
	srand(time(NULL));
	Reset();

}

FCowsAndBulls::~FCowsAndBulls()
{

}


void FCowsAndBulls::AddWords(FString Word)
{
	Words.push_back(Word);
}


 int32 FCowsAndBulls::GetMaxTry() const
{
	return MaxTry;
}

 int32 FCowsAndBulls::GetCurrentTry() 
{

	if (CurrentTry >= MaxTry)
		State = EGameState::Lost;
	CurrentTry++;
	return CurrentTry;
}

void FCowsAndBulls::SetMaxTry(int32 tryLimit) 
{
	MaxTry = tryLimit;
}

FBullCowCount FCowsAndBulls::CountBullsCows(const FString &GuessedWord) 
{
	FBullCowCount st_bullcowCount;
	for (int32 i = 0; i < CurrentWord.length(); i++)
	{
		for (int32 j = 0; j < GuessedWord.length(); j++)
		{
			if (CurrentWord[i] == GuessedWord[j])
			{
				if (i != j)
					st_bullcowCount.cows++;
				else
					st_bullcowCount.bulls++;
					
			}
		}
	}
	if (st_bullcowCount.bulls == CurrentWord.length())
	{
		State = EGameState::Won;
	}
	return st_bullcowCount;
}

EWordState FCowsAndBulls::GuessWord(const FString &GuessedWord)
{
	if (!isIsogram(GuessedWord))
	{    
		CurrentTry--;
		return EWordState::Not_isogram;
	}

	if (!IsValid(GuessedWord))
	{ 
		CurrentTry--;
		return EWordState::Invalid;
	}

	if (!HasCorrectLength(GuessedWord))
	{
		CurrentTry--;
		return EWordState::NotValidLength;
	}

	return EWordState::OK;
}
//Scope for optimization
bool FCowsAndBulls::isIsogram(const FString &GuessedWord) const
{
	for (int i = 0; i < GuessedWord.length(); i++)
	{
		for (int j = 0; j < GuessedWord.length(); j++)
		{
			if (i != j)
			{
				if (GuessedWord[i] == GuessedWord[j])
				{
					return false;
				}
			}
		}
	}
	return true;
}

//Checks if guessed Word  doesnot contains invalid character
bool FCowsAndBulls::IsValid(const FString &GuessedWord) const
{
	bool result = std::find_if(GuessedWord.begin(), GuessedWord.end(), std::not1(std::ptr_fun((int(*)(int))std::isalpha))) != GuessedWord.end();
	return !result;
}

bool FCowsAndBulls::HasCorrectLength(const FString &GuessedWord) const
{
	return GuessedWord.length() == CurrentWord.length() ? true : false;
}

FString FCowsAndBulls::GetNextWord()
{
	//Get random number from 0 to Words size -1

		int32 index = -1;
		while (true)
		{
			index = rand() % Words.size();
			if (Words[index].size() > 0) {
				CurrentWord = Words[index];
				return Words[index];
			}
			
		}
		
}

void FCowsAndBulls::Reset()
{
	//Reset GameState
	State = EGameState::Default;
	//Reset Max Number of Try
	MaxTry = 0;
	CurrentTry = 0;
	Words.clear();

}

void FCowsAndBulls::SetState(EGameState newState)
{
	State = newState;
}

EGameState FCowsAndBulls::GetState() const
{
	return State;
}
