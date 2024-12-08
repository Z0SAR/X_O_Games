#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
//
//int main()
//{
//    vector< vector<char> > grid = {
//            {'o','o','o','o','x'},
//            {'x','o','o','x','x'},
//            {'x','o','o','x','x'},
//            {'o','x','x','o','x'},
//            {'x','x','o',' ','o'}
//    };
//    map<char,int>mp;
//
//    for(int j = 0;j<grid.size();j++)
//    {
//        for(int i = 0;i<grid[j].size();i++)
//        {
//            if(j == 0 || j == 1)
//            {
//                if( i < 3 )
//                {
//                    if(grid[i][j] == grid[i][j+1] && grid[i][j+1] == grid[i][j+2])
//                    {
//                        mp[grid[i][j]]++;
//                    }
//                    if(grid[i][j] == grid[i+1][j+1] && grid[i+1][j+1] == grid[i+2][j+2])
//                    {
//                        mp[grid[i][j]]++;
//                    }
//                    if(grid[i][j] == grid[i+1][j] && grid[i+1][j] == grid[i+2][j])
//                    {
//                        mp[grid[i][j]]++;
//                    }
//                }
//                else
//                {
//                    if(grid[i][j] == grid[i][j+1] && grid[i][j+1] == grid[i][j+2])
//                    {
//                        mp[grid[i][j]]++;
//                    }
//                }
//            }
//            else if(j == 2)
//            {
//                if( i < 3 )
//                {
//                    if(grid[i][j] == grid[i][j+1] && grid[i][j+1] == grid[i][j+2])
//                    {
//                        mp[grid[i][j]]++;
//                    }
//                    if(grid[i][j] == grid[i+1][j+1] && grid[i+1][j+1] == grid[i+2][j+2])
//                    {
//                        mp[grid[i][j]]++;
//                    }
//                    if(grid[i][j] == grid[i+1][j] && grid[i+1][j] == grid[i+2][j])
//                    {
//                        mp[grid[i][j]]++;
//                    }
//                    if(grid[i][j] == grid[i+1][j-1] && grid[i+1][j-1] == grid[i+2][j-2])
//                    {
//                        mp[grid[i][j]]++;
//                    }
//                }
//                else
//                {
//                    if(grid[i][j] == grid[i][j+1] && grid[i][j+1] == grid[i][j+2])
//                    {
//                        mp[grid[i][j]]++;
//                    }
//                }
//            }
//            else if(j == 3 || j == 4)
//            {
//                if(i < 3 )
//                {
//                    if(grid[i][j] == grid[i+1][j-1] && grid[i+1][j-1] == grid[i+2][j-2])
//                    {
//                        mp[grid[i][j]]++;
//                    }
//                    if(grid[i][j] == grid[i+1][j] && grid[i+1][j] == grid[i+2][j])
//                    {
//                        mp[grid[i][j]]++;
//                    }
//                }
//            }
//
//        }
//    }
//
//
////    for(int j = 0;j<grid.size();j++)
////    {
////        for(int i = 0;i<grid[j].size();i++)
////        {
////            cout << grid[i][j] << " ";
////        }
////        cout << endl;
////    }
////
////    cout << "-------------------------------------------"<<endl;
////
////    for(auto& it1: grid)
////    {
////        for(auto& it2 : it1)
////        {
////            cout << it2 << " ";
////        }
////        cout << endl;
////    }
//
////    for(auto& it : mp)
////    {
////        cout << it.first << "  " << it.second <<endl;
////    }
////    if(mp['x'] >= mp['o'])
////    {
////        cout << "YES" << endl;
////    }
////    else
////    {
////        cout << "NO" << endl;
////    }
//
////    char c = static_cast<char> (toupper(0));
////    cout << c <<endl;
////
////    map<char,int>mmp;
////    cout<<mmp['N'] <<endl;
//
////    int b;
////    cout << "b: " << b << endl;
//
////    srand(static_cast<unsigned int >( time(nullptr) ) );
////
////    int n = 24;
////    while(n--)
////    {
////        int x = rand() % 5;
////        int y = rand() % 5;
////        cout << "X: "<<x <<"  Y: "<<y<<endl;
//////        Sleep(1500);
////    }
//
//    // Generate all unique pairs (x, y) in the range 0 to 4
////    std::vector<std::pair<int, int>> pairs;
////    for (int x = 0; x <= 4; ++x) {
////        for (int y = 0; y <= 4; ++y) {
////            pairs.emplace_back(x, y);
////
////        }
////    }
////
////    // Shuffle the pairs randomly
////    std::random_device rd;
////    std::mt19937 g(rd()); // Use Mersenne Twister for randomization
////    std::shuffle(pairs.begin(), pairs.end(), g);
////
////    // Output the unique pairs
////    for (const auto& pair : pairs) {
////        std::cout << "(" << pair.first << ", " << pair.second << ")\n";
////    }
//
//    std::random_device rd; // Seed for randomness
//    std::mt19937 gen(rd()); // Mersenne Twister random number generator
//
//    // Distribution in the range [low, high]
//    std::uniform_int_distribution<int> dist(0, 4);
//
//    // Generate a random floating-point number
//    int random_number = dist(gen);
//
//    std::cout << "Random Number: " << random_number << std::endl;
//
//
//    return 0;
//}


