#include <iostream>

using namespace std;

int main(){
    int k,l,m,n,d;
    cin>>k>>l>>m>>n>>d;

    bool oof[d+1];
    for(int i=1; i<d+1; i++){
        oof[i] = false;
    }
    for(int i=1; i<d+1; i++){
        if(i%k ==0){
            oof[i] =true;
        }else if(i%l ==0){
            oof[i] = true;
        }else if(i%m ==0){
            oof[i] = true;
        }else if(i%n ==0){
            oof[i] = true;
        }
    }
    int ans=0;
    for(int i=1; i<d+1; i++){
        if(oof[i]){
            ans++;
        }
    }
    cout << ans;


}