# efektyvumo tyrimo rezultatai
************************************************************
v0.5 efektyvumo tyrimas:
Atliktas trimas su 10000 ir 100000 eilučių
(Lentelėse pateiktas laikas yra suvidurkintas iš 3 bandymų)

Su 10000 eilučių: 
|     Tipas     |     Laikas    |
| :-----------: | :-----------: |
|     vector    |    323,886    |
|      list     |    330,263    |
|     deque     |    306,632    |

Su 100000 eilučių: 
|     Tipas     |   Laikas(ms)  |
| :-----------: | :-----------: |
|     vector    |    305,271    |
|      list     |    350,538    |
|     deque     |    331,799    |


Iš gautų rezultatų matome, kad programa greičiausiai veikia su vector ir deque tipais ir šiek tiek lėčiau su list tipo konteineriais
************************************************************
| Tables        | Are           |
| ------------- |:-------------:|
| col 3 is      | right-aligned |
| col 2 is      | centered      |
| zebra stripes | are neat      |
