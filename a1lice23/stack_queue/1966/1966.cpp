#include <cstdio>
#include <queue>

using namespace std;

pair<int, int> p;

int main(){
	
    int t; scanf("%d", &t);
    
    while(t--){
           int n, m;
    int ans = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        int tmp; scanf("%d", &tmp);
        q.push(make_pair(tmp, i));
        pq.push(tmp);
    }
    while(!q.empty()){ 
        pair<int,int> poped = q.front();
        q.pop();
        if(pq.top() == poped.first){
            ans++;
            pq.pop();
            if(poped.second == m) break;
        }else q.push(poped);
    }
    printf("%d\n", ans);
    }
}