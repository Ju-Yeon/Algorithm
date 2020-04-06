#include <vector>
#include <map>
#include <iostream>

using namespace std;
map <long long, long long> m;

long long find(long long key){

    if(!m[key]) return key;
    return find(m[key]+1);

}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for(int i = 0; i < room_number.size(); i++){

        long long n = find(room_number[i]);
        
        //다음 인덱스 고려
        if(!m[n+1]) m[n] = n;
        else m[n] = n + 1;;

        //이전 인덱스 고려
        if(m[n-1]) m[n-1] = n;

        answer.push_back(n);

    }
    for(int i =0 ; i < answer.size(); i++)
        cout<<answer[i]<<endl;
    return answer;
}

int main(){
    solution(10, {1,3,4,1,3,1});
}