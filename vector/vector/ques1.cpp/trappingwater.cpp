// #include<iostream>   //no.42 in leetcode famous question make two array
// #include<vector>
// #include<stack>
// using namespace std;
// int water(vector<int>&height){
//     //previous element
//     int n=height.size(); 
//     int arr[n];
//     arr[0]=-1;
//     int max=height[0];
//     for(int i=1;i<n;i++){   //previous element to find
//         arr[i]=max;
//         if(max<height[i]) max=height[i];
//     }
//     //next element
//     int brr[n];
//     brr[n-1]=-1;
//     max=height[n-1];
//     for(int i=n-2;i>=0;i--){   
//         brr[i]=max;
//         if(max<height[i]) max=height[i];
//     }
//     //least element /minimum element
//     int crr[n];
//     for(int i=0;i<n;i++){
//         crr[i]=min(arr[i],brr[i]);
//     }
//     //diffrences 
//     int sum=0;
//     for(int i=1;i<n-1;i++){    //first and last element are not consider
//         if(crr[i]>height[i]){
//             sum+=(crr[i]-height[i]);
//         }
//     }
//     cout<<sum;

//     return sum;
// }


// int main(){
//     vector<int>height;   //heights
//     height.push_back(0);
//     height.push_back(1);
//     height.push_back(0);
//     height.push_back(2);
//     height.push_back(1);
//     height.push_back(0);
//     height.push_back(1);
//     height.push_back(3);
//     height.push_back(2);
//     height.push_back(1);
//     height.push_back(2);
//     height.push_back(1);
//     water(height);
    
// }