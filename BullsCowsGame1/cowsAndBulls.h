#pragma once
#include<string>
#include<vector>

using FString = std::string;
using int32 = int;

//Game State
enum class EGameState
{
	Lost,
	Won,
	Default
};

//Word State
enum class EWordState
{
	Not_isogram,
	Invalid,
	NotValidLength,
	OK
};

struct FBullCowCount
{
	int32 bulls = 0;
	int32 cows = 0;
};

class FCowsAndBulls
{

private:

	int32 MaxTry;
	int32 CurrentTry;
	FString CorrectWord;
	EGameState  State;
	std::vector<FString>Words;

	/**Returns True if the word can be isogram*/
	bool isIsogram(const FString&GuessedWord)const;

	/**Returns True if the Word doesnot contains digits or special character*/
	bool IsValid(const FString&GuessedWord)const;

	/**Returns True if the Guessed Word Length is equal to Current Word Length*/
	bool HasCorrectLength(const FString &GuessedWord) const;

public:
	FCowsAndBulls();
	~FCowsAndBulls();

	/**Returns Maximum Try allowed*/
	int32 GetMaxTry() const;

	/**Returns Current Try */
	int32 GetCurrentTry() ;

	/**Returns Next Word*/
	FString GetNextWord();
    
	/**Check if Guessed Word is valid */
	EWordState GuessWord(const FString &GuessedWord);

	/**Returns Number of Cows and Bulls*/
	FBullCowCount CountBullsCows(const FString &GuessedWord);

	/**Add Words to available List of Words */
	void AddWords(FString Word);
	
	/**Set Current State */
	void SetState(EGameState newState);

	/**Reset State ,Maximum Try and Current Try and List*/
	void Reset();

	/**Set Maximum Try available */
	void SetMaxTry(int32 tryLimit);

	/** Returns State */
	EGameState GetState() const;



};

