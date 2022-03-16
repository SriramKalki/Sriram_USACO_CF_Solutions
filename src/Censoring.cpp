#include <iostream>
#include <vector>

using namespace std;
int main(){
    string s;
    string key;
    cin >> s >> key;
    bool array[s.length()];
    for(int i=0; i<s.length(); i++){
        array[i] = true;
    }
    bool censored = false;
    while(!censored){
        for(int i=0; i< 1; i++) {
            bool deletes = false;
            string curr = "";
            int deleted[key.length()];
            int x(0);
            for (int j = 0; j < s.length(); j++) {
                if (array[j]) {
                    curr += s[j];
                    deleted[x] = j;
                    x++;

                } else {
                    continue;
                }

                if (curr.length() == 3) {
                    if (curr.compare(key) == 0) {
                        for (int k = 0; k < key.length(); k++) {
                            array[deleted[k]] = false;
                        }
                        deletes = true;
                        break;
                    }
                }
            }

            if (!deletes) {
                censored = true;
            }else{
                i--;
            }
        }

    }



}