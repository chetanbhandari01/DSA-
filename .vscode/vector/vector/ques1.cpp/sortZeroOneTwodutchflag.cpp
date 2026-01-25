#include<iostream>
#include<vector>
using namespace std;
//method no.1 this method solve in online exam 
//method no.2 solve in interview one pass solution

// void sort012(vector<int>&v){    //method no.1
//     int zero0=0;
//     int one1=0;
//     int two2=0;
//     int n=v.size();
//     for(int i=0;i<n;i++){   //count
//         if(v[i]==zero0) zero0++;
//         else if(v[i]==one1) one1++;
//         else two2++;
//     }
//     //fill
//     for(int i=0;i<n;i++){
//         if(i<zero0) v[i]=0;
//         else if(i<(zero0+one1)) v[i]=1;
//         else v[i]=2;
//     }
// }

void sort012(vector<int>&v){  //method 2 is dutch flag very important
    int n=v.size();
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(v[mid]==2){
            int temp=v[mid];
            v[mid]=v[high];
            v[high]=temp;
            high--;
        }
        else if(v[mid]==0){
            int temp=v[mid];
            v[mid]=v[low];
            v[low]=temp;
            mid++;
            low++;
        }
        else if(v[mid]==1){
            mid++;
        }
    }
}
int main(){
    vector<int>v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    sort012(v);
    for(int i=0;i<=v.size()-1;i++){
        cout<<v[i]<<" ";
    }
}