#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to perform operation
int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;  // assumes b != 0
        case '^': {
            int result = 1;
            for(int i = 0; i < b; i++) result *= a;
            return result;
        }
    }
    return 0;
}

int evaluatePostfix(string postfix) {
    stack<int> st;

    for(char ch : postfix) {
        if(isdigit(ch)) {
            st.push(ch - '0');  // convert char to int
        }
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result = applyOp(a, b, ch);
            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression (single-digit operands): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}