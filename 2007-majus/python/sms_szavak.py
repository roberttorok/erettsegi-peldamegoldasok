# progmentor.hu

bill = dict()
bill["a"] = bill["b"] = bill["c"] = 2
bill["d"] = bill["e"] = bill["f"] = 3
bill["g"] = bill["h"] = bill["i"] = 4
bill["j"] = bill["k"] = bill["l"] = 5
bill["m"] = bill["n"] = bill["o"] = 6
bill["p"] = bill["q"] = bill["r"] = bill["s"] = 7
bill["t"] = bill["u"] = bill["v"] = 8
bill["w"] = bill["x"] = bill["y"] = bill["z"] = 9


def feladat_1():
    betu = input("kerem a karaktert: ")
    print(bill[betu])


def get_kod(szo):
    eredmeny = ""
    for kar in szo:
        eredmeny += str(bill[kar])
    return eredmeny


def feladat_2():
    szo = input("Kerem a szot: ")
    print(get_kod(szo))


szavak = []


def feladat_3():
    for line in open("szavak.txt", "r").readlines():
        szavak.append(line.replace("\r", "").replace("\n", ""))


def feladat_4():
    leghosszabb_szo = ""
    for szo in szavak:
        if len(szo) > len(leghosszabb_szo):
            leghosszabb_szo = szo
    print(leghosszabb_szo)


def feladat_5():
    rovid_szavak = []
    for szo in szavak:
        if len(szo) <= 5:
            rovid_szavak.append(szo)

    print("Rovid szavak: %d" % (len(rovid_szavak)))


def feladat_6():
    with open("kiir.txt", "w") as f:
        for szo in szavak:
            f.write(get_kod(szo) + "\n")


def feladat_7():
    szamsor = input("Kerem a szamsort: ")

    for szo in szavak:
        if szamsor == get_kod(szo):
            print(szo)

def feladat_8():
    kodok = dict()

    for szo in szavak:
        kod = get_kod(szo)
        if kod not in kodok:
            kodok[kod] = []
        kodok[kod].append(szo)

    kimenet = ""
    for kod in kodok:
        if len(kodok[kod]) > 1:
            for szo in kodok[kod]:
                kimenet += "%s : %s;" % (szo, kod)
    print(kimenet)

    return kodok


def feladat_9(kodok):
    max_kodok = []
    for kod in kodok:
        if len(kodok[kod]) > len(max_kodok):
            max_kodok = kodok[kod]

    print("Legtobbszor elofordulo: ")
    for szo in max_kodok:
        print(szo)


feladat_1()
feladat_2()
feladat_3()
feladat_4()
feladat_5()
feladat_6()
feladat_7()
kodok = feladat_8()
feladat_9(kodok)
