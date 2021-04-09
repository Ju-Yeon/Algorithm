#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set <string> h;
    
    for(auto& i : phone_book){
        for(int l = 1; l < i.size(); l++){
            h.insert(i.substr(0,l));
        }
    }
    
    for(auto & i : phone_book){
        if(h.find(i) != h.end()) return false;
    }
    return true;

}