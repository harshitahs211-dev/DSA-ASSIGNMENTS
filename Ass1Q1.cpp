#include <iostream>
using namespace std;
int main() {
   int x;
   char f;
   int a;
   int arr[100];
   bool k=false;
   cout<<"1.Create \n2.Display \n3.Insert\n4.Delete\n5.Linear Search\n6.exit\n";
  do{ cout<<"Enter the number as per the operation you need to perform: ";
   cin>>x;
   switch(x){
       case 1:{
       cout<<"Enter size of array: ";
       cin>>a;
       cout<<"Enter array elements: ";
       for(int i=0;i<a;i++){
           cin>>arr[i];
       }
       cout<<"Array created";
       k=true;
   
   break;
       }
   case 2:{
   if(!k){
       cout<<"create array first";
       break;
   }
   
   for(int i=0;i<a;i++){
       cout<<arr[i]<<" ";
   }
   break;}
   case 3:{
    if(!k){
       cout<<"create array first";
       break;
   }
   int b,c;
   cout<<"Enter the element to be inserted: ";
   cin>>b;
   cout<<"Enter the position at which element needs to be inserted: ";
   cin>>c;
   for(int i=a-1;i>=c-1;i--){
       arr[i+1]=arr[i];
   }
   arr[c-1]=b;
   
   for(int i=0;i<=a;i++){
       cout<<arr[i]<<" ";
   }
   a++;
   break;}
   case 4:{
    if(!k){
       cout<<"create array first";
       break;
   }
   int d;
   cout<<"Enter the position to be deleted: ";
   cin>>d;
   for(int i=d-1;i<a-1;i++){
       arr[i]=arr[i+1];
   }
   a--;
   for(int i=0;i<a;i++){
       cout<<arr[i]<<" ";
   }
   break;}
   case 5:{
    if(!k){
       cout<<"create array first";
       break;
   }
   int s;
   cout<<"Enter the element to be searched:";
   cin>>s;
   int z=0;
   for(int i=0;i<a;i++){
       
       if(arr[i]==s){
           cout<<"found at index"<<i;
           z=1;
           break;
           
       }
       else{
           z=0;
       }
      
   }
   if(z==0){
       cout<<"Not found";
   }
   break;}
   case 6:{
   cout<<"Program exited";
   break;}
   default:
   cout<<"invalid operartor";
  }
  cout<<"\nDo you want to continue(y/n): ";
  cin>>f;
}while(f=='y');

    return 0;
}
