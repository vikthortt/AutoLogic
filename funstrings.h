#ifndef _FUNSTRINGS_H_
#define _FUNSTRINGS_H_

#include <string>
#include <stack>
#include <vector>

#include "preposicion.h"

using namespace std;
/* Libreria de funciones de
 * Cadena, similar a las implementadas
 * en el lenguaje JAVA
 */

std::string trim(std::string str);
std::string replaceFor(std::string str, std::string in, std::string out);


void error(string );
int tipoOperador(string );
Preposicion* generaArbolRecursion(stack <string> &);
Preposicion* crearArbol(vector <string> &);
void inorden(Preposicion *);
void inordenCute(Preposicion *);

#endif