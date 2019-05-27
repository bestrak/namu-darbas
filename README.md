# efektyvumo tyrimo rezultatai
************************************************************
v1.0 efektyvumo tyrimas:
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
