#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;
double getmedian(priority_queue<int>&left,priority_queue<int,vector<int>,greater<int>>&right,int x ,int y ){
    int totalsize = x+y;
    if(totalsize %2 !=0){ //odd
        return right.top();
    }
    else { //even
        return (left.top()+right.top())/2.0;
    }
}
bool isbalanced(int x,int y){
    return (x==y)|| (y == x + 1);
}
vector<double>slidling_median(vector<int>&arr ,int n,int k){
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    int x =0,y=0;
    right.push(arr[0]); //index
    y++;
    for(int i=1;i<k;i++){
        int curr = arr[i];
        double med = getmedian(left,right,x,y);
        if(curr < med){ //go left
            left.push(curr);
            x++;
            if(!isbalanced(x,y)){
                int toberemove = left.top();
                left.pop();
                right.push(toberemove);
                x-- ;y++;
            }
        }
        else{ //go right
            right.push(curr);
            y++;
            if(!isbalanced(x,y)){
                int toberemove = right.top();
                right.pop();
                left.push(toberemove);
                x++; y--;
            }
        }
    }
    double m = getmedian(left,right,x,y);  //first element median
    vector<double>result;
    result.push_back(m);
    unordered_map<int,int>mp;
    for(int i=k;i<n;i++){
        int newElementindex = i;
        int oldelementtodeleted = i-k;
        double med = getmedian(left,right,x,y);
        if(arr[newElementindex] >=med){
            //go right
            right.push(arr[newElementindex]);
            y++;
            if(!isbalanced(x,y)){
                int toberemove = right.top();
                right.pop();
                left.push(toberemove);
                x++; y--;
            }
        }
        else {
            //go left
            left.push(arr[newElementindex]);
            x++;
            if(!isbalanced(x,y)){
                int toberemove = left.top();
                left.pop();
                right.push(toberemove);
                x-- ;y++;
            }
        }
        mp[arr[oldelementtodeleted]]++;
        while (!left.empty() && mp[left.top()] > 0) {
            mp[left.top()]--;
            if (mp[left.top()] == 0) mp.erase(left.top());
            left.pop();
            x--;
        }

        while (!right.empty() && mp[right.top()] > 0) {
            mp[right.top()]--;
            if (mp[right.top()] == 0) mp.erase(right.top());
            right.pop();
            y--;
        }
        while (!isbalanced(x, y)) {
            if (x > y) {
                right.push(left.top());
                left.pop();
                x--; y++;
            } else {
                left.push(right.top());
                right.pop();
                x++; y--;
            }
        }
        result.push_back(getmedian(left,right,x,y));
    }
    return result;
}
int main(){
    vector<int>arr = {1,3,-1,-3,5,3,6,7};
    vector<double> result =slidling_median(arr,8,3);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}

