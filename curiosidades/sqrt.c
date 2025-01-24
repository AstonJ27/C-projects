//Algorithm nth root for binary search
#include <stdio.h>

double nthRoot(double radicand, int n){

    double bottom = 0;
    double top = radicand;
    double center;
    double epsilon = 0.00000001;    // desired precision

    // if the radicand is less to 1, adjust the range

    if(radicand < 1){
        top = 1;
    }

    while(top-bottom > epsilon){
        center = (top+ bottom)/2;
        double power = 1;

        // calculate center^n
        for(int i = 0; i < n; i++){
            power *= center;
        }

        if(power < radicand){
            bottom = center;    //search top half
        }else{
            top = center;      //search lower half
        }
    }
    
    return (bottom + top) / 2;  // return average as result
}

int main(){
    double radicand = 4.0;
    double squareRooth = nthRoot(radicand, 2);
    //double cubeRooth = nthRoot(radicand, 3);

    printf("square root of %.2f is %.8f\n", radicand,squareRooth);
    //printf("cube root of %.2f is %.8f\n", radicand,cubeRooth);


    return 0;
}