#include <iostream>
#include <bits/stdc++.h>


using namespace std;
int time(int n,int m,int rb,int cb,int rd,int cd){
    bool found = false;
    int answer =0;
    int dirr(1),dirc(1);

    while(!found){
        if(cb == cd || rb == rd){
            found = true;
            return answer;
        }
        answer++;
        //first we move rb
        if(rb ==1){
            dirr =1;
        }else if(rb ==n) {
            dirr = -1;
        }
        rb += dirr;
        //now we move cb
        if(cb ==1){
            dirc =1;
        }else if(cb ==m) {
            dirc = -1;
        }
        cb += dirc;
        //clean and check


    }


}
int main(){
    int t;
    cin >> t;
    int a,b,c,d,e,f;
    for(int i=0; i<t; i++){
        cin >>a>>b>>c>>d>>e>>f;
        cout << time(a,b,c,d,e,f) << endl;

    }



}