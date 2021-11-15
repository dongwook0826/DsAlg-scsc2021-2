#include<iostream>
#include<stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    stack<int> st;
    stack<int> temp;
    for(int i=0; i<n; i++){
        int j;
        cin >> j;
        temp.push(j);
    }
    for(int i=0; i<n; i++){
        st.push(temp.top());
        temp.pop();
    }

    while(n){
        int curVal = st.top();
        st.pop();

        int stCount = 1;
        while(1){
            int nextVal = st.top();
            if(stCount == n){
                cout << '-1 ';
                n--;

                for(int i=0; i<n; i++){
                    st.push(temp.top());
                    temp.pop();
                }
            }
            else if(curVal < nextVal){
                
                while(stCount--){
                    cout << nextVal << " ";
                    n--;
                }
                while(!temp.empty()) temp.pop();
            }
            else{
                stCount++;
                temp.push(st.top());
                st.pop();
            }
        }
    }

    return 0;
}