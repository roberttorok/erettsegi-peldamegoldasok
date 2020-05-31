// progmentor.hu

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

struct meccs
{
    int fordulo;
    std::string hazai_csapat;
    int hazai_felido;
    int hazai_hazaivegeredmeny;

    std::string idegen_csapat;
    int idegen_felido;
    int idegen_vegeredmeny;
};
std::vector<meccs> meccsek;

void feladat_1()
{
    std::cout << "1. feladat" << std::endl;

    std::ifstream bemenet("meccs.txt");
    if (!bemenet.is_open())
    {
        return;
    }

    int meccsek_szama;
    bemenet >> meccsek_szama;

    struct meccs akt_meccs;
    while (bemenet >> akt_meccs.fordulo >>
           akt_meccs.hazai_hazaivegeredmeny >>
           akt_meccs.idegen_vegeredmeny >>
           akt_meccs.hazai_felido >>
           akt_meccs.idegen_felido >>
           akt_meccs.hazai_csapat >>
           akt_meccs.idegen_csapat)
    {
        meccsek.push_back(akt_meccs);
    }

    bemenet.close();

    std::cout << std::endl;
}

void feladat_2()
{
    std::cout << "2. feladat" << std::endl;

    std::cout << "Adjon meg egy fordulot: ";
    int fordulo;
    std::cin >> fordulo;

    for (const auto &meccs : meccsek)
    {
        if (meccs.fordulo == fordulo)
        {
            std::cout << meccs.hazai_csapat << "-" << meccs.idegen_csapat << ": "
                      << meccs.hazai_hazaivegeredmeny << "-" << meccs.idegen_vegeredmeny << " ("
                      << meccs.hazai_felido << "-" << meccs.idegen_felido << ")" << std::endl;
        }
    }

    std::cout << std::endl;
}

void feladat_3()
{
    std::cout << "3. feladat" << std::endl;

    for (auto &meccs : meccsek)
    {
        bool hazai_forditott = meccs.hazai_felido < meccs.idegen_felido && meccs.hazai_hazaivegeredmeny > meccs.idegen_vegeredmeny;
        bool idegen_forditott = meccs.hazai_felido > meccs.idegen_felido && meccs.hazai_hazaivegeredmeny < meccs.idegen_vegeredmeny;

        if (hazai_forditott)
        {
            std::cout << meccs.fordulo << ". fordulo: " << meccs.hazai_csapat << std::endl;
        }

        if (idegen_forditott)
        {
            std::cout << meccs.fordulo << ". fordulo: " << meccs.idegen_csapat << std::endl;
        }
    }

    std::cout << std::endl;
}

std::string feladat_4()
{
    std::cout << "4. feladat" << std::endl;
    std::string csapat;
    std::cout << "Adjon meg egy csapatot: ";
    std::cin >> csapat;

    std::cout << std::endl;

    return csapat;
}

std::string feladat_5(std::string csapat)
{
    std::cout << "5. feladat" << std::endl;

    int kapott = 0;
    int lott = 0;
    for (const auto &meccs : meccsek)
    {
        if (meccs.hazai_csapat == csapat)
        {
            kapott += meccs.idegen_vegeredmeny;
            lott += meccs.hazai_hazaivegeredmeny;
        }
        if (meccs.idegen_csapat == csapat)
        {
            kapott += meccs.hazai_hazaivegeredmeny;
            lott += meccs.idegen_vegeredmeny;
        }
    }
    std::cout << "Lott golok: " << lott << std::endl;
    std::cout << "Kapott golok: " << kapott << std::endl;

    std::cout << std::endl;

    return csapat;
}

void feladat_6(std::string csapat)
{
    std::cout << "6. feladat" << std::endl;

    int vesztes_forudlo_eloszor = 0;
    std::string vesztes_forudlo_ellenfel = "";

    for (const auto &meccs : meccsek)
    {
        if (meccs.hazai_csapat == csapat && meccs.hazai_hazaivegeredmeny < meccs.idegen_vegeredmeny)
        {
            vesztes_forudlo_eloszor = meccs.fordulo;
            vesztes_forudlo_ellenfel = meccs.idegen_csapat;
            break;
        }
    }

    if (vesztes_forudlo_eloszor != 0)
    {
        std::cout << "A " << csapat << " a " << vesztes_forudlo_eloszor << " forduloban kapott ki a " << vesztes_forudlo_ellenfel << " csapattol." << std::endl;
    }
    else
    {
        std::cout << "A " << csapat << " otthon veretlen maradt " << std::endl;
    }

    std::cout << std::endl;
}

void feladat_7()
{
    std::cout << "7. feladat" << std::endl;

    std::map<std::string, int> eredmenyek;
    for (auto &meccs : meccsek)
    {
        int eredmeny1 = meccs.hazai_hazaivegeredmeny > meccs.idegen_vegeredmeny ? meccs.hazai_hazaivegeredmeny : meccs.idegen_vegeredmeny;
        int eredmeny2 = meccs.hazai_hazaivegeredmeny < meccs.idegen_vegeredmeny ? meccs.hazai_hazaivegeredmeny : meccs.idegen_vegeredmeny;
        std::string kulcs = std::to_string(eredmeny1) + "-" + std::to_string(eredmeny2);
        if (eredmenyek.find(kulcs) == eredmenyek.end())
        {
            eredmenyek[kulcs] = 0;
        }
        eredmenyek[kulcs] += 1;
    }

    std::ofstream kimenet("stat.txt");
    if (!kimenet.is_open())
    {
        return;
    }

    for (auto const &eredmeny : eredmenyek)
    {
        kimenet << eredmeny.first << ":" << eredmeny.second << std::endl;
    }

    kimenet.close();

    std::cout << std::endl;
}

int main(void)
{
    feladat_1();
    feladat_2();
    feladat_3();
    std::string csapat = feladat_4();
    feladat_5(csapat);
    feladat_6(csapat);
    feladat_7();

    return 0;
}
