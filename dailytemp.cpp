#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temperatures[n];
    int answer[n];

    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
        answer[i] = 0; // initialize with 0
    }

    stack<int> st; // stack of indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prev = st.top();
            st.pop();
            answer[prev] = i - prev;
        }
        st.push(i);
    }

    cout << "Answer: ";
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}