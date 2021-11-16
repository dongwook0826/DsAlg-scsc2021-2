#include <iostream>
#include <queue>
using namespace std;

// Problem 1966

int main() {
    int N;
    cin >> N;
    for (int cs = 0; cs < N; cs++) {
        queue<int> prtr_q;
        int impo_cnt[10] = {0};
        int max_impo = 9;
        int num, pos;
        cin >> num >> pos;
        int cnt = 0;
        for (int i = 0, impo; i < num; i++) {
            cin >> impo;
            prtr_q.push(impo);
            impo_cnt[impo]++;
        }
        while (max_impo > 0 && impo_cnt[max_impo] == 0)
            max_impo--;
        while (!prtr_q.empty()) {
            if (prtr_q.front() == max_impo) { // poll
                cnt++; num--;
                if (pos == 0) {
                    cout << cnt << '\n';
                    break;
                }
                prtr_q.pop();
                pos--;
                impo_cnt[max_impo]--;
                while (max_impo > 0 && impo_cnt[max_impo] == 0)
                    max_impo--;
            } else { // cycle
                int tmp = prtr_q.front();
                prtr_q.pop();
                prtr_q.push(tmp);
                pos--;
                if (pos < 0)
                    pos += num;
            }
        }
    }
    return 0;
}
