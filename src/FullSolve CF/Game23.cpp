#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int div;
    int a(0),b(0);
    if(m % n != 0){
        cout << -1;
        return 0;
    }else{
        div= m/n;

    }
    int two(pow(2,a)),three(pow(3,b));
    while(div % two == 0){
        a++;
        two = pow(2,a);

    }
    a--;
    while(div % three == 0){
        b++;
        three = pow(3,b);

    }
    b--;
    int powers = pow(2,a)*pow(3,b);

    if(div/powers != 1){
        cout << -1;
        return 0;

    }else{
        cout << a+b;
        return 0;
    }
}