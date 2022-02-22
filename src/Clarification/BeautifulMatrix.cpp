#include<iostream>
using namespace std;
int main() {
    int array[5][5];
    int currentNum = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> array[i][j];
            if(array[i][j] ==1){

                cout << abs(2-i) + abs(2-j) << endl;

            }

        }
    }



}


