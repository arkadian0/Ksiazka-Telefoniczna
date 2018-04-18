#include "dodajosobe.h"
void lista::usun_osobe (int nr)
{
    osoba *pom = pierwsza;

        // jezeli to pierwszy element listy
    if (pom->ID==nr)
    {
        osoba *temp = pierwsza;
        pierwsza = temp->nastepna; //poczatek listy, 1 el. wskazuje na 2 el. itd..
    }

    // je¿eli nie jest to pierwszy element
    if (pom->ID!=nr)
    {
        int j = 1;

        // do usuniecia srodkowego elemetnu potrzebujemy wskaznika na osobe n-1
        // wskaznik *wsk bedzie wskaznikiem na osobe poprzedzajaca osobe usuwana
        osoba *temp = pierwsza;

        while (temp)
        {
            // sprawdzamy czy wskaznik jest na osobie n-1 niz usuwana
            if (temp->nastepna->ID==nr) break;

            // jezeli nie to przewijamy petle do przodu
            temp = temp->nastepna;

        }

        // wskaznik *temp wskazuje teraz na osobe n-1
        // nadpisujemy wkaznik osoby n na osobe n+1
        // bezpowrotnie tracimy osobe n-ta

        // dodatkowo sprawdzamy czy aby nie jest to ostatni element
        // wtedy nalezy wyzerowac ostatni wskaznik
        if (temp->nastepna->nastepna==0)       
            temp->nastepna = 0;

        // jezeli nie byl to ostatni element
        else
            temp->nastepna = temp->nastepna->nastepna;
    }
}
