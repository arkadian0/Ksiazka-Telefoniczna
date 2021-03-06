//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <sstream>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int ID;
lista *baza = new lista;
osoba *pokaz = new osoba;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{


}
//---------------------------------------------------------------------------

void __fastcall TForm1::pZaladujClick(TObject *Sender)
{

baza->usun_liste(&baza->pierwsza);
baza->zaladujBaze();


}
void lista::zaladujBaze()
{
  string imie , nazwisko , miasto,ulica,numerdomu,numermieszkania,kodpocztowy,numertelefonu;
fstream plik2;
int i =-1;
int numerID;

string wiersz;

plik2.open( "baza_danych.txt", ios::in );
    if( plik2.good() == true )

    {

        while(getline( plik2, wiersz ) )
        {

         i++;

       if(i==0) numerID = atoi(wiersz.c_str());
       if(i==1) imie = wiersz;
       if(i==2) nazwisko = wiersz;
       if(i==3) miasto = wiersz;
       if(i==4) ulica = wiersz;
       if(i==5) numerdomu = wiersz;
       if(i==6) numermieszkania = wiersz;
       if(i==7) kodpocztowy = wiersz;
       if(i==8)
       {

           numertelefonu = wiersz;
           baza->dodaj_osobe(numerID,imie,nazwisko, miasto,ulica,numerdomu, numermieszkania,kodpocztowy,numertelefonu);
           i = -1;

       }


        }

        plik2.close();
    }

    //dodajemy rekordy do bazy

    baza->wczytaj_liste();


}
//---------------------------------------------------------------------------

void lista::zapisz_do_pliku()
{

    fstream plik;
    // wskaznik na pierszy element listy

    osoba *temp =pierwsza;

    //utworzenie bazy danych

plik.open( "baza_danych.txt", ios::out | ios::trunc );
    // przewijamy wskazniki na nastepne elementy

    while (temp)
    {


        if( plik.good() == true )
        {
            plik << temp->ID << endl;
            plik << temp->imie<< endl;
            plik << temp->nazwisko << endl;
            plik << temp->miasto << endl;
            plik << temp->ulica << endl;
            plik << temp->numerDomu << endl;
            plik << temp->numerMieszknia << endl;
            plik << temp->kodPocztowy << endl;
            plik << temp->numerTelefonu << endl;

        }


        temp=temp->nastepna;

    }

plik.close();
}
int getMax()
{
     int numerID = 0;


         fstream uPlik;
         string wiersz;
         uPlik.open("baza_danych.txt", ios::in );
int max=0;
int nrID;
int i =-1;
if( uPlik.good() == true )
{
while(getline(uPlik, wiersz ))

        {
               i++;
           if(i==numerID)
           {
           nrID = atoi(wiersz.c_str());
            numerID = numerID +9;
             if(max < nrID)
             {
             max = nrID;
             ID = max;
            }
            }
            }

    }
    uPlik.close();



}
void lista::wczytaj_liste()
{
  Form1->ListBox1->Clear();
  osoba *temp = pierwsza;
  while (temp)
    {

   stringstream ss;
   ss << temp->ID;
   string elementListy = string(ss.str().c_str()) + " " +temp->imie.c_str()+ " " +temp->nazwisko.c_str();
   Form1->ListBox1->Items->Add(elementListy.c_str());
   temp=temp->nastepna;

    }
}

void __fastcall TForm1::pWyjscieClick(TObject *Sender)
{
       Close();
       baza->zapisz_do_pliku();
}
//---------------------------------------------------------------------------








