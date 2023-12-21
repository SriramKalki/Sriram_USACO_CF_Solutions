#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#define ll long long
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct Point{
    int time,x,y;
};




int main(){
    int g,n;
    int innocent = 0;

    cin >> g >> n;
    vector<Point> gr(g);
    vector<Point> cow(n);

    for(int i=0; i<g; i++){
        cin >> gr[i].x >> gr[i].y >> gr[i].time;
    }


    for(int i=0; i<n; i++){
        cin >> cow[i].x >> cow[i].y >> cow[i].time;
    }

    sort(begin(gr),begin(gr), [](const Point &x, const Point &y){return x.time < y.time;});
    sort(begin(cow),begin(cow), [](const Point &x, const Point &y){return x.time < y.time;});

    for(int i=0; i<n; i++){
        auto it = lower_bound(gr.begin(),gr.end(),cow[i]);
    }
}