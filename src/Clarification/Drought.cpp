#include <iostream>
#include <vector>


using namespace std;


int main(){

    int t;
    cin >>t;

    for(int i=0; i<t; i++){
        int n,x;
        cin >>n;
        int maxX =1000000000;

        vector<int> base(n);
        vector<int> array(n);
        for(int j=0; j<n; j++){
            base[j]= 0;
            cin >> array[j];
            maxX = min(array[j],maxX);
        }

        if(n==1 || n==2){
            if(n==1){
                cout<<0<<endl;
            }else{
                if(array[0] !=array[1]){
                    cout << -1 << endl;
                }else{
                    cout <<0 << endl;
                }
            }
        }else{
            bool check = false;
            bool fail = false;
            int sum=0;
            vector<int> values(n-1);
            for(int j=maxX; j>=0; j--){
                fail = false;
                values[0] = array[0]-j;
                sum = values[0];
                if(values[0] <0){
                    fail = true;
                }
                if(!fail) {
                    for (int k = 1; k < n - 1; k++) {
                        values[k] = array[k] - values[k - 1] - j;
                        if (values[k] < 0) {
                            fail = true;
                            break;
                        }
                        sum+= values[k];
                    }

                }
                if(values[n-2] + j != array[n-1]){
                    fail = true;
                }
                if(!fail){
                    cout << 2*(sum) << endl;
                    break;
                }
            }
            if(fail){
                cout << -1 << endl;
            }
        }

    }


}