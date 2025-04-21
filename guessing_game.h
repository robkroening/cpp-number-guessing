#pragma once

class GuessingGame {
// this data is internal to itself for the game
private:
    // number to guess to win the game
    int targetNumber;
    // amount of guesses the user has guessed
    int numGuesses;
    // min bound for range
    int minRange;
    // max bound for range
    int maxRange;

    // A method to generate a new random number
    void generateRandomTargetNumber();

public:
    //  Constructor
    GuessingGame(int minRange = 1, int maxRange = 100);

    // A method to start the game (run the main loop)
    void startGame();

    // play a round
    void playRound();

    // gets the guess from user input and input validation
    int getUserGuess();

    // A method to get input from the user
    int getUserInput();

    // A method to check the guess against the target
    void checkGuess(int guess);

    // ask the user if they want to play again
    bool askToPlayAgain();
};