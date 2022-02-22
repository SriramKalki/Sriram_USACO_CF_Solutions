#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int N=0;
    int k=0;
    cin >> N;
    cin >> k;
    int scores [N];
    for(int i=0; i<N; i++){
        cin >> scores[i];

    }
    int cutoff = scores[k-1]; //indexing
    int qualifiers=0;
    for(int i=0; i<N; i++){
        if(scores[i] >0 && scores[i] >= cutoff){
            qualifiers++;
        }

    }
    cout << qualifiers;


}