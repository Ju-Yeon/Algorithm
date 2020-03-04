#include <iostream>
#include <queue>
#include <set>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
     
    int score_case;
    int N, size, a, b, c;
    queue <int> score_q;
 
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N;
        queue <int> total_sq;
        set <int> s;
 
        for(score_case = 1; score_case <= N; ++score_case)
        {
            cin >> b;
            score_q.push(b);
        }
 
        while(!score_q.empty())
        {
            b = score_q.front();
            size = total_sq.size();
             
            if(size == 0)
            {
                total_sq.push(0);
                total_sq.push(b);
            }
            else
                {
                for (a = 0; a < size; a++) {
                    c = total_sq.front();
                    total_sq.pop();
                    total_sq.push(c+0);
                    total_sq.push(c+b);
                }
            }
            score_q.pop();
        }
 
       while(!total_sq.empty())
       {
           b = total_sq.front();
           s.insert(b);
           total_sq.pop();
       }
       cout<<"#"<<test_case<<" "<<s.size()<<endl;
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
