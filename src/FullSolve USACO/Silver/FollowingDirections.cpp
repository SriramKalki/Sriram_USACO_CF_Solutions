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

int n;
struct Cell{
    bool vat;
    string dir;
    int cost;
};

Cell arr[1501][1501];
int cow[1501][1501];
bool visited[1501][1501];
vector<pair<int,int>> days(1501);

int sum(0);
int dfs(int i, int j){
    if(visited[i][j]){
        return 0;
    }
    if(arr[i][j].vat){

        return arr[i][j].cost;;
    }

    visited[i][j] = true;

    if(arr[i][j].dir == "R"){
            return dfs(i,j+1);
    }else{
            return dfs(i+1,j);
    }
        //don't know the cost yet



}



int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<n;j++){
            Cell c;
            c.vat = false;
            c.dir = s[j];
            c.cost = 0;
            arr[i][j] = c;
        }
        int k; cin >> k;
        Cell c; c.vat = true; c.dir = ""; c.cost = k;
        arr[i][n] = c;
    }

    for(int i=0; i<n; i++){
        int k; cin >> k;
        Cell c; c.vat = true; c.dir = ""; c.cost = k;
        arr[n][i] = c;
    }


    int q; cin >> q;
    days[0] = {1500,1500};
    for(int i=0; i<q; i++){
        int x; int y; cin >>x; cin >> y; x--; y--;
        days[i+1] = {x,y};
    }

    int currDay = 0;

    while(currDay <= q){
        if(currDay != 0){
            if(arr[days[currDay].first][days[currDay].second].dir == "D"){
                arr[days[currDay].first][days[currDay].second].dir = "R";
            }else{
                arr[days[currDay].first][days[currDay].second].dir = "D";
            }
            //yes ik there's a cleaner way to do it but its 2am
        }
        memset( cow, 0, sizeof(cow) );

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dfs(i,j);
            }
        }
        currDay++;
    }
}