#include <iostream> 
    using namespace std;

class rectangulo{
    private:
        int ancho;
        int alto;
    //end

    public:
        rectangulo(int,int); //constructor
        void perimetro();
        void area();
    //end

};//end class

rectangulo::rectangulo(int _ancho, int _alto){
    ancho = _ancho;
    alto = _alto;
}

void rectangulo::perimetro(){
    
    cout <<"perimetro: "<<2*(ancho+alto)<<endl;

}

void rectangulo::area(){

    cout <<"area: "<<ancho*alto<<endl;

}

int main(){
    rectangulo r1(2,4);
    
    r1.area();
    r1.perimetro();
    return 0;
}
/* 
friend std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
        os << "Representación de MyClass";
        return os;
    }

*/