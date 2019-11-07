//H-index https://www.welcomekakao.com/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> citations) {

    int i=0;
    int num = citations.size();
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(i=0; i<num; i++)
    {
        if(citations[i]<i+1)
            break;
    }
    return i;
}
