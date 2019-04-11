#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

const int max_nd_kiekis = 100;
const int max_stud_kiekis = 100;

struct studentas
{
    string vardas;
    string pavarde;
    int nd[max_nd_kiekis];
    int egz;
    int nd_kiekis;
    double galutinis;
    double nd_vidurkis;
    double mediana;
} ;

void read(studentas& stud);
int read_nd(string& ar);
int read_egz();
void skaiciavimai(studentas& stud);
int output();
void generate_data(studentas& stud, int i);

int main ()
{
    studentas stud[max_stud_kiekis];
    string generuoti;
    int i = 0;

    cout << "Norite ivesti studentu duomenis ar generuoti atsitiktinai?(Ivesti-I;Generuoti-G)" << endl;
    cin >> generuoti;

    if(generuoti == "G" || generuoti == "g")
    {
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
        for(int j = 0; j < kiekis; j++)
        {
            generate_data(stud[j], j);
            skaiciavimai(stud[j]);
            i++;
        }
    }
    else
    {
        string next = "T";
        while(next == "T" || next == "t")
        {
            next = "N";
            read(stud[i]);
            skaiciavimai(stud[i]);
            i++;
            cout << "Ar norite ivesti dar viena studenta? (T-taip, N-ne)" << endl;
            cin >> next;
            cout << endl;
        }
    }
    int kuris = output();
    if(kuris == 2)
    {
        for(int j = 0; j < i; j++)
        {
            cout << stud[j].vardas << setw(15) << stud[j].pavarde << setw(20) << stud[j].mediana << endl;
        }
    }
    else
    {
        for(int j = 0; j < i; j++)
        {
            cout << stud[j].vardas << setw(15) << stud[j].pavarde << setw(20) << stud[j].galutinis << endl;
        }
    }

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
        stud.nd[i] = ran;
        stud.nd_vidurkis += ran;
    }
    int random = rand() % 10 + 1;
    stud.egz = random;
    stud.nd_vidurkis = stud.nd_vidurkis / 5;
    stud.nd_kiekis = 5;
}
void read(studentas& stud)
{

    int i = 0;
    cout << "Iveskite studento varda:" << endl;
    cin >> stud.vardas;
    cout << "Iveskite studento pavarde:" << endl;
    cin >> stud.pavarde;
    string ar = "T";

    int ar_teisingas = 0;
    stud.nd_vidurkis = 0;
    while(ar == "T" || ar == "t")
    {
        ar_teisingas = (int)read_nd(ar);
        if(ar_teisingas != -1)
        {
            stud.nd_vidurkis += ar_teisingas;
            stud.nd[i] = ar_teisingas;
            i++;
        }
    }
    stud.nd_kiekis = i;
    stud.nd_vidurkis = stud.nd_vidurkis/i;
    stud.egz = read_egz();

}
int read_nd(string& ar)
{
    int nd;
    cout << "Iveskite namu darbu pazymi:" << endl;
    cin >> nd;
    if(nd < 0 || nd > 10)
    {
        cout << "Klaidingai ivestas pazymys! Bandykite dar karta" << endl;
        cout << "Ar norite ivesti dar viena namu darbu pazymi?(T-taip, N-ne)" << endl;
        cin >> ar;
        return -1;
    }
    else
    {

        cout << "Ar norite ivesti dar viena namu darbu pazymi?(T-taip, N-ne)" << endl;
        cin >> ar;
        return nd;
    }

}
int read_egz()
{
    int egz;
    cout << endl << "Iveskite egzamino pazymi:" << endl;
    cin >> egz;
    if(egz < 0 || egz > 10)
    {
        cout << "Klaidingai ivestas pazymys! Bandykite dar karta" << endl;
        egz = read_egz();
        return egz;
    }
    return egz;
}
void skaiciavimai(studentas& stud)
{
    stud.galutinis = stud.nd_vidurkis * 0.4 + stud.egz * 0.6;
    int pazymiai[stud.nd_kiekis];
    for(int i = 0; i < stud.nd_kiekis; i++)
    {
        pazymiai[i] = stud.nd[i];
    }
    int n = sizeof(pazymiai)/sizeof(pazymiai[0]);
    sort(pazymiai, pazymiai+n);
    if (n % 2 != 0)
    {
        stud.mediana = (double)pazymiai[n/2];
    }
    else
    {
        stud.mediana = (double)(pazymiai[(n-1)/2] + pazymiai[n/2])/2;
    }
}
int output()
{
    int i = 0;
    cout << "Norite skaiciuoti vidurki ar mediana? (Vidurkis = 1;Mediana = 2)" << endl;
    cin >> i;
    if(i == 2)
    {
        cout << "Vardas" << setw(16) << "Pavarde" << setw(30) << "Galutinis (med.)" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "Vardas" << setw(16) << "Pavarde" << setw(30) << "Galutinis (vid.)" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
    }
    return i;
}
