#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements, cannot interleave!" << endl;
        return;
    }

    queue<int> firstHalf;
    int half = n / 2;

    
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original Queue: ";
    display(q);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    display(q);

    return 0;
}