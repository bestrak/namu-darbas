# efektyvumo tyrimo rezultatai
************************************************************
v0.5 efektyvumo tyrimas:
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
************************************************************
