#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>

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
    vector<studentas> stud;
    int i = 0;

    int kiekis = 0;
    cout << "Kiek norite generuoti duomenu?" << endl;
    try
    {
        cin >> kiekis;
    }
    catch(int e)
    {
        cout << "Klaidos nr " << e << endl;
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

    for(int j = 0; j < kiekis; j++)
    {

        stud.push_back(generate_data(j));
        skaiciavimai(stud[j]);
        int ar = tikrinimas(stud[j]);
        if(ar > 0)
        {
            out(stud[j],out_teig);
        }
        else
        {
            out(stud[j],out_neig);
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
studentas generate_data(int i)
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
