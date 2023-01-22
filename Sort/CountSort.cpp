#include<iostream>
using namespace std;
void CountSort(int array[], int size) {
    int output[1000];
    int count[1000];
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max){
            max=array[i];
        }
    }
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}
int main(){
    int a[]={1,6,4,2,6,7,1,18,7,5,6};
    CountSort(a,10);
    for(int i=0;i<10;i++){
        cout <<a[i]<<" ";
    }
    cout<<endl;
}
