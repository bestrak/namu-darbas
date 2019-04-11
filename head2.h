#ifndef HEAD2_H_INCLUDED
#define HEAD2_H_INCLUDED
#include "head.h"
#include <iomanip>
#include <vector>

void read(studentas& stud);
int read_nd(std::string& ar);
int read_egz();
void skaiciavimai(studentas& stud);
int output();
void read_from_file(std::string eilute, studentas& stud);
std::vector<std::string> split(const std::string& s, char delimiter);

#endif // HEAD2_H_INCLUDED
