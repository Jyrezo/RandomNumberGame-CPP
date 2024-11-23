#include <iostream>
#include <string>

std::int16_t upper_bound_number = 100; 
std::int16_t lower_bound_number = 1;
std::int16_t random_number;

enum GUESS_RESULT {
    HIGHER,
    LOWER,
    CORRECT,
    INVALID_GUESS
};

GUESS_RESULT getGuess(){
    std::string guess_input;

    std::cin >> guess_input;

    try {
        int16_t guess_int = std::stoi(guess_input);

        if (guess_int > random_number){
            return LOWER;
        } else if (guess_int < random_number){
            return HIGHER;
        } else {
            return CORRECT;
        }
    } catch (const std::exception& error) {
        return INVALID_GUESS;
    }
}

int main(int argc, char** argv) {
    srand(time(0));
    random_number = lower_bound_number + (rand() % (upper_bound_number - lower_bound_number + 1));

    printf("Welcome to the Random Number Game, guess the random number! (%s - %s)\n", std::to_string(lower_bound_number).c_str(), std::to_string(upper_bound_number).c_str());

    int16_t number_of_guesses = 0;

    while (true)
    {
        std::cout << "Input guess: ";
        GUESS_RESULT guess_result = getGuess();

        number_of_guesses += 1;

        if (guess_result == CORRECT)
        {
            printf("Correct!\nYou guessed the number in %s guesses!\n", std::to_string(number_of_guesses).c_str());
            break;
        } else
        {
            if (guess_result == HIGHER){
                std::cout << "The number is higher than your guess." << std::endl;
            } else if (guess_result == LOWER) {
                std::cout << "The number is lower than your guess." << std::endl;
            } else if (guess_result == INVALID_GUESS) {
                std::cout << "Your guess is not valid." << std::endl;
            }
        }    
    }

    system("pause");

    return 0;
}
