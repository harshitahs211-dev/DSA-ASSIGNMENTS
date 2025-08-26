#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements";
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
            cin>>arr[i];
    }

    int x;
    cout<<"Enter the number to be checked";
    cin>>x;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=j; k<n; k++){
                        if(x==arr[i]) k++;
        }
    }
}

for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}

return 0;}