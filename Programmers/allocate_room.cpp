#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    set<int> s;
    for(int i = 0, l; i < room_number.size(); i++){
        l = room_number[i];
        while(!s.insert(l).second){l++;}
        answer.push_back(l);
    }

    return answer;
}