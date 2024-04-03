//Code is like humour. When you have to explain it, it’s bad. //

//Author - royboylab

#include <bits/stdc++.h>
using namespace std;

//Not optimal to use this 
int check(int row , int col ,vector<string> board,int n){
    int c=col;
    int r=row;

    //check column
    while(col>=0){
        if(board[row][col]=='Q') return 0;
        col--;
    }
    //check upper diagonal
    col=c,row=r;
    while(row>=0 and col>=0){
        if(board[row][col]=='Q') return 0;  
        row--;col--;
    }

    //check lower diagonal 
    col=c,row=r;
    while(row<n and col>=0){
        if(board[row][col]=='Q') return 0;
        row++;col--;
    }

    return 1;
}

void Nqueen(int col,vector<string> board,vector<vector<string>> &NqueenPatterns,int n){

    if(col==n){ //all the columns already filled (0 based indexing)
        NqueenPatterns.push_back(board);
        return;
    }
    
    for(int row = 0; row < n; row++){
        if(check(row,col,board,n)){
            board[row][col]='Q';
            Nqueen(col+1,board,NqueenPatterns,n);
            board[row][col]='.'; // backtracking step - remove queen 
        }
    }
}

void NqueenOptimized(int col,vector<string> board,vector<vector<string>> &NqueenPatterns,int n,vector<int> &leftRow, vector<int> &upperDiag , vector<int> &lowerDiag){
      if(col==n){
        NqueenPatterns.push_back(board);
        return;
    }
    
    for(int row = 0; row < n; row++){
        if(!leftRow[row] and !upperDiag[row+col] and !lowerDiag[n-1+col-row]){
            board[row][col]='Q';
            leftRow[row]=upperDiag[row+col]=lowerDiag[n-1+col-row]=1;
            NqueenOptimized(col+1,board,NqueenPatterns,n,leftRow,upperDiag,lowerDiag);
            leftRow[row]=upperDiag[row+col]=lowerDiag[n-1+col-row]=0;
            board[row][col]='.'; // backtracking step
        }
    }
}


int main()
{   
    int n=4;
    vector<vector<string>> NqueenPatterns;
    string s(n,'.');
    vector<string> board(n,s);
    Nqueen(0,board,NqueenPatterns,n);

    vector<int> leftRow(n,0);
    vector<int> upperDiag(2*n-1,0);
    vector<int> lowerDiag(2*n-1,0);

    NqueenOptimized(0,board,NqueenPatterns,n,leftRow,upperDiag,lowerDiag);

    for(auto x : NqueenPatterns){
        for(auto k : x ){
            cout<<k<<endl;
        }
        cout<<endl;
    }
    
}
