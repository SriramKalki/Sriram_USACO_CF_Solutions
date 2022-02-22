#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
ll array[50];
ll n;
ll loc;
cin >> n;
array[0] = 0;
array[1] = 1;
if(n==0){
    cout << 0 << " " << 0 << " " << 0;
    return 0;
}else if(n==1){
    cout << 1 << " " << 0 << " " << 0;
    return 0;
}
for(int i=2; i<50; i++){
    array[i] = array[i-1]+array[i-2];
    if(array[i] == n){
       loc = i;
       break;
    }

}
cout << array[loc-1] << " " << array[loc-2] << " " << 0;


}