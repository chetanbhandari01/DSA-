#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int mincostTobreak(int n,int m,vector<int>&vertical,vector<int>&horizontal){
    sort(vertical.begin(),vertical.end(),cmp);
    sort(horizontal.begin(),horizontal.end(),cmp);
    int hz = 1;
    int vr = 1;
    int h=0 ,v =0;
    int ans=0;
    while(h<horizontal.size() && v<vertical.size()){
        if(vertical[v] >horizontal[h]){
            ans+=vertical[v]*vr;
            hz++;

            v++;
        }
        else{ //horizontal is greater
            ans+=horizontal[h]*hz;
            vr++;

            h++;
        }
    }
    while(h<horizontal.size()){
        ans+=horizontal[h]*hz;
        vr++;

        h++;
    }
    while( v<vertical.size()){
        ans+=vertical[v]*vr;
        hz++;

        v++;
    }
    return ans;
}
int main(){
    int m=6;
    int n=4;
    vector<int>vertical={2,1,3,1,4};
    vector<int>hori={4,1,2};
    cout<<mincostTobreak(n,m,vertical,hori);
}
