//binary triangle
#include<iostream>
using namespace std;
// int main(){
//     int n;
//     cout<<"enter number : ";
//     cin>>n;
//     int x=1;
//     for(int i=1;i<=n;i++){
//         if(i%2==0){
//             x=0;       //even row star from 0
//         }
//         else{           //odd row start from 1
//             x=1;
//         }
//         for(int j=1;j<=i;j++){
//             cout<<x;
//             //flipping
//             if(x==1) x=0;
//             else x=1;
//         }
//         cout<<endl;
//     }
// }


//mathamatically way 
int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if((i+j)%2==0){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        cout<<endl;
    }
}