/****************************************************************************************
 * Program Name:        rock_paper_scissors.cpp
 * Author:              Damian Amerman-Smith
 * Description:         Basic rock-paper-scissors game allowing the user to play against
 *                      random computer choices.
 * Inputs:              User choices (typed in full) & if the user would like to keep
 *                      playing. Note: there is no input checking for a player's choice.
 * Outputs:             The computer's choice, the outcome of a game, the ongoing scores,
 *                      & prompts for input.
 ***************************************************************************************/
#include <iostream>
#include <ctime>
#include <random>
using namespace std;

enum class rps {
    rock,
    paper,
    scissors,
    error,
};


class Score {
    private:
        int player_score;
        int computer_score;
    public:
        Score() {
            player_score = 0;
            computer_score = 0;
        }

        void print() {
            cout << "----------------------------------------------------" << endl
                 << "| Your points: " << player_score << "\t|\t" 
                 << "Computer Score: " << computer_score << "|" << endl
                 << "----------------------------------------------------" << endl << endl;
        }

        void determine_winner(rps choice, rps computer_choice) {
            if (choice == computer_choice) {
                cout << "It's a tie! No points gained." << endl << endl;
            } else if ((choice == rps::paper) && (computer_choice == rps::rock)) {
                cout << "You win!" << endl << endl;
                player_score += 1;
            } else if ((choice == rps::scissors) && (computer_choice == rps::rock)) {
                cout << "You lose!" << endl << endl;
                computer_score += 1;
            } else if ((choice == rps::rock) && (computer_choice == rps::paper)) {
                cout << "You lose!" << endl << endl;
                computer_score += 1;
            } else if ((choice == rps::scissors) && (computer_choice == rps::paper)) {
                cout << "You win!" << endl << endl;
                player_score += 1;
            } else if ((choice == rps::rock) && (computer_choice == rps::scissors)) {
                cout << "You win!" << endl << endl;
                player_score += 1;
            } else if ((choice == rps::paper) && (computer_choice == rps::scissors)) {
                cout << "You lose!" << endl << endl;
                computer_score += 1;
            }
            cout << endl << endl;
        }

};


rps stoc(string str_choice) {
    if ((str_choice == "rock") || (str_choice == "Rock")) {
        return rps::rock;
    } else if ((str_choice == "paper") || (str_choice == "Paper")) {
        return rps::paper;
    } else if ((str_choice == "scissors") || (str_choice == "Scissors")) {
        return rps::scissors;
    } else {
        return rps::error;
    }
}


rps decide_computer_choice() {
    int int_choice = (1 + rand() % 3);
    switch (int_choice) {
        case 1:
            cout << "We chose rock!" << endl;
            return rps::rock;
            break;
        case 2:
            cout << "We chose paper" << endl;
            return rps::paper;
            break;
        case 3:
            cout << "We chose scissors!" << endl;
            return rps::scissors;
            break;
        default:
            cout << "We don't know what we chose." << endl;
            break;
    }
    return rps::error;
}


bool is_input_good(string str_in) {
    if ((str_in == "yes") || (str_in == "no")) {
        return true;
    } else {
        return false;
    }
}


int main () {
    srand(time(NULL));
    bool quit = false;
    cout << "Welcome to Rock Paper Scissors! You're going to play against us, and we'll keep score!" << endl;
    Score score;
    do {
        string str_choice;
        rps choice;
        do {
            cout << "Choose rock, paper, or scissors." << endl;
            cin >> str_choice;
            choice = stoc(str_choice);
            cout << endl << endl;
        } while (choice == rps::error);
        rps computer_choice = decide_computer_choice();
        score.determine_winner(choice, computer_choice);
        score.print();
        string str_in;
        do {
            cout << "Would you like to continue? Type yes or no." << endl;
            cin >> str_in;
            cout << endl << endl;
        } while (!(is_input_good(str_in)));
        if (str_in == "no") {
            quit = true;
        }
    } while (quit == false);
    return 0;
}


