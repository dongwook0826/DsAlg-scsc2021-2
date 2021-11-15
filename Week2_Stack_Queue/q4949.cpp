#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while (1)
    {
        string sentence;
        getline(cin, sentence);

        if (sentence == ".")
            return 0;

        stack<char> box;

        for (char ch : sentence)
        {
            if (ch == '.') {
                if (!box.empty())
                    cout << "no" << '\n';
                else
                    cout << "yes" << '\n';
                break;
            }

            if (ch == '(' || ch == '[') {
                box.push(ch);
            }
            else if (ch == ')') {
                if (box.empty() || box.top() == '[') {
                    cout << "no" << '\n';
                    break;
                }
                else
                    box.pop();
            }
            else if (ch == ']') {
                if (box.empty() || box.top() == '(') {
                    cout << "no" << '\n';
                    break;
                }
                else
                    box.pop();
            }
        }
    }
}
