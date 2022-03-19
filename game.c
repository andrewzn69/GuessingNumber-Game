/***************************************************************
 *
 *   Program: Hadani nahodnych cisel
 *
 *   Autor: Ondrej Zeman, IT1B
 *
 *   Description: Uzivatel si vybere obtiznost, nasledne podle
 *                vyberu hada nahodne vygenerovane cisla
 *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bolest prstu ✨ gone ✨
#define p printf

int main()
{
    system("cls");

    // Zapneme generaci nahodnych cisel
    srand(time(0));

    // Deklarujeme si promenne
    int lives, randomnum, range1, range2, guess, vyber_menu = 0, vyber_nastaveni = 1;
    char napoveda = 'N', repeat;

    // Uzivatel si vybere obtiznost, nebo vypne hru, (loop pro blbuvzdornost)
    while (vyber_menu < 1 || vyber_menu > 7 || vyber_nastaveni == 2 || vyber_nastaveni == 0 || repeat == 'y' || repeat == 'Y')
    {
        p("[1] Lekha - rozmezi 1-10, 4 pokusy\n");
        p("[2] Stredni - rozmezi 1-50, 7 pokusu\n");
        p("[3] Tezka - rozmezi 1-100, 9 pokusu\n");
        p("[4] Jak hra funguje\n");
        p("[5] Nastaveni\n");
        p("[6] Ukonceni hry\n\n");
        scanf("%d", &vyber_menu);
        system("cls");

        // Urcime si hodnoty (nebo vypneme program) podle toho, co si uzivatel vybral
        switch (vyber_menu)
        {

        // 1. Obtiznost
        case 1:
            lives = 4;
            range1 = 1;
            range2 = 1;
            randomnum = rand() % range2 + range1;
            break;

        // 2. Obtiznost
        case 2:
            lives = 7;
            range1 = 1;
            range2 = 50;
            randomnum = rand() % range2 + range1;
            break;

        // 3. Obtiznost
        case 3:
            lives = 9;
            range1 = 1;
            range2 = 100;
            randomnum = rand() % range2 + range1;
            break;

        // Popis hry uzivatelovi
        case 4:
            system("cls");
            p("V teto hre musis uhodnout dany pocet nahodne generovanych cisel.\n");
            p("Pro START zmackni [ENTER]\n");
            getchar();
            system("cls");

        // Uzivatel si muze zapnout napovedu, defaultne je napoveda vypnuta
        case 5:
            while (vyber_nastaveni != 2)
            {
                p("[1] Napoveda: %c\n", napoveda);
                p("[2] Zpet do menu\n\n");

                scanf("%d", &vyber_nastaveni);

                if (vyber_nastaveni == 1 && napoveda == 'N')
                    napoveda = 'Y';
                else if (vyber_nastaveni == 1 && napoveda == 'Y')
                    napoveda = 'N';
                system("cls");
            }
            vyber_nastaveni = 0;
            break;

        // Vypnuti Hry
        case 6:
            system("cls");
            exit(0);
            break;
        }

        // Hra zacina: Uzivatel hada cislo, ukazuji se mu zivoty a rozmezi cisel
        while (guess != randomnum && lives > 0)
        {
            p("Uhodni cislo v rozmezi %d-%d, zbyva ti %d zivotu\n\n", range1, range2, lives);
            scanf("%d", &guess);

            if (guess == randomnum)
            {
                system("cls");
                p("Krasna prace, kamarade, chces to zkusit znovu? (y/n)");
                scanf(" %c", &repeat);
                system("cls");
            }
        }
    }
    repeat = 'n';
}
