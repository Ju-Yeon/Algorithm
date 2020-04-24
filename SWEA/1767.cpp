#include<vector>
#include<iostream>

using namespace std;

void addLine(int num, int core, int len, vector<pair<int, int>> coreLoc, vector <vector <int>> board );

int totalCore = 0;
int totalLen = 0;

int main(int argc, char** argv)
{
    int test_case;
    int T, N;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N;
        totalCore = 0; totalLen = 0;
        vector <vector <int>> board(N, vector<int> (N));
        vector <pair <int, int>> coreLoc;

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
        addLine(0, temp, 0, coreLoc, board);

        cout<<"#"<<test_case<<" "<<totalLen<<endl;
    }
    return 0;
}

void addLine(int num, int core, int len, vector<pair<int, int>> coreLoc, vector <vector <int>> board ){

    if(num == coreLoc.size()){
        if(totalCore < core){
            totalLen = len;
            totalCore = core;
        }else if(totalCore == core){
            totalLen = totalLen < len ? totalLen : len;
        }
        return;
    }

    int y = coreLoc[num].first;
    int x = coreLoc[num].second;
    int N = board.size();
    int flag = 1, length = 0;

    vector <pair <int, int>> method = {make_pair(y+1, N), make_pair(x+1, N), make_pair(0, y), make_pair(0, x)};

    //위, 오른쪽, 아래, 왼쪽
    for(int i = 0; i < 4; i++){
        vector <vector <int>> b = board;
        flag = 1; length = 0;

        if(i % 2 == 0){
            for(int l = method[i].first; l < method[i].second; l++){
                if(b[l][x] == 1){
                    flag = 0;
                    break;
                } else {
                    b[l][x] = 1;
                    length++;
                }
            }
            if(flag) addLine(num+1, core+1, len+length, coreLoc, b);


        }else{
            for(int l = method[i].first; l < method[i].second; l++){
                if(b[y][l] == 1){
                    flag = 0;
                    break;
                } else {
                    b[y][l] = 1;
                    length++;
                }
            }
            if(flag) addLine(num+1, core+1, len+length, coreLoc, b);
        }
    }
    //안함
    return addLine(num+1, core, len, coreLoc, board);
}