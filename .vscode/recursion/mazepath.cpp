#include<iostream>
using namespace std;
int maze(int sr,int sc,int er,int ec){  //these for no.of ways
    if(sr>er || sc>ec) return 0;   //sr=starting row , sc=start column
    if(sr==er && sc==ec) return 1;  //er=endind row  , ec=endind column
    int rightway=maze(sr,sc+1,er,ec); 
    int downways=maze(sr+1,sc,er,ec);
    int total=rightway+downways;
    return total;
}
void mazepath(int sr,int sc,int er,int ec,string s){  //these are path we follow
    if(sr>er || sc>ec) return ;   
    if(sr==er && sc==ec){
        cout<<s<<endl;
        return;
    }
    mazepath(sr,sc+1,er,ec,s+"R"); //if column is shift at right side than "right" taken 
    mazepath(sr+1,sc,er,ec,s+"D"); //if row is shifted at downside than "down" taken
    
}
int main(){
    cout<<maze(1,1,3,3)<<endl;
    mazepath(1,1,3,3,"");
}