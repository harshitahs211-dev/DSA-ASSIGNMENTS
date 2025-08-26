// BINARY SEARCH
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements";
    cin>>n;

    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int x;
    cout<<"Enter the element to be searched";
    cin>>x;

    int start=0;
    int end=n-1;
    int mid;
    bool flag = false;

    while(start<=end){
        
     mid= (start+end)/2;
        if(arr[mid]>x) end=mid-1;
         else if(arr[mid]<x) start=mid+1;
         else{ 
                if (arr[mid]==x){
                    flag = true;
                    cout<<"Elements found- and the index is"<<mid<<endl;
                break;
         } 

        }}
        
    if(flag==false) cout<<"Element does not exist";
    
    return 0;
}