#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T, N, k, sum;
    string l;

    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        sum = 0;
        cin >> N;
        k = (N-1)/2;

        for(int i = 0; i < k; i++)
        {
            cin>>l;
            for(int j = k-i; j <= k+i; j++)
            {
               sum += l[j]-48;
            }
        }

        cin >> l;
        for(int j = 0; j < N; j++)
        {
            sum += l[j]-48;
        }

        for(int i = k-1; i >= 0; i--)
        {
            cin>>l;
            for(int j = k-i; j <= k+i; j++)
            {
                sum += l[j]-48;
            }
        }

        cout<<"#"<<test_case<<" "<<sum;

    }
    return 0;
}