#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main(){

    setIO("blocks");

    int n;
    cin >> n;

    string array[2*n];
    for(int i=0; i< 2*n; i++){
        cin >> array[i];
    }
    int a[26];
    int b[26];
    int answer[26];

    for(int i=0; i<26; i++){
        a[i]=0;
        b[i]=0;
        answer[i]=0;

    }

    string curr;
    for(int i=0; i<2*n; i=i+2 ){
        curr = array[i];
        for(int j=0; j< array[i].length();j++){

            a[int (curr[j])-97]++;

        }
        curr=array[i+1];
        for(int j=0; j< array[i+1].length();j++){

            b[int (curr[j])-97]++;


        }

        for(int j=0; j<26;j++){

            answer[j] += max(a[j],b[j]);
            a[j]=0;
            b[j]=0;
        }


    }


    for(int i=0; i<26; i++){
        cout<<answer[i]<<endl;
    }


}