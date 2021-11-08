#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void makeblank(int n){
    for(int i=0; i<n; i++)
        cout << " ";
}

int star(int n, int l, bool enter){
    if(n == l)
        return 0;

    // n = 3, 재귀함수 Child 위치 처리
    if(n == 3){
        if(l == 1){
            cout << "* *"; return 0;
        }
        else{ // l == 1, l == 3
            cout << "***"; return 0;
        }
    }

    int prev_n = n / 3;
    int prev_l = l % prev_n;
 
    star(prev_n, prev_l, false);
    
    if(prev_n <= l && prev_n * 2 > l){
        makeblank(prev_n);
    } else{
        star(prev_n, prev_l, false);
    }

    star(prev_n, prev_l, false);

    if(enter == true)
        cout << '\n';
    
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    
    if(n == 3)
        cout << "***" << '\n' << "* *" << '\n' << "***";
    else{
        for(int l=0; l < n; l++)
            star(n, l, true);
            cout << '\n';
    }

    return 0;
}
