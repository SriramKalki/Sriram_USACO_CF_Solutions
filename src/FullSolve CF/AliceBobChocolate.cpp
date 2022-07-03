#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int array[n];
    bool a[n],b[n];
    for(int i=0; i<n; i++){
        cin >> array[i];
        a[i] = false; b[i] = false; //true if the chocolate has been bit off
    }
    int left(0), right(n-1);

    while(left <= right){
        if(left == right){
            if(b[right]){
                right--;
                break;
            }
            left++;
            break;
        }
        int t = min(array[left], array[right]);
        array[left] -= t; a[left] = true;
        array[right] -= t; b[right] = true;

        if(array[left] == 0){
            left++;
        }

        if(array[right] == 0){
            right--;
        }
    }

    int a1 = left;
    int b1 = n - left;
    cout << a1 << " " << b1;
}