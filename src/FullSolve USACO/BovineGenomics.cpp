#include <iostream>
#include <cstdio>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}



int main(){
    setIO("cownomics");
    int n,m;
    cin >> n >> m;
    string spot[n];
    string plain[n];
    string curr;
    for(int i=0; i<n; i++){
        cin >> spot[i];

    }
    for(int i=0; i<n; i++){
        cin >> plain[i];

    }
    int answer=0;
    bool count = true;
    for(int i=0; i<m; i++){
        for(int j=0;j<n; j++){
            //which plain cow are we using
            for(int k=0; k<n; k++){
                if(spot[k][i] == plain[j][i]){
                    //if this happens the genome prediction is not accurate for character i
                    count = false;
                    break;
                }
            }
            if(!count){
                break;
            }

        }
        if(count){
            answer++;
        }
        count = true;

    }
    cout << answer;

}