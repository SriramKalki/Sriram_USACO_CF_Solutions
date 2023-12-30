#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#define ll long long
using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int n;
vector<string> v[25];
vector<string> all_chars;

bool cross(int a,int b){
    int A =0, B=0, AB=0;
    for(int i=0; i<n; i++){
        vector<string> &p = v[i];
        bool has_a = false;
        bool has_b = false;
        for(int j=0; j < p.size(); j++){
            if(p[j] == all_chars[a]) has_a = true;
            if(p[j] == all_chars[b]) has_b = true;
        }
        if(has_a && has_b) AB++;
            else if(has_a) A++;
            else if(has_b) B++;

    }
    return A>0 && B>0 && AB>0;
}
int main(){
    setIO("evolution");
    cin >> n;
    
    for(int i=0; i<n; i++){
        int k; cin >> k;
        for(int j=0; j<k;j++){
            string s; cin >> s;
            v[i].push_back(s);

            bool found = false;
            for(int p=0; p < all_chars.size(); p++){
                if(all_chars[p] == s) found = true;
            }
            if(!found) all_chars.push_back(s);
        }
    }

    int M = all_chars.size();
    bool good = true;
    for(int i=0; i<M; i++){
        for(int j=i+1; j<M; j++){
            if(cross(i,j)){
                //cout << all_chars[i] << " and " << all_chars[j] << " cross" << endl;
                good = false;
            } 
        }    
    }
    if(good) cout << "yes";
    else cout << "no";




}