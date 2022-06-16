#include <iostream>
#include <cstdio>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main(){

    setIO("gymnastics");

    int k,n;
    cin >> k >> n;
    int array[k][n];
    int performance[k][n];
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            cin >> array[i][j];
            performance[i][array[i][j]-1] = j+1;
        }

    }
    bool maj1 = true;
    bool maj2 = true;
    int answer = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            maj1 = true;
            maj2 = true;
            for(int l=0; l<k; l++){
                if(performance[l][i] > performance[l][j]){
                    maj1 = false;
                    break;
                }
            }
            for(int l=0; l<k; l++){
                if(performance[l][i] < performance[l][j]){
                    maj2 = false;
                    break;
                }
            }
            if(maj1 || maj2){
                answer++;
            }
        }
    }
    cout << answer;








}