#ifndef _PREPOSICION_H_
#define _PREPOSICION_H_

#include "nodo.h"
#include <string>

using namespace std;

class Preposicion : public Nodo{
  public:
    Preposicion(string );
    //Metodos GET
    bool getVerdad();
    Preposicion *getHI();
    Preposicion *getHD();
    bool getVerdadHI();
    bool getVerdadHD();
    char getTipo();

    //Metodos SET


    //Metodos de la clase

    /* Asignar verdad a las preposiciones o evaluar la operación
     * Todavia no funciona, falta implementar el indice... ese es en el arbol o un metodo extra?
     */
    void asignarVerdad(unsigned int );

    //Asignamos el tipo de operador al Nodo
    void asignarTipo(string );

    //realizar la operación
    bool operacion( string , bool , bool);

  private:
    bool verdadero;
    char tipo;
};

#endif
