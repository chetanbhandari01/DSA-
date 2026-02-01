//longest subarray of 1`s after deleting one element 
//leetcode =1493
//same code like max consecutive ones leetcode 1004
#include<iostream>
#include<vector>
using namespace std;
int longestSubarray(vector<int>& nums) {
    int n=nums.size();
    int k=1;
    int flip=0,i=0,j=0;
    int maxlen=INT_MIN,len=INT_MIN;
    while(j<n){
        if(nums[j]==1) j++;
        else {   //nums[j]==0
            if(flip<k) {
                flip++;
                j++;
            }
            else {  //flip==k
                len=j-i;
                maxlen=max(maxlen,len);
                //i ko just uske aage wale 0 se ek aage le jaao
                while(nums[i]==1) i++;
                i++;
                j++;
            }
        }
    }
    len=j-i;
    maxlen=max(maxlen,len);
    return maxlen-1;  //we are filp it actual we want to delete it than -1
}
int main(){
    vector<int >v={1,0,1,1,1,0,0,1,1,1,0};
    cout<<longestSubarray(v);
}