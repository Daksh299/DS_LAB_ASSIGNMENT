#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Task {
    string name;
    int priority;

    bool operator>(const Task& other) const {
        return this->priority > other.priority;
    }
};

int main() {
    
    priority_queue<Task, vector<Task>, greater<Task>> pq;

    pq.push({"Task A", 3});
    pq.push({"Task B", 1});
    pq.push({"Task C", 2});

    cout << "Processing tasks by priority:\n";
    while (!pq.empty()) {
        cout << pq.top().name << " (priority " << pq.top().priority << ")\n";
        pq.pop();
    }

    return 0;
}