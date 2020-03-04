#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
    int T, N, i, l;
    int test_case, score_case;
    int arr[10000];
    queue <int> q;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N;

        fill_n(arr, 10000, 0);
        arr[0] = 1;

        for(score_case = 0; score_case < N; score_case++)
        {
            cin>>l;
            auto itr = find(arr, arr+10000, 1);

            while(itr != end(arr)) {
                q.push(distance(arr,itr));
                itr = find(itr+1, arr+10000, 1);
            }

            while(!q.empty()){
                i = q.front();
                arr[i+l] = 1;
                q.pop();
            }
        }

        i=0;
        auto itr = find(arr, arr+10000, 1);
        while(itr != end(arr)) {
            i++;
            itr = find(itr+1, arr+10000, 1);
        }

       cout<<"#"<<test_case<<" "<<i<<endl;

    }
    return 0;
}