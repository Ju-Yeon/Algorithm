#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    vector<vector<int>> sets;
    vector<pair<int, int>> order;

    int size = 0;
    string stemp = "";
    vector<int> temp;

    for(int i = 1, o = 0; i < s.length()-1; i++){
        if( s[i] == '{'){
            temp = {};
            size = 0;
            stemp = "";

        }else if( s[i] == '}'){
            temp.push_back(atoi(stemp.c_str()));
            size++;

            sort(temp.begin(), temp.end());
            sets.push_back(temp);
            order.push_back(make_pair(size, o++));
            i++;
        }else {
            if(s[i] == ','){
                temp.push_back(atoi(stemp.c_str()));
                size++;
                stemp ="";
            }else {
                stemp += s[i];
            }
        }
    }

    sort(order.begin(), order.end());

    answer.push_back(sets[order[0].second][0]);

    for(int i = 1; i< order.size(); i++){
        vector<int>v(1);
        int idx1 = order[i-1].second;
        int idx2 = order[i].second;

        set_difference(sets[idx2].begin(), sets[idx2].end(), sets[idx1].begin(), sets[idx1].end(), v.begin());
        answer.push_back(v[0]);
    }

    return answer;
}