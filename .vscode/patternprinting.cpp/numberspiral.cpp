#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number  : ";
    cin>>n;
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            int a=i;
            int b=j;
            if(a>n){
                a=2*n-i;      //between two number min is printing than 5,6,7 number are convert into 3,2,1
            }
            if(b>n){
                b=2*n-j;
            }
            cout<<min(a,b);    //min between (1,2) is 1 so 1 is printing
        }
        cout<<endl;
    }
    
}



// //half triangle 
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"enter a number  : ";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(i<=j){
//                 cout<<i;
//             }
//             else if (i>=j){
//                 cout<<j;
//             }
//             else{
//                 cout<<1;
//             }
//         }
//         cout<<endl;
//     }
// }