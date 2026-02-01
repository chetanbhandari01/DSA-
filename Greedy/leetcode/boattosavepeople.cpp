#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int numRescueBoats(vector<int>& people, int limit) {
    int n = people.size();
    sort(people.begin(),people.end());
    int i=0;
    int j=n-1;
    int boat=0;
    while(i<=j){
        if(people[i]+people[j]>limit){
            boat++;
            j--;
        }
        else{  //people[i]+people[j]<limit
            boat++;
            i++;
            j--;
        }
    }
    return boat;
}
int main(){
    vector<int> people={3,5,3,4};
    int size= 5;
    cout<<numRescueBoats(people,size);
}