std::vector<std::vector<std::string>> createSmallBoard() {
    return std::vector<std::vector<std::string>>(3, std::vector<std::string>(3, "X"));
}

std::vector<std::vector<std::vector<std::vector<std::string>>>> createMetaBoard() {
    std::vector<std::vector<std::vector<std::vector<std::string>>>> metaBoard(3);
    for (int i = 0; i < 3; i++) {
        metaBoard[i] = std::vector<std::vector<std::vector<std::string>>>(3, createSmallBoard());
    }
    return metaBoard;
}

void printMetaBoard(const vector<vector<vector<vector<string>>>>& metaBoard) {
    for (int metaRow = 0; metaRow < 3; metaRow++) {
        for (int row = 0; row < 3; row++) { // Iterate through rows of small boards
            for (int metaCol = 0; metaCol < 3; metaCol++) {
                for (int col = 0; col < 3; col++) { // Iterate through cells of small boards
                    cout << metaBoard[metaRow][metaCol][row][col];
                    if (col < 2) cout << " | "; // Cell separator in a small board
                }
                if (metaCol < 2) cout << " || "; // Small board separator
            }
            cout << endl;
            if(row < 2) cout << string(10,'-') << "  "<< string(10,'-') << "   "<< string(10,'-') << "  "<<endl;
        }
        if (metaRow < 2) cout << string(35, '=') << endl; // Row separator for meta-board
    }
}


int main()
{

//    printMetaBoard(createMetaBoard());

//    vector<vector<char> > board(9,vector<char>(9,'0'));
//    cout << "            (0,0)                         (0,1)                           (0,2)      \n";
//    for (int i = 0; i < 9; ++i)
//    {
//        for (int j = 0; j < 9; ++j)
//        {
//            int localRow = i % 3, localCol = j % 3;
//
//            cout <<  "(" << localRow << "," << localCol << ")";
//            cout << ' ' << board[i][j] << ' ';
//            if ((j + 1) % 3 == 0 && j < 8)
//            {
//                cout << " || ";
//            }
//            else if(j != 8)
//            {
//                cout << "| ";
//            }
//        }
//        cout << '\n';
//        if ((i + 1) % 3 == 0 && i < 8)
//        {
//            if(i == 2)
//            {
//                cout << "===========================================================================================";
//                cout << '\n';
//                cout << "            (1,0)                         (1,1)                           (1,2)      \n";
//            }
//            else if(i == 5)
//            {
//                cout << "===========================================================================================";
//                cout << '\n';
//                cout << "            (2,0)                         (2,1)                           (2,2)      \n";
//            }
//
//        }
//        else if(i != 8)
//        {
//            cout << "---------------------------     ---------------------------     ---------------------------";
//            cout << '\n';
//        }
//    }


//    int new_i = 0 ,new_j = 0,upper_i = 3, upper_j = 3,count = 3;
//    int n = 3;
//    while(count--)
//    {
//        while(n--)
//        {
//            for(int i = new_i;i<upper_i;i++)
//            {
//                for(int j = new_j ;j<upper_j;j++)
//                {
//                    cout <<  "(" << i << "," << j << ") " ;
//                }
//            }
//            cout << endl;
//            new_j += 3;     upper_j += 3;
//        }
//        new_i += 3;
//        upper_i += 3;
//
//        new_j = 0;
//        upper_j = 3;
//
//        n = 3;
//    }


    vector<vector<char> > board(9,vector<char>(9,'0'));

    int new_i = 0 ,new_j = 0,upper_i = 3, upper_j = 3,count = 3;
    int n = 3;
    for(int x = 0;x < count;x++)
    {
        for(int y = 0;y < n;y++)
        {
            for(int i = new_i;i<upper_i;i++)
            {
                for(int j = new_j ;j<upper_j;j++)
                {
                    cout <<  "(" << i << "," << j << ") " << board[i][j] ;
                }
            }
            cout << endl;
            new_j += 3;     upper_j += 3;
        }
        new_i += 3;     upper_i += 3;

        new_j = 0;      upper_j = 3;
    }
    return 0;
}
//if(this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2] && this->board[i][j] != 0)
//                    {
//                        if(this->board[i][j] == 'X')
//                        {
//                            flag_X = true;
//                        }
//                        else
//                        {
//                            flag_O = true;
//                        }
//                    }
//                    if(this->board[i][j] == this->board[i+1][j] && this->board[i+1][j] == this->board[i+2][j] && this->board[i][j] != 0)
//                    {
//                        if(this->board[i][j] == 'X')
//                        {
//                            flag_X = true;
//                        }
//                        else
//                        {
//                            flag_O = true;
//                        }
//                    }
//                    if(this->board[i+1][j+1] == this->board[i][j] && this->board[i+1][j+1] == this->board[i+2][j+2] && this->board[i+1][j+1] != 0)
//                    {
//                        if(this->board[i+1][j+1] == 'X')
//                        {
//                            flag_X = true;
//                        }
//                        else
//                        {
//                            flag_O = true;
//                        }
//                    }
//                    if(this->board[i+1][j+1] == this->board[i+2][j] && this->board[i+1][j+1] == this->board[i][j+2] && this->board[i+1][j+1] != 0)
//                    {
//                        if(this->board[i+1][j+1] == 'X')
//                        {
//                            flag_X = true;
//                        }
//                        else
//                        {
//                            flag_O = true;
//                        }
//                    }


