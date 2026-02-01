#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v(5);  // v(5) means size of 5 array is made and by default 0 is store in all
    cout<<v[1]<<endl;  

    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;


    //
    vector<int>vec(5,7);  //initial size=5 and each element has 7 value
    cout<<vec[2]<<endl;
}