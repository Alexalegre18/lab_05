#include <iostream>
using namespace std;

class Cirujia;

class Cajero{
public:
    int codigo_cajero;
    void modificarCosto(Cirujia &c);
    void consultarCosto(Cirujia &C);
    Cajero(){
        codigo_cajero = 0;
    }
};


class Cirujia {   
public:
    int precio;
    int& referenciaCosto = precio;
    string nombre_cirujano;
    string nombre_intervencion;
    friend void Cajero::consultarCosto(Cirujia &c);
    friend void Cajero::modificarCosto(Cirujia &c);
    Cirujia(){
        precio =0;
        nombre_cirujano =" ";
        nombre_intervencion =" ";
    }
};

void Cajero::consultarCosto(Cirujia &c){
    cout <<"El costo de la cirujia es: "<<c.precio<<endl;
}
void Cajero::modificarCosto(Cirujia &c){
    cout << "El costo modificado es: " << c.referenciaCosto;
}

int main(){
    int Nuevocosto;
    string desicion;
    Cirujia c1;
    c1.nombre_cirujano = "Alberto Delgado";
    c1.nombre_intervencion ="operacion de apendice";
    c1.precio = 1700;
    Cajero caja1;
    caja1.consultarCosto(c1);
    cout<<"Desea modificar el costo: ";
    cin >>desicion;
    if (desicion == "si"){
        cout << "Ingrese el nuevo costo: ";
        cin >> Nuevocosto;
        c1.referenciaCosto = Nuevocosto;
        caja1.modificarCosto(c1);
    }
    else if (desicion=="no"){
        cout <<"accion terminada";
    }


}
