#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> d(0);
    
    for(auto& i : participant) d[i]++;
    for(auto& i : completion) d[i]--;
    for(auto& i : d){
        if(i.second > 0) return i.first;
    }
    
    return 0;
}