//https://www.acmicpc.net/problem/2947

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> arr(5);

void swap(int n){
    swap(arr[n], arr[n+1]);

    for(int i = 0; i < 5; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int check(){
    for(int i = 0; i < 4; i++) {
        if(arr[i] > arr[i+1])
            return 0;
    }
    return 1;
}

void bubbleSort(){

    do {
        for(int i = 0; i < 4; i++){
            if(arr[i] > arr[i+1])
                swap(i);
        }
    }while(!check());
}

int main(){

    for(int i = 0; i < 5; i++)
        cin>>arr[i];

    bubbleSort();
}