//leetcode 658
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> findclosestelement(vector<int> &arr,int x,int k){
    int n=arr.size();
    vector<int> ans(k);
    if(x<arr[0]){
        for(int i=0;i<k;i++){
            ans[i]=arr[i];
        }
        return ans;
    }
    if(x>arr[n-1]){  //1 2 3 4 5 k=2  x=7 ->  
        int i=n-1;  //i=4 means index 4
        int j=k-1;  //j=1  0,1 two element store hoge
        while(j>=0){
            ans[j]=arr[i];
            j--;
            i--;
        }
        return ans;
    }
    int lo=0;
    int hi=n-1;
    bool flag =false;   //if x is present or not
    int t=0; //representing index of ans
    int mid=-1;
    while(lo<=hi){    //binary search
        mid=lo+(hi-lo)/2;
        if(x==arr[mid]){
            flag =true;
            ans[t]=arr[mid];
            t++;
            break;
        }
        else if(arr[mid]>x) hi=mid-1;
        else lo=mid+1;
    }
    int lb=hi;  //lowerbound and upperbound when loop ended
    int ub=lo;
    if(flag==true ){
        lb=mid-1;
        ub=mid+1;
    }

    while(t<k && lb>=0 && ub<=n-1){
        int d1=abs(x-arr[lb]);    //d1 means difference 1 and abs is absolute value means mode jaise
        int d2=abs(x-arr[ub]);
        if(d1<=d2){
            ans[t]=arr[lb];
            lb--;
        }
        else{   //d1 >d2
            ans[t]=arr[ub];
            ub++;
           
        }
        t++;
    }
    if(lb<0){      //lower bound outof loop than
        while(t<k){
            ans[t]=arr[ub];
            ub++;
            t++;
        }

    }
    if(ub>n-1){
        while(t<k){
            ans[t]=arr[lb];
            lb--;
            t++;
        }

    }
    sort(ans.begin(),ans.end());
    return ans;
    
}
int main(){
    

    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    vector<int> result = findclosestelement(arr, k, x);
     //run to leetcode
    
}