#include <iostream>
#include <vector>

using namespace std;
bool solution(vector<vector<int>> key, vector<vector<int>> lock);
int insert (int x, int y, int N,  vector<vector<int>> board, vector<vector<int>> key);
vector<vector<int>> rotate(vector<vector<int>> key);

int main() {
    vector<vector <int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector <int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    cout<< solution(key, lock) <<endl;

  return 0;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size(), M = key.size();
    vector<vector<int>> board(2*M+N-2, vector<int>(2*M+N-2, 0));

    int a=0, b=0;
    for(int ny = M-1; ny < M-1 + N; ny++){
        for(int nx = M-1; nx < M-1 + N; nx++) {
            board[ny][nx] = lock[a][b++];
        }
        b = 0; a++;
    }

    int count = 0;
    for(int ny = M-1; ny < M+N-1; ny++){
        for(int nx = M-1; nx <  N+M-1; nx++){
            if(!board[ny][nx]) count ++;
        }
    }
    if(count == 0) return true;


    for(int i = 0; i < M+N-2; i++){
        for (int l = 0; l < M+N-2; l++){
            vector<vector <int>> nextKey(M, vector<int>(M));
            nextKey= key;

            for(int d = 0; d < 4; d++)
            {
                if(insert(l, i, N, board, nextKey) == 0) return true;
                nextKey = rotate(nextKey);
            }
        }
    }
    return false;
}

vector<vector<int>> rotate(vector<vector<int>> key){
    int s = key.size();
    vector<vector<int>> result(s, vector<int>(s, 0));

    int a = 0, b = 0;
    for (int l = 0; l < s; l++){
        for(int i = s-1; i >= 0 ; i--){
            result[a][b++] = key[i][l];
        }
        b = 0; a++;
    }
    return result;
}

int insert (int x, int y, int N, vector<vector<int>> board, vector<vector<int>> key){
    int M = key.size();
    int a = 0, b = 0;

    for(int ny = y; ny < y + M; ny++){
        for(int nx = x; nx < x + M; nx++) {
            board[ny][nx] = board[ny][nx] ^ key[a][b];
            if(!board[ny][nx] && key[a][b]) return -1;
            b++;
        }
        b = 0; a++;
    }

    //출력
    // cout<<endl;
    // for(int ny = 0; ny < 2*M+N-2; ny++){
    //     for(int nx = 0; nx < 2*M+N-2; nx++)
    //         cout<<board[ny][nx];
    //     cout<<endl;
    // }

    int count = 0;
    for(int ny = M-1; ny < M+N-1; ny++){
        for(int nx = M-1; nx <  N+M-1; nx++){
            if(!board[ny][nx]) count ++;
        }
    }
    return count;

}


