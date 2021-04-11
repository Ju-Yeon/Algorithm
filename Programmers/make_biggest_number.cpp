

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string s = "";

    for(int i = 0; i < number.length(); i++){
        
        //string 에서 한자리 숫자 비교가능(사전순서대로기 때문), 그러나 여러자리를 비교할 때는 형변환 필요
        while (s.length() != 0 && number[i] > s.back() && k > 0) {
            s.pop_back();
            k--;
        }
        if(k == 0){
            s += number.substr(i);
            break;
        }
        s.push_back(number[i]);
    }
    cout<<s<<endl;
    return s.substr(0,s.length() - k);
}

int main(){
    solution("1924", 2);
    solution("1231234", 3);
    solution("4177252841", 4);
}