#include "preposicion.h"

#include <string>
#include "nodo.h"

using namespace std;

//Constructor
Preposicion::Preposicion(string v): Nodo(v){
  asignarTipo(v);
}
//Metodos GET
bool Preposicion::getVerdad(){return verdadero;}
Preposicion *Preposicion::getHI(){return (Preposicion *)hijo_izq;}
Preposicion *Preposicion::getHD(){return (Preposicion *)hijo_der;}
bool Preposicion::getVerdadHI(){return getHI()->getVerdad();}
bool Preposicion::getVerdadHD(){return getHD()->getVerdad();}
char Preposicion::getTipo(){return tipo;}

//Metodos SET



//Metodos de la clase

/* Asignar verdad a las preposiciones o evaluar la operación
* Todavia no funciona, falta implementar el indice... ese es en el arbol o un metodo extra?
*/
void Preposicion::asignarVerdad(unsigned int mascara){
  if( getTipo() == 'P' ){
      unsigned int aux = 1;
//            aux = aux << (indice( getValor() ) - 1 );
      verdadero = ((mascara & aux) > 1)?true:false;
  } else {
      if(getValor() != "~")
          verdadero = operacion( getValor(), getVerdadHI(), getVerdadHD() );
      else
          verdadero = ! getVerdadHD();
  }
}

//Asignamos el tipo de operador al Nodo
void Preposicion::asignarTipo(string v){
  if(v == "->" || v == "^" || v == "v" || v == "<->" || v == "~")
      tipo = 'O';
  else
      tipo = 'P';
}

//realizar la operación
bool Preposicion::operacion( string oper, bool operI, bool operD){
  if( oper == "^")
      return operI && operD;
  else if( oper == "v")
      return operI || operD;
  else if( oper == "->")
      return (operI == true && operD == false)?false:true;
  else // oper == "<->"
      return operI == operD;
}

