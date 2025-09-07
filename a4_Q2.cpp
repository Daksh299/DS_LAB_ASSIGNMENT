#include <iostream>
using namespace std;

#define SIZE 5   //maximum size of circular queue

int cq[SIZE];
int front = -1, rear = -1;


bool isEmpty() {
    return (front == -1);
}


bool isFull() {
    return ((rear + 1) % SIZE == front);
}


void enqueue(int x) {
    if (isFull()) {
        cout << "Queue is FULL! Cannot enqueue " << x << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    cq[rear] = x;
    cout << x << " enqueued successfully." << endl;
}


void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Cannot dequeue." << endl;
        return;
    }
    cout << cq[front] << " dequeued successfully." << endl;

    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % SIZE;
    }
}


void peek() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
    } else {
        cout << "Front element: " << cq[front] << endl;
    }
}


void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << cq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    peek();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);  //show FULL
    display();

    peek();
    dequeue();
    dequeue();
    display();

    return 0;
}