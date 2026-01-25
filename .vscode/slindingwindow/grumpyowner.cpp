//1052 grumpy bookstore owner
#include<iostream>
#include<vector>
using namespace std;
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n=customers.size();
    int k=minutes;
    int prevloss=0;
    int maxloss=0;
    int maxidx=-1;
    for(int i=0;i<k;i++){
        if(grumpy[i]==1) prevloss+=customers[i];
    }
    maxloss=prevloss;
    maxidx=0;
    int i=1;
    int j=k;
    while(j<n){
        int currentloss=prevloss;
        if(grumpy[j]==1) currentloss +=customers[j] ;
        if(grumpy[i-1]==1) currentloss -=customers[i-1];
        if(maxloss<=currentloss){
            maxloss=currentloss;
            maxidx=i;
        }
        prevloss=currentloss;
        i++;
        j++;
    }
    //filling zero in grumpy arr
    for(int i=maxidx;i<maxidx+k;i++){
        grumpy[i]=0;
    }
    //sum of satisfy
    int satisfy=0;
    for(int i=0;i<n;i++){
        if(grumpy[i]==0){
            satisfy +=customers[i];
        }
    }
    return satisfy;

}
int main(){
    vector<int >c={1,0,1,2,1,1,7,5};
    vector<int> g={0,1,0,1,0,1,0,1};
    int min=3;
    cout<<maxSatisfied(c,g,min);
}