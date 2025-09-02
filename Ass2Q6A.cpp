#include <iostream>
using namespace std;

void createTriplet(int arr[100][100], int rows, int columns, int triplet[][3]){
    int k=1;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(arr[i][j] != 0){
                 triplet[k][0]=i;
                 triplet[k][1]=j;
                 triplet[k][2]=arr[i][j];
                 k++;
            }
        }
    }
    triplet[0][0]=rows;
    triplet[0][1]=columns;
    triplet[0][2]=k-1;

    cout << "Triplet Representation"<<endl;
    cout << "Row Col Val"<<endl;
    for (int i = 0; i < k; i++) {
        cout << " " << triplet[i][0]
             << "   " << triplet[i][1]
             << "   " << triplet[i][2] << endl;
    }
}

void createTranspose(int triplet[][3], int final[][3]){
    int rows = triplet[0][0];
    int columns = triplet[0][1];
    int nonZero = triplet[0][2];

    final[0][0] = columns;
    final[0][1] = rows;
    final[0][2] = nonZero;

    for(int i=1; i<=nonZero; i++){
        final[i][0] = triplet[i][1];
        final[i][1] = triplet[i][0];
        final[i][2] = triplet[i][2];
    }
    
    cout<<"The Transpose Is"<<endl;
    cout<<"Row Col Value"<<endl;
    
}

int main(){
    
    int triplet[3][3];
    int rows;
    int final [3][3];
    cout<<"Enter number of rows";
    cin>>rows;

    int columns;
    cout<<"Enter number of columns";
    cin>>columns;
     int arr[100][100];

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout<<"Enter matrix elements";
            cin>>arr[i][j];
        }
    }

    createTriplet(arr, rows, columns, triplet);
    createTranspose(triplet, final);
}