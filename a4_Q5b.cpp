#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int x) {
    int size = q.size();
    q.push(x);

    // Rotate all old elements behind new one
    for (int i = 0; i < size; i++) {
        q.push(q.front());
        q.pop();
    }
}

void pop() {
    if (q.empty()) {
        cout << "Stack is empty\n";
        return;
    }
    q.pop();
}

int top() {
    if (q.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return q.front();
}

void display() {
    if (q.empty()) {
        cout << "Stack is empty\n";
        return;
    }
    queue<int> temp = q;
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