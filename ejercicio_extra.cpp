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
        nombre = " ";
        precio = 0.0;
        cantidad= 0;
    }
    string getnombre(){return nombre;}
    int getcantidad(){return cantidad;}
    float getprecio(){return precio;}
    float getReferencia(){return referenciaprecio;}
    Abarrotes& setNombre(string nombre){this -> nombre=nombre;return *this;}
    Abarrotes& setCantidad(int cantidad){this-> cantidad=cantidad; return *this;}
    Abarrotes& setReferencia(float referencia){this -> referenciaprecio=referencia;return *this;}
    
    

};
class Cliente {
private:
    string nombre;
    int dni;
public:
    Cliente(){
        nombre =" ";
        dni = 0;
    }
    Cliente& setNombreCliente(string nombre){this->nombre=nombre;return *this;}
    Cliente& setDNI(int dni){this->dni=dni;return *this;}
    string getNombre(){return nombre;}
    int getDni(){return dni;}
};

class Ventas{
private:
    float total;
    string metodo_pago;
    int num_abarrotes,num_clientes;
    Abarrotes* producto1[100];
    Cliente* cliente1[100];
public:
    ~Ventas() ;
    ~Ventas(){}
    Ventas(){
        total= 0.0;
        metodo_pago = " "; 
    }
    
    string getMetodo(){return metodo_pago;}
    float PagoTotal(){
        float total = 0.0;
        for (int i = 0; i < num_abarrotes; i++) {
            total += producto1[i]->getprecio() * producto1[i]->getcantidad();
        }
        cout << total;
    }
    void metodoPago(string metodo_pago){this -> metodo_pago=metodo_pago;}
    void agregarAbarrotes(Abarrotes* producto) {
        if (num_abarrotes < 100) {
            producto1[num_abarrotes] = producto;
            num_abarrotes++;
        }
    }

    void agregarCliente(Cliente* cliente) {
        if (num_clientes < 100) {
            cliente1[num_clientes] = cliente;
            num_clientes++;
        }
    }


     void boleta() {
        cout << "--- Cliente ---" << endl;
        if (num_clientes > 0) {
            for (int i = 0; i < num_clientes; i++) {
                cout << "Nombre: " << cliente1[i]->getNombre() << endl;
                cout << "DNI: " << cliente1[i]->getDni() << endl;
                cout << "----------------------" << endl;
            }
        }
        else {
            cout << "No hay clientes registrados." << endl;
        }

        cout << "--- Productos ---" << endl;
        if (num_abarrotes > 0) {
            for (int i = 0; i < num_abarrotes; i++) {
                cout << "Nombre: " << producto1[i]->getnombre() << endl;
                cout << "Cantidad: " << producto1[i]->getcantidad() << endl;
                cout << "Precio: " << producto1[i]->getReferencia() << endl;
                cout << "----------------------" << endl;
            }
        }
        else {
            cout << "No hay productos registrados." << endl;
        }

        cout << "Metodo de pago: " << metodo_pago << endl;
        cout << "Precio total: " << total << endl;
    }

};


int main(){
    Abarrotes* producto1 = new Abarrotes();
    Cliente* cliente1 = new Cliente();
    Ventas* boleta1 =new Ventas();
    string nom_cliente, nom_abarrotes,metodo_pago;
    int opcion,dni,cantidad;
    float precio;
    do
    {
        cout <<"---------MENU---------"<<endl;
        cout <<" 1. Agregar Cliente "<<endl;
        cout <<" 2. Agregar Producto "<<endl;
         cout <<" 3. Metodo de pago "<<endl;
        cout <<" 4. Imprimir boleta "<<endl;
        cout <<" 5. Salir "<<endl;
        cout << "Ingrese una opcion: ";
        cin>>opcion;
        switch (opcion)
        {
        case 1:{
            cout << "Ingrese el nombre del cliente: ";
            cin >> nom_cliente;
            cout << " Ingrese el DNI del cliente: ";
            cin >> dni;
            cliente1->setNombreCliente(nom_cliente).setDNI(dni);
            boleta1->agregarCliente(cliente1);
        }
            break;
        case 2:{
            
            cout << "Ingrese el nombre del producto: ";
            cin >> nom_abarrotes;
            cout << "Ingrese la cantidad: ";
            cin >> cantidad;
            cout << "Ingrese el precio: ";
            cin >>precio;
            producto1->setNombre(nom_abarrotes).setCantidad(cantidad).setReferencia(precio);
            boleta1->agregarAbarrotes(producto1);
            break;
        }
        case 3:{cout << "Ingrese el metodo de pago: ";
            cin >>metodo_pago; 
            boleta1->metodoPago(metodo_pago);
            break;}
        case 4:
            boleta1->boleta();
            boleta1->PagoTotal();
            break;
        case 5:cout << "Fin del programa...";
            break;
        default:cout << "opcion no encontrada";
        }
    } while (opcion !=5);
    

    delete producto1;
    delete cliente1;
    delete boleta1;
    
    return 0;

  
}
