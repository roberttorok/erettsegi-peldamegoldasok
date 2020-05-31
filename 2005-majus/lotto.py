"""
    Lottó

    Példamegoldás a 2005. májusi emelt szintű
    érettségi programozás feladatához.

    progmentor.hu
"""

def feladat_1():
    global het_52
    bemenet = input("Adja meg az 52. heti lottószámokat!: ")
    het_52 = [int(szam) for szam in bemenet.split(' ')]


def feladat_2():
    global het_52
    het_52.sort()
    for szam in het_52:
        print(szam, ' ', end='')
    print()


def feladat_3():
    global het
    het = input("Adjon meg egy számot 1-51 között!: ")


def feladat_4():
    global lottoszamok
    lottoszamok = []
    with open('lottosz.dat', 'r') as f:
        for sor in f.readlines():
            heti_szamsor = [int(szam) for szam in sor.split(' ')]
            lottoszamok.append(heti_szamsor)
    print(lottoszamok[het])


def feladat_5():
    for szam in range(1, 91):
        talalt = False
        for heti_szamok in lottoszamok:
            if szam in heti_szamok:
                talalt = True
                break
            if talalt: break
        if not talalt:
            print("Van")
            return

    print("Nincs")


def feladat_6():
    paratlanok = 0
    for heti_szamok in lottoszamok:
        for szam in heti_szamok:
            if szam % 2 == 1: paratlanok += 1
    print(paratlanok)


def feladat_7():
    osszes = list(lottoszamok)
    osszes.append(het_52)
    with open('lottok.ki', 'w') as f:
        for heti_szamok in osszes:
            print(' '.join(str(szam) for szam in heti_szamok), file = f)


def feladat_8():
    osszes = list(lottoszamok)
    osszes.append(het_52)

    gyakorisag = {}
    for szam in range(1, 91): gyakorisag[szam] = 0

    for heti_szamok in osszes:
        for szam in heti_szamok:
            gyakorisag[szam] += 1

    for szam in range(1, 91):
        print(gyakorisag[szam],' ', end = '')
        if szam % 6 == 0: print()

    print()


def primek():
    primek = {2}
    for i in range(3, 91):
        prim = True
        for j in range(2, i // 2 + 1):
            if i % j == 0:
                prim = False
                break
        if prim: primek.add(i)
    return primek


def feladat_9():
    osszes = list(het_52)
    for heti_szamok in lottoszamok: osszes.extend(heti_szamok)

    for prim in primek():
        if prim not in osszes:
            print(prim)
            continue


# feladat_1()
het_52 = [89,24,34,11,64]
feladat_2()
# feladat_3()
het = 31
feladat_4()
feladat_5()
feladat_6()
feladat_7()
feladat_8()
feladat_9()
