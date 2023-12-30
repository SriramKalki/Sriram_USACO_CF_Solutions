#include <vector>
#include <string>
#include <iostream>
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

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int begin_f = 0;
    int end_f = 0;
    
    int i=0;
    while(s[i] == 'F'){
        begin_f++;
        i++;
    }
    int j= n-1;
    while(s[j] == 'F'){
        end_f++;
        j--;
    }

    if(begin_f == n){
        //full text of 'F'
        cout << n << endl;
        for(int i=0; i <n; i++) cout << i << endl;
        return 0;
    }
    
    char start, end;
    int confirmed = 0;
    int curr_streak = 0;
    int max = 0;
    int min = 0;
    for(int c = i; c<=j; c++){
        if(c > i && s[c] == s[c-1] && s[c] != 'F'){
            confirmed++;
        }
        
        if(curr_streak == 0 && s[c] != 'F'){
            continue;
        }else if(curr_streak != 0 && s[c] == 'F'){
            curr_streak++;
            continue;
        }
        
        if(curr_streak == 0 && s[c] == 'F'){
            start = s[c-1];
            curr_streak++;
            continue;
        }

        if(curr_streak != 0 && s[c] != 'F'){
            end = s[c];
            if(start == end){
                max += curr_streak + 1;
                min += (curr_streak -1) % 2;
            }else{
                max += curr_streak;
                min += curr_streak % 2;
            }
            curr_streak = 0;
        }
        
    }
    int total_f = begin_f + end_f;
    if(total_f == 0){
        int k = max/2 - min/2 + 1;
        cout << k<< endl;
        for(int a = min; a <= max; a+=2){
            cout << a +confirmed<< endl;
        }
    }else{
        cout << max + total_f - min + 1<< endl;
        for(int a = min; a <= max + begin_f + end_f; a++){
            cout << a +confirmed<< endl;
        }
    }

}