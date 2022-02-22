#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int array[n+1];

    for(int i=2; i<=n; i++){
        cin >> array[i];

        //screw indexing
       //array[2] tells where the 2nd router is connected to


    }
    array[0] =0;
    array[1] =1;
    int nextRouter =n;
    int p=n;
    int connect[n+1];
    while(nextRouter != 1){
        connect[p] = nextRouter;
        nextRouter = array[nextRouter];
        p--;
    }
     connect[p] =1;
    for(int x = p; x<=n; x++){
        cout << connect[x] << " ";
    }


}