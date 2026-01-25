#include<iostream>
#include<vector>
using namespace std;
// //using while loop function to reverse
// void reverse(vector<int>&v){
//     int i=0;
//     int j=v.size()-1;
//     while(i<j){
//         int temp=v[i];
//         v[i]=v[j];
//         v[j]=temp;
//         i++;
//         j--;
//     }
// }

int main(){
    vector<int>v;
    int n;
    cout<<"enter a number : ";
    cin>>n;
    for(int i=0;i<=n-1;i++){
        int q;
        cin>>q;
        v.push_back(q);
    }

    //reverse order without variable
    for(int i=0,j=v.size()-1;i<=j;i++,j--){   //i is not greater than j
        //swap i and j
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
    }
    // reverse(v);
    for(int i=0;i<=n-1;i++){
        cout<<v[i]<<" ";
    }

    
}
