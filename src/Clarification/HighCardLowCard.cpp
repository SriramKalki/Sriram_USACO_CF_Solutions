#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
 void setIO(string s) {
     freopen((s + ".in").c_str(), "r", stdin);
     freopen((s + ".out").c_str(), "w", stdout);
 }

int main(){
    setIO("cardgame");
    int n;
    cin >> n;
    vector<bool> taken(2*n + 1,false);
    vector<int> e1,e2;
    vector<int> b1,b2;
    for(int i=0; i<n; i++){
        int x;
        if(i < n/2){
            cin >> x;
            e1.push_back(x);
            taken[e1[i]] = true;
        }else {
            cin >> x;
            e2.push_back(x);
            taken[e2[i-(n/2)]] = true;

        }
    }

    for(int i=1; i<=2*n; i++){
        if(b2.size() < n/2) {
            if (!taken[i]) b2.push_back(i);
        }else{
            if (!taken[i]) b1.push_back(i);
        }
    }
    //bessie plays b1 for highest n/2, b2 for lowest n/2 games

    int answer = 0;
    int bcard = 0;
    sort(begin(b1),end(b1));
    sort(begin(b2),end(b2),greater<int>());
    sort(begin(e1),end(e1));
    sort(begin(e2),end(e2),greater<int>());

    for(int i=0; i<b1.size(); i++){
        if(b1[bcard] > e1[i]){
            answer++;
            bcard++;
        }
    }

    bcard=0;

    //1 8 4 3 10 11
    //b2(2 5 6) 7 9 12

    //11 10 3 (after reverse sort)
    //6 5 2
    for(int i=0; i<b2.size(); i++){
        if(b2[bcard] < e2[i]){
            answer++;
            bcard++;
        }
    }
    cout << answer;


}