void __fastcall TForm1::pDodajClick(TObject *Sender)
{
    lImie->Visible = true;
    lNazwisko->Visible=true;
    lMiasto->Visible=true;
    lUlica->Visible=true;
    lNumerdomu->Visible=true;
    lNumermieszkania->Visible=true;
    lKodpocztowy->Visible=true;
    lNumertelefonu->Visible=true;
    eImie->Visible=true;
    eNazwisko->Visible=true;
    eMiasto->Visible=true;
    eUlica->Visible=true;
    eNumerdomu->Visible=true;
    eNumermieszkania->Visible=true;
    eKodpocztowy->Visible=true;
    eNumertelefonu->Visible=true;
    bMaledodaj->Visible=true;
    eImie->Clear();
    eNazwisko->Clear();
    eMiasto->Clear();
    eUlica->Clear();
    eNumerdomu->Clear();
    eNumermieszkania->Clear();
    eKodpocztowy->Clear();
    eNumertelefonu->Clear();
    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::bMaledodajClick(TObject *Sender)
{
getMax();
    baza->dodaj_osobe (ID+1,(eImie->Text).c_str(),(eNazwisko->Text).c_str(),(eMiasto->Text).c_str(),(eUlica->Text).c_str(),(eNumerdomu->Text).c_str(),(eNumermieszkania->Text).c_str(),(eKodpocztowy->Text).c_str(),(eNumertelefonu->Text).c_str());
    baza->zapisz_do_pliku();
    lImie->Visible = false;
    lNazwisko->Visible=false;
    lMiasto->Visible=false;
    lUlica->Visible=false;
    lNumerdomu->Visible=false;
    lNumermieszkania->Visible=false;
    lKodpocztowy->Visible=false;
    lNumertelefonu->Visible=false;
    eImie->Visible=false;
    eNazwisko->Visible=false;
    eMiasto->Visible=false;
    eUlica->Visible=false;
    eNumerdomu->Visible=false;
    eNumermieszkania->Visible=false;
    eKodpocztowy->Visible=false;
    eNumertelefonu->Visible=false;
    bMaledodaj->Visible=false;
    ListBox1->Clear();
    baza->usun_liste(&baza->pierwsza);
    baza->zaladujBaze();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::pUsunClick(TObject *Sender)
{
     int numerID = (ListBox1->ItemIndex)*9;


         fstream uPlik;
         string wiersz;
         uPlik.open("baza_danych.txt", ios::in );
int ID;
int i =-1;
if( uPlik.good() == true )
{
while(getline(uPlik, wiersz ))

        {
               i++;
           if(i==numerID)
           {
            ID = atoi(wiersz.c_str());
            break;
            }

    }
    uPlik.close();
    }
   baza->usun_osobe(ID);
   ListBox1->Items->Delete(ListBox1->ItemIndex);
   baza->zapisz_do_pliku();

}
//---------------------------------------------------------------------------


void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
int numerID = (ListBox1->ItemIndex)*9;
osoba *temp = baza->pierwsza;
fstream uPlik;
string wiersz;
uPlik.open("baza_danych.txt", ios::in );
int ID;
int i =-1;
if( uPlik.good() == true )
{
while(getline(uPlik, wiersz ))

        {
               i++;
           if(i==numerID)
           {
            ID = atoi(wiersz.c_str());
            break;
            }

    }
    uPlik.close();
  }

while(temp)
{
if(temp->ID == ID)
{
Label1->Caption = temp->imie.c_str();
Label2->Caption = temp->nazwisko.c_str();
Label3->Caption =temp->ulica.c_str();
Label4->Caption = temp->miasto.c_str();
Label5->Caption = temp->numerDomu.c_str();
Label6->Caption = temp->numerMieszknia.c_str();
Label7->Caption = temp->kodPocztowy.c_str();
Label8->Caption = temp->numerTelefonu.c_str();
}
temp = temp->nastepna;
}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::bEdycjaClick(TObject *Sender)
{
    lImie->Visible = true;
    lNazwisko->Visible=true;
    lMiasto->Visible=true;
    lUlica->Visible=true;
    lNumerdomu->Visible=true;
    lNumermieszkania->Visible=true;
    lKodpocztowy->Visible=true;
    lNumertelefonu->Visible=true;
    eImie->Visible=true;
    eNazwisko->Visible=true;
    eMiasto->Visible=true;
    eUlica->Visible=true;
    eNumerdomu->Visible=true;
    eNumermieszkania->Visible=true;
    eKodpocztowy->Visible=true;
    eNumertelefonu->Visible=true;
    bZakonczedycje->Visible=true;
     int numerID = (ListBox1->ItemIndex)*9;
osoba *temp = baza->pierwsza;
fstream uPlik;
string wiersz;
uPlik.open("baza_danych.txt", ios::in );
int ID;
int i =-1;
if( uPlik.good() == true )
{
while(getline(uPlik, wiersz ))

        {
               i++;
           if(i==numerID)
           {
            ID = atoi(wiersz.c_str());
            break;
            }

    }
    uPlik.close();
  }
while(temp)
{
if(temp->ID == ID)
{
eImie->Text = temp->imie.c_str();
eNazwisko->Text = temp->nazwisko.c_str();
eUlica->Text = temp->ulica.c_str();
eMiasto->Text = temp->miasto.c_str();
eNumerdomu->Text = temp->numerDomu.c_str();
eNumermieszkania->Text = temp->numerMieszknia.c_str();
eKodpocztowy->Text = temp->kodPocztowy.c_str();
eNumertelefonu->Text = temp->numerTelefonu.c_str();
}
temp = temp->nastepna;
}


}
//---------------------------------------------------------------------------


void __fastcall TForm1::bZakonczedycjeClick(TObject *Sender)
{
  int numerID = (ListBox1->ItemIndex)*9;
osoba *temp = baza->pierwsza;
fstream uPlik;
string wiersz;
uPlik.open("baza_danych.txt", ios::in );
int ID;
int i =-1;
if( uPlik.good() == true )
{
while(getline(uPlik, wiersz ))

        {
               i++;
           if(i==numerID)
           {
            ID = atoi(wiersz.c_str());
            break;
            }

    }
    uPlik.close();
  }
while(temp)
{
if(temp->ID == ID)
{
temp->imie = eImie->Text.c_str();
temp->nazwisko = eNazwisko->Text.c_str();
temp->ulica = eUlica->Text.c_str();
temp->miasto = eMiasto->Text.c_str();
temp->numerDomu = eNumerdomu->Text.c_str();
temp->numerMieszknia = eNumermieszkania->Text.c_str();
temp->kodPocztowy = eKodpocztowy->Text.c_str();
temp->numerTelefonu = eNumertelefonu->Text.c_str();
Label1->Caption = temp->imie.c_str();
Label2->Caption = temp->nazwisko.c_str();
Label3->Caption = temp->ulica.c_str();
Label4->Caption = temp->miasto.c_str();
Label5->Caption = temp->numerDomu.c_str();
Label6->Caption = temp->numerMieszknia.c_str();
Label7->Caption = temp->kodPocztowy.c_str();
Label8->Caption = temp->numerTelefonu.c_str();
}
temp = temp->nastepna;
}
 lImie->Visible = false;
    lNazwisko->Visible=false;
    lMiasto->Visible=false;
    lUlica->Visible=false;
    lNumerdomu->Visible=false;
    lNumermieszkania->Visible=false;
    lKodpocztowy->Visible=false;
    lNumertelefonu->Visible=false;
    eImie->Visible=false;
    eNazwisko->Visible=false;
    eMiasto->Visible=false;
    eUlica->Visible=false;
    eNumerdomu->Visible=false;
    eNumermieszkania->Visible=false;
    eKodpocztowy->Visible=false;
    eNumertelefonu->Visible=false;
    bZakonczedycje->Visible=false;
baza->zapisz_do_pliku();
baza->usun_liste(&baza->pierwsza);
baza->zaladujBaze();
}
//---------------------------------------------------------------------------

