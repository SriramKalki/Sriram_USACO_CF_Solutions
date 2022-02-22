#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    double h,m,s,t1,t2;
    cin >> h >> m >> s >> t1 >> t2;
    if(h == 12){
        h=0;
    }
    h = 30*h + 0.5 * m + ((double) 1/120) * s;
    m = 6 * m;
    s = 6 * s;
    if(t1 == 12){
        t1 =0;
    }
    if(t2 == 12){
        t2=0;
    }
    t1 = 30 * t1;
    t2 = 30 * t2;

    //everything is converted to degrees now
    double array[] = {h,m,s};
    sort(array,array+3);
    bool check = ((array[0] < t1) && (array[0] < t2) && (array[1] > t1) && (array[1] > t2)) || ((array[1] < t1) && (array[1] < t2) && (array[2] > t1) && (array[2] > t2));
    if(((array[0] < t1) && (array[0] < t2) && (array[1] > t1) && (array[1] > t2)) || ((array[1] < t1) && (array[1] < t2) && (array[2] > t1) && (array[2] > t2))){
        cout << "YES";

    }else if(!check && t1 > array[2] && t2 > array[2]){
        cout << "YES";
    }else{
        cout << "NO";
    }
}