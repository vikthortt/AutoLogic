#include "nodo.h"
#include <string>


Nodo::Nodo (std::string v){
   valor = v;
   hijo_der = NULL;
   hijo_izq = NULL;
}

//Metodos GET
std::string Nodo::getValor(){ return valor;}

//Metodos SET
void Nodo::setValor(std::string v){ valor = v;}
void Nodo::setHD(Nodo* hd){ hijo_der = hd;}
void Nodo::setHI(Nodo* hi){ hijo_izq = hi;}
