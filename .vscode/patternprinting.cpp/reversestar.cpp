//reverse star triangle
#include<iostream>
using namespace std;
// int main(){
//     int n;
//     cout<<"enter a number : ";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=n;j>=i;j--){    //j=4 ;that will check 4>=1,3>=1,2>=1;1>=1 ;because j-- 
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }

//or one more way to solve
int main(){
    int n;
    cout<<"enter a number : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1-i;j++){     //n+1-i = 6+1-1 than next line 6+1-2 than next line 6+1-3,6+1-4,6+1-5,6+1-6
            cout<<"*";
        }
        cout<<endl;
    }
}