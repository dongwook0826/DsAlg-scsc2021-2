#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

void hanoi(int n, int curPlace, int targetPlace){
    if(n == 1){
        cout << curPlace << ' ' << targetPlace << '\n';
        return;
    }

    int remainPlace = 6 - curPlace - targetPlace;
    
    hanoi(n-1, curPlace, remainPlace);
    cout << curPlace << ' ' << targetPlace << '\n';
    hanoi(n-1, remainPlace, targetPlace);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    cout << (long long)(pow(2, n) - 1) << '\n';
    hanoi(n, 1, 3);

    return 0;
}