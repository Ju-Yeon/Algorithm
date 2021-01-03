#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, Q;
vector <pair<int, int>> v[5001];

int bfs(int k, int n){
    int result = 0;
    vector<bool> check(5001, false);
    queue<int> q;

    q.push(n);
    check[n] = true;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int i = 0; i < v[current].size(); i++){
            int next = v[current][i].first;
            int value = v[current][i].second;

            if(!check[next] && k <= value){
                check[next] = true;
                q.push(next);
                result++;
            }
        }
    }
    return result;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;

    int p,q,r,k,n;
    for(int i = 0; i < N-1; i++){
        cin>>p>>q>>r;
        v[p].push_back({q,r});
        v[q].push_back({p,r});

    }
    for(int i = 0; i < Q; i++){
        cin>>k>>n;
        cout<<bfs(k, n)<<endl;
    }
    return 0;
    
}