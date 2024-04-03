#include <bits/stdc++.h>
using namespace std;
int check(int row,int col,vector<vector<char>> &board,int l){
    for (int  i = 0; i < 9; i++)
    {
        if(board[row][i]==l){
            return 0;
        }
        if(board[i][col]==l){
            return 0;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==l){
            return 0;
        }
    }
    return 1;
}
int SudokoSolver(vector<vector<char>> &board){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(board[i][j]=='.'){
                for (int l = '1'; l <= '9'; l++)
                {
                    if(check(i,j,board,l)){
                        board[i][j]=l;
                    
                        if(SudokoSolver(board)){
                            return 1;
                        }
                        else{
                            board[i][j]='.';
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main()
{   

}
