// TTT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class TicTacToe{

    private:
        string table[3][3];
        bool finished;
        char currentPlayer;

        //printing out the board to visualize to the players what spots are taken.
        void printBoard()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if ((j + 1) == 3)
                    {
                        cout << table[i][j] << endl;
                    }
                    else
                    {
                        cout << table[i][j] << "|";
                    }
                }
                if ((i + 1) != 3)
                {
                    cout << "_____" << endl;
                }
            }
        }

        //check if the board is full (this will be one of the 3 ways I will be checking for game completion.
        bool checkBoardFull()
        {
            int count = 0;
            for (auto& row : table)
            {
                for (string val : row)
                {
                    if (val == "*")
                    {
                        count++;
                    }

                }
            }
            if (count == 0)
            {
                finished = true;
                return true;
            }
            return false;
        }
        bool checkWin() {
            // Check rows (horizontal)
            for (int i = 0; i < 3; i++) {
                if (table[i][0] != "*" && table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
                    return true;
                }
            }

            // Check columns (vertical)
            for (int j = 0; j < 3; j++) {
                if (table[0][j] != "*" && table[0][j] == table[1][j] && table[1][j] == table[2][j]) {
                    return true;
                }
            }

            // Check diagonals
            if (table[0][0] != "*" && table[0][0] == table[1][1] && table[1][1] == table[2][2]) {
                return true;
            }
            if (table[0][2] != "*" && table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
                return true;
            }

            return false;
        }

    public:
        TicTacToe() {
            finished = false;
            currentPlayer = 'X';
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    table[i][j] = "*";
                } 
            }
        }
        void play() {
            cout << "Welcome to Tic-Tac-Toe!" << endl;
            cout << "Players take turns entering row (0-2) and column (0-2)." << endl;

            while (!finished) {
                printBoard();

                string ro, co;
                int row, col;
                cout << "Player " << currentPlayer << " enter row: ";
                cin >> ro;
                for (char c : ro)
                {
                    if(isdigit(static_cast<unsigned char>(c)))
                    {
                        row = c - '0';
                        break;
                    }
                }
                cout << "\nPlayer " << currentPlayer << " enter column: ";
                cin >> co;
                for (char c : co)
                {
                    if(isdigit(static_cast<unsigned char>(c)))
                    {
                        col = c - '0';
                        break;
                    }
                }

                if (row < 0 || row > 2 || col < 0 || col > 2) {
                    cout << "Invalid coordinates! Please choose between 0 and 2." << endl;
                    continue;
                }

                if (table[row][col] != "*") {
                    cout << "That spot is already taken! Choose another." << endl;
                    continue;
                }

                // Place the move
                table[row][col] = string(1, currentPlayer);

                // Check for a win
                if (checkWin()) {
                    printBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    finished = true;
                    break;
                }

                // Check for a draw (board full)
                if (checkBoardFull()) {
                    printBoard();
                    cout << "It's a draw! The board is full." << endl;
                    finished = true;
                    break;
                }

                // Switch player
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
};
int main()
{   
    TicTacToe game;
    game.play();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
