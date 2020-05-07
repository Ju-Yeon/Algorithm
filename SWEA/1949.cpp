#include<iostream>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

int N, k, totalLen, maxNum;
int map[8][8];
int map_fixed[8][8];
int dx[] = {0, +1, 0, -1};
int dy[] = {+1, 0, -1, 0};
vector <pair<int, int>> load;
vector<pair<int, int>> highest;
void dfs(int y, int x, int k, int len);
int isChecked(int y, int x);

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N>>k;
        maxNum = 0;
        totalLen = 0;
        memset(map, 0, 8);
        memset(map_fixed, 0, 8);
        load.clear();

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
            }
        }

        for(int i = 0; i < highest.size(); i++) {
            load.emplace_back(make_pair(highest[i].first, highest[i].second));
            dfs(highest[i].first, highest[i].second, k, 1);
            load.pop_back();
        }
        cout<<"#"<<test_case<<" "<<totalLen<<endl;
    }
    return 0;
}

void dfs(int y, int x, int k, int len) {


    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N ) continue;

        if (map[y][x] > map[ny][nx] && isChecked(ny, nx)) {
            load.push_back(make_pair(ny, nx));
            dfs(ny, nx, k, len + 1);
            flag++;
            load.pop_back();
        }

        for (int t = 1; t <= k; t++) {
            if (map_fixed[ny][nx]-t < 0) continue;
            map[ny][nx] = map_fixed[ny][nx] - t;

            if (map[y][x] > map[ny][nx] && isChecked(ny, nx)){
                load.push_back(make_pair(ny, nx));
                dfs(ny, nx, 0, len + 1);
                flag++;
                load.pop_back();
            }
            map[ny][nx] = map_fixed[ny][nx];

        }
    }
    //더이상 이동하지 않으면 종료
    if(flag == 0){
        if (totalLen < len) totalLen = len;
        return;
    }
}

//경로 방문 유뮤
int isChecked(int y, int x){
    for(int i = 0; i < load.size(); i++) {
        if (load[i].first == y && load[i].second == x)
            return 0;
    }
    return 1;
}