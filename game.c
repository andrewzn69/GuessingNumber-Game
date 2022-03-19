/***************************************************************
 *
 *   Program: Hadani nahodeho cisla
 *
 *   Autor: Ondrej Zeman, IT1B
 *
 *   Description: Uzivatel si vybere obtiznost, nasledne podle
 *                vyberu hada nahodne vygenerovane cislo
 *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bolest prstu ✨ gone ✨
#define p printf

// Promenna pro zapnuti napovedy, jeji globalita je potrebna pro ulozeni preference pro opakovani hry

char napoveda = 'N';

int main()
{
    system("cls");

    // Zapneme generaci nahodnych cisel
    srand(time(0));

    // Deklarujeme si promenne
    int lives, randomnum, range1, range2, guess, vyber_nastaveni, zadana_hodnota = 0, vyber_menu = 0;
    char repeat = 'n';

    // Uzivatel si vybere obtiznost, nebo vypne hru, (loop pro blbuvzdornost)
    while (vyber_menu < 1 || vyber_menu > 6)
    {
        p(">> GUESSING NUMBER GAME <<\n\n");
        p("Obtiznosti:\n");
        p("[1] Lekha - rozmezi 1-10, 4 pokusy\n");
        p("[2] Stredni - rozmezi 1-50, 7 pokusu\n");
        p("[3] Tezka - rozmezi 1-100, 9 pokusu\n\n");
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
            range2 = 10;
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
            p("V teto hre musis uhodnout nahodne vygenerovane cislo\n");
            p("Pro navrat do menu zmackni [ENTER]\n\n");
            getchar();
            getchar();
            system("cls");
            main();
            break;

        // Uzivatel si muze zapnout napovedu, defaultne je napoveda vypnuta
        case 5:

            // Jestli uzivatel nevybere navrat do menu
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
            vyber_menu = 0;
            vyber_nastaveni = 0;
            break;

        // Vypnuti Hry
        case 6:
            system("cls");
            exit(0);
            break;
        default:
            main();
        }
    }

    // Zacatek hry, uzivatel hada vygenerovane cislo
    while (guess != randomnum && lives >= 1)
    {
        // Napoveda zapnuta
        if (zadana_hodnota > 0)
        {
            if (napoveda == 'Y' && guess < randomnum)
                p("Generovane cislo je vetsi!\n\n");
            else if (napoveda == 'Y' && guess > randomnum)
                p("Generovane cislo je mensi!\n\n");
        }

        // Hlavni otazka
        p("Uhodni cislo (%d-%d), zbyva ti %d pokusu.\n\n", range1, range2, lives);
        scanf("%d", &guess);
        zadana_hodnota++;
        lives--;
        system("cls");

        // Uzivatel vyhraje
        while (guess == randomnum)
        {
            p("Vyhral jsi!\n");

            // Program se pta uzivatele, jestli chce opakovat hru
            p("Chces hru opakovat znovu? (y/n)\n\n");
            scanf(" %c", &repeat);
            system("cls");

            // Uzivatel chce opakovat hru
            if (repeat == 'y' || repeat == 'Y')
            {
                main();
            }

            // Uzivatel nechce opakovat hru
            else
                exit(0);
        }

        // Uzivatel prohraje
        while (lives == 0)
        {
            system("cls");
            p("Prohral jsi!\n");
            p("Cislo bylo: %d\n", randomnum);

            // Program se pta uzivatele, jestli chce opakovat hru
            p("Chces to opakovat znovu? (y/n)\n\n");
            scanf(" %c", &repeat);
            system("cls");

            // Uzivatel chce opakovat hru
            if (repeat == 'y' || repeat == 'Y')
            {
                main();
                vyber_menu = 0;
            }
            // Uzivatel nechce opakovat hru
            else
                exit(0);
        }
    }
}
