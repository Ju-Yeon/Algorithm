#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
map <int, int> m;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = i;
        for(int l = 0; l < i; l++){
            if(computers[i][l] == 1){
                m[i] = l;
                m[l] = i;
                cout<<i<<" "<<l<<endl;
            }
        }
    }

    for(int i = 0; i < v.size(); i++){
        int elem = v.front();
        cout<<elem<<endl;
        while(m[elem]){
            m.erase(elem);
            v.erase(find(v.begin(), v.end(), elem));
            elem = v.front();
        }
        answer++;
    }
    return answer;
}

int main(){
    cout<<solution(5,  {{1, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {1, 0, 1, 1, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 0, 1}})<<endl;
}