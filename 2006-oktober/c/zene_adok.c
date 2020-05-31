#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define RADIOADOK_SZAMA 3

struct szam
{
    int radio_sorszam;
    int hossz_perc;
    int hossz_masodperc;
    char teljes_cim[1024];
};

struct szam szamok[1024];
int hossz_szamok = 0;

int feladat1()
{
    int szam_osszes = 0;

    FILE *fp = fopen("musor.txt", "r");
    char tmp[1024];
    int sor = 0;
    while (fgets(tmp, 1024, fp))
    {
        if (sor++ == 0)
        {
            szam_osszes = atoi(tmp);
            continue;
        }

        szamok[hossz_szamok].radio_sorszam = atoi(strtok(tmp, " "));
        szamok[hossz_szamok].hossz_perc = atoi(strtok(NULL, " "));
        szamok[hossz_szamok].hossz_masodperc = atoi(strtok(NULL, " "));

        char teljes_szamcim[1024];
        teljes_szamcim[0] = 0;

        char *token = NULL;
        while (token = strtok(NULL, " "))
        {
            strcat(szamok[hossz_szamok].teljes_cim, token);
            strcat(szamok[hossz_szamok].teljes_cim, " ");
        }
        szamok[hossz_szamok].teljes_cim[strlen(szamok[hossz_szamok].teljes_cim) - 2] = 0;

        hossz_szamok++;
    }

    fclose(fp);
}

void feladat2()
{
    int szamol_adok[] = {0, 0, 0};
    for (int i = 0; i < hossz_szamok; i++)
    {
        szamol_adok[szamok[i].radio_sorszam - 1]++;
    }

    printf("\n2. feladat\n");
    printf("===========\n");
    for (int i = 0; i < RADIOADOK_SZAMA; i++)
    {
        printf("%d. radioado: %d\n", i + 1, szamol_adok[i]);
    }
}

void feladat3()
{
    int eltelt_masodperc = 0;
    int elso_idopont_masodperc = 0;
    int masodik_idopont_masodperc = 0;

    for (int i = 0; i < hossz_szamok; i++)
    {
        if (szamok[i].radio_sorszam != 1)
        {
            continue;
        }

        if (!strncmp(szamok[i].teljes_cim, "Eric Clapton", strlen("Eric Clapton")))
        {
            if (elso_idopont_masodperc == 0)
            {
                elso_idopont_masodperc = eltelt_masodperc;
            }
            else
            {
                masodik_idopont_masodperc = eltelt_masodperc + szamok[i].hossz_perc * 60 + szamok[i].hossz_masodperc;
            }
        }
        eltelt_masodperc += szamok[i].hossz_perc * 60 + szamok[i].hossz_masodperc;
    }

    int kulonbseg = masodik_idopont_masodperc - elso_idopont_masodperc;
    int ora = kulonbseg / 60 / 60;
    int perc = (kulonbseg / 60) % 60;
    int masodperc = kulonbseg % 60;
    printf("\n3. feladat\n");
    printf("===========\n");
    printf("ennyi ido telt el: %d ora, %d perc, %d masodperc\n", ora, perc, masodperc);
}

void feladat4()
{
    char elozo[RADIOADOK_SZAMA][1024];
    for (int i = 0; i < hossz_szamok; i++)
    {
        if (!strncmp(szamok[i].teljes_cim, "Omega:Legenda", strlen("Omega:Legenda")))
        {
            printf("\n4. feladat\n");
            printf("===========\n");
            printf("A szam ezen a csatornan volt hallhato: %d\n", szamok[i].radio_sorszam);
            printf("A tobbi csatornan ezek szoltak: \n");
            for (int j = 0; j < RADIOADOK_SZAMA; j++)
            {
                if (j != szamok[i].radio_sorszam - 1)
                {
                    printf("%i. radioadas: %s\n", j + 1, elozo[j]);
                }
            }
            break;
        }

        strcpy(elozo[szamok[i].radio_sorszam - 1], szamok[i].teljes_cim);
    }
}

char *make_kisbetu(char *szoveg)
{
    char *kisbetus = (char *)malloc(sizeof(char) * strlen(szoveg) + 1);
    for (int i = 0; i < strlen(szoveg); i++)
    {
        kisbetus[i] = tolower(szoveg[i]);
    }
    kisbetus[strlen(szoveg)] = 0;

    return kisbetus;
}

void feladat5()
{
    char keres[1024];
    printf("Kereses: ");
    scanf("%s", keres);

    int talalt_szamlalo = 0;
    char talalt[1024][1024] = {0};
    for (int i = 0; i < hossz_szamok; i++)
    {
        char *teljes_szam_kisbetu = make_kisbetu(szamok[i].teljes_cim);
        char *keres_kisbetu = make_kisbetu(keres);

        int talalt_betuk = 0;
        for (int j = 0; j < strlen(teljes_szam_kisbetu); j++)
        {
            if (teljes_szam_kisbetu[j] == keres_kisbetu[talalt_betuk])
            {
                talalt_betuk++;
                continue;
            }
        }

        if (talalt_betuk == strlen(keres_kisbetu))
        {
            strcpy(talalt[talalt_szamlalo], szamok[i].teljes_cim);
            talalt_szamlalo++;
        }
    }

    FILE *fp = fopen("keres.txt", "w");
    fprintf(fp, "%s\n", keres);
    for (int i = 0; i < talalt_szamlalo; i++)
    {
        fprintf(fp, "%s\n", talalt[i]);
    }
    fclose(fp);
}

void feladat6()
{
    int eltelt_masodperc = 0;
    for (int i = 0; i < hossz_szamok; i++)
    {
        if (szamok[i].radio_sorszam != 1)
        {
            continue;
        }

        int hossz_szam = szamok[i].hossz_perc * 60 + szamok[i].hossz_masodperc + 60;
        int lejatszas_utan_ido = eltelt_masodperc + hossz_szam;
        if (eltelt_masodperc / 3600 < lejatszas_utan_ido / 3600)
        {
            int ora = (lejatszas_utan_ido / 3600) * 60 * 60;
            eltelt_masodperc += ora - eltelt_masodperc + 3 * 60;
        }
        eltelt_masodperc += hossz_szam;
    }

    int ora = eltelt_masodperc / 60 / 60;
    int perc = eltelt_masodperc / 60 % 60;
    int masoperc = eltelt_masodperc % 60;

    printf("\n6. feladat\n");
    printf("===========\n");
    printf("ennyi ido utan van vege a musornak: ");
    printf("%d ora, %d perc, %d masodperc\n", ora, perc, masoperc);
}

int main(void)
{
    feladat1();
    feladat2();
    feladat3();
    feladat4();
    feladat5();
    feladat6();

    return 0;
}