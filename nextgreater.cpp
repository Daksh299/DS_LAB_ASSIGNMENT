#include <iostream>
#include <stack>
using namespace std;

void nextGreaterElements(int arr[], int n)
{
    int result[n];
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        if (st.empty())
            result[i] = -1;
        else
            result[i] = st.top();

        st.push(arr[i]);
    }

    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterElements(arr, n);
    return 0;
}