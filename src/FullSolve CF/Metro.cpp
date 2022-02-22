#include <iostream>

using namespace std;

int main(){
    int stations;
    cin >> stations;

    int alice;
    cin >> alice;

    int first[stations];
    int second[stations];
    for(int i=0; i<stations; i++){
        cin >> first[i];


    }
    for(int i=0; i<stations; i++){
        cin >> second[i];

    }
    //start at i=0
    alice--; //indexing
    // first  ------>
    // second <------

   if(first[0] == 0){
       cout << "NO";
       return 0;
   }else{
       if(first[alice] == 1){
           cout << "YES";
           return 0;
       }else{
           if(second[alice] ==0){
               cout << "NO";
               return 0;
           }

           for(int i= alice; i<stations; i++){
                //we are given that second[alice] is 1 due to the return statement, and first[alice] =0
                if(first[i] ==1 && second[i] ==1){
                    cout << "YES";
                    return 0;
                }

           }
           cout << "NO";
           return 0;
       }
   }
}