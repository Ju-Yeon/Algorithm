#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;
int boardY(vector<vector<int>> board, int x);
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack <int> s;

    for(int i = 0; i < moves.size(); i++){
        int y = boardY(board, moves[i]-1);
        if(y < 0) continue;
        
        if(!s.empty()) {
            if (s.top() != board[y][moves[i] - 1]){
                s.push(board[y][moves[i] - 1]);

            }else {
                s.pop();
                answer += 2;
            }
        }else{
            s.push(board[y][moves[i] - 1]);
        }
        board[y][moves[i]-1] = 0;
    }

    return answer;
}

int boardY(vector<vector<int>> board, int x){
    for(int i = 0; i< board.size(); i++){
        if(board[i][x] != 0) {
            return i;
        }
    }
    return -1;
}