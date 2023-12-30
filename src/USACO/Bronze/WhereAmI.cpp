#include <iostream>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("whereami");
    int n;
    cin >> n;
    string s;
    cin >> s;
    int equalSubs,equalLetters;
    for(int k=1; k <= s.length(); k++ ){
        bool failkfound = false;
        for(int i=0; i <= n-k; i++){
            //this for loop compares one substring of length k with all others
            string current = "";
            for(int j=i; j< i+k; j++){
                //makes the substring
                current += s[j];
            }
            equalSubs =0;
            for(int j=0; j <= n-k; j++){
                //compares

                equalLetters =0;
                int x=0; int c = j;
                for(int p=0; p<k; p++){
                    if(current[x] == s[c]){
                        equalLetters++;
                        x++; c++;

                    }
                }
                if(equalLetters == k){
                    equalSubs++;
                }
            }
            if(equalSubs > 1){

                failkfound = true;
                break;

            }


        }
        if(!failkfound){
            cout << k;
            return 0;
        }

    }


}