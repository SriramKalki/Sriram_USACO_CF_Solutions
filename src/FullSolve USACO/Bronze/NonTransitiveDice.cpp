#include <iostream>

using namespace std;



int firstCalculateOPR(int a[], int b[]){
    int aopr(0),bopr(0);

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(a[i] >b[j]){
                aopr++;
            }else if(b[j] > a[i]){
                bopr++;
            }
        }
    }

    if(aopr > bopr){
        return 69;
    }else if(bopr > aopr){
        return 420;
    }else{
        return 69420;
    }
}
int calculateOPR(int a[], int w, int x, int y, int z){
    int c[] = {w,x,y,z};
    if(firstCalculateOPR(a,c) == 69){
        return 69;
    }else if(firstCalculateOPR(a,c) == 420){
        return 420;
    }
    return 0;
}


int main(){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int a[4],b[4];
        bool invalid = false;
        bool ainit = false;
        for(int j=0; j<4; j++){
            cin >> a[j];
        }
        for(int j=0; j<4; j++){
            cin >> b[j];
        }
        int awin(0),bwin(0),cwin(0),p;
        p= firstCalculateOPR(a,b);
        if(p == 69){
            awin++;
            ainit= true;
        }else if(p == 420){
            bwin++;
            ainit= false;
        }else{
            cout << "no"<< endl;
            invalid = true;
        }

        bool found = false;
        if(!invalid){

            for(int w=1; w<=10; w++){
                for(int x=w; x<=10; x++){
                    for(int y=x; y<=10; y++){
                        for(int z=y; z<=10; z++){
                            p=calculateOPR(a,w,x,y,z);

                            if(p == 69){
                                //a wins here
                                awin++;
                            }else if(p == 420){
                                //c wins here
                                cwin++;
                            }
                            p=calculateOPR(b,w,x,y,z);
                            if(p == 69){
                                //b wins here
                                bwin++;
                            }else if(p == 420){
                                //c wins here
                                cwin++;
                            }

                            if(awin == bwin && bwin == cwin && awin ==1){
                                found = true;
                                cout << "yes" << endl;
                                break;
                            }else{
                                if(ainit){
                                    awin =1;
                                    bwin =0;
                                    cwin =0;
                                }else{
                                    awin=0;
                                    bwin=1;
                                    cwin=0;
                                }
                            }

                        }
                        if(found){
                            break;
                        }
                    }
                    if(found){
                        break;
                    }
                }
                if(found){
                    break;
                }


            }
            if(!found){
                cout <<"no"<<endl;
            }
        }

    }




}