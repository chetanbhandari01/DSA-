#include<iostream>
using namespace std;
void printing(int x){
    if(x==0) return ;
    cout<<"good morning"<<endl;
    printing(x-1);
}
int main(){
    printing(5);   
    
}
//firstly checking 5==0 no than print it,4,3,2,1 and when equal to zero than return 