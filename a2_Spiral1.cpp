#include<iostream>
using namespace std;
#include<vector>

int main(){
    int m , n;
    vector<int> ans(n*n);
    vector<vector<int>> mat(m , vector<int>(n));
    cout<<"enter m\n";
    cin>>m;
    cout<<"enter n\n";
    cin>>n;
    for(int i=0  ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            cin>>mat[i][j];
        }
    }

    
    
    int srow = 0 ;int scol = 0 ; int erow = m-1 ;int ecol = n-1;
    while(srow<= erow && scol <= ecol){
        for(int j=0 ; j<=ecol ; j++){
            ans.push_back(mat[srow][j]);
        }

        for(int i = srow+1 ; i<=erow ; i++){
            ans.push_back(mat[i][erow]);
        }

        for(int j = ecol-1 ; j>= scol ; j--){
            if(srow == erow){
                break;
            }
            ans.push_back(mat[erow][j]);
        }

        for(int i = erow-1 ; i>=srow+1 ; i--){
            if(scol == ecol){
                break;
            }
            ans.push_back(mat[i][scol]);
        }

        srow++ ; 
        erow--;
        scol++;
        ecol--;
    }
    for(int val : ans){
        cout<<ans[val]<<"\t";
    }
    return 0;

}
