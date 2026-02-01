// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"enter number : ";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int k=1;k<=n-i;k++){
//             cout<<" ";
//         }
//         for(int j=1;j<=2*i-1;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

// one more method  this is useful in diamond printing
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
    int nst=1;   //no.of star 
    int nsp=n-1;   //no. of space
    for(int i=1;i<=n;i++){
        for(int k=1;k<=nsp;k++){
            cout<<" ";
        }
        for(int j=1;j<=nst;j++){
            cout<<"*";
        }
        nsp--;
        nst+=2;
        cout<<endl;
    }
}
