#include "funstrings.h"
#include <string>
#include <vector>
#include <stack>
#include <iostream>

#include "preposicion.h"

using namespace std;

//Borramos blancos iniciales
string trim(string str){
    int cnt=0;
    int size = str.size();
    if(size > 0){
        char aux;
        aux = str.at(cnt);

        while( aux == ' ' )
            aux = str.at(++cnt);
        str = str.substr(cnt,size);
    }
    return str;
}

//Reemplazamos la primera aparicion de in por out en str
//ṡQué dijo? e.e
string replaceFor(string str, string in, string out){
    string ret = "";
    unsigned int size_to_replace = in.size();
    unsigned int size_for_replace = out.size();
    unsigned int i, j;
    bool cambio = false;
    if(str.size() > 0)
    for(i=0; i<str.size(); i++){
        if(!cambio){
            if( str[i] != in[0] )
                ret += str[i];
            else if( !cambio){
                bool encontrado=true;
                for(j=0; j<size_to_replace; j++){
                    if( str[i+j] != in[j] )
                        encontrado = false;
                }
                if(encontrado){
                    i += size_to_replace-1;
                    for(j=0; j<size_for_replace; j++){
                        ret += out[j];
                    }
                    cambio = true;
                }
            }
        }else{
            ret += str[i];
        }
    }
    return ret;
}


/*Resto de funciones auxiliares */

//No sirve de mucho xD
void mostrarPila(stack <string> p){
    while(!p.empty()){
        cout << p.top() << ", ";
        p.pop();
    }
}

//Mostramos el error correspondiente
void error(string e){
    cout << endl << e << endl;
}


int tipoOperador(string arg){
    if( arg == "->" || arg == "<->" || arg == "^" || arg == "v")
        return 2;
    else if( arg == "~")
        return 1;
    else
        return 0;

}

Preposicion* generaArbolRecursion(stack <string> &premisa){
    Preposicion *aux=NULL;
    string elem = premisa.top();
    premisa.pop();
    switch( tipoOperador(elem) ){
    case 0:
        aux = new Preposicion(elem);
        break;
    case 1:
        aux = new Preposicion(elem);
        aux->setHD( generaArbolRecursion(premisa) );
        break;
    case 2:
        aux = new Preposicion(elem);
        aux->setHD( generaArbolRecursion(premisa) );
        aux->setHI( generaArbolRecursion(premisa) );
        break;
    }
    return aux;
}

Preposicion* crearArbol(vector <string> &cadena){
    stack <string> pila;
    Preposicion *raiz;
    for(unsigned int i=0; i<cadena.size(); i++){
        pila.push(cadena.at(i));
    }
    raiz = generaArbolRecursion( pila );
    return raiz;
}


void inorden(Preposicion *tipo){
    if(tipo == NULL)
        return;
    inorden(tipo->getHI() );
    cout << tipo->getValor() << " ";
    inorden(tipo->getHD());
}

void inordenCute(Preposicion *tipo){
    if(tipo == NULL)
        return;
    if(tipo->getHI() != NULL )
        cout << "( ";
    inordenCute(tipo->getHI() );
    cout << tipo->getValor() << " ";
    inordenCute(tipo->getHD());
    if(tipo->getHD() != NULL)
        cout << ") ";
}


