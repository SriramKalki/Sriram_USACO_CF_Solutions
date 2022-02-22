#include <iostream>

using namespace std;

int main(){
   //sum of the total amount of moves when initial position is edge (n-1) abs(k-1) + n-1
   //sum of the total amt of rock moves n+1
   //sum of the total amt of coin grabs n
   int n,k;
   cin >> n >> k;
   if(k==n){
       k=1;
   }
   //min(n-k, k-1) + n-1
   cout << min(n-k,k-1) + 3*n;


}