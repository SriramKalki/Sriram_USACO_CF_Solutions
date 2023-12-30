#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int even(0),odd(0);
    int current;
    for(int i=0; i<n; i++){
        cin >> current;
        if(current % 2 ==0){
            even++;
        }else{
            odd++;

        }
    }

    int answer =0;
    int c = min(even,odd);
    answer = c *2;
    even -= c;
    odd -= c;

    //if there are no more evens left
    if(even == 0){
        //1 + 1 = 0 mod 2
        //every 3 one's can make a 0 1
        int triples = floor(odd/3);

        odd -= 3 * triples;
        answer += 2*triples;

        if(odd % 3 == 1){
            answer -= 1;
        }else if(odd % 3 == 2){
            answer ++;
        }

    }else{
        //one zero can go after an 0 1
        answer++;
        even--;
        //remaining zeros don't matter (additive property or smth)
    }


    cout << answer;

}