#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <map>
#include <set>

std::map<char,bool> getAlphabet();

int main() {
    //Keeps track if they would like to play again
    bool contGame = false;
    //Stores all the words
    std::vector<std::string> wordBank {"spectacular", "dogs", "start", "locket", "playground", "zealous", "vigorous", "cure", "stale", "delirious"};

    //Runs the game until the user chooses to quit
    do {
        //used to store if the player desires to continue or not
        char playerDecision;
        //initializes random seed
        srand(time(NULL));
        //selects the random word.
        std::string theWord = wordBank.at(rand() % wordBank.size());
        std::string currentState (theWord.size(), '_');
        //keeps track of all incorrect guesses
        std::set<char> lettersGuessed;
        //The map is used to prevent repeat guesses
        std::map<char,bool> allLettersGuessed = getAlphabet();

        int correctGuess = 0;
        int incorrectGuess = 0;
        std::cout << "Welcome to Hangman!" << std::endl << "The word has " + std::to_string(theWord.size()) +" letters." << std::endl;
        //plays until the word is guessed
        while (currentState != theWord) {
            char curGuess;
            std::vector<int> matchingIdx;
            std::cout << "Please guess a letter: " << std::endl;
            std::cin >> curGuess;

            //verifies input as being valid and if it has been guessed before
            while (!isalpha(curGuess)) {
                std::cout << "Please enter a letter from a-z" << std::endl;
                curGuess = '\0';
                std::cin >> curGuess;
            }
            while(allLettersGuessed[tolower(curGuess)] == true) {
                std::cout << "You already guessed that! Guess again: " << std::endl;
                curGuess = '\0';
                std::cin >> curGuess;
            }
            allLettersGuessed[tolower(curGuess)] = true;
            curGuess = tolower(curGuess);

            //check at what indecies if any have the corresponding letter
            for(size_t i = 0; i < theWord.size(); i++) {
                if (theWord.at(i) == tolower(curGuess)) {
                    matchingIdx.push_back(i);
                }
            }

            //if letter is not in the word
            if(matchingIdx.size() == 0) {
                incorrectGuess++;
                std::cout << "Your guess \'" << curGuess << "\' is not in the word along with: ";
                std::set<char>::iterator it;
                for (it = lettersGuessed.begin(); it != lettersGuessed.end(); ++it) {
                    std::cout << *it << " ";
                }
                std::cout << std::endl;

                lettersGuessed.insert(curGuess);

            }
            else { //it is a correct guess
                correctGuess++;
                for(int i : matchingIdx) {
                    currentState.at(i) = curGuess;
                }
                if (currentState == theWord) {
                    break;
                }
                std::cout << "Correct!" << std::endl << "Here's the curent state of the word: " << currentState << std::endl;
            }

            std::cout << "Correct Guesses: " + std::to_string(correctGuess) << std::endl << "Incorrect Guesses: " + std::to_string(incorrectGuess) << std::endl;
            std::cout << currentState << std::endl;
        }

        std::cout << "CONGRATS! YOU SUCCESSFULLY GUESSED THE WORD! \"" + theWord + "\"" << std::endl << "It only took " + std::to_string(correctGuess + incorrectGuess) + " guesses!" << std::endl;
        std::cout << "Would you like to play again? (\'y\'/\'n\')" << std::endl;
        std::cin >> playerDecision;

        //validate user input
        while (std::tolower(playerDecision) != 'y' && std::tolower(playerDecision) != 'n') {
            std::cout << "Please enter either \'y\'/\'n\'" << std::endl;
            playerDecision = '\0';
            std::cin >> playerDecision;
        }
        if (tolower(playerDecision) == 'y') {
            contGame = true;
        }
        else {
            contGame = false;
        }

    } while (contGame);
    std::cout << "Thanks for playing! Have a great day!";
    return 0;
}

std::map<char,bool> getAlphabet() {
    std::map<char,bool> toReturn;
    toReturn['a'] = false;
    toReturn['b'] = false;
    toReturn['c'] = false;
    toReturn['d'] = false;
    toReturn['e'] = false;
    toReturn['f'] = false;
    toReturn['g'] = false;
    toReturn['h'] = false;
    toReturn['i'] = false;
    toReturn['j'] = false;
    toReturn['k'] = false;
    toReturn['l'] = false;
    toReturn['m'] = false;
    toReturn['n'] = false;
    toReturn['o'] = false;
    toReturn['p'] = false;
    toReturn['q'] = false;
    toReturn['r'] = false;
    toReturn['s'] = false;
    toReturn['t'] = false;
    toReturn['u'] = false;
    toReturn['v'] = false;
    toReturn['w'] = false;
    toReturn['x'] = false;
    toReturn['y'] = false;
    toReturn['z'] = false;
    return toReturn;
}
# Hangman-Challenge
