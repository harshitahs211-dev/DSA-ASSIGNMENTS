#include <iostream>
using namespace std;

void lowerTriangularMatrix(int arr[][100], int n){

       for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            if(i==j || i>j){

                cout<<arr[i][j]<<" ";

            }
            else {

                cout<<"0 ";
            }

            
        }

        cout<<endl;
       }

}

int main(){
    
    int n;
    cout<<"Enter the number of elements in a row and column"<<endl;
    cin>>n;

    int arr[100][100]={};

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            
        }
    }

    lowerTriangularMatrix(arr,n);
}