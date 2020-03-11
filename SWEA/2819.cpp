#include<iostream>
#include<string>
#include<set>

using namespace std;

char arr[4][4];
set <string> resultSet;

void dfs(int count, int x, int y, string result);

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        resultSet.clear();
        resultSet.insert("");

        for(int i = 0; i < 4; i++){
            for (int l = 0; l < 4; l++){
                cin>>arr[i][l];
            }
        }

        for(int i = 0; i < 4; i++) {
            for (int l = 0; l < 4; l++) {
                dfs(0, i, l, "");
            }
        }
        cout<<"#"<<test_case<<" "<<resultSet.size()-1<<endl;
    }
    return 0;
}

void dfs(int count, int x, int y, string result)
{
    int nx[4] = {0, 0, -1, +1};
    int ny[4] = {-1, +1, 0, 0};

    if(count == 7) {
        resultSet.insert(result);
        return;
    }

    for(int i = 0; i < 4; i++){
        int dx = x + nx[i];
        int dy = y + ny[i];

        if( dx < 0 || dx > 3 || dy < 0 || dy > 3) continue;
        else{
            dfs(count + 1, dx, dy, result + arr[dx][dy]);
        }

    }

    return;
}