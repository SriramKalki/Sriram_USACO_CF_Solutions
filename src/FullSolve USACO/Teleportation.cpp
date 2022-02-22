#include <iostream>
#include <cstdio>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("teleport");
    int a,b,x,y;
    cin >> a >> b >> x >> y; //a,b is the start and end

    //go to teleporter x -> y -> b
    // abs(x-a) + abs(y-b);
    //go to teleporter y -> x -> b
    // abs(x-b) + abs(y-a);
    //go manually
    // abs(a-b)
    //we find the min

    cout << min((abs(x-a)+abs(y-b)),min(abs(x-b)+abs(y-a),abs(a-b)));


}