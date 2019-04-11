#include <iostream>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
#include "head.h"
#include "head2.h"

using namespace std;


const int max_nd_kiekis = 100;
const int max_stud_kiekis = 100;

int main ()
{
    studentas stud[max_stud_kiekis];
    string ar_failas;
    int i = 0;

    cout << "Norite ivesti studentu duomenis ar importuoti is failo?(Ivesti-I, Failas-F)" << endl;
    cin >> ar_failas;

    if(ar_failas == "F" || ar_failas == "f")
    {
        ifstream data_file;
        try
        {
            data_file.open ("kursiokai.txt");
            int n = 0;
            string eilute;
            data_file >> eilute;
            while (data_file >> eilute)
            {
                read_from_file(eilute, stud[n]);
                skaiciavimai(stud[n]);
                i++;
                n++;
            }
            data_file.close();
        }
        catch(int e)
        {
            cout << "Error number " << e << endl;
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
            cout << left << setw(15) <<stud[j].vardas << setw(15) << stud[j].pavarde << right<< setw(5) << stud[j].mediana << endl;
        }
    }
    else
    {
        for(int j = 0; j < i; j++)
        {
            cout << left << setw(15) << stud[j].vardas << setw(15) << stud[j].pavarde << right << setw(5) << stud[j].galutinis << endl;
        }
    }

    return 0;
}
