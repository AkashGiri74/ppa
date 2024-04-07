#include <iostream>
using namespace std;
class QuickSort{
    private:
    int partition(int arr[],int low,int high){
        int i=low-1;
        int pivot=arr[high];
        for(int j=low;j<high;j++){
            if(pivot > arr[j]){
                i++;
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            } 
        }
        i++;
        int temp=arr[i];
        arr[i]=arr[high];
        arr[high]=temp;
        return i;
    }

    public:
    void quickSort(int arr[], int low,int high){


        if(low<high){
            int pIndex=partition(arr,low,high);
            quickSort(arr , low, pIndex-1);
            quickSort(arr, pIndex+1,high);
        }
        
    }


    void display(int arr[],int size)
    {
        for(int i=0;i<size;i++){
            cout<<arr[i]<<"\t";
        }
    }
};

int main(){
    int arr[]={3,1,5,2,6};
    QuickSort qs;
    qs.quickSort(arr,0,4);
    qs.display(arr,5);
    return 0;
}