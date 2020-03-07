#include<iostream>
#include<string>
#include<set>

using namespace std;

char arr[4][4];
set <string> resultSet;

void move(int count, int x, int y, string result);

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
                move(0, i, l, "");
            }
        }
        cout<<"#"<<test_case<<" "<<resultSet.size()-1<<endl;
    }
    return 0;
}

void move(int count, int x, int y, string result)
{
    if(count == 7) {
        resultSet.insert(result);
        return;
    }

    count++;
    result += arr[x][y];

    if(x != 3) move(count, x+1, y, result);
    if(x != 0) move(count, x-1, y, result);
    if(y != 3) move(count, x, y+1, result);
    if(y != 0) move(count, x, y-1, result);

    return;
}
