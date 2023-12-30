#include <bits/stdc++.h>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("lazy");
    int n,k;
    cin >> n >> k;
    int array[n][n];
    int psum[n][n+1],val(0);
    for(int i=0; i<n; i++){
        val =0;
        for(int j=0; j<n+1; j++){
            if(j!= n){cin >> array[i][j];}
            if(j == 0){psum[i][j] = val; continue;}
            val += array[i][j-1];
            psum[i][j] = val;
        }
    }


    //to find the sum from array[i][j] to array[i][k], do psum[i][j+1]-psum[i][k]
    int answer = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int curr(0);
            int height = k;
            for(int h= i - k; h <= i +k; h++){

                //height + length = k;


                int l = k-height;
                if(!(h < 0 || h > n - 1)){

                    curr += psum[h][min(j + l, n-1) + 1] - psum[h][max(j - l, 0)];
                }

                if(h >= i){
                    height++;
                }else{
                    height--;
                }



            }

            answer = max(curr,answer);
        }
    }
    cout << answer;
}