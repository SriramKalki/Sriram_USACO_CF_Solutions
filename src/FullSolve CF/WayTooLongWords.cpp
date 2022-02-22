#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    int wordSize;
    for (int i = 0; i < n; i++) {
        cin >> s;
        wordSize = s.length();
        if (wordSize <= 10) {
            cout << s << endl;
        } else {
            cout << s[0] << wordSize-2 << s[wordSize-1] << endl;

        }

    }


}