#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
void addLine(int num, int core, int len);

int N = 0;
int totalCore = 0;
int totalLen = 0;
int board[12][12];
int board_temp[12][12];

vector <pair <int, int>> coreLoc;

int dx[] = {0, -1, 0, +1};
int dy[] = {-1, 0, +1, 0};

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N;

        //initial
        totalCore = 0;
        totalLen = 0;
        memset(board, 0, sizeof(board));
        memset(board_temp, 0, sizeof(board_temp));
        coreLoc.clear();

        int temp = 0;
        for(int i = 0; i < N; i++){
            for(int l = 0; l < N; l++){
                cin>>board[i][l];
                if(board[i][l] == 1){
                    if(i*l == 0 || i == N-1 || l == N-1) temp++;
                    else coreLoc.emplace_back(i,l);
                }
            }
        }
        addLine(0, temp, 0);
        cout<<"#"<<test_case<<" "<<totalLen<<endl;

    }
    return 0;
}

void addLine(int num, int core, int len){

    if(num >= coreLoc.size()){
        if(totalCore < core){
            totalLen = len;
            totalCore = core;
        }else if(totalCore == core && totalLen > len){
            totalLen = len;
        }
        return;
    }

    int board_fixed[12][12];
    for(int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            board_temp[a][b] = board[a][b];
            board_fixed[a][b] = board[a][b];
        }
    }

    int nx, ny, length, flag = 0;
    

    //위, 오른쪽, 아래, 왼쪽
    for(int i = 0; i < 4; i++) {

        length = 0;
        nx = coreLoc[num].second;
        ny = coreLoc[num].first;

        for(int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                board_temp[a][b] = board_fixed[a][b];
            }
        }

        while (1) {
            nx += dx[i];
            ny += dy[i];
            if (nx == -1 || ny == -1 || nx == N || ny == N) break;

            if (board_temp[ny][nx] == 1) {
                length = 0;
                break;
            } else {
                board_temp[ny][nx] = 1;
                length++;
            }
        }

        if (length > 0) {
            for (int a = 0; a < N; a++) {
                for (int b = 0; b < N; b++) {
                    board[a][b] = board_temp[a][b];
                }
            }
            addLine(num + 1, core + 1, len + length);
            flag++;
        }
    }
    //안함
    if(flag == 0) {
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                board[a][b] = board_fixed[a][b];
            }
        }
        addLine(num + 1, core, len);
    }
}