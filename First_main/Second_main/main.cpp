// 백준 10870
#include <iostream>
using namespace std;
int Fibonacci_rec(int);

int main(int argc, const char * argv[]) {
    int num,result;
    cin >> num;
    result = Fibonacci_rec(num);
    cout << result;
    return 0;
}

int Fibonacci_rec(int n){
    if(n==0){
        return 0;
    }
    else if (n==1){
        return 1;
    }
    else {
        return Fibonacci_rec(n-1)+Fibonacci_rec(n-2);
    }
}
