//https://www.acmicpc.net/problem/15586

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, Q;
vector <vector <int>> v;

int dijkstra(){

    int k;
    for(int i = 0; i < N; i++){
        vector<int> isVisited(N, 0);
        isVisited[i] = 1;

        k = 0;
        while(k < N){
            if(isVisited[k] == 0 && v[i][k] != 0){
               isVisited[k] = 1;

               for(int l = 0; l < N; l++){
                   if(v[k][l] != 0 && isVisited[l] == 0 ) {
                       isVisited[l] = 1;
                       v[i][l] = v[k][l] < v[i][k] ? v[k][l] : v[i][k];
                       v[l][i] = v[i][l];
                   }
               }
            }else k++;
        }
    }

}


int main(){

    cin >> N >> Q;
    vector <int> vSub (N, 0);
    for(int i = 0 ; i < N; i++){
        v.push_back(vSub);
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

    dijkstra();
//    for(int a = 0; a < N; a++){
//        for(int b = 0; b < N; b++)
//            cout<<v[a][b]<<" ";
//        cout<<endl;
//    }

    for(int i = cmd.size()-Q; i < cmd.size(); i++){
        n = 0;
        for(int l = 0; l < N; l ++) {
            if (v[cmd[i][2]-49][l] >= cmd[i][0]-48){
                n++;
            }
        }
        cout << n << endl;
    }
}