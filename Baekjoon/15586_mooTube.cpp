#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, Q;
vector <vector <int>> v;
vector <int> dx;

int solution(int target, int currentPos, int currentValue, vector<int> check){

    int value = v[currentPos][target];
    if(v[currentPos][target] != 0) return currentValue == 0 || value < currentValue? value: currentValue;
    check[currentPos] = 1;

    for(int i = 1; i < N; i ++){
        value = v[currentPos][(currentPos+dx[i])%4];
        if(check[(currentPos+dx[i])%4] == 1 || value == 0) continue;
        return solution(target, (currentPos+dx[i])%4, currentValue == 0 || value < currentValue? value: currentValue, check);
    }

}


int main(){

    cin >> N >> Q;
    vector <int> vSub (N, 0);
    for(int i = 0 ; i < N; i++){
        v.push_back(vSub);
        dx.push_back(i);
    }


    string str;
    vector <string> cmd;

    int n = 0;
    cin.ignore();
    while(true){
        str.empty();
        getline(cin, str);
        cmd.push_back(str);
        if(str.length() == 3 && ++n == Q)break;
    }

    for(int i = 0; i < cmd.size() - Q; i++){
        v[cmd[i][0]-49][cmd[i][2]-49] = cmd[i][4]-48;
        v[cmd[i][2]-49][cmd[i][0]-49] = cmd[i][4]-48;
    }

    vector<int> check(N, 0);
    for(int i = cmd.size()-Q; i < cmd.size(); i++){
        n = 0;
        for(int l = 0; l < N; l ++) {
            if(cmd[i][2]-49 == l) continue;

            fill(check.begin(),check.end(),0);
            v[cmd[i][2]-49][l] = solution(l,cmd[i][2]-49, 0, check);
            v[l][cmd[i][2]-49] = v[cmd[i][2]-49][l];

            if(cmd[i][0]-48 <= solution(l,cmd[i][2]-49, 0, check))n++;
        }
        cout << n << endl;
    }
}