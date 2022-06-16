#include <iostream>
#include <cstdio>


using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("buckets");
    char array[10][10];
    string curr;
    int bx,by,lx,ly,rx,ry;
    for(int i=0; i<10; i++){
        cin >> curr;
        for(int j=0; j<10; j++){
            array[i][j] = curr[j];

            if(array[i][j] == 'B'){
                bx = j;
                by = i;
            }
            if(array[i][j] == 'L'){
                lx = j;
                ly = i;
            }
            if(array[i][j] == 'R'){
                rx = j;
                ry = i;
            }


        }


    }

    if(((bx < rx && rx < lx) || (lx < rx && rx < bx)) && by == ly && by == ry){
        cout << abs(lx - bx) +1;
    }else if(((by< ry && ry < ly) || (ly < ry && ry < by)) && bx == lx && bx == rx){
        cout << abs(ly - by) +1;
    }else {
        cout << abs(lx - bx) + abs(ly - by) - 1;
    }
}