/*utility.h Contains common Functionality
*/

#pragma once
#include<string>

//Using this syntax to make Unreal Friendly
using FText = std::string;
using int32 = int;

class FUtility
{
public:
	FUtility();

	~FUtility();

	/**Coverts a Word  to lowercase*/
    static void ProcessWord(std::string &GuessedWord);

	/**  Function for asking Player to Play again*/
	static bool PlayAgain();

	/**  Function for Printing message on Screen*/
	template<typename T,typename ...Args>
	static void PrintOnScreenInfo(const T &var, Args... args)
	{
		if (sizeof...(Args) == 0)
		{
			std::cout << std::endl;
		}

		std::cout << var << " ";

		FUtility::PrintOnScreenInfo(args...);
	}

	template<typename T>
	static void PrintOnScreenInfo(const T &var)
	{
		std::cout << var << std::endl;
	}

};

