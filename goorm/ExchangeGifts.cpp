//자료형 시간초과
//https://devth-preview.goorm.io/exam/53763/주-구르미-신입-개발자-공개채용-코딩테스트/quiz/3

#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
    cout.tie(NULL);
	
    int T;
    unsigned long long M, N, k;
    cin>>T;

    for(int i = 0; i < T; i++){
		cin>>N>>M;

    k = N/5;
    while(k != 0){
        if(M+N >= 12*k)break;
        else k--;
    }

    cout<<k<<endl;
	}

	return 0;
}
