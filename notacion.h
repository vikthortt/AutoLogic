#ifndef _NOTACION_H_
#define _NOTACION_H_

#include <string>
#include <vector>
#include <stack>

using namespace std;

//Clase para la Notación Polaca
class Notacion{
  public:
    //Operadores unicaracter
    bool isOperator( char  );

    //ṡPrioridades arbitrarias?
    //Buscar verdaderas prioridades
    //O asignar a todos los binarios la misma
    int prioridad(string );

    //Evaluar la prioridad de los operadores
    //creo :S
    void evalOper( vector<string> &, stack<string> &, string & );

    //ṡPor qué no directamente al árbol?
    //Pues porque no supe como xD
    int postfija(string , vector <string> &);

};


#endif