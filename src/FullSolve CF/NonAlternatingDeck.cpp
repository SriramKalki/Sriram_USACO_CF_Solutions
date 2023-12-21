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

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;

        int moves = (int) (1 + sqrt(1 + 8*n)) / 4.0;


        int aTurns = (moves % 2 == 0) ? moves/2 : moves/2 + 1;
        int bTurns = moves - aTurns;

        int aTot = aTurns * (4*aTurns - 3);
        //more white
        int aWhite = (aTot % 2 == 0) ? aTot/2 : aTot/2 + 1;
        int aBlack = aTot - aWhite;

        int bTot = bTurns * (4 * bTurns + 1);
        //more black
        int bBlack = (bTot %2 == 0) ? bTot/2 : bTot/2 + 1;
        int bWhite = bTot - bBlack;

        if(moves % 2 == 0){
            //more white
            int overflow =n - moves*(2*moves-1);
            aTot += overflow;
            aBlack += (overflow % 2 == 0) ? overflow/2 : overflow/2 - 1;
            aWhite += overflow - aBlack;
        }else{
            //more black
            int overflow =n - moves*(2*moves-1);
            bTot += overflow;
            bBlack += (overflow % 2 == 0) ? overflow/2 : overflow/2 + 1;
            bWhite += overflow - bBlack;
        }
        cout << aWhite << " " << aBlack << " " << bWhite << " " << bBlack << endl;


    }

}