#include <iostream>
using namespace std;


class Miclase
{
    private:
    int atributoEntero;
    float atributoFlotante;
    public:
    Miclase(int i, float f){
        atributoEntero = i;
        atributoFlotante = f;
    }
    ~Miclase(){
        cout<<"Ejecutando destructor..."<<endl;
    }
    void mostrar(){
        cout<<"Atributo entero: "<<atributoEntero<<endl;
        cout<<"Atributo flotante: "<<atributoFlotante<<endl;
    }
};
int main(){
    Miclase *clase1 = new Miclase(10,23.5);
    clase1->mostrar();
    delete clase1;
    return 0;


}
