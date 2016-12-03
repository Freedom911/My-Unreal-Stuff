/*Contains the implementation of Logic for the Game
*/

#pragma once
#include <string>
#include "cowsAndBulls.h"

//Using this syntax to make Unreal Friendly
using FText = std::string;
using int32 = int;


class FBullsGame
{
private:

	/**Initializes List of Words that can be isogram from Which user have to choose*/
	void InitializeWords();

	/**Resets Game */
	void ResetGame();
    
	/**Contains Implementation of the game */
	void Play();

	FCowsAndBulls OCowsAndBulls;

	

public:
	FBullsGame();

	/**Function for Starting the Game*/
	static void StartGame();
};

