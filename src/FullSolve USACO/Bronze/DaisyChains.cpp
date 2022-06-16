#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
   int N;
   cin >> N;
   int petals[N];
   for(int i=0; i<N; i++){
       cin >> petals[i];


   }
   //now we iterate through all pairs of i and j
   int sum=0;
   int average=0;
   int averageFlower=0;

   for(int i=0; i<N; i++){
       for(int j=i; j<N; j++){
           //first we calculate the average
           for(int n=i; n<=j; n++){
               sum+= petals[n];
           }


           //now we look for an element that is equal to the average
           for(int n=i; n<=j; n++){
               if(petals[n] * (j-i+1) == sum){
                    averageFlower++;
                    break;
               }
           }

           sum=0; //need to reset values for the next iteration

       }
   }

   cout << averageFlower << endl;

   return 0;

}

