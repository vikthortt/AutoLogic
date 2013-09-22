#ifndef _NODO_H_
#define _NODO_H_

#include <string>


using namespace std;

class Nodo{

    protected:
        string valor;
        void *hijo_der;
        void *hijo_izq;

    public:
        Nodo (string );

        //Metodos GET
        string getValor();
        virtual Nodo *getHD(){ return (Nodo *)hijo_der;}
        virtual Nodo *getHI(){ return (Nodo *)hijo_izq;}

        //Metodos SET
        void setValor(string v);
        void setHD(Nodo* );
        void setHI(Nodo* );
};


#endif