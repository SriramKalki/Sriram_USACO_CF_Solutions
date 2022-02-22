#include <iostream>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("blist");
    int n;
    cin >> n;

    int s[n],t[n],b[n];

    for(int i=0; i<n; i++){
        cin >> s[i] >> t[i] >> b[i];


    }
    int bucketsInUse(0), bucketsFree(0), totalBuckets(0);
    for(int i=1; i<= 1000; i++){
        for(int j=0; j<n; j++){
            if(t[j] == i){
                bucketsInUse -= b[j];
                bucketsFree += b[j];


            }
            if(s[j] == i){
                if(b[j] >= bucketsFree){
                    totalBuckets += b[j]-bucketsFree;
                    bucketsInUse += b[j];
                    bucketsFree = totalBuckets - bucketsInUse;
                }else{
                    bucketsInUse += b[j];
                    bucketsFree -= b[j];
                }
            }


        }

    }
    cout << totalBuckets;




}