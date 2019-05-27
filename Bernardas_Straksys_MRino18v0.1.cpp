#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int max_nd_kiekis = 100;

struct studentas
{
    string vardas;
    string pavarde;
    vector <int>nd;
    int egz;
    int nd_kiekis;
    double galutinis;
    double nd_vidurkis;
    double mediana;
} ;

studentas read();
int read_nd(string& ar);
int read_egz();
void skaiciavimai(studentas& stud);
int output();

int main ()
{
    vector<studentas> stud;
    int i = 0;
    string next = "T";
    while(next == "T" || next == "t")
    {
        next = "N";
        stud.push_back(read());
        skaiciavimai(stud[i]);
        i++;
        cout << "Ar norite ivesti dar viena studenta? (T-taip, N-ne)" << endl;
        cin >> next;
        cout << endl;
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
studentas read()
{

    studentas stud;
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
            stud.nd.push_back(ar_teisingas);
            i++;
        }
    }
    stud.nd_kiekis = i;
    stud.nd_vidurkis = stud.nd_vidurkis/i;
    stud.egz = read_egz();
    return stud;
}
int read_nd(string& ar)
{
    int nd;
    cout << "Iveskite namu darbu pazymi:" << endl;
    while(true)
    {
        cin >> nd;
        try
        {
            if(cin.fail())
            {

                cout << "Klaidingai ivestas pazymys! Programa nutraukiama" << endl;
                throw "error";
                cout << "Ar norite ivesti dar viena namu darbu pazymi?(T-taip, N-ne)" << endl;
                cin >> ar;
                return -1;
            }
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
        catch( char* error)
        {
            cout << "Ar norite ivesti dar viena namu darbu pazymi?(T-taip, N-ne)" << endl;
            cin >> ar;
            return -1;
            break;
        }
    }
    return -1;
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
        cout << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (med.)" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (vid.)" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
    }
    return i;
}
