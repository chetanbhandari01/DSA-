#include<iostream>
#include<vector>
using namespace std;
int longestOnes(vector<int>& nums, int k) {
    int n=nums.size();
    int flip=0,i=0,j=0;
    int maxlen=INT_MIN ,len=INT_MIN;
    while(j<n){
        if(nums[j]==1) j++;
        else{  //nums[j]==0
            if(flip<k){
                flip++;
                j++;
            }
            else{  //flip==k
                len=j-i;
                maxlen=max(maxlen,len);
                //i ko just uske aage wale 0 se ek aage le jaao
                while(nums[i]==1) i++;
                i++;
                j++;
            }
        }
    }
    len=j-i;    //this for when j is outof loop than last group karo 
    maxlen=max(maxlen,len);
    return maxlen;
}
int main(){
    vector<int >v={1,0,1,1,1,0,0,1,1,1,0};
    int k=1;
    cout<<longestOnes(v,k);
}