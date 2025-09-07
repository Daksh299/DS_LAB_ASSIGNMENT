#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int freq[256] = {0}; 

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        
        freq[ch]++;

        
        q.push(ch);

        // Remove all characters from front that are repeating
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        // Print answer
        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string str = "aabc";
    firstNonRepeating(str);
    return 0;
}