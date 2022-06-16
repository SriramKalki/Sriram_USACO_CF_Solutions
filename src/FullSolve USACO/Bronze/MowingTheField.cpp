#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("mowing");
    vector<int> a;
    int n;
    cin >> n;
    //array[10*n][10*n] is the origin
    int array[20*n][20*n];
    for(int i=0; i<20*n; i++){
        for(int j=0; j<20*n; j++){
            array[i][j] =0;
        }
    }
    int locX(10*n),locY(10*n),time(0);
    for(int i=0; i<n; i++){
        char current;
        cin >> current;
        if(current == 'N'){
            int steps;
            cin >> steps;
            for(int j=0; j<steps; j++){
                locY++;
                time++;
                if(array[locX][locY] != 0){
                    a.push_back(time - array[locX][locY]);
                }
                array[locX][locY] = time;


            }
        }else if(current == 'S'){
            int steps;
            cin >> steps;
            for(int j=0; j<steps; j++){
                locY--;
                time++;
                if(array[locX][locY] != 0){
                    a.push_back(time - array[locX][locY]);
                }
                array[locX][locY] = time;


            }
        }else if(current == 'W'){
            int steps;
            cin >> steps;
            for(int j=0; j<steps; j++){
                locX--;
                time++;
                if(array[locX][locY] != 0){
                    a.push_back(time - array[locX][locY]);
                }
                array[locX][locY] = time;


            }
        }else{
            int steps;
            cin >> steps;
            for(int j=0; j<steps; j++){
                locX++;
                time++;
                if(array[locX][locY] != 0){
                    a.push_back(time - array[locX][locY]);
                }
                array[locX][locY] = time;


            }
        }
    }
    sort(a.begin(),a.end());
    if(a.size() == 0){
        cout << -1;
    }else{
        cout << a[0];
    }
}