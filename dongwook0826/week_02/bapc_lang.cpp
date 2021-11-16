#include <iostream>
#include <vector>
using namespace std;

// Problem 5430

int main() {
    int CASE_NUM;
    cin >> CASE_NUM;
    for (int cs = 0, len; cs < CASE_NUM; cs++) {
        string command, arr_raw;
        cin >> command >> len >> arr_raw;
        vector<int> arr(len, 0);
        if (len >= 1) {
            for (int i = 0, ci = 1, cj = 1; ci < arr_raw.length(); i++, ci = ++cj) {
                while (arr_raw.at(cj) != ',' && arr_raw.at(cj) != ']')
                    cj++;
                arr[i] = stoi(arr_raw.substr(ci, cj - ci));
            }
        }
        int head = 0, tail = len;
        bool on_head = true, is_error = false;
        for (int i = 0, cnt = 0; i < command.length(); cnt = 0) {
            while (i < command.length() && command.at(i) == 'R') {
                i++; cnt++;
            }
            if (cnt & 1)
                on_head = !on_head;
            cnt = 0;
            while (i < command.length() && command.at(i) == 'D') {
                i++; cnt++;
            }
            if (cnt > tail - head) {
                is_error = true;
                break;
            }
            if (on_head)
                head += cnt;
            else
                tail -= cnt;
        }
        // print in given format
        if (is_error) {
            cout << "error\n";
        } else {
            if (head == tail) {
                cout << "[]\n";
            } else if (on_head) {
                cout << '[' << arr[head++];
                while (head < tail)
                    cout << ',' << arr[head++];
                cout << "]\n";
            } else {
                cout << '[' << arr[--tail];
                while (tail > head)
                    cout << ',' << arr[--tail];
                cout << "]\n";
            }
        }
    }
    return 0;
}
