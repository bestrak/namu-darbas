#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std;

const int max_stud_kiekis = 100000;

struct studentas
{
    string vardas;
    string pavarde;
    int egz;
    double galutinis;
    double nd_vidurkis;
} ;

void skaiciavimai(studentas& stud);
void generate_data(studentas& stud, int i);
int tikrinimas(studentas stud);
void out(studentas stud, ofstream& file);

int main ()
{
    vector<studentas> stud;
    int i = 0;

    int kiekis = 0;
    cout << "Kiek norite generuoti duomenu? (max 100000)" << endl;
    try
    {
        while(true)
        {
            cin >> kiekis;
            if(kiekis > 100000)
            {
                cout << "Per didelis norimu duomenu kiekis! Iveskite is naujo" << endl;
            }
            else if (kiekis < 0)
            {
                cout << "Per mazas norimu duomenu kiekis! Iveskite is naujo" << endl;
            }
            else
            {
                break;
            }
        }
    }
    catch(int e)
    {
        cout << "Klaidos nr " << e << endl;
    }
   // auto start = chrono::steady_clock::now();
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
        generate_data(stud[j], j);
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
   // auto end = chrono::steady_clock::now();
    //auto diff = end - start;
    //cout  << "uztruko: " << chrono::duration <double, nano> (diff).count() << " ns" << endl;
    out_neig.close();
    out_teig.close();

    return 0;
}
void generate_data(studentas& stud, int i)
{
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
