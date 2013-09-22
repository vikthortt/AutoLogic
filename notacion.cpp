#include "notacion.h"

#include <string>
#include <vector>
#include <stack>

#include "funstrings.h"

using namespace std;

//Operadores unicaracter
bool Notacion::isOperator( char oper ){
  if( oper == '^' || oper == 'v' || oper == '~')
      return true;
  else
      return false;
}

//ṡPrioridades arbitrarias?
//Buscar verdaderas prioridades
//O asignar a todos los binarios la misma
int Notacion::prioridad(string oper){
  if(oper == "~")
      return 0;
  else if( oper == "^" )
      return 1;
  else if( oper == "v" )
      return 1;
  else if( oper == "->" )
      return 1;
  else if( oper == "<->" )
      return 1;
  else
      return 5;
}

//Evaluar la prioridad de los operadores
//creo :S
void Notacion::evalOper( vector<string> &ep, stack<string> &pila, string &exp ){
  bool hecho = false;
  do{
      if( pila.empty() || prioridad(pila.top()) >= prioridad(exp) ){
          pila.push(exp);
          hecho = true;
      } else  {
          ep.push_back(pila.top());
          pila.pop();
      }
  }while(!hecho);

}

//ṡPor qué no directamente al árbol?
//Pues porque no supe como xD
int Notacion::postfija(string in, vector <string> &ret){
  stack <string> pila;
  string saux;
  in = trim(in);

  while( in.length() > 0 ){

      if( in.at(0) == '-' ){ //  ->
          if(in.at(1) == '>'){
              saux = "->";
              in = replaceFor(in, saux, "");
              evalOper(ret, pila, saux);
          } else {
              error("Error de sintaxis");
              return 1;
          }
      } else if( in.at(0) == '<' ){  // <->
          if(in.at(1) == '-'){
              if( in.at(2) == '>'){
                  saux = "<->";
                  in = replaceFor(in, saux, "");
                  evalOper(ret, pila, saux);
              }else{
                  error("Error de sintaxis");
                  return 1;
              }
          } else {
              error("Error de sintaxis");
              return 1;
          }
      } else if( in.at(0) == '(' ){  // Parentesis que abre
          in = replaceFor(in, "(", "");
          pila.push("(");
      } else if( in.at(0) == ')' ){  // Parentesis que cierra
          in = replaceFor(in, ")", "");
          while( !pila.empty() && pila.top() != "("){
              ret.push_back( pila.top() );
              pila.pop();
          }
          pila.pop();
      } else if( isOperator( in.at(0) ) ){  // Operadores unicaracter ( ^, v, ~ )
          saux =  in.at(0);
          in = in.substr( 1, in.size() );
          evalOper(ret, pila, saux);
      } else{     // Es preposicion simple
          saux =  in.at(0);
          in = replaceFor(in, saux, "");
          ret.push_back(saux);
      }
      in = trim(in);
  }

  while( !pila.empty() ){
      ret.push_back( pila.top() );
      pila.pop();
  }

  return 0;
}
