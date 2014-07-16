// Guess my Number
// The player must choice a number and the computer has to guess it

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//seed the number generator
	srand(static_cast<unsigned int>(time(0)));
	
	int numberPick = 0;
	int maxLevel = 100;
	int minLevel = 0;
	int guess;
	int tries = 0;
	bool numberOk = false;
	bool isGuessIt = false;

	cout << "\tGuess My Number\n\n";

	//loop that contol the number entered for the gamer
	while (!numberOk)
	{
		cout << "Enter a number between 1 to 100: ";
		cin >> numberPick;

		if (numberPick >= 0 && numberPick <= 100)
			numberOk = true;
		else
		{
			cout << "\nYou must enter a number between 1 and 100\n\n";
			numberOk = false;
		}			
	}

	//this loop guess the number
	while (!isGuessIt)
	{
		guess = rand() % maxLevel + 1; //random between 1 to maxLevel value
		cout << "I think is: " << guess << endl;
		++tries;

		if (guess >= minLevel)
		{
			if (guess == numberPick)
			{
				cout << "After " << tries << " intents I win!!\n";
				cout << "The number you enter is " << guess << endl;
				isGuessIt = true;
			}
			else
			{
				if (guess > numberPick)
				{
					//is to high, so this is the new maxLevel value
					maxLevel = guess;
				}
				if (guess < numberPick)
				{
					//is to low, so this is the new minLevel value
					minLevel = guess;
				}
				//isGuessIt = false;
			}
		}
		//else
			//isGuessIt = false;
	}

	return 0;
}