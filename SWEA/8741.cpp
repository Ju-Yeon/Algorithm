#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T, find_idx = 0, idx;
    string result, word;
    cin>>T;
    cin.ignore();

    for(test_case = 1; test_case <= T; ++test_case)
    {

        getline(cin, word);
        idx = 0;
        find_idx = idx;
        result = "";

        result = word[0];
        while(word.length()){

            find_idx = word.find(" ", idx);
            if(find_idx == -1) break;
            idx = find_idx + 1;
            result += word[idx];

        }
        transform(result.begin(), result.end(), result.begin(), ::toupper);
        cout<<"#"<<test_case<<" "<<result<<endl;


    }
    return 0;
}