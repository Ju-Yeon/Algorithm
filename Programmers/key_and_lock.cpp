#include <iostream>
#include <vector>

using namespace std;
bool solution(vector<vector<int>> key, vector<vector<int>> lock);
int insert (int x, int y, int N,  vector<vector<int>> board, vector<vector<int>> key);
vector<vector<int>> rotate(vector<vector<int>> key);

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size(), M = key.size();
    vector<vector<int>> board(2*M+N-2, vector<int>(2*M+N-2, 0));

    //put lock on the board
    for(int ny = M-1, a = 0; ny < M-1 + N; ny++, a++){
        for(int nx = M-1, b = 0; nx < M-1 + N; nx++, b++) {
            board[ny][nx] = lock[a][b];
        }
    }

    //put key on board with rotation
    for(int i = 0; i < M+N-1; i++){
        for (int l = 0; l < M+N-1; l++){
            vector<vector <int>> nextKey = key;

            for(int d = 0; d < 4; d++)
            {
                if(insert(l, i, N, board, nextKey) == 0) return true;
                nextKey = rotate(nextKey);
            }
        }
    }
    return false;
}

//rotate function, just put element start from side, 왼쪽 아래부터
vector<vector<int>> rotate(vector<vector<int>> key){
    int s = key.size();
    vector<vector<int>> result(s, vector<int>(s, 0));

    for (int l = 0, a = 0; l < s; l++, a++){
        for(int i = s-1, b = 0; i >= 0 ; i--, b++){
            result[a][b] = key[i][l];
        }
    }
    return result;
}

//insert and count function, if it isn't fit then return -1, or count the 1 in lock board to check if it fits well
int insert (int x, int y, int N, vector<vector<int>> board, vector<vector<int>> key){
    int M = key.size();

    //비트논리연산자 이용
    for(int ny = y, a = 0; ny < y + M; ny++, a++){
        for(int nx = x, b = 0; nx < x + M; nx++, b++) {
            board[ny][nx] = board[ny][nx] ^ key[a][b];
            if(!board[ny][nx] && key[a][b]) return -1;
        }
    }

    //해당 자물쇠가 다 들어맞았는지 1의 갯수를 count
    int count = 0;
    for(int ny = M-1; ny < M+N-1; ny++){
        for(int nx = M-1; nx <  N+M-1; nx++){
            if(!board[ny][nx]) count ++;
        }
    }
    return count;

}

int main() {
    vector<vector <int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector <int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    cout<< solution(key, lock) <<endl;

    return 0;
}
