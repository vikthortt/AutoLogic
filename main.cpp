#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "nodo.h"
#include "notacion.h"
#include "funstrings.h"

/*
*   NOTA 1:
*   VICTOR TORRES TORRES
*   (12 DE ABRIL 2013)
*
*   Ya funciona la notacion polaca, NO MUEVAS NADA DE:
*   - string trim(string str)
*   - string replaceFor(string str, string in, string out)
*   - bool isOperator( char oper )
*   - int prioridad(string oper)
*   - void evalOper( vector<string> &ep, stack<string> &pila, string &exp )
*   - postfija(string in, vector <string> &ret)
*
*   Implementar función para crear el indice de preposiciones
*   -
*
*/

using namespace std;


int main()
{
    vector <string> polaca;
    string in;

    Notacion tn;

    cout << "Que expresion deseas convertir?" << endl << "> ";
    getline(cin, in);

    if( tn.postfija(in, polaca) == 0)
        for(unsigned int i=0; i<polaca.size(); i++){
            cout << polaca[i] ;
        }

    Preposicion *raiz = crearArbol(polaca);
    cout << endl << endl;
    inorden(raiz);
    cout << endl << endl;
    inordenCute(raiz);


    return 0;
}
