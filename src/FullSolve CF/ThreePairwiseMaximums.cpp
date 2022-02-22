#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t=0;
    int x=0;
    int y=0;
    int z=0;
    int maximum =0;
    int minimum =0;
    cin >> t ;
    for(int i=0; i<t; i++){
        cin >> x;
        cin >> y;
        cin >> z;
        maximum = max(max(x,y),z);
        minimum = min(min(x,y),z);
        if( (x==y && y==z) || (x==y && y>z) || (x==z && z>y) || (y==z && z>x)){
            cout << "YES" << endl;
            cout << maximum << " "<< minimum << " " << minimum << endl;

        }else{
            cout << "NO" << endl;

        }



    }



}