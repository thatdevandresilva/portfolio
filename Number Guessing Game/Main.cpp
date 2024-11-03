#include <iostream>

void welcomePlayer()
{
    std::cout << "\nWelcome to the Number Guessing Game!" << std::endl;
    std::cout << "You are given 5 attempts to guess the right number." << std::endl;
    std::cout << "The game range is from 1 to 100" << std::endl;
    std::cout << "Each time you try a guess, you will be given a hint 'too high' or 'too low'. \n" << std::endl;
}

void tooLow()
{
    std::cout << "Too low.. \n" << std::endl;
}

void tooHigh()
{
    std::cout << "Too high.. \n" << std::endl;
}

void winning()
{
    std::cout << "YOU WON! \n" << std::endl;
}

void enterAttempt()
{
    std::cout << "Enter attempt: " << std::endl;
}

int main()
{
    // variables
    int attempt, randomNum, userGuess;
    bool running = true, playing, guessing, replay = true;

    // while running the app
    while (running)
    {
        playing = true;
        guessing = true;

        welcomePlayer();
        srand(time(0));

        // playing loop
        while (playing)
        {
            // random number
            randomNum = rand() % 101;

            // reset the attempt number to 0 after each try
            attempt = 0;

            std::cout << "Let's begin? \n" << std::endl;

            // guessing logic
            for (attempt = 0; attempt < 5 && guessing; attempt++)
            {
                std::cout << "Attempt: " << attempt << "/5" << std::endl;
                enterAttempt();

                while (!(std::cin >> userGuess) )
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
                } else {
                    winning();
                    guessing = false;
                    break;
                }
            }

            if (guessing)
            {
                std::cout << "You Lost.. :(" << std::endl;
                std::cout << "The correct answer was: " << randomNum <<  "\n" << std::endl;
                playing = false;
                replay = true;
            }

            char userReplay;

            std::cout << "Want to play again? (Y/N): " << std::endl;

            while (!(std::cin >> userReplay) || (userReplay != 'y' && userReplay != 'Y' && userReplay != 'n' && userReplay != 'N'))
            {
                std::cout << "Error: Invalid option. Enter either Y or N." << std::endl;
                std::cin.clear();
            }

            switch (userReplay)
            {
                case 'y':
                {
                    playing = true;
                    guessing = true;
                    break;
                }

                case 'n':
                {
                std::cout << "Thanks for playing. See you again soon!" << std::endl;
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