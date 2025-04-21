#include <iostream> // for std::cout and std::cin
#include <cstdlib> // for random numbers
#include <ctime> // for time
#include "guessing_game.h"

// This class will include:
//      storing the target number
//      counting the amount of guesses
//      Running the game loop
//      Handling input and feedback

// target number
// number of guesses
// min range
// max range
// generate the target number method
int targetNumber;
int numGuesses;
int minRange;
int maxRange;
void GuessingGame::generateRandomTargetNumber() {
    // targetNumber gets assigned here so you dont have to do it again in the constructor
    targetNumber = minRange + (std::rand() % (maxRange - minRange + 1));
};

    // constructor -> what happens at the start of each game
GuessingGame::GuessingGame(int minimumRange, int maximumRange) {
    this->minRange = minimumRange;
    this->maxRange = maximumRange;
    this->numGuesses = 0;
    generateRandomTargetNumber();
}

    // start game method is public
    // this should initiate the game
    // then perform a loop that continues while the user is in the playround loop
void GuessingGame::startGame() {
    char playAgain;
    do {
        // initialize number of guesses
        numGuesses = 0;
        // initialize target number
        generateRandomTargetNumber();
        
        // provde some basic prompt to user
        std::cout << "I am thinking of a random number between " << minRange << " and " << maxRange << " . Can you guess what it is?";

        // play the game
        playRound();

        // tell user if they won or not
        std::cout << "Nice! You won in " << numGuesses << " guesses.";
        // ask the user if they want to play again or not
        std::cout << "Would you like to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}

// private:
// handles the guessing game loop
void GuessingGame::playRound() {
    int numberGuess;
    do {
        // gets the user's guess
        numberGuess = getUserGuess();
        // increase the number of guesses by 1
        numGuesses = numGuesses + 1;
        // check to see if the guess is the target number
        checkGuess(numberGuess);
    } while (targetNumber != numberGuess);
}

// gets the user's guess for the game
int GuessingGame::getUserGuess() {
    int guess;
    std::cout << "Please input a number to guess: ";
    std::cin >> guess;
    return guess;
}

// checks the guess
// provides feedback based on the guess
void GuessingGame::checkGuess(int guess) {
    if (guess < targetNumber) {
        std::cout << "You guessed a number too low.";
    } else if (guess > targetNumber) {
        std::cout << "You guessed a number too high.";
    } else {
        std::cout << "Congrats! You've guessed the correct number.";
    }
}