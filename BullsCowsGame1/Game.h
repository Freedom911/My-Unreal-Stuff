#pragma once
#include <string>
#include "cowsAndBulls.h"

using FText = std::string;
using int32 = int;


class FBullsGame
{
private:

	/**Initializes List of Words that can be isogram from Which user have to choose*/
	void InitializeWords();

	/**Resets Game */
	void ResetGame(int maxTry);
    
	/**Contains Implementation of the game */
	void Play();

	FCowsAndBulls OCowsAndBulls;

	

public:
	FBullsGame();
	~FBullsGame();

	/**Function for Starting the Game*/
	static void StartGame();
};

