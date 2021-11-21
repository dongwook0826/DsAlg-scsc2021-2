#include <iostream>

using namespace std;

void quick(int*, int, int);

int main(void){
    int n;
    cin >> n;
    
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    quick(arr, 0,n);
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}

void quick(int *data, int start, int end){
    if(start>=end){
        return ;
    }
    int pivot=start;
    int i=pivot+1;
    int j=end;
    int temp;
    
    while(i<=j){
        while(i<=end&&data[i]<=data[pivot]){
            i++;
        }
        while(j>start&&data[j]>=data[pivot]){
            j--;
        }
        if(i>j){
            temp=data[j];
            data[j]=data[pivot];
            data[pivot]=temp;
        }
        else{
            temp=data[i];
            data[i]=data[j];
            data[j]=temp;
        }
    }
    quick(data,start,j-1);
    quick(data, j+1, end);
}
