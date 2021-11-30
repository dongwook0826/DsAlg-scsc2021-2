#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    int s = 1, e = k, res;
    while(s <= e){
        int cnt = 0;
        int pivot = (s + e) / 2;
        for(int i = 1; i <= n; i++)
            cnt += min(pivot/i, n);
        if(cnt < k)
            s = pivot + 1;
        else{
            res = pivot;
            e = pivot - 1;
        }
    }
    cout << res;
    return 0;
}