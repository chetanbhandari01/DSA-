//number triangle flipped
#include<iostream>
using namespace std;
// int main(){
//     int n;
//     cout<<"enter number : ";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int k=1;k<=n-i;k++){
//             cout<<" ";
//         }
//         for(int j=1;j<=i;j++){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }


//second way with mathmatically 
int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i+j)>=n+1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}