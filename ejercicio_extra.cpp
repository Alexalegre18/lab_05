#include <iostream>
using namespace std;

class Abarrotes{
private:
    string nombre;
    int cantidad;
    float precio;
    float& referenciaprecio=precio;
public:
    Abarrotes(){
        this -> nombre=nombre;
        this -> cantidad=cantidad;
        this -> precio=precio;
    }
    string getnombre()
    {
        return nombre;
    }
    int getcantidad()
    {
        return cantidad;
    }
    float getprecio()
    {
        return precio;
    }
    float getReferencia(){
        return referenciaprecio;
    }
    Abarrotes& setNombre(string nombre){
        this -> nombre=nombre;
        return *this;
    }
    Abarrotes& setCantidad(int cantidad){this-> cantidad=cantidad; return *this;}
    Abarrotes& setReferencia(float referencia){this -> referenciaprecio=referencia;return *this;}
    
    

};
class Cliente {
private:
    string nombre;
    int dni;
public:
    Cliente(string nombre, int dni){
        this->nombre=nombre;
        this->dni=dni;
    }
    string getNombre(){
        return nombre;
    }
    int getDni(){
        return dni;
    }
};
class Ventas{
private:
    float precio_total;
    string metodo_pago;
    Abarrotes* producto1;
    Cliente* cliente1;
public:
    Ventas(){
        this ->precio_total =precio_total;
        this ->metodo_pago=metodo_pago;
    }
    ~Ventas() {
        delete producto1;
        delete cliente1;
    }

    void setProducto(Abarrotes* producto) {
        this->producto1 = producto;
    }

    void setCliente(Cliente* cliente) {
        this->cliente1 = cliente;
    }

    void boleta(Abarrotes producto){
        cout << "--- producto---"<<endl;
        cout<<producto.getnombre()<<endl;
        cout<<producto.getcantidad()<<endl;
        cout<<producto.getReferencia()<<endl;

    }

};

int main(){
    Abarrotes* producto1 = new Abarrotes();
    producto1->setNombre("Leche").setCantidad(3).setReferencia(3.90);

    Ventas* boleta1 = new Ventas();
    boleta1->setProducto(producto1);
    boleta1->boleta(*producto1);

    Cliente* cliente1 = new Cliente("EladioCarrion", 987654321);
    cout << cliente1->getNombre() << endl;
    cout << cliente1->getDni() << endl;

    delete producto1;
    delete boleta1;
    delete cliente1;

    return 0;

  
}