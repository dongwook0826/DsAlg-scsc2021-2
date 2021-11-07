// 백준 11729
#include <iostream>
using namespace std;


void move(int n,int start, int arrive, int spare){
    if(n==1){
        cout << start << " "<< arrive<<endl;
    }
    else{
        move(n-1,start,spare,arrive);
        cout << start << " " << spare<<endl;
        move(n-1,spare,arrive,start);
    }
}

int main(){
    int num;
    cin >> num;
    cout << (1<<num)-1<<endl;
    move(num,1,2,3);
    return 0;
}
