#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,d,m;
    cin >> n >> d >> m;

    int answer=0;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        if(!(y > x + d) && !(y < -x + d) && !(y < x - d) && !(y > -x + 2*n - d)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }


}