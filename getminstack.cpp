#include<iostream>
#include<stack>
using namespace std;

stack<int> mainStack; 
stack<int> minStack; 


void push(int x) {
    mainStack.push(x);

    
    if (minStack.empty() || x <= minStack.top())
        minStack.push(x);
}

void pop() {
    if (mainStack.empty()) {
        
        return;
    }

    int topElement = mainStack.top();
    mainStack.pop();

    if (!minStack.empty() && topElement == minStack.top())
        minStack.pop();
}


int peek() {
    if (mainStack.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return mainStack.top();
}


int getMin() {
    if (minStack.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return minStack.top();
}


bool isEmpty() {
    return mainStack.empty();
}

int main() {
    push(5);
    push(2);
    push(8);
    push(1);

    cout << "Current Min: " << getMin() << endl; 
    pop();
    cout << "Current Min: " << getMin() << endl; 
    cout << "Top Element: " << peek() << endl;   

    return 0;
}