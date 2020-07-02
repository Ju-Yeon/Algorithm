#include <iostream>
using namespace std;
int main() {
	int T, N, M, count;
	cin>>T;
	
	int n, k;
	for(int i = 0; i < T; i++){
		count = 0;
		cin>>N>>M;
		
		while(N >= 5){
			N -= 5;
			
			if(M >= 7){
				M -= 7;
			}else if(N >= (7-M)){
				N -= (7 - M);
		    M = 0;
			}else
				break;
			
			count++;
		}
		cout<<count<<endl;
	}
}