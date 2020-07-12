#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp  (const string &a, const string &b)
{
    return (a+b) > (b+a);
}

string solution(vector<int> numbers) {

    string answer = "";
    
    vector<string> number;
    for(int i = 0; i < numbers.size(); i++)
        number.push_back(to_string(numbers[i]));

    sort(number.begin(), number.end(), comp);
    if(number.front()=="0")return "0";

    for(int i = 0; i < number.size(); i++)
        answer += number[i];
    
    //string answers = to_string(stoi(answer));
    return answer;
}