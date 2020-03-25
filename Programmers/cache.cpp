#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

//캐시클래스
class cacheClass{
public:
    vector<string> memory;
    int maxSize;

    cacheClass(int cacheSize): maxSize(cacheSize){}

    //사이즈에 따라 캐시를 끝에 넣어준다. 끝의 우선순위가 높다.
    void insert(string input){
        transform(input.begin(), input.end(), input.begin(), towlower);
        if(memory.size() >= maxSize)
            memory.erase(memory.begin());
        memory.push_back(input);
    }
    //find함수, 해당 elem이 있으면 값을 지워주고 다시 집어넣는다. 우선순위 변동을 위해 
    int isFind(string elem){
        if(!memory.size()) return 0;
        
        transform(elem.begin(), elem.end(), elem.begin(), towlower);
        auto itr = find(memory.begin(), memory.end(), elem);

        if(itr != memory.end()){
            memory.erase(itr);
            insert(elem);
            return 1;
        }else return 0;
    }

};

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0) return cities.size()*5;

    cacheClass cache(cacheSize);

    for( int i = 0; i < cities.size(); i++){
        //찾으면 내부적으로 우선순위를 바꿔주고
        if(cache.isFind(cities[i])) {
            answer++;
        //찾지 못하면 캐시에 넣어준다. 
        } else {
            answer += 5;
            cache.insert(cities[i]);
        }
    }
    //cout<<answer<<endl;
    return answer;
}

int main(){
    solution(3, {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"});
}