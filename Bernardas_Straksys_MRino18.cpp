#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int max_nd_kiekis = 100;
const int max_stud_kiekis = 100;

struct studentas {
  string vardas;
  string pavarde;
  vector <int>nd;
  int egz;
  double galutinis;
  double vidurkis;
  double mediana;
} ;

void read(studentas& stud);
int read_nd(string& ar);
int read_egz();
void skaiciavimai(studentas& stud);
int output();

int main ()
{
studentas stud[max_stud_kiekis];
  int i = 0;
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
  int kuris = output();
    if(kuris == 2){
  for(int j = 0; j < i; j++)
    {
        cout << stud[j].vardas << setw(15) << stud[j].pavarde << setw(20) << stud[j].mediana << endl;
    }
    }
    else{
            for(int j = 0; j < i; j++){
        cout << stud[j].vardas << setw(15) << stud[j].pavarde << setw(20) << stud[j].galutinis << endl;
            }
    }

  return 0;
}
void read(studentas& stud){

    int i = 0;
  cout << "Iveskite studento varda:" << endl;
  cin >> stud.vardas;
  cout << "Iveskite studento pavarde:" << endl;
  cin >> stud.pavarde;
  string ar = "T";

  int ar_teisingas = 0;
  stud.vidurkis = 0;
  while(ar == "T" || ar == "t")
  {
      ar_teisingas = (int)read_nd(ar);
      if(ar_teisingas != -1){
    stud.vidurkis += ar_teisingas;
      stud.nd.push_back(ar_teisingas);
      i++;
      }
  }
  stud.vidurkis = stud.vidurkis/i;
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
void skaiciavimai(studentas& stud){
    stud.galutinis = stud.vidurkis * 0.4 + stud.egz * 0.6;

    int n = sizeof(stud.nd)/sizeof(stud.nd[0]);
    //sort(stud.nd, stud.nd+n);

    if (n % 2 != 0) {
       stud.mediana = (double)stud.nd[n/2];
    }
    else{
    stud.mediana = (double)(stud.nd[(n-1)/2] + stud.nd[n/2])/2;
    }
}
int output()
{
    int i = 0;
    cout << "Norite skaiciuoti vidurki ar mediana? (Vidurkis = 1;Mediana = 2)" << endl;
    cin >> i;
    if(i == 2){
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
