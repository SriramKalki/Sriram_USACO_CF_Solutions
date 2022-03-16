#include <iostream>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("hps");
    int n;
    cin >> n;
    int array[3][n+1]; //bus 0 is Hoof bus 1 is Paper bus 2 is Scissor
    array[0][0] =0; array[1][0] =0; array[2][0] =0;
    //array[1] is game 0 results, array[2] is game 0 + game 1 results ... array[5] is game 0 + game 1 + game 2 + game 3 + game 4
    for(int i=0; i<n; i++){
        char s;
        cin >> s;
        if(s == 'H'){
            array[0][i+1] = array[0][i];
            array[1][i+1] = array[1][i] + 1;
            array[2][i+1] = array[2][i];
        }else if(s == 'P'){
            array[0][i+1] = array[0][i];
            array[1][i+1] = array[1][i];
            array[2][i+1] = array[2][i] + 1;
        }else if(s == 'S'){
            array[0][i+1] = array[0][i] + 1;
            array[1][i+1] = array[1][i];
            array[2][i+1] = array[2][i];
        }

    }
    int answer =0;
    //H and P combo
    for(int x =1; x < n+1; x++){
        answer = max(answer,max(array[0][x]+array[1][n]-array[1][x],array[1][x]+array[0][n]-array[0][x]));
        answer = max(answer,max(array[0][x]+array[2][n]-array[2][x],array[2][x]+array[0][n]-array[0][x]));
        answer = max(answer,max(array[1][x]+array[2][n]-array[2][x],array[2][x]+array[1][n]-array[1][x]));
    }
    cout << answer;
}