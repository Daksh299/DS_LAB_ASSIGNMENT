#include<iostream>
using namespace std;    
void tranpose (int (&arr)[3][3],int m)
{int temp;
    for(int i=0;i<m;i++){
    for(int j=0;j<=i;j++){
        temp=arr[i][j];
        arr[i][j]=arr[j][i];
        arr[j][i]=temp;
    }
}


}
int main() 
{ 
   int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
   tranpose(arr,3);

   for (int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout<<arr[i][j]<<"     ";
    }cout<<endl;
   }
}
