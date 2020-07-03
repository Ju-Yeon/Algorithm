#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;
vector<int>numbers;
bool comp  (int a,  int b);
void quickSort( int s, int e);

string solution(vector<int> number) {

    numbers = number;
    string answer = "";
    quickSort(0,numbers.size()-1);

    if(numbers[0]==0)return "0";

    for(int i=0;i<numbers.size(); i++)
        answer = answer + to_string(numbers[i]);

    string answers = "";
    answers=to_string(stoi(answer));
    return answers;
}


bool comp  (int a,  int b)
{
    string aa = to_string(a);
    string bb = to_string(b);

    return (stoi(string(aa+bb))>stoi(string(bb+aa)));

}

void quickSort( int s, int e){
    if(s+1 >= e) return;

    int p = (s + e)/2;
    int pivot = numbers[p];
    int l = s;
    int r = e;
    int temp;

    while(l < r){
        while(comp(numbers[l], pivot) && l<e)
            l++;
        while(comp(pivot,numbers[r]) && s<r)
            r--;

        if(l<r) { //swap
            temp = numbers[l];
            numbers[l] = numbers[r];
            numbers[r] = temp;
        }
    }
    quickSort(l, e);
    quickSort(s, r);

}

int main(){
    cout<<solution({3, 30})<<endl;

}