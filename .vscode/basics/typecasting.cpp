//take an integer from user and print half of the number
#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"enter number : ";
    cin>>x;
    float y;
    y=(float)x/2;
    cout<<y<<endl;

    //take float input and print the fractional part of the number
    float a=-1.4;
    int b=(int)a;
    if(a<0){
        b=b-1;
    }
    float result = a-b;
    cout<<result;
}