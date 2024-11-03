#include <iostream>
#include <cstdlib>
#include <ctime>

void tooLow()
{
    std::cout << "Too low.. \n" << std::endl;
}

void tooHigh()
{
    std::cout << "Too high.. \n" << std::endl;
}

void enterAttempt()
{
    std::cout << "Enter an attempt: " << std::endl;
}

void winning()
{
    std::cout << "YOU WIN!!!! :D" << std::endl;
}

int main()
{
    // game variables
    int attempt = 0, userGuess, i;
    bool running = true, playing, guessing, replayOption = true;

    // user input
    // menu
    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "You are given 5 attempts to guess the right number." << std::endl;
    std::cout << "Each time you try a guess, you will be given a hint 'too high' or 'too low'." << std::endl;

    // main game loop
    // loop thats checks if the user has gotten the number right
    // limit of attempts 5
    while (running)
    {
        // correct flag position in case the loops crashes or resets
        playing = true;
        guessing = true;
        // begin
        std::cout << "Ready? Let's begin." << std::endl;

        // random number
        // variable
        int randomNum;

        // get a different random number each time the program runs
        srand(time(0));

        // random number generator 1-100
        randomNum = rand() % 101;

        while (playing)
        {   
            attempt = 0;

            for (; attempt < 6 && guessing; attempt++)
            {
                switch (attempt) {
                    case 0: {
                        // prompt the user for input
                        std::cout << "\n" << "Attempt: 1/5" << std::endl;
                        enterAttempt();
                        
                        while (!(std::cin >> userGuess))
                        {
                        std::cout << "Error: Invalid input. Enter a number." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        }
                        
                        if (userGuess < randomNum)
                        {
                            tooLow();
                        } else if (userGuess > randomNum) {
                            tooHigh();
                        } else if (userGuess == randomNum) {
                            winning();
                            guessing = false;
                        }
                        break;
                    }

                    case 1: {
                        // prompt the user for input
                        std::cout << "Attempt: 2/5" << std::endl;
                        enterAttempt();
                        
                        while (!(std::cin >> userGuess))
                        {
                        std::cout << "Error: Invalid input. Enter a number." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        }
                        
                        if (userGuess < randomNum)
                        {
                            tooLow();
                        } else if (userGuess > randomNum) {
                            tooHigh();
                        } else if (userGuess == randomNum) {
                            winning();
                            guessing = false;
                        }
                        break;
                    }

                    case 2: {
                        // prompt the user for input
                        std::cout << "Attempt: 3/5" << std::endl;
                        enterAttempt();
                        
                        while (!(std::cin >> userGuess))
                        {
                        std::cout << "Error: Invalid input. Enter a number." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        }
                        
                        if (userGuess < randomNum)
                        {
                            tooLow();
                        } else if (userGuess > randomNum) {
                            tooHigh();
                        } else if (userGuess == randomNum) {
                            winning();
                            guessing = false;
                        }
                        break;
                    }

                    case 3: {
                        // prompt the user for input
                        std::cout << "Attempt: 4/5" << std::endl;
                        enterAttempt();
                        
                        while (!(std::cin >> userGuess))
                        {
                        std::cout << "Error: Invalid input. Enter a number." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        }
                        
                        if (userGuess < randomNum)
                        {
                            tooLow();
                        } else if (userGuess > randomNum) {
                            tooHigh();
                        } else if (userGuess == randomNum) {
                            winning();
                            guessing = false;
                        }
                        break;
                    }

                    case 4: {
                        // prompt the user for input
                        std::cout << "Last Chance.. Make it count." << std::endl;
                        std::cout << "Attempt: 5/5" << std::endl;
                        enterAttempt();
                        
                        while (!(std::cin >> userGuess))
                        {
                        std::cout << "Error: Invalid input. Enter a number." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        }
                        
                        if (userGuess < randomNum)
                        {
                            tooLow();
                        } else if (userGuess > randomNum) {
                            tooHigh();
                        } else if (userGuess == randomNum) {
                            winning();
                            guessing = false;
                        }
                        break;
                    }

                    case 5: {
                        std::cout << "You Lost.. :(" << std::endl;
                        std::cout << "The correct awnser was: " << randomNum <<  "\n" << std::endl;
                        playing = false;
                        replayOption = true;
                    }
                }
            }

            // replay option
            char userReplay;

            std::cout << "Want to play again? (Y/N): " << std::endl;

            while(!(std::cin >> userReplay) || (userReplay != 'y' && userReplay != 'n'))
            {
                std::cout << "Invalid option. Enter either Y or N." << std::endl;
                userReplay = tolower(userReplay);
                std::cin.clear();
            }
            
            switch (userReplay)
            {
                case 'y': {
                    playing = true;
                    guessing = true;
                    replayOption = false;
                    break;
                }
                case 'n': {
                    std::cout << "Thanks for playing. See you again soon!" << std::endl;
                    replayOption = false;
                    guessing = false;
                    playing = false;
                    running = false;
                    break;
                }
            }
        }
    }
    return 0;
}