#include <iostream>
#include <cstdio>


using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("word");
    int n,k;
    cin >> n >> k;
    string array[n];

    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    int currLine=0;

    for(int i=0; i<n; i++){
        if(currLine + array[i].size() <=k){
            cout << array[i];
            currLine += array[i].size();
            if(i!= n-1){
                if(array[i+1].length() + currLine <=k)
                cout << " ";
            }
        }else{
            cout << endl << array[i];
            currLine = array[i].length();
            if(i!= n-1){
                if(array[i+1].length() + currLine <=k)
                    cout << " ";
            }
        }



    }




}