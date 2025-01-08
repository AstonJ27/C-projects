#include <iostream>
#include <math.h>
using namespace std;



int main(){

    float a,b,c, det;
    float r1,r2;
    bool complex = false;
    
    cout<< "a: ";
    cin >>a;
    cout<< "b: ";
    cin >>b;
    cout<< "c: ";
    cin >>c;
    if(a == 0){
        cout << "a  != 0"<< endl;
    }else{
            
        det = b*b - 4*a*c;
        if(det > 0){
            r1 = (-b + sqrt(det)) / (2*a);
            r2 = (-b - sqrt(det)) / (2*a);

        }else if(det == 0){
            r1 = (-b) / (2*a);
            r2 = r1;
        }else{
            //complex
            det = abs(det);
            
            r1 = (-b + sqrt(det)) / (2*a);
            r2 = (-b - sqrt(det)) / (2*a);
            complex = true;
        }

    }
        if(complex){
            cout << "r1 = " << r1 <<" i" << endl;
            cout << "r2 = " << r2 <<" i" <<  endl;
        }else{
            cout << "r1 = " << r1 << endl;
            cout << "r2 = " << r2 <<  endl;
        }
    
    return 0;
}