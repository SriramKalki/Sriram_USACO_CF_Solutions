#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int diff[1001][1000];
    for(auto c : diff){c = 0;}

    for(int i=0; i<n; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        //x values are shifted by one
        //[null,a=0,a=1;a=2;a=3] [5,6] will be one less than [5,5]
        // a and c are x values b and d are y values. array[i][j] i is the y val j is the x val
        for(int j=b; j<=d; j++){diff[j][a]++; diff[j][c]--;} //right - left
    }
    cout << diff[5][5] << endl;
    int data[1000][1001];
    int answer = 0;

    for(int i=0; i<1000; i++){
        for(int j=0; j<1001; j++){
            if(diff[i][j] == k) answer++;
            diff[i][j+1] += diff[i][j];
        }
    }

    cout << answer;
}