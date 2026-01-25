// //
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"enter number : ";
//     cin>>n;
//     //2n-1 star in first line
//     for(int i=1;i<=2*n-1;i++){
//         cout<<"*";
//     }
//     cout<<endl;
//     int m=n-1;
//     int nst=1;
//     for(int i=1;i<=m;i++){
//         //stars
//         for(int j=1;j<=m+1-i;j++){
//             cout<<"*";
//         }
//         //space
//         for(int b=1;b<=nst;b++){
//             cout<<" ";
//         }
//         nst+=2;
//         for(int j=1;j<=m+1-i;j++){
//             cout<<"*";
//         }

        
//         cout<<endl;
//     }
// }



//number bridge
//
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
    //2n-1 star in first line
    for(int i=1;i<=2*n-1;i++){
        cout<<i;
    }
    cout<<endl;
    int m=n-1;
    int nst=1;
    for(int i=1;i<=m;i++){
        //stars
        int a=1;
        for(int j=1;j<=m+1-i;j++){
            cout<<a;
            a++;
        }
        //space
        for(int b=1;b<=nst;b++){
            cout<<" ";
            a++;
        }
        nst+=2;
        for(int j=1;j<=m+1-i;j++){
            cout<<a;
            a++;
        }

        
        cout<<endl;
    }
}