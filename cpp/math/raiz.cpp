#include <iostream>
#include <math.h>

using namespace std;

int main(){

    int x, y;
    float ans;

    cout << "f(x,y) = sqrt(x)/y^2-1"<<endl;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    if (y == 1){
        cout<<"y no puede ser igual a 1"<<endl;
    }else{
        ans = sqrt(x) / (pow(y, 2) - 1);
        cout << "f(" << x << "," << y << ") = " << ans << endl;
    }
    return 0;
}