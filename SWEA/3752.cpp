#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
    int T, N, temp, score;
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
            cin >> score;
            auto itr = find(arr, arr+10000, 1);

            while(itr != end(arr)) {
                q.push(distance(arr,itr));
                itr = find(itr+1, arr+10000, 1);
            }

            while(!q.empty()){
                temp = q.front();
                arr[temp + score] = 1;
                q.pop();
            }
        }

        temp=0;
        auto itr = find(arr, arr+10000, 1);
        while(itr != end(arr)) {
            temp++;
            itr = find(itr+1, arr+10000, 1);
        }

       cout << "#" << test_case << " " << temp << endl;

    }
    return 0;
}