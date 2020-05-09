#1
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector <pair <int, int>> loc = {make_pair(3,1),
                                make_pair(0,0), make_pair(0, 1), make_pair(0,2),
                                make_pair(1,0), make_pair(1, 1), make_pair(1,2),
                                make_pair(2,0), make_pair(2, 1), make_pair(2,2),
                                make_pair(3,0), make_pair(3,2)};

int distance(int s, int e){
    return abs(loc[s].first - loc[e].first) + abs(loc[s].second - loc[e].second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int r = 10, l=11, rd, ld;

    for(int i = 0; i < numbers.size(); i++ ){

        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            l = numbers[i];

        }else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            r = numbers[i];

        }else{
            rd = distance(r, numbers[i]);
            ld = distance(l,numbers[i]);

            if(rd > ld){
                answer += "L";
                l = numbers[i];

            }else if(rd < ld){
                answer += "R";
                r = numbers[i];

            }else{
                if(hand[0] = 'r'){
                    answer += "R";
                    r = numbers[i];
                }else {
                    answer += "L";
                    l = numbers[i];
                }
            }
        }
    }
    return answer;
}