//---------------------------------------------------------------------------------------------------------------------

//#include <iostream>
//#include "BoardGame_Classes.h"
//#include "3x3X_O.h"
//#include "X_O_5x5.h"
//#include "Misere_X_O.h"
//#include "X_O_9x9_3.h"
//
//using namespace std;
//
//int main()
//{
////    int choice;
////    Player<char>* players[2];
////    Board<char> *B = new X_O_9x9_Board<char>();
////
////    string playerXName, player2Name;
////
////
////    // Set up player 1
////    cout << "Enter Player X name: "<<endl;
////    cin >> playerXName;
////    cout << "Choose Player X type: "<<endl;
////    cout << "1. Human"<<endl;
////    cout << "2. Random Computer"<<endl;;
////    cin >> choice;
////
////    switch(choice) {
////        case 1:
////            players[0] = new Player_9x9_X_O<char>(playerXName, 'X');
////            players[0]->setBoard(B);
////            break;
////        case 2:
////            players[0] = new Random_Player_9x9_X_O<char>('X');
////            players[0]->setBoard(B);
////            break;
////        default:
////            cout << "Invalid choice for Player 1. Exiting the game."<<endl;
////            return 1;
////    }
////
////    // Set up player 2
////    cout << "Enter Player 2 name: "<<endl;
////    cin >> player2Name;
////    cout << "Choose Player 2 type: "<<endl;
////    cout << "1. Human"<<endl;
////    cout << "2. Random Computer"<<endl;
////    cin >> choice;
////
////    switch(choice) {
////        case 1:
////            players[1] = new Player_9x9_X_O<char>(player2Name, 'O');
////            players[1]->setBoard(B);
////            break;
////        case 2:
////            players[1] = new Random_Player_9x9_X_O<char>('O');
////            players[1]->setBoard(B);
////            break;
////        default:
////            cout << "Invalid choice for Player 2. Exiting the game."<<endl;
////            return 1;
////    }
////
////    // Create the game manager and run the game
////    GameManager<char> x_o_game(B, players);
////    x_o_game.run();
////
////    // Clean up
////    delete B;
////    for (int i = 0; i < 2; ++i) {
////        delete players[i];
////    }
//
//
//
//
//
//
////==========================================================================
//    int choice;
//    Player<char>* players[2];
//    Board<char> *B = new Misere_board_X_O<char>();
//
//    string playerXName, player2Name;
//
//
//    // Set up player 1
//    cout << "Enter Player X name: "<<endl;
//    cin >> playerXName;
//    cout << "Choose Player X type: "<<endl;
//    cout << "1. Human"<<endl;
//    cout << "2. Random Computer"<<endl;;
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            players[0] = new Misere_Player_X_O<char>(playerXName, 'X');
//            players[0]->setBoard(B);
//            break;
//        case 2:
//            players[0] = new Misere_randomPlayer_X_O<char>('X');
//            players[0]->setBoard(B);
//            break;
//        default:
//            cout << "Invalid choice for Player 1. Exiting the game."<<endl;
//            return 1;
//    }
//
//    // Set up player 2
//    cout << "Enter Player 2 name: "<<endl;
//    cin >> player2Name;
//    cout << "Choose Player 2 type: "<<endl;
//    cout << "1. Human"<<endl;
//    cout << "2. Random Computer"<<endl;
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            players[1] = new Misere_Player_X_O<char>(player2Name, 'O');
//            players[1]->setBoard(B);
//            break;
//        case 2:
//            players[1] = new Misere_randomPlayer_X_O<char>('O');
//            players[1]->setBoard(B);
//            break;
//        default:
//            cout << "Invalid choice for Player 2. Exiting the game."<<endl;
//            return 1;
//    }
//
//    // Create the game manager and run the game
//    GameManager<char> x_o_game(B, players);
//    x_o_game.run();
//
//    // Clean up
//    delete B;
//    for (int i = 0; i < 2; ++i) {
//        delete players[i];
//    }
//
//
//
////==================================================================
//    int choice;
//    Player<char>* players[2];
//    Board_5x5_X_O<char>* B = new Board_5x5_X_O<char>();
//    string playerXName, player2Name;
//
//
//    // Set up player 1
//    cout << "Enter Player X name: "<<endl;
//    cin >> playerXName;
//    cout << "Choose Player X type: "<<endl;
//    cout << "1. Human"<<endl;
//    cout << "2. Random Computer"<<endl;;
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            players[0] = new Player_5x5_X_O<char>(playerXName, 'X');
//            break;
//        case 2:
//            players[0] = new RandomPlayer_5x5_X_O<char>('X');
//            break;
//        default:
//            cout << "Invalid choice for Player 1. Exiting the game."<<endl;
//            return 1;
//    }
//
//    // Set up player 2
//    cout << "Enter Player 2 name: "<<endl;
//    cin >> player2Name;
//    cout << "Choose Player 2 type: "<<endl;
//    cout << "1. Human"<<endl;
//    cout << "2. Random Computer"<<endl;
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            players[1] = new Player_5x5_X_O<char>(player2Name, 'O');
//            break;
//        case 2:
//            players[1] = new RandomPlayer_5x5_X_O<char>('O');
//            break;
//        default:
//            cout << "Invalid choice for Player 2. Exiting the game."<<endl;
//            return 1;
//    }
//
//    // Create the game manager and run the game
//    GameManager<char> x_o_game(B, players);
//    x_o_game.run();
//
//    // Clean up
//    delete B;
//    for (int i = 0; i < 2; ++i) {
//        delete players[i];
//    }
//
//
////==========================================================================
//    int choice;
//    Player<char>* players[2];
//    X_O_9x9_Board<char>* B = new X_O_9x9_Board<char>();
//
//    string playerXName, player2Name;
//    cout << "Welcome to FCAI X-O Game. :)\n";
//    // Set up player 1
//    cout << "Enter Player X name: ";
//    cin >> playerXName;
//    cout << "Choose Player X type:\n";
//    cout << "1. Human\n";
//    cout << "2. Random Computer\n";
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            players[0] = new Player_9x9_X_O<char>(playerXName, 'X');
//            break;
//        case 2:
//            players[0] = new Random_Player_9x9_X_O<char>('X');
//            break;
//        default:
//            cout << "Invalid choice for Player 1. Exiting the game.\n";
//            return 1;
//    }
//
//    // Set up player 2
//    cout << "Enter Player 2 name: ";
//    cin >> player2Name;
//    cout << "Choose Player 2 type:\n";
//    cout << "1. Human\n";
//    cout << "2. Random Computer\n";
//    cin >> choice;
//
//    switch(choice) {
//        case 1:
//            players[1] = new Player_9x9_X_O<char>(player2Name, 'O');
//            break;
//        case 2:
//            players[1] = new Random_Player_9x9_X_O<char>('O');
//            break;
//        default:
//            cout << "Invalid choice for Player 2. Exiting the game.\n";
//            return 1;
//    }
//
//    // Create the game manager and run the game
//    GameManager<char> x_o_game(B, players);
//    x_o_game.run();
//
//    // Clean up
//    delete B;
//    for (int i = 0; i < 2; ++i) {
//        delete players[i];
//    }
//
//
//
//
//
//    return 0;
//}