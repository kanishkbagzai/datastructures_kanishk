#include<iostream>
using namespace std;
void insertionsort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int temp=a[i];
        for(; j>=0;j--){
            if(a[j]>temp){
                a[j+1]=a[j];

            }
            else{
                break;
            }
        }
    a[j+1]=temp;
    }

}



int main(){
    int a[5]={60,40,50,90,100};
    insertionsort(a,5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
}