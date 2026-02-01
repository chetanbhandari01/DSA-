#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    int n;
    cout<<"enter a size : ";
    cin>>n;
    for(int i=0;i<=n-1;i++){
        int q;
        cin>>q;
        v.push_back(q);
    }

    //reverse order with given part
    int startrev;
    int endrev;
    cout<<"enter start reverse part of array : ";
    cin>>startrev;
    cout<<"enter end part of array : ";
    cin>>endrev;
    for(int i=startrev,j=endrev;i<=j;i++,j--){   //i is not greater than j
        //swap i and j
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
    }
    for(int i=0;i<=n-1;i++){
        cout<<v[i]<<" ";
    }
}