#include <iostream>
using namespace std;

int main() {

int target;
cout <<"enter the target:";
cin >>target;
int arr[7];
for(int i=0 ;i<7;i++){


    cin>>arr[i];}
    for(int i=0 ;i<7;i++){
    for (int j=i+1;j<7;j++){
       if (arr[i]+arr[j]==target) {
        cout<<arr[i]<<" + "<<arr[j]<<"="<<target<<endl;}
       }
    }







}








































