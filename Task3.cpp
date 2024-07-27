/* A simple console-based Tic-Tac-Toe game that allows two players
to play against each other */
#include <iostream>
#include <conio.h>
using namespace std;

void printgrid(char grid[3][3]);
void game(char P, char grid[3][3]);
bool check(char grid [3][3], char P);

int main()
{
    cout << "Let's play Tic-Tac Toe\n";
   start: cout << "Press any Key to Continue...\n";
    getch();
    char grid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    printgrid(grid);
    char player = 'X';
    int z;
   for (z = 1; z <= 9; z++)
    {  game(player, grid);
       if (check(grid,player)== true){
        cout << "Player "<<player<< " wins!";
        break;
       }
       else
       cout<< "Game Ongoing\n";
       player = (player== 'X')? 'O':'X'; 
       }
   if (z==9 && !check(grid,'X') && !check(grid,'O'))
   {cout<< "It's a draw!";
   }
   cout<< "\nDo you want to play again?\nType 'yes' or 'no' : ";
   string again;
   cin>> again;
   if (again=="yes")
   {cout<< "Let's play again\n";
    goto start;
   }
    
}
void game(char P, char grid[3][3])
{
    initiate: cout << "Player " << P << " Enter the row(0/1/2): ";
    int rOW_iNPUT;
    int cOLUMN_iNPUT;
    cin >> rOW_iNPUT;
    cout<< "Enter the column(0/1/2): ";
    cin >> cOLUMN_iNPUT;
    if ((rOW_iNPUT<0)||(cOLUMN_iNPUT<0)||(rOW_iNPUT>2)||(cOLUMN_iNPUT>2)||(grid[rOW_iNPUT][cOLUMN_iNPUT]!=' '))
    {
        cout<<"Invalid Input! Please Enter Again\n";
        goto initiate;
    }
    else {grid[rOW_iNPUT][cOLUMN_iNPUT] = P;
    printgrid(grid);}
}
void printgrid(char grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "-------------\n";
        for (int j = 0; j < 3; j++)
        {
            cout << "| " << grid[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-------------\n";
}
bool check(char grid [3][3], char P){
    for (int i=0;i<3;i++ ){
    if ((grid[i][0] == P && grid[i][1] == P && grid[i][2] == P)||(grid[0][i] == P && grid[1][i] == P && grid[2][i] == P))
        return true;
    }
    if (((grid[0][0] == P && grid[1][1] == P && grid[2][2] == P) ||
        (grid[0][2] == P && grid[1][1] == P && grid[2][0] == P))) 
        return true;
    else 
        return false;
}