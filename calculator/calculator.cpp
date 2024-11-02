#include <iostream>
#include <cmath>

int main() 
{
    // variables
    char operation;
    double number1, number2;

    // menu
    bool running = true;

    // outer loop
    while (running)
    {
    // if else statement checking entered operation
        // user input
        std::cout << "Enter First number: " << std::endl;
        while (!(std::cin >> number1))
        {
            std::cout << "Invalid input. Enter a valid number: " << std::endl;
            std::cin.clear();
        }

        std::cout << "Enter Operation (+, -, *, /): " << std::endl;
        while (!(std::cin >> operation) || (operation != '+' && operation != '-' && operation != '*' && operation != '/'))
        {
            std::cout << "Invalid operation. Enter a valid option (+, -, *, /): " << std::endl;
            std::cin.clear();
        }

        std::cout << "Enter Second number: " << std::endl;
        while (!(std::cin >> number2))
        {
            std::cout << "Invalid input. Enter a valid number: " << std::endl;
            std::cin.clear();
        }

        switch (operation)
        {
            case '+': {
                double add = number1 + number2;
                std::cout << number1 << " + " << number2 << " = " << add << std::endl;
                break;
            }

            case '-': {
                double sub = number1 - number2;
                std::cout << number1 << " - " << number2 << " = " << sub << std::endl;
                break;
            }

            case '*': {
                double mult = number1 * number2;
                std::cout << number1 << " * " << number2 << " = " << mult << std::endl;
                break;
            }

            case '/': {
                if (number2 != 0) {
                    double div = number1 / number2;
                    std::cout << number1 << " / " << number2 << " = " << div << std::endl;
                } else {
                    std::cout << "Error: Division by zero not allowed." << std::endl;
                }
                break;
            }

            default: {
                std::cout << "Invalid Operator! Choose a valid option." << std::endl;
                break;
            }
        }

        bool validChoice = false;

        // replay options
        while (!validChoice)
        {
            char choice;

            std::cout << "Continue? (Y or N) : " << std::endl;
            std::cin >> choice;
            choice = tolower(choice);

            while (choice != 'y' && choice != 'n')
            {
                std::cout << "Invalid option. Enter a valid option (Y or N): " << std::endl;
                std::cin >> choice;
                choice = tolower(choice);
            }

            switch (choice)
            {
                case 'y': {
                    validChoice = true;
                    break;
                }

                case 'n': {
                    validChoice = true;
                    running = false;
                    std::cout << "Exiting calculator..." << std::endl;
                    break;
                }

                default: {
                    std::cout << "Error: Invalid option. (Y or N)!" << std::endl;
                    break;
                }
            }
        }
    }
    return 0;
}