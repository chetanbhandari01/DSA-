#include<iostream>
#include<vector>
using namespace std;
// bool searchmatrix(vector<vector<int>> &matrix ,int target){
//     int row=matrix.size();
//     int col=matrix[0].size();
//     int i=0;
//     int j=col-1;
//     while(i<row && j>=0){
//         if(matrix[i][j]==target) return true;
//         else if(matrix[i][j]>target) {     //shift left 
//             j--;
//         }
//         else i++;     //martix[i][j]<target    //shift down
//     }
//     return false;
// }
// int main(){
//     vector<vector<int>> matrix;
//     vector<int> v={1,4,7,11,15};
//     vector<int> v1={2,5,8,12,19};
//     vector<int> v2={3,6,9,16,22};
//     vector<int> v3={10,13,14,17,24};
//     matrix.push_back(v);
//     matrix.push_back(v1);
//     matrix.push_back(v2);
//     matrix.push_back(v3);
//     cout<<searchmatrix(matrix,5);
// }

int main(){
    int x=12345;
    int y=0;
    int res=0;
    while(x>0){
        int temp=x;
        y=temp%10;
        x=temp/10;
        
        res=res*10+y;
    }
    cout<<res;
}