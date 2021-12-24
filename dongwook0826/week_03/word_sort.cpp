#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comp_word(const string &, const string &);

// Problem 1181

int main() {
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++)
        cin >> words[i];
    sort(words.begin(), words.end(), comp_word);
    cout << words[0] << '\n';
    for (int i = 1; i < N; i++) {
        if (words[i] == words[i-1]) continue;
        cout << words[i] << '\n';
    }
}

bool comp_word(const string &str1, const string &str2) {
    int sz1 = str1.size(), sz2 = str2.size();
    if (sz1 < sz2) return true;
    if (sz1 == sz2)
        for (int i = 0; i < sz1; i++) {
            if (str1[i] == str2[i]) continue;
            return str1[i] < str2[i];
        }
    return false;
}
