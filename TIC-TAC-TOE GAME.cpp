
#include <iostream>
using namespace std;

char g_board[3][3];
//assigning the positions to game board 
void board_positions()
{   char a='1';
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
           g_board[i][j]=a;
            a=a+1;
        }
    }
}

void display_board()
{
    cout <<"\n";
    for(int i=0; i<3; i++){
        cout << " ";
    for(int j=0; j<3; j++)
    {
        cout << g_board[i][j];
        if (j<2)
         cout << " | ";
    }
    cout << "\n";
    if (i<2) 
    cout << "---|---|---\n";
    }
    cout << "\n";
}

// to check status of match
bool status(char ply)
{
// checking along rows and columns
for (int i=0; i<3; i++)
{
    if(g_board[i][0]==ply && g_board[i][1]==ply && g_board[i][2]==ply) 
    return true;
    if(g_board[0][i]==ply && g_board[1][i]==ply && g_board[2][i]==ply) 
    return true;
    
}
//checking along diagonals
if(g_board[0][0]==ply && g_board[1][1]==ply && g_board[2][2]==ply) 
    return true;
if(g_board[0][2]==ply && g_board[1][1]==ply && g_board[2][0]==ply) 
    return true;
return false;
}
//to check whether the game is draw or not
bool drawstatus()
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if (g_board[i][j] != 'x' && g_board[i][j]!='0')
                return false;
    return true; 
}

int main()
{
    int position;
    char player ='x';
    bool game = true;
    
    while(game)
    {
        board_positions();
        while(game){
            display_board();
            cout << "player " << player << " enter a number(1-9):";
            cin >> position;
            int row= (position-1)/3;
            int column= (position-1)%3;
            //position typoerror and already assigned error
            if (position< 1 || position >9 || g_board[row][column]=='x' || g_board[row][column]=='0')
            {
                cout << "invalid entry \n";
                continue;
            }
            g_board[row][column]= player;
            if (status(player)) {
                display_board();
                cout << "Player:"<< player <<" win\n";
                break;
            }
            else if (drawstatus()){
            display_board();
            cout << "draw\n";
            break;
                
            }
            if (player=='x')
                player='0';
            else player='x';
            }
            char play_again;
            cout << "y or n\n";
            cin >> play_again;
            if (play_again=='n') game=false;
            
        }
        return 0;
    
}