#include <iostream>

using namespace std;

int main(){
    string s;
    int n,t,x(0);
    cin >> n >> t >> s;
    for(int i=0; i<t; i++){
        while(x<=n){
            if(s[x] == 'B' && s[x+1] == 'G'){
                swap(s[x],s[x+1]);
                x=x+2;
            }else{
                x++;
            }
        }
        x=0;
    }
    cout << s;


}