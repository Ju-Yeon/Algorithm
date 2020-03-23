#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int c;
void dfs(int num, int N, string alpha, vector<string> words);

int main(int argc, char** argv)
{
    int test_case;
    int T, N;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {

        cin>>N;
        vector <string> words(N);
        for(int i = 0; i < N; i++)
            cin>>words[i];

        c = 0;
        string alpha = "00000000000000000000000000";
        dfs(-1, N, alpha, words);

        cout<<"#"<<test_case<<" "<<c<<endl;
    }
    return 0;
}

void dfs(int num, int N, string alpha, vector<string> words){
    if(num != -1){
       int idx1 = alpha.find("0");

       while( idx1 != -1 ){
           int idx2 = words[num].find(idx1+97);
           if(idx2 != -1) alpha[idx1] = '1';
           idx1 = alpha.find("0", idx1+1);
        }

        idx1 = alpha.find("0");
        if(idx1 == -1) c++;

    }

    for(int i = num+1 ; i < N; i++)
        dfs(i, N, alpha, words);

    return;
}