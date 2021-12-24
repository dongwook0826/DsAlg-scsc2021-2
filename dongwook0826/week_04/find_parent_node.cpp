#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

// Problem 11725

int main() {
    cin.sync_with_stdio();
    cin.tie(0);
    int N;
    cin >> N;

    set<int> tree[N+1];
    for (int i = 1, n1, n2; i < N; i++) {
        cin >> n1 >> n2;
        tree[n1].insert(n2);
        tree[n2].insert(n1);
    }

    int parent[N+1];
    queue<int> tree_bfs;
    tree_bfs.push(1);
    while (!tree_bfs.empty()) {
        int& fn = tree_bfs.front();
        set<int> &fn_child = tree[fn];
        for_each(fn_child.begin(), fn_child.end(),
                 [&parent, &tree_bfs, &tree, fn]
                 (int cn) {
                     parent[cn] = fn;
                     tree_bfs.push(cn);
                     tree[cn].erase(fn);
                 });
        tree_bfs.pop();
    }

    for (int n = 2; n <= N; n++) {
        cout << parent[n] << '\n';
    }
}
