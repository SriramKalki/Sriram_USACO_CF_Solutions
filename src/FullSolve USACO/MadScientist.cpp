#include <iostream>
#include <cstdio>


using namespace std;



void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("breedflip");
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;

    int answer =0;
    bool mismatched = false;

    for(int i=0; i<n; i++){
        if(s1[i] != s2[i]){
            if(!mismatched){
                answer++;
                mismatched=true;
            }

        }else{
            mismatched = false;
        }



    }



    cout << answer;




}