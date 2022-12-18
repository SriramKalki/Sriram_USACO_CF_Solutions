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
    setIO("highcard");
    int n;
    cin >> n;
    vector<bool> taken(2*n + 1,false);
    vector<int> e(n);
    vector<int> b;
    for(int i=0; i<n; i++){
        cin >> e[i];
        taken[e[i]] = true;
    }

    for(int i=1; i<=2*n; i++){

        if(!taken[i]) b.push_back(i);
    }

    sort(begin(e),end(e));
    sort(begin(b),end(b));

    int card = 0;
    int answer = 0;
    for(int i=0; i<n; i++){
        bool win = false;
        while(card < n){

            if(e[i] < b[card]) {
                answer++;
                win = true;
                card++;
                break;
            }
            card++;
        }
        if(!win){
            break;
        }
    }

    cout <<answer;


}