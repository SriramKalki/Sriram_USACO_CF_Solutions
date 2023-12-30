#include <vector>
#include <string>
#include <iostream>
#include <numeric>
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

int n,k;
int board[100][10],region[100][10],regsize[1001];

void gravity(){
    for(int j=0; j<10; j++){
        int shift = 0;
        for(int i= n-1; i>=0; i--){
            if(board[i][j] == 0) shift++;
            else if(shift!=0){
                int c = board[i][j];
                board[i+shift][j] = c;
                board[i][j] = 0;
            }
        }
    }
}
void visit(int i,int j,int r){
    region[i][j] = r;
    regsize[r]++;

    if(i<n-1 && region[i+1][j] == 0 && board[i+1][j] == board[i][j]) visit(i+1,j,r); //down
    if(i>0 && region[i-1][j] == 0 && board[i-1][j] == board[i][j]) visit(i-1,j,r); //up
    if(j < 9 && region[i][j+1] == 0 && board[i][j+1] == board[i][j]) visit(i,j+1,r); //right
    if(j>0 && region[i][j-1] == 0 && board[i][j-1] == board[i][j]) visit(i,j-1,r); //left
}

bool iterate(){
    //reset
    for(int i=0; i<100; i++){
        for(int j=0; j<10; j++){
            region[i][j] = 0;
        }
    }
    for(int i=0; i<1001; i++) regsize[i] =0;
    //start floodfill
    int r=0;
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<10; j++){
            if(board[i][j] == 0 || region[i][j] != 0) continue;
            //undiscovered region found
            r++;
            visit(i,j,r);
        }
    }
    bool progress = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            if(board[i][j] !=0 && regsize[region[i][j]] >= k){
                progress = true;
                board[i][j] = 0;
            }
        }
    }
    gravity();
    return progress;
}


int main(){
    setIO("mooyomooyo");

    cin >> n >> k;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<10; j++){
            board[i][j] = s[j] - '0';

        }
    }
    while(iterate()){}
    
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}