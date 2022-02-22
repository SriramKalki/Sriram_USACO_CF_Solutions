#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


bool sortbysec(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main(){
    setIO("reduce");
    int n;
    cin >> n;

    vector<pair <int,int>> a;
    vector<pair <int,int>> x;
    vector<pair <int,int>> y;


    for(int i=0; i<n; i++){
        int j,k;
        cin >> j >> k;

        a.push_back(make_pair(j,k));

        x.push_back(make_pair(j,k));

        y.push_back(make_pair(j,k));

    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end(), sortbysec);
    //remove the leftmost point and find the area, then rightmost point
    //(x[n-1].first)-(x[1].first)
    int xlength,ylength,currArea(1000000000),minArea(1000000000);
    for(int i=0; i<1; i++){
        xlength = x[n-1].first - x[1].first;
        //we are deleting x[0].first
        //the deleted x coordinate could be the max y, or the min y
        if(y[n-1].first == x[0].first){
            ylength = y[n-2].second;
        }else{
            ylength = y[n-2].second;
        }

        if(y[0].first == x[0].first){
            ylength -= y[1].second;
        }else{
            ylength -= y[0].second;
        }
        currArea = xlength * ylength;

        minArea = min(minArea,currArea);
    }
    //remove the rightmost point
    for(int i=0; i<1; i++){
        xlength = x[n-2].first - x[0].first;
        if(y[n-1].first == x[n-1].first){
            ylength = y[n-2].second;
        }else{
            ylength = y[n-2].second;
        }

        if(y[0].first == x[n-1].first){
            ylength -= y[1].second;
        }else{
            ylength -= y[0].second;
        }
        currArea = xlength * ylength;
        minArea = min(minArea,currArea);
    }

    //remove the bottommost point with coordinates y[0].first and y[0].second
    for(int i=0; i<1; i++){
        ylength = y[n-1].second - y[1].second;
        if(x[n-1].first == y[0].first){
            xlength = x[n-2].first;
        }else{
            xlength = x[n-1].first;
        }
        if(x[0].first == y[0].first){
            xlength -= x[1].first;
        }else{
            xlength -= x[0].first;
        }
        currArea = xlength * ylength;
        minArea = min(minArea,currArea);

    }
    //remove the topmost point
    for(int i=0; i<1; i++){
        ylength = y[n-2].second - y[0].second;
        if(x[n-1].first == y[n-1].first){
            xlength = x[n-2].first;
        }else{
            xlength = x[n-1].first;
        }
        if(x[0].first == y[n-1].first){
            xlength -= x[1].first;
        }else{
            xlength -= x[0].first;
        }
        currArea = xlength * ylength;
        minArea = min(minArea,currArea);

    }
    cout << minArea;
}