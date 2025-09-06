#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str = "DataStructure";
    stack<char> st;

    
    for (char ch : str) {
        st.push(ch);
    }

    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }

    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reversed << endl;

    return 0;
}