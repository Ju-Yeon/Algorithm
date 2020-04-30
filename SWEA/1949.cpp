#include<iostream>
#include<vector>

using namespace std;

int N, k, totalLen, minNum, maxNum;
int map[8][8];
int map_fixed[8][8];
int dx[] = {0, +1, 0, -1};
int dy[] = {+1, 0, -1, 0};
vector<pair<int, int>> highest;
void dfs(int y, int x, int k, int len);

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N>>k;
        maxNum = 0;
        minNum = 21;
        totalLen = 0;
        memset(map, 0, 12);
        memset(map_fixed, 0, 12);

        for(int i = 0; i < N; i++){
            for(int l = 0; l < N; l++){
                cin>>map[i][l];
                map_fixed[i][l] = map[i][l];
                if(maxNum < map[i][l]) {
                    maxNum = map[i][l];
                    highest.clear();
                    highest.emplace_back(make_pair(i, l));
                } else if (maxNum == map[i][l]){
                    highest.emplace_back(make_pair(i,l));
                }

                if(minNum > map[i][l])
                    minNum = map[i][l];
            }
        }

        for(int i = 0; i < highest.size(); i++) {
            dfs(highest[i].first, highest[i].second, k, 1);
           cout<<totalLen<<endl;
        }

        cout<<"#"<<test_case<<" "<<totalLen<<endl;
    }
    return 0;
}

void dfs(int y, int x, int k, int len) {
    if(map[y][x] == minNum) {
        if (totalLen < len) totalLen = len;
        return;
    }

    int flag = 0,  minNum_fixed;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        for (int t = 0; t <= k; t++) {
            if (t != 0) {
                map[ny][nx] = map_fixed[ny][nx] - t;
                if (map[ny][nx] < 0) map[ny][nx] = 0;
                if (minNum > map[ny][nx]) {
                    minNum_fixed = minNum;
                    minNum = map[ny][nx];
                }
                if (map[y][x] > map[ny][nx]) {
                    dfs(ny, nx, 0, len + 1);
                    flag++;
                }
                map[ny][nx] = map_fixed[ny][nx];
                minNum = minNum_fixed;
            }

            if (map[y][x] > map[ny][nx]) {
                dfs(ny, nx, k, len + 1);
                flag++;
            }
        }
    }

    if(flag == 0){
        if (totalLen < len) totalLen = len;
        return;
    }
}