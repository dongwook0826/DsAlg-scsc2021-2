#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    char sol[1000000];
    int solptr(0);
    int n,x,max(0);
    stack<int> s;
    cin >> n;
    
    while(n--){
        cin >> x;
        if(x>max){
            for(int i=max+1;i<=x;i++){
                s.push(i);
                sol[solptr++]='+';
            }
        }
        else{
            if(s.top()!=x){
                cout<<"No!";
                return 0;
            }
        }
        s.pop();
        sol[solptr++]='-';
        if (max<x) max=x;
    }
    for(int i=0;i<solptr;i++) cout<<sol[i]<<endl;
    return 0;
}
