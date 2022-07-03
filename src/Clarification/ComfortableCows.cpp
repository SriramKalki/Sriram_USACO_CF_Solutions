#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int x[n];
    int y[n];
    int answer(0), tangent(0);
    for(int i=0;i<n; i++){
        cin >> x[i] >> y[i];
        if( i < 3){
            cout << 0 << endl;
        }else{
            for(int j=0;j<=i; j++){
                for(int k=0; k<=i;k++){
                    if((abs(x[j]-x[k]) == 1 && abs(y[j]-y[k]) == 0) || (abs(x[j]-x[k]) == 0 && abs(y[j]-y[k]) == 1)){
                        tangent++;

                    }

                }
                if(tangent ==3){
                    answer++;
                }
                tangent =0;


            }
            cout << answer << endl;
            answer = 0;

        }
    }

}