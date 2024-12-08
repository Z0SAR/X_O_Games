#include "BoardGame_Classes.h"
#include <vector>
#include "3x3X_O.h"
template <typename T>
class X_O_9x9_Board:public Board<T>
{
private:
    vector<pair<int ,int>>joe;
    X_O_Board<char>* x_o_board;
    int current_X;
    int current_Y;
public:
    X_O_9x9_Board ();
    static  int nn;
    static  int X;
    static  int Y;
    bool update_board (int x , int y , T mark);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class Player_9x9_X_O : public Player<T> {
public:
    Player_9x9_X_O (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class Random_Player_9x9_X_O : public RandomPlayer<T>{
public:
    Random_Player_9x9_X_O (T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

template <typename T>

X_O_9x9_Board<T>::X_O_9x9_Board()
{
    current_X = -1;
    current_Y = -1;
    this->rows = 9;
    this->columns = 9;
    this->n_moves = 0;
    this->board = new char*[this->rows];
    for(int i = 0;i<this->rows;i++)
    {
        this->board[i] = new char[this->columns];
        for(int j = 0; j<this->columns; j++)
        {
            this->board[i][j] = 0;
        }
    }
    x_o_board = new X_O_Board<char>();
}

template<class T>
bool X_O_9x9_Board<T>::update_board(int gridX, int gridY, T mark)
{
    int nnn = 0;
    if(gridX==-1&&gridX==-1)
    {
        if(nn==0) {
            gridX=rand()%3;
            gridY=rand()%3;
            for( auto & i:joe ) {
                if(i.first==gridX&&i.second==gridY) {
                    nn=0;
                    return false;
                }
            }
        }else {
            gridX=X;
            gridY=Y;
            for( auto & i:joe ) {
                if(i.first==gridX&&i.second==gridY) {
                    nn=0;
                    return false;
                }
            }
        }
        current_X = gridX;
        current_Y = gridY;
        int startX = gridX * 3;
        int startY = gridY * 3;
        for (int i = startX; i < startX + 3; i++)
        {
            for (int i2 = startY; i2 < startY + 3; i2++)
            {
                if (this->board[i][i2] =='O'||this->board[i][i2] =='X')
                {
                    nnn++;
                }
            }
        }
        if(nnn<9) {
            int subX ,x1,y1;
            int subY;
            do {
                subX=rand()%3;
                subY=rand()%3;
                x1 = gridX * 3 + subX;
                y1 = gridY * 3 + subY;
            }while(this->board[x1][y1] == 'X' || this->board[x1][y1] == 'O');
            if (!(x1 < 0 || x1 >= this->rows || y1 < 0 || y1 >= this->columns) && (this->board[x1][y1] == 0 || mark == 0))
            {
                if (mark == 0)
                {
                    this->n_moves--;
                    this->board[x1][y1] = 0;
                }
                else
                {
                    this->n_moves++;
                    this->board[x1][y1] = toupper(mark);
                }
            }
            X = subX;
            Y = subY;
            nn = 1;
            return true;
        }
        return false;
    }{
        for( auto & i:joe ) {
            if(i.first==gridX&&i.second==gridY) {
                return false;
            }
        }
        if (gridX > 2 || gridX < 0 || gridY > 2 || gridY < 0)
        {
            return false;
        }
        current_X = gridX;
        current_Y = gridY;

        int startX = gridX * 3;
        int startY = gridY * 3;
        for (int i = startX; i < startX + 3; i++)
        {
            for (int i2 = startY; i2 < startY + 3; i2++)
            {
                if (this->board[i][i2] =='O'||this->board[i][i2] =='X')
                {
                    nnn++;
                }
            }
        }
        if(nnn<9)
        {
            cout << "Please enter your move x and y (0 to 2) separated by spaces : " << endl;
            int subX, subY;
            cin >> subX >> subY;
            while (subX > 2 || subX < 0 || subY > 2 || subY < 0)
            {
                cout << "Enter new x and y (0 to 2): ";
                cin >> subX >> subY;
            }
            int x1 = gridX * 3 + subX;
            int y1 = gridY * 3 + subY;
            while ((this->board[x1][y1] == 'X' || this->board[x1][y1] == 'O') )
            {
                cout << "Enter new x and y: ";
                cin >> subX >> subY;
                x1 = gridX * 3 + subX;
                y1 = gridY * 3 + subY;
            }
            if (!(x1 < 0 || x1 >= this->rows || y1 < 0 || y1 >= this->columns) && (this->board[x1][y1] == 0 || mark == 0))
            {
                if (mark == 0)
                {
                    this->n_moves--;
                    this->board[x1][y1] = 0;
                }
                else
                {
                    this->n_moves++;
                    this->board[x1][y1] = toupper(mark);
                }
            }
            X = subX;
            Y = subY;
            nn = 1;
            return true;
        }
        return false;
    }

}

template <typename T>
void X_O_9x9_Board<T>::display_board()
{
    cout << "            (0,0)                         (0,1)                           (0,2)      \n";
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            int localRow = i % 3, localCol = j % 3;

            cout <<  "(" << localRow << "," << localCol << ")";
            cout << ' ' << this->board[i][j] << ' ';
            if ((j + 1) % 3 == 0 && j < 8)
            {
                cout << " || ";
            }
            else if(j != 8)
            {
                cout << "| ";
            }
        }
        cout << '\n';
        if ((i + 1) % 3 == 0 && i < 8)
        {
            if(i == 2)
            {
                cout << "===========================================================================================";
                cout << '\n';
                cout << "            (1,0)                         (1,1)                           (1,2)      \n";
            }
            else if(i == 5)
            {
                cout << "===========================================================================================";
                cout << '\n';
                cout << "            (2,0)                         (2,1)                           (2,2)      \n";
            }

        }
        else if(i != 8)
        {
            cout << "---------------------------     ---------------------------     ---------------------------";
            cout << '\n';
        }
    }
}

// Returns true if there is any winner
template <typename T>
bool X_O_9x9_Board<T>::is_win()
{
    if(current_X != -1 && current_Y != -1)
    {
        vector< vector<char> > vec(3,vector<char>(3,0));
        int temp_x = current_X,temp_y = current_Y;
        int index1 = 0,index2 = 0;
        for(int i = (current_X * 3);i < (current_X * 3) + 3 ;i++)
        {

            for(int j = (current_Y * 3);j < (current_Y * 3) + 3;j++)
            {
                vec[index1][index2++] = this->board[i][j];

            }
            index1++;   index2 = 0;
        }
        //-----------------------------------------------------
        for (int i = 0; i < vec.size(); i++)
        {
            if(vec[i][0] == vec[i][1] && vec[i][1] == vec[i][2] && vec[i][0] != 0)
            {
                if(vec[i][0] == 'X')
                {
                    x_o_board->update_board(temp_x,temp_y,'X');
                }
                else
                {
                    x_o_board->update_board(temp_x,temp_y,'O');
                }
                joe.emplace_back(temp_x,temp_y);
            }
            if(vec[0][i] == vec[1][i] && vec[1][i] == vec[2][i] && vec[0][i] != 0)
            {
                if(vec[0][i] == 'X')
                {
                    x_o_board->update_board(temp_x,temp_y,'X');
                }
                else
                {
                    x_o_board->update_board(temp_x,temp_y,'O');
                }
                joe.emplace_back(temp_x,temp_y);
            }

        }
        //-----------------------------------------------------
        if(vec[0][0] == vec[1][1] && vec[1][1] == vec[2][2] && vec[0][0] != 0)
        {
            if(vec[0][0] == 'X')
            {
                x_o_board->update_board(temp_x,temp_y,'X');
            }
            else
            {
                x_o_board->update_board(temp_x,temp_y,'O');
            }
            joe.emplace_back(temp_x,temp_y);
        }
        if(vec[0][2] == vec[1][1] && vec[1][1] == vec[2][0] && vec[0][2] != 0)
        {
            if(vec[0][2] == 'X')
            {
                x_o_board->update_board(temp_x,temp_y,'X');
            }
            else
            {
                x_o_board->update_board(temp_x,temp_y,'O');
            }
            joe.emplace_back(temp_x,temp_y);
        }
        //-----------------------------------------------------
        if(x_o_board->is_win())
        {
            return true;
        }
    }
    return false;
}


template <typename T>
bool X_O_9x9_Board<T>::is_draw() {
    return (this->n_moves == 81 && !is_win());
}

template <typename T>
bool X_O_9x9_Board<T>::game_is_over()
{
    return ( is_win() || is_draw() );
}

//--------------------------------------

// Constructor for X_O_Player
template <typename T>
Player_9x9_X_O<T>::Player_9x9_X_O(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Player_9x9_X_O<T>::getmove(int& x, int& y)
{
    if ( X_O_9x9_Board<T>::nn== 0)
    {
        string inputX,inputY;
        while (true)
        {
            cout << "Please enter your move x and y (0 to 2) separated by spaces : " << endl;
            cin >> inputX >> inputY;

            stringstream ss1(inputX);
            stringstream ss2(inputY);
            if ((ss1 >> x && ss1.eof()) && (ss2 >> y && ss2.eof()) && (x != -1 && y != -1))
            {
                break;
            }
            else
            {
                cout << "*** Enter only integers value for both (x,y) ! ***" << endl;
            }
        }
    }
    else
    {
        x = X_O_9x9_Board<T>::X;
        y = X_O_9x9_Board<T>::Y;
        X_O_9x9_Board<T>::nn = 0;
    }
}

// Constructor for X_O_Random_Player
template <typename T>
Random_Player_9x9_X_O<T>::Random_Player_9x9_X_O(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Random_Player_9x9_X_O<T>::getmove(int& x, int& y) {
    x=-1;
    y=-1;
}
//------------------------------------------------------------------------------
template<class T>
int X_O_9x9_Board<T>::nn= 0;

template<class T>
int X_O_9x9_Board<T>::X= -1;

template<class T>
int X_O_9x9_Board<T>::Y= -1;