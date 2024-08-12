#include<iostream>
using namespace std;
void selectionsort(int a[],int n){
    for(int i= 0; i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[minindex]){
                minindex=j;
            }
        }
    swap(a[minindex],a[i]);
    }
}
int main(){
    int a[5]={60,40,50,90,100};
    selectionsort(a,5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
}