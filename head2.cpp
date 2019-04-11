#include "head2.h"
#include <iomanip>
#include <iostream>
#include <bits/stdc++.h>

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
void read_from_file(std::string eilute, studentas& stud)
{
    std::vector<std::string> data = split(eilute, ';');

    stud.nd_vidurkis = 0;
    stud.vardas = data[0];
    stud.pavarde = data[1];
    for(int i = 0; i < 5; i++)
    {

        stud.nd.push_back(stoi(data[2+i]));
        stud.nd_vidurkis += stoi(data[2+i]);
    }
    stud.egz = stoi(data[7]);
    stud.nd_vidurkis = stud.nd_vidurkis / 5;
    stud.nd_kiekis = 5;
}
int read_nd(std::string& ar)
{
    int nd;
    std::cout << "Iveskite namu darbu pazymi:" << std::endl;
    while(true)
    {
        std::cin >> nd;
        try
        {
            if(std::cin.fail())
            {

                std::cout << "Klaidingai ivestas pazymys! Programa nutraukiama" << std::endl;
                throw "error";
                std::cout << "Ar norite ivesti dar viena namu darbu pazymi?(T-taip, N-ne)" << std::endl;
                std::cin >> ar;
                return -1;
            }
            if(nd < 0 || nd > 10)
            {
                std::cout << "Klaidingai ivestas pazymys! Bandykite dar karta" << std::endl;
                std::cout << "Ar norite ivesti dar viena namu darbu pazymi?(T-taip, N-ne)" << std::endl;
                std::cin >> ar;
                return -1;
            }
            else
            {
                std::cout << "Ar norite ivesti dar viena namu darbu pazymi?(T-taip, N-ne)" << std::endl;
                std::cin >> ar;
                return nd;
            }
        }
        catch( char* error)
        {
            std::cout << "Ar norite ivesti dar viena namu darbu pazymi?(T-taip, N-ne)" << std::endl;
            std::cin >> ar;
            return -1;
            break;
        }
    }
    return -1;
}
int read_egz()
{
    int egz;
    std::cout << std::endl << "Iveskite egzamino pazymi:" << std::endl;
    std::cin >> egz;
    if(egz < 0 || egz > 10)
    {
        std::cout << "Klaidingai ivestas pazymys! Bandykite dar karta" << std::endl;
        egz = read_egz();
        return egz;
    }
    return egz;
}
void read(studentas& stud)
{

    int i = 0;
    std::cout << "Iveskite studento varda:" << std::endl;
    std::cin >> stud.vardas;
    std::cout << "Iveskite studento pavarde:" << std::endl;
    std::cin >> stud.pavarde;
    std::string ar = "T";

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
    std::sort(pazymiai, pazymiai+n);
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
    std::cout << "Norite skaiciuoti vidurki ar mediana? (Vidurkis = 1;Mediana = 2)" << std::endl;
    std::cin >> i;
    if(i == 2)
    {
        std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(15) << "Galutinis (med.)" << std::endl;
        std::cout << "-----------------------------------------------------------------------" << std::endl;
    }
    else
    {
        std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(15) << "Galutinis (vid.)" << std::endl;
        std::cout << "-----------------------------------------------------------------------" << std::endl;
    }
    return i;
}
