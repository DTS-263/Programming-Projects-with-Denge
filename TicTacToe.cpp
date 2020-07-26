#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Other variables
int choice;
int row,column;
char turn = 'X';
bool draw = false;

// Making the board
void display_board()
{
	cout<<"PLAYER 1-[X]t PLAYER 2-[O]"<<endl;
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<board[0][0]<<"  | "<<board[0][1]<<"   | "<<board[0][2]<<" \n";
	cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}
// Function to get the player input and update the board

void player_turn()
{
	if(turn == 'X')
	{
		cout<<"\n\tPlayer 1-[X] turn : ";
	}	
	else
	{
		cout<<"\n\tPlayer 2-[O] turn : ";
	}
	// Taking the input from the user in the variable choice declared above
	cin>>choice;
	// Using switch case for going to a particular row and column
	switch(choice)
	{
		case 1: row=0; column=0; break;
		case 2: row=0; column=1; break;
		case 3: row=0; column=2; break;
		case 4: row=1; column=0; break;
		case 5: row=1; column=1; break;
		case 6: row=1; column=2; break;
		case 7: row=2; column=0; break;
		case 8: row=2; column=1; break;
		case 9: row=2; column=2; break;
		default: 
		cout<<"[WARNING] Invalid Move!!"<<endl;
	}
	//Searching for the box and detecting whether the box is empty or not
	if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
	{
		//After identifing that the turn is of X and knowing that the box is empty we would replace the value number by the sign X
		board[row][column] = 'X';
		turn = 'O';
	}
	else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
	{
		board[row][column] = 'O';
		turn = 'X';
	}
	else
	{
		cout<<"Box already filled!!\nPlease try another box!!\n\n";
		player_turn();
	}
	//Ends
	display_board();
}
// Function to know the game status WON or in CONTINUE mode
bool gameover()
{
	//checks the rows and columns
	for(int i=0;i<3;i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] || board[0][i] == board[1][i] && board[1][i] == board[2][i])
		return false; 
	}
	// checks the diagonals
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return false;
	}
	// checks and keeps the game in CONTINUE mode
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j] != 'X' && board[i][j] != 'O')
			{
				return true;
			}
		}
	}
	// checks if already draw
	draw = true;
	return false;
}
int main()
{
	cout<<setw(50)<<"TIC TAC TOE GAME"<<endl;
	cout<<setw(50)<<"For 2 Players"<<endl;
	while(gameover())
	{
		display_board();
		player_turn();
		gameover();
	}
	
	if(turn == 'X' && draw == false)
	{
		cout<<"\n\nCongratulations!! Player with 'O' won the game!!\n";
	}
	else if(turn == 'O' && draw == false)
	{
		cout<<"\n\nCongratulations!! Player with 'X' won the game!!\n";
	}
	else
	{
		cout<<"\n\nGame Drawn!!";
	}
	
}
