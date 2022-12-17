#include <bits/stdc++.h>
using namespace std;

void trueCheck(char board[8][8], int col);
bool isValid(char board[8][8], int row, int col);
char board[8][8]; 
int counter = 0;

void printboard(char board[8][8]){
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			cout << board[i][j];
		}
		cout<<endl;
	}
}

int main(){
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			cin >> board[i][j];
		}
	}
	trueCheck(board,0);
	cout << counter;
}

void trueCheck(char board[8][8], int col){
	if(col==8)
	{
		// cout<<" TEST\n";
		// printboard(board);
		counter++;
		return;
	}
	// once all columns are completely checked
	for(int i=0; i<8; i++)
	{
		if(isValid(board,i,col) && board[i][col] == '.')
		{
			board[i][col] = 'x';
			trueCheck(board,col+1);
			board[i][col] = '.';
		}
	}
}

bool isValid(char board[8][8], int row, int col){
	// cout << row << col << ' ';
	int i,j;
	for(i=0; i<col; i++){
		if(board[row][i]=='x'){
			// cout << "false\n";
			return false;
		}
	}
	for(i=row,j=col; i>=0 && j>=0; i--, j--){
		if(board[i][j]=='x'){
			// cout << "false\n";
			return false;
		}
	}
	for(i=row,j=col; i<8 && j>=0; i++, j--){
		if(board[i][j]=='x'){
			// cout << "false\n";
			return false;
		}
	}
	// cout << "true\n";
	return true;
}