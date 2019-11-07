//targetNumber https://www.welcomekakao.com/learn/courses/30/lessons/43165

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count(vector<int> numbers, int idx, int sum, int target, string temp);
int solution(vector<int> numbers, int target);

int solution(vector<int> numbers, int target) {

    int answer=0;
    answer = count(numbers, 0, 0, target,"");
    return answer;

}

int count(vector<int> numbers, int idx, int sum, int target, string temp)
{
    int a = 0, b = 0;
    int c = numbers[idx];

    if(idx == numbers.size()) {
        return (sum == target);
    }
    else if(idx < numbers.size()){
        idx++;
        a = count(numbers, idx, sum + c, target, temp + to_string((+1)*c));
        b = count(numbers, idx, sum - c, target, temp + to_string((-1)*c));
        return (a + b);
    }

}

int main()
{
    vector<int> numbers = {1,1,1,1,1};
    int result = solution(numbers, 3);
    cout <<result;
}
