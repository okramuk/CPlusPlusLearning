// Word Jumble with score

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//enum the fields required
	enum fields {WORD, HINT, NUM_FIELDS};

	//declare the variables and array 
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{ "flower", "Is something that always give a smile to women"},
		{ "pencil", "If you are an artist this will be your best friend." },
		{ "window", "Is something that can't miss in the front of a house"},
		{ "shoes", "You can't use it inside a japanese house"},
		{ "computer", "This tool is the best friend for a game developer"}
	};

	
	//now choice a word
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];
	
	//now jumble the word
	string jumble = theWord;
	int lengthWord = theWord.size();

	for (int i = 0; i < lengthWord; ++i)
	{
		int index1 = (rand() % lengthWord);
		int index2 = (rand() % lengthWord);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	//give the Welcome to the gamer
	cout << "\t\t\tWelcome Jumble Word!!\n\n";
	cout << "You must guess the word that I share!!\n";
	cout << "Each word has a score, How much do you obtained?\n\n";
	cout << "I give you the word but if you want help enter 'hint'.\n";
	cout << "If you want to exit, enter 'quit'.\n\n";
	cout << "I choice the word, and this it is: " << jumble << endl;

	string guess;
	cout << "Enter the word: ";
	cin >> guess;
	
	while ((guess != "quit") && (guess != theWord) )
	{
		if (guess == "hint")
		{
			cout << theHint << endl;
		}
		else
		{
			cout << "Sorry, that's not!!\n\n\n";
		}

		cout << "Enter the word: ";
		cin >> guess;				
	}
	
	if (guess == theWord)
	{
		cout << "You got it!!\n\n";
		cout << "You're score now is: " << theWord.size() * 10 << endl;
	}
	
	cout << "Thanks for playing.\n";

	return 0;
}