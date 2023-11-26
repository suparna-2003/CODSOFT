#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() 
{
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Generate a random number between 1 and 10
    int secretNumber = std::rand() % 10 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number game!\n";
    std::cout << "Try to guess the number between 1 and 10.\n";

    do {
    	std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess == secretNumber) 
        {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        } 
        else if (guess < secretNumber) 
        {
            std::cout << "Too low! Try again.\n";
        } else 
        {
            std::cout << "Too high! Try again.\n";
        }

    } while (guess != secretNumber);

    return 0;
}
