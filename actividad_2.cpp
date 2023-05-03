# include <iostream>
#include <string.h>
using namespace std;
class Hijo{
private:
    string nombre;

public:
    Hijo(string nombre){
        this -> nombre =nombre;
    }
  
    string getNombre(){ return nombre; }
};
class Padre{
private:
    string nombre;
    Hijo* hijos[100];
    int numHijos;
public:
    Padre(string nombre){
        this ->nombre=nombre;
        numHijos = 0;
    }
    string getNombre(){
        return nombre;
    }
    void agregarHijo(Hijo* hijo){
        if (numHijos < 100)
        {
            hijos[numHijos++]=hijo;
        }
        else{
            cout <<"No se puede agregar mas hijos"<<endl;
        } 
    }
    void imprimirInfo(){
        cout << "-----------------"<<endl;
        cout <<" ------Hijos------"<< endl;
        cout << "-----------------"<<endl;
        cout << "Nombre del padre: " << nombre << endl; 
        cout << "Numero de hijos: "<< numHijos<<endl;
        
    }
};
int main(){
    Padre* p1 = new Padre("Anton");
    Hijo* h1 = new Hijo("Julian");
    Hijo* h2 = new Hijo("Maria");
    Hijo* h3 = new Hijo("Juan");

    p1->agregarHijo(h1);
    p1->agregarHijo(h2);
    p1->agregarHijo(h3);
    p1 ->imprimirInfo();

}