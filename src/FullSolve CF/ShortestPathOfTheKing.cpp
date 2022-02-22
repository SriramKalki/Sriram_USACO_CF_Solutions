#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
    string beg;
    string end;
    cin >> beg >> end;
    int x1,y1,x2,y2;
    x1 = int (beg[0]) -96;
    y1 = int (beg[1]) -48;
    x2 = int (end[0]) -96;
    y2 = int (end[1]) -48;
    //x1 = 1 y1 =8 x2 =8 y2 =1
    int u(0),d(0),l(0),r(0),count(0);
    if(x2-x1 >=0){
        r = x2-x1;
    }else{
        l = x1-x2;
    }

    if(y2-y1 >=0){
        u = y2-y1;
    }else{
        d = y1-y2;
    }

    if(u>=d && r >=l){
        count = min(u,r) + (r-min(u,r)) + (u - min(u,r));
        cout << count << endl;
        for(int i=0; i< min(u,r); i++){
            cout << "RU" << endl;
        }
        for(int i=0; i< r- min(u,r); i++){
            cout << "R" << endl;
        }
        for(int i=0; i< u- min(u,r); i++){
            cout << "U" << endl;
        }
    }else if(u>=d && r<l){
        count = min(u,l) + (u - min(u,l)) + (l - min(u,l));
        cout << count << endl;
        for(int i=0; i< min(u,l); i++){
            cout << "LU" << endl;
        }
        for(int i=0; i< l- min(u,l); i++){
            cout << "L" << endl;
        }
        for(int i=0; i< u- min(u,l); i++){
            cout << "U" << endl;
        }

    }else if(u<d && r >= l){
        count = -min(d,r) + d +r;
        cout << count << endl;
        for(int i=0; i< min(d,r); i++){
            cout << "RD" << endl;
        }
        for(int i=0; i< r- min(d,r); i++){
            cout << "R" << endl;
        }
        for(int i=0; i< d- min(d,r); i++){
            cout << "D" << endl;
        }

    }else{
        count = -min(d,l) + d + l;
        cout << count << endl;
        for(int i=0; i< min(d,l); i++){
            cout << "LD" << endl;
        }
        for(int i=0; i< l- min(d,l); i++){
            cout << "L" << endl;
        }
        for(int i=0; i< d- min(d,l); i++){
            cout << "D" << endl;
        }
    }

}