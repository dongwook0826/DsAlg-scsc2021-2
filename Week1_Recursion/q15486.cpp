#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define MAX_LENGTH 1500001

int n;
int t[MAX_LENGTH];
int p[MAX_LENGTH];

int memo[MAX_LENGTH];

int optimal(int curT){
    if(curT >= n)
        return 0;

    if(memo[curT] != -1)
        return memo[curT];

    int profit_do, profit_skip;
    if (curT + t[curT] - 1 >= n)
        profit_do = 0;
    else
        profit_do = p[curT] + optimal(curT + t[curT]);
    
    if (curT + 1 >= n)  
        profit_skip = 0;
    else
        profit_skip = optimal(curT + 1);

    memo[curT] = max(profit_do, profit_skip);
    
    return memo[curT];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fill_n(memo, MAX_LENGTH, -1);
    cin >> n;
    for(int k=0; k<n; k++)  cin >> t[k] >> p[k];

    cout << optimal(0);
    
    return 0;
}