#include <iostream>
#include <vector>
#include <string>
#include <emscripten.h>

using namespace std;

EMSCRIPTEN_KEEPALIVE
void printBoard(vector<string> &board,int n){
    cout<<"board"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}
EMSCRIPTEN_KEEPALIVE
bool isSafe(int row,int col,vector<string> &board,int n){
    int trow=row;
    int tcol=col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    row=trow;
    col=tcol;
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }

    row=trow;
    col=tcol;
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }
    return true;
}

EMSCRIPTEN_KEEPALIVE
void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
    if(col==n){
        ans.push_back(board);
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
        // printBoard(board,n);
    
}
extern "C"{
EMSCRIPTEN_KEEPALIVE
const char* solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    solve(0,board,ans,n);

    string res="";
    
    for (int i = 0; i < ans.size(); i++) {
        res+='#';//hash means new arrange ment
        for (int j = 0; j < ans[i].size(); j++) {
            res+=ans[i][j];
            res+='$'; //dollar means new line
        }
        res+='$';
    }
    
    return res.c_str();
}
}

EMSCRIPTEN_KEEPALIVE
int main() {
  int n = 4;
  
  string ans = solveNQueens(n);
//   for (int i = 0; i < ans.size(); i++) {
//     cout << "Arrangement " << i + 1 << "\n";
//     for (int j = 0; j < ans[0].size(); j++) {
//       cout << ans[i][j];
//       cout << endl;
//     }
//     cout << endl;
//   }
    cout<<ans<<endl;
  return 0;
}
