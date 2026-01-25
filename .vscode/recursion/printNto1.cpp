#include<iostream>
using namespace std;
// void print(int n){
//     if(n==0) return ;
//     cout<<n<<endl;
//     return print(n-1);
// }
// int main(){
//     int n=10;
//     print(n);
// }


// // 1 to n   use extra variable
// void print(int i,int n){
//     if(i>n) return ;
//     cout<<i<<endl;
//     print(i+1,n);
    
// }
// int main(){
//     int n=10;
//     print(1,n);
// }


//1 to n
void print(int n){
    if(n==0) return ;
    print(n-1);
    cout<<n<<endl;
    
}
int main(){
    int n=10;
    print(n);
}