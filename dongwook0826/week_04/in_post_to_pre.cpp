#include <iostream>
using namespace std;

// Problem 2263

void in_post_to_pre(int*, int, int, int*, int, int, int);

int main() {
    cin.sync_with_stdio();
    cin.tie(0);
    int N;
    cin >> N;
    int inorder[N], postorder[N];
    for (int i = 0; i < N; i++)
        cin >> inorder[i];
    for (int i = 0; i < N; i++)
        cin >> postorder[i];

    in_post_to_pre(inorder, 0, N, postorder, 0, N, 0);
}

void in_post_to_pre(int *inorder, int ibegin, int iend,
                    int *postorder, int pbegin, int pend,
                    int depth) {
    if (ibegin >= iend) return;
    int root = postorder[pend - 1];
    int iroot = -1;
    for (int i = ibegin; i < iend; i++) {
        if (inorder[i] == root) {
            iroot = i;
            break;
        }
    }
    cout << (depth == 0 ? "" : " ") << root;
    int proot = pbegin + iroot - ibegin;
    in_post_to_pre(inorder, ibegin, iroot,
                   postorder, pbegin, proot, depth + 1);
    in_post_to_pre(inorder, iroot + 1, iend,
                   postorder, proot, pend - 1, depth + 1);
}
