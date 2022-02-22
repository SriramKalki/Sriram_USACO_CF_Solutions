#include <iostream>

using namespace std;

int main(){
    int h1,m1,h2,m2;
    char c1,c2;
    cin >> h1 >> c1 >> m1 >> h2 >> c2 >> m2;
    int t1,t2;
    t1= 60*h1+m1;
    t2= 60*h2+m2;
    int t3;
    t3= (t1+t2)/2;
    int h3,m3;
    h3 = (t3/60) % 24;
    m3 = t3 % 60;

    if(h3 < 10 && m3 < 10){
        cout << 0 << h3 << c1 << 0 << m3;
    }else if(h3 < 10 && m3 >= 10){
        cout << 0 << h3 << c1 << m3;
    }else if(h3 >= 10 && m3 <10){
        cout << h3 << c1 << 0 << m3;
    }else {
        cout << h3 << c1 << m3;
    }
}