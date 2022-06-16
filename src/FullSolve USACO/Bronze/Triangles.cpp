#include <iostream>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("triangles");
   int n;
   cin >> n;
   int x[n],y[n];
   int cases =0;
   for(int i=0; i<n; i++){
       cin >> x[i] >> y[i];

   }
    int current(0),maximum(0);
   for(int a=0; a<n-2; a++){
       for(int b=a+1; b<n-1; b++){
            for(int c= b+1; c<n; c++){
                current =0;
                if((x[b] == x[a] && (y[c] == y[b] || y[c] == y[a]))){
                    if(y[c] == y[b]){
                        current = abs(y[a]-y[c])*abs(x[c]-x[a]);
                    }else{
                        current = abs(y[b]-y[c])*abs(x[c]-x[a]);
                    }
                }else if((x[c] == x[a] && (y[b] == y[a] || y[b] == y[c]))){
                    if(y[c] == y[b]){
                        current = abs(y[a]-y[b])*abs(x[b]-x[a]);
                    }else{
                        current = abs(y[b]-y[c])*abs(x[b]-x[a]);
                    }
                }else if((x[c] == x[b] && (y[a] == y[b] || y[a] == y[c]))){
                    if(y[a] == y[b]){
                        current = abs(y[a]-y[c])*abs(x[c]-x[a]);
                    }else{
                        current = abs(y[a]-y[b])*abs(x[c]-x[a]);
                    }
                }
                maximum = max(current, maximum);
            }

       }

   }
   cout << maximum;
}