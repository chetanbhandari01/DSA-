#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
int main(){
    string str="raghav is a best C++ teacher in a pw";
    stringstream str1(str);  //make in one -one word
    string temp;
    vector<string>str2;
    while(str1>>temp){
        str2.push_back(temp);  //storing in vector
    }
    
    //sort karo time complexity requried
    sort(str2.begin(),str2.end());
    // for(int i=0;i<str.size();i++){
    //     cout<<str2[i]<<endl;
    // }

    //counting max
    int maxcount=1;
    int count=1;
    for(int i=1;i<str2.size();i++){
        if(str2[i]==str2[i-1]) count++;
        else count=1;
        maxcount=max(maxcount,count);
    }
    //printing max character
    count=1;
    for(int i=1;i<str2.size();i++){
        if(str2[i]==str2[i-1]) count++ ;
        else count=1;
        if(maxcount ==count){
            cout<<str2[i]<<" "<<maxcount<<endl;
        }
    }


}