#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <deque>

using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    int egz;
    double galutinis;
    double nd_vidurkis;
} ;

void skaiciavimai(studentas& stud);
studentas generate_data(int i);
int tikrinimas(studentas stud);
void out(studentas stud, ofstream& file);

int main ()
{
    //vector<studentas> stud;
    //list<studentas> stud;
    deque<studentas> stud;

    int i = 0;
    int kiekis = 100000;
    ifstream data;
    data.open("visi.txt");
    string line;
    for(int i = 0; i < kiekis; i++)
    {
        studentas naujas;
        data >> line;
        naujas.vardas = line;
        data >> line;
        naujas.pavarde = line;
        data >> line;
        naujas.nd_vidurkis = stod(line);
        data >> line;
        naujas.egz = stoi(line);
        stud.push_back(naujas);
    }

    auto start = chrono::steady_clock::now();
    ofstream out_teig;
    ofstream out_neig;
    out_teig.open("teigiami.txt");
    out_neig.open("neigiami.txt");

    out_neig << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (vid.)" << endl;
    out_neig << "-----------------------------------------------------------------------" << endl;

    out_teig << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (vid.)" << endl;
    out_teig << "-----------------------------------------------------------------------" << endl;

    //for (list<studentas>::iterator it = stud.begin(); it != stud.end(); it++)
    for (deque<studentas>::iterator it = stud.begin(); it != stud.end(); it++)
    //for (vector<studentas>::iterator it = stud.begin(); it != stud.end(); it++)
    {

        skaiciavimai(*it);
        int ar = tikrinimas(*it);
        if(ar > 0)
        {
            out(*it,out_teig);
        }
        else
        {
            out(*it,out_neig);
        }
        i++;
    }
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout  << "Uztruko: " << chrono::duration <double, milli> (diff).count() << " milli s" << endl;
    out_neig.close();
    out_teig.close();

    return 0;
}
studentas get_data(int i, ifstream data)
{
    studentas stud;
    stud.nd_vidurkis = 0;
    stud.vardas = "vardas" + to_string(i);
    stud.pavarde = "pavarde" + to_string(i);
    for(int i = 0; i < 5; i++)
    {
        int ran = rand() % 10 + 1;
        stud.nd_vidurkis += ran;
    }
    int random = rand() % 10 + 1;
    stud.egz = random;
    stud.nd_vidurkis = stud.nd_vidurkis / 5;
    return stud;
}
void skaiciavimai(studentas& stud)
{
    stud.galutinis = stud.nd_vidurkis * 0.4 + stud.egz * 0.6;
}
int tikrinimas(studentas stud)
{
    if(stud.galutinis < 5)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
void out(studentas stud, ofstream& file)
{
    file << left << setw(15) << stud.vardas << setw(15) << stud.pavarde << right << setw(5) << stud.galutinis << endl;
}
