#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T, N;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N;
        vector<pair <int, int>> v(N, {0, 0});

        for(int i = 0; i < N; i++)
            cin>>v[i].second>>v[i].first;

        sort(v.begin(), v.end());

        int start_date = v.back().first - v.back().second;
        v.pop_back();

        while(!v.empty()){
            int ed = v.back().first;
            int st = v.back().first - v.back().second;

            if(ed >= start_date)
                start_date = st - (ed - start_date);
            else start_date = st;

            v.pop_back();
        }

        cout<<"#"<<test_case<<" "<<start_date<<endl;
    }
    return 0;
}