#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSatisfaction(vector<int>& satisfaction) {
    int n=satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    vector<int>suffix(n);
    suffix[n-1]=satisfaction[n-1];

    for(int i=n-2;i>=0;i--){
        suffix[i]=satisfaction[i]+suffix[i+1];
    }
    //find idx
    int idx=-1;
    for(int i=0;i<n;i++){
        if(suffix[i]>=0) {
            idx=i;
            break;
        }
    }
    if(idx==-1) return 0;
    //max sum
    int maxsum=0;
    int x=1;
    for(int i=idx;i<n;i++){
        maxsum+=(satisfaction[i]*x);
        x++;
    }
    return maxsum;
}
int main(){
    vector<int> v={-1,-8,0,5,-9};
    cout<<maxSatisfaction(v);
}