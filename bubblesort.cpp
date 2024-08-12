#include<iostream>
using namespace std;
void bubblesort(int arr[],int n){
    for(int i=1;i<n;i++){
        bool swapped=false;
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                    swapped=true;

                }
            if(swapped==false){
                break;
        }
            }
        }

    }
int main(){
    int a[5]={60,40,50,90,100};
    bubblesort(a,5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }

}