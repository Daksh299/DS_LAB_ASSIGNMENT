#include <iostream>
using namespace std;

int main() {
    int m, n, t1, t2;
    cout << "Enter rows, cols and non-zeros of A: ";
    cin >> m >> n >> t1;
    int A[100][3];
    A[0][0]=m; A[0][1]=n; A[0][2]=t1;
    cout << "Enter A (row col val):\n";
    for(int i=1;i<=t1;i++) cin>>A[i][0]>>A[i][1]>>A[i][2];

    cout << "Enter rows, cols and non-zeros of B: ";
    cin >> m >> n >> t2;
    int B[100][3];
    B[0][0]=m; B[0][1]=n; B[0][2]=t2;
    cout << "Enter B (row col val):\n";
    for(int i=1;i<=t2;i++) cin>>B[i][0]>>B[i][1]>>B[i][2];

    int C[100][3];
    C[0][0]=A[0][0]; C[0][1]=A[0][1];
    int i=1,j=1,k=1;

    while(i<=t1 && j<=t2) {
        if(A[i][0]<B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1])) {
            C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]; i++; k++;
        }
        else if(B[j][0]<A[i][0] || (A[i][0]==B[j][0] && B[j][1]<A[i][1])) {
            C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2]; j++; k++;
        }
        else {
            C[k][0]=A[i][0]; C[k][1]=A[i][1];
            C[k][2]=A[i][2]+B[j][2]; i++; j++; k++;
        }
    }
    while(i<=t1) { C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]; i++; k++; }
    while(j<=t2) { C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2]; j++; k++; }

    C[0][2]=k-1;

    cout << "\nA + B (triplet form):\n";
    for(int p=0;p<=C[0][2];p++) {
        cout<<C[p][0]<<" "<<C[p][1]<<" "<<C[p][2]<<endl;
    }
    return 0;
}