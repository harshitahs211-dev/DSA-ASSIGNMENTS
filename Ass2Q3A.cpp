#include <iostream>
using namespace std;

int findMissingNumber(int n, int arr[]){
    int x = 1;
   
    for(int i=0; i<=n-1; i++){
        if(arr[i] == x) x++;
        else{
            return x;
        }
    } return n;
}

int main(){
    int n=5;
    int arr[n]= {1,2,4,5};
    cout<<"Missing number is "<<findMissingNumber(n,arr);
    return 0;
}