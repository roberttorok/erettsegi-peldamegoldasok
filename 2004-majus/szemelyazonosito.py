"""
    Személyazonosító
    
    Példamegoldás a 2004-es emelt szintű informatikai
    érettségi programozás részéhez.

    progmentor.hu
"""

import datetime

def feladat_a():
    azon = input("Adjon meg egy személyazonosító jel első tíz karakterét!: ")
    return azon

def feladat_b(azon):
    if azon[0] == "1" or azon[0] == "3":
        print("Férfi")
    else:
        print("Nő")


def feladat_c(azon):
    print(azon[1:7])


def feladat_d(azon):
    ev = datetime.datetime.now().year
    szemely_ev = int(("19" if azon[0] == "1" or azon[0] == "2" else "20") + azon[1:3])
    hanyadik_szulnap = ev - szemely_ev
    print("A személynek a ",hanyadik_szulnap,". születésnapja van az évben.")


def feladat_e():
    azon = input("Adjon meg egy másik személyazonosító jel első tíz karakterét!:")
    return azon


def szul_ev(azon):
    return int(("19" if azon[0] == "1" or azon[0] == "2" else "20") + azon[1:3])


def szul_datum_teljes(azon):
    return int(("19" if azon[0] == "1" or azon[0] == "2" else "20") + azon[1:10])


def feladat_f(szemely_a, szemely_b):
    if szul_datum_teljes(szemely_a) < szul_datum_teljes(szemely_b):
        print("Az első személy az idősebb!")
    else:
        print("A második személy az idősebb!")


def feladat_g(szemely_a, szemely_b):
    ev_kulonbseg = abs(szul_ev(szemely_a) - szul_ev(szemely_b))
    print("Különbség az évek között: ", ev_kulonbseg)


def feladat_h(azon):
    szam = 0
    for (i, c) in enumerate(azon):
        szam += int(c) * (10 - i)
    maradek = szam % 11
    if maradek == 10:
        print("Hibás születési sorszám!")
    else:
        print("A teljes személyazonosító: ", azon + str(maradek))


def feladat_i(szemely_a, szemely_b):
    with open('szemszam.txt', 'w') as f:
        print(szemely_a, file = f)
        print(szemely_b, file = f)
    print("A személyazonosítók szemszam.txt sikeresen mentve.")

teszt_azon_a = "2880627001"
teszt_azon_b = "1780627102"

azon_a = teszt_azon_a
azon_b = teszt_azon_b

azon_a = feladat_a()
feladat_b(azon_a)
feladat_c(azon_a)
feladat_d(azon_a)
azon_b = feladat_e()
feladat_f(azon_a, azon_b)
feladat_g(azon_a, azon_b)
feladat_h(azon_b)
feladat_i(azon_a, azon_b)
