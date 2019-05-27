# Duomenu apdorojimas
Kiekvienoje šakoje yra atskirai kiekvienai versijai kurtas kodas + duomenų failai
****************************************************************************************
*v0.1*
Yra dvi versijos v0.1 versijos, t.y. su array ir su vector tipo konteineriais
Studentų duomenys yra įvedami ranka konsolėje

*v0.2*
Pridėta galimybė paimti studentų duomenis iš duomenų failų

*v0.3*
Išskirtas .h (headerio) failas, panaudoti try - catch blokai

*v0.4*
Pridėta galimybė generuoti atsitiktinius studentų duoemnis nurodant jų kiekį
Įvesti duomenys išskirstomi į "patenkinamus" ir "nepatenkinamus" pažymius gavusių studentų sąrašus, kurie išvedami į rezultatų failus "teigiami.txt" ir "neigiami.txt"
Atlikta programos greičio spartos analizė

Rezultatai:

| Eilučių kiekis | Laikas(ms)    |
| ------------- | ------------- |
| 10            | 3,001       |
| 100           | 6,001       |
| 1000          | 48,973       |
| 10000         | 482,74       |
| 100000        | 4367,91       |

Iš gautų rezultatų matome, kad didėjant duomenų kiekiui išauga ir programos veikimo laikas, tai gi galime teigti, kad programos veikimo laikas yra tiesiogiai proporingas duomenų kiekiui

*v0.5*
Atliktas testavimas su skirtingais konteinerių tipais: vector, list, deque

Rezultatai:
Atliktas trimas su 10000 ir 100000 eilučių
(Lentelėse pateiktas laikas yra suvidurkintas iš 3 bandymų)

Su 10000 eilučių: 

| Tipas         | Laikas(ms)    | Vieta pagal greitį |
| ------------- | ------------- | ----------------- |
| vector        | 323,886       | 2 |
| list          | 330,263       | 3 |
| deque         | 306,632       | 1 |

Su 100000 eilučių: 

|     Tipas     |   Laikas(ms)  | Vieta pagal greitį |
| ----------- | ----------- | ----------------- |
|     vector    |    3392,0     | 3 |
|      list     |    3180,38    | 1 |
|     deque     |    3354,8     | 2 |


Iš gautų rezultatų matome, kad programa letėja priklausomai nuo duomenų kiekio. Visi konteineriai veikia panašiu greičiu, tačiau su daugiau duomenų list tipo konteineris veikė greičiausiai, kai vector tipo konteineris veikė lėčiausiai

*v1.0*
Atliktas tyrimas su dviejomis strategijomis:
1. Kai "teigiami" ir "neigiami" pažymiai yra išskirstomi į du naujus konteinerius
2. Kai "teigiami" pažymiai yra paliekami sename konteineryje, o "neigiami" perkeliami į naują ir ištrinami iš senojo

Rezultatai:

Atliktas trimas su 10000 eulučių, nes su 100000 nebuvo sulaukta kada programa baigs darbą (veikė ilgiau nei 5 min)
(Lentelėse pateiktas laikas yra suvidurkintas iš 3 bandymų)

Su 10000 eilučių pagal pirmą strategiją (išskirstoma į du naujus konteinerius): 

| Tipas         | Laikas(ms)    | Vieta pagal greitį |
| ------------- | ------------- | ----------------- |
| vector        | 3432,827      | 3 |
| list          | 3365,297      | 2 |
| deque         | 3216,093      | 1 |

Su 10000 eilučių pagal antrą strategiją (išskirstoma į vieną naują konteinerį ir trynama iš seno): 

| Tipas         | Laikas(ms)    | Vieta pagal greitį |
| ------------- | ------------- | ----------------- |
| vector        | 11621,07      | 3 |
| list          | 934,0263      | 1 |
| deque         | 5452,027      | 2 |

Iš gautų rezultatų matome, kad naudojant trynimo operaciją smarkiai suletėja programos veikimas su vector tipo konteineriu, šiek tiek sulėtėja su deque tipo konteineriu, bet pagreitėja su list tipo konteineriu.
************************************************************
