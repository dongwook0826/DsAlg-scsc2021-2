#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int optimal(string key){
    if(key.size() == 1)
        return 1;
    
    if(key.size() == 2 && stoi(key.substr(0, 2)) <= 26)
        return 1;

    if(stoi(key.substr(0, 2)) < 26)
        return optimal(key.erase(0,2)) + optimal(key.erase(0,1)); 
    else
        return optimal(key.erase(0,1));
}

int main(void)
{   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string key;
    cin >> key;

    cout << optimal(key);

    return 0;
}