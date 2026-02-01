#include<iostream>
#include<vector>
using namespace std;
vector<vector<int >> pascal(int number){
    int m= number+1;
    vector<vector<int>> v;
    for(int i=0;i<m;i++){
        vector<int> a(i+1);
        v.push_back(a);
        for(int j=0;j<=i;j++){
            if(j==0 || i==j){
                v[i][j]=1;
            }
            else{
                v[i][j]=v[i-1][j-1]+v[i-1][j];
            }
        }
    }
    return v;

}
int main(){
    vector<vector<int>> v=pascal(5);
    for(int i=0;i<=5;i++){
        for(int j=0;j<=i;j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
}