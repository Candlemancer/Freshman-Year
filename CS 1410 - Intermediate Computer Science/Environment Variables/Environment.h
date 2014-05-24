// Jonathan Petersen
// A01236750
// Environment Analysis
// Function header file

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <sstream>

using namespace std;

//Top-level functions
void getEVars(stringstream&);
void getWords(stringstream&);
void analysis(stringstream&);
void userFind(stringstream&);

//Supporting functions
char filterChars(char );
bool filterWords(char*);

//

#endif