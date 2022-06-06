//
// Created by rajat joshi on 03-06-2022.
//

//#include <iostream>
//#include <string>
//#include <random>
//#include <unordered_map>

#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool playing = true;
    string userMoveStr, playAgain;
    int playerWins = 0, compWins = 0, compMove, userMove, result;
    typedef unordered_map<int,string> moveMap;
    moveMap moves = { {1, "Rock"}, {2, "Paper"}, {3, "Scissors"} };

    // Initialize random number generator
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(1, 3); // define the range

    std::cout << "Welcome!" << std::endl;

    while(playing)
    {
        cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: \n";
        getline(cin, userMoveStr);

        while(!(userMoveStr == "1" || userMoveStr == "2" || userMoveStr == "3"))
        {
            cout << "Unknown command! Please try that again..." <<"\n";
            cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: ";
            getline(cin, userMoveStr);
        }

        // Convert the user move from a string to an integer
        userMove = stoi(userMoveStr);

        // Create random integer in range [1,3] to simulate the computer selecting a move
        compMove = distr(eng);

        result = userMove - compMove;

        if(result == 0)
            cout << "Tie game!" << "\n";
        else if(result == 1 || result == -2)
        {
            cout << "Congratulations, you won!" << "\n";
            playerWins++;
        } else
        {
            cout << "Sorry, you lost!" << "\n";
            compWins++;
        }

        cout << "Your move: " << moves[userMove] << " // Computer's move: " << moves[compMove] << "\n";
        cout << "(Player: " << playerWins << " | Computer: " << compWins << ")" << "\n";
        cout << "Play again? [y/n]: ";
        getline(cin, playAgain);

        while(!(playAgain == "y" || playAgain == "n"))
        {
            cout << "Unknown command! Please try that again..." << "\n";
            cout << "Play again? [y/n]: ";
            getline(cin, playAgain);
        }
        if(playAgain == "n")
            playing = false;
    }
    return 0;
}