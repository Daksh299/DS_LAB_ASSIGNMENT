#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int x) {
    // Step 1: push new element into q2
    q2.push(x);

    // Step 2: move all elements from q1 to q2
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }

    // Step 3: swap q1 and q2
    swap(q1, q2);
}

void pop() {
    if (q1.empty()) {
        cout << "Stack is empty\n";
        return;
    }
    q1.pop();
}

int top() {
    if (q1.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return q1.front();
}

void display() {
    if (q1.empty()) {
        cout << "Stack is empty\n";
        return;
    }
    queue<int> temp = q1;
    cout << "Stack (top to bottom): ";
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    display();                 // 30 20 10
    cout << "Top = " << top() << endl;  // 30
    pop();
    display();                 // 20 10

    return 0;
}