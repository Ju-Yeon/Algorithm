//자료형 시간초과
//https://devth-preview.goorm.io/exam/53763/주-구르미-신입-개발자-공개채용-코딩테스트/quiz/3

#include <stdio.h>

int main() {
    int T;
	long long M, N, k1, k2, k;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%lld %lld", &N, &M);
		
        k1 = N/5;
		k2 = (N+M)/12;
		k = k1 < k2 ? k1: k2;
		
        while(N+M < 12*k){
			if(k == 0) break;
			k--;
        }
        printf("%lld\n",k);
	}
	return 0;
}
