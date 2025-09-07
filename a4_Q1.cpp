#include <iostream>
using namespace std;

#define SIZE 5

int q[SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == SIZE - 1) {
        cout << "Queue is Full!\n";
    } else {
        if (front == -1) front = 0;
        q[++rear] = x;
        cout << x << " inserted.\n";
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty!\n";
    } else {
        cout << q[front] << " removed.\n";
        front++;
    }
}

void isEmpty() {
    if (front == -1 || front > rear)
        cout << "Queue is Empty.\n";
    else
        cout << "Queue is NOT Empty.\n";
}

void isFull() {
    if (rear == SIZE - 1)
        cout << "Queue is Full.\n";
    else
        cout << "Queue is NOT Full.\n";
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty!\n";
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << q[i] << " ";
        cout << "\n";
    }
}

void peek() {
    if (front == -1 || front > rear)
        cout << "Queue is Empty!\n";
    else
        cout << "Front element: " << q[front] << "\n";
}

int main() {
    int choice, val;
    while (1) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                isFull();
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}