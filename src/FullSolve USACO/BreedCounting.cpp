#include <iostream>
#include <cstdio>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("bcount");
    int n,q;
    cin >> n >> q;
    int array[n];
    int psum1[n],psum2[n],psum3[n];

    for(int i=0; i<n; i++){
        if(i==0){
            psum1[i]=0;
            psum2[i]=0;
            psum3[i]=0;
        }else{

            psum1[i]=psum1[i-1];
            psum2[i]=psum2[i-1];
            psum3[i]=psum3[i-1];

        }
        cin>>array[i];
        switch(array[i]){
            case 1: psum1[i]++;
                break;
            case 2: psum2[i]++;
                break;
            case 3: psum3[i]++;
                break;
        }

    }
    int a,b;
    for(int i=0; i<q; i++){
        cin >> a >> b;
        a--;
        b--;
        //from pt 0 to pt 5 - then psum1[5] - 0
        //from pt 1 to pt 5 - then psum1[5] - psum1[1]
        if(a!= 0) {
            cout << psum1[b] - psum1[a-1] << " " << psum2[b] - psum2[a-1] << " " << psum3[b] - psum3[a-1] << endl;
        }else{

            cout << psum1[b] << " " << psum2[b] << " " << psum3[b] << endl;
        }

    }

}