#include <iostream>
#include <string>

std::int16_t upper_bound_number = 100; 
std::int16_t lower_bound_number = 1;
std::int16_t random_number;

enum GUESS_RESULT {
    HIGHER,
    LOWER,
    CORRECT
};

GUESS_RESULT getGuess(){
    std::string guess_input;

    std::cin >> guess_input;

    int16_t guess_int = std::stoi(guess_input);

    if (guess_int > random_number){
        return LOWER;
    } else if (guess_int < random_number){
        return HIGHER;
    } else {
        return CORRECT;
    }
}

int main(int argc, char** argv) {
    srand(time(0));
    random_number = lower_bound_number + (rand() % upper_bound_number);

    std::cout << "Welcome to the Random Number Game, Please Guess the Random Number " << std::endl;

    while (true)
    {
        std::cout << "Input guess: ";
        GUESS_RESULT guess_result = getGuess();

        if (guess_result == CORRECT)
        {
            std::cout << "Correct" << std::endl;
            break;
        } else
        {
            if (guess_result == HIGHER){
                std::cout << "The number is higher than your guess." << std::endl;
            } else if (guess_result == LOWER) {
                std::cout << "The number is lower than your guess." << std::endl;
            }
        }    
    }

    return 0;
}
