"""
    progmentor.hu
"""

import re

class Vigenere():

    def feladat_1(self):
        self.szoveg = input("Adjon meg egy szoveget!")

    def feladat_2(self):
        csere_szotar = dict()
        csere_szotar["Ő"] = csere_szotar["Ö"] = csere_szotar["Ó"] = "O"
        csere_szotar["Ú"] = csere_szotar["Ü"] = csere_szotar["Ű"] = "U"
        csere_szotar["Á"] = "A"
        csere_szotar["É"] = "E"
        csere_szotar["Í"] = "I"
        for key in csere_szotar:
            self.szoveg = self.szoveg.upper().replace(key, csere_szotar[key])
        self.szoveg = re.sub('[^A-Z]', '', self.szoveg)
    

    def feladat_3(self):
        print(self.szoveg)


    def feladat_4(self):
        self.kulcs = input("Adjon meg egy kulcsszot!")

    
    def feladat_5(self):
        self.kulcsszoveg = ""
        for i in range(0, len(self.szoveg)):
            self.kulcsszoveg += self.kulcs[i % len(self.kulcs)]
        print(self.kulcsszoveg)


    def feladat_6(self):
        self.tabla = []
        for line in open("/home/r/Vtabla.dat", "r").readlines():
            self.tabla.append(list(line))
        self.kodolt = ""
        for i in range(0, len(self.szoveg)):
            self.kodolt += self.tabla[ord(self.szoveg[i])-65][ord(self.kulcsszoveg[i])-65]


    def feladat_7(self):
        print(self.kodolt)
        open("kodolt.dat", "w").write(self.kodolt)

vigenere = Vigenere()
vigenere.feladat_1()
vigenere.feladat_2()
vigenere.feladat_3()
vigenere.feladat_4()
vigenere.feladat_5()
vigenere.feladat_6()
vigenere.feladat_7()
