#pragma once
#include "stdafx.h"
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <windows.h>
#pragma comment(lib, "winmm.lib")
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;
int muzyka = 0;

string nazwa_przeciwnika;
int przeciwnik_hp;
float przeciwnik_df, przeciwnik_dmg, postac_dps, postac_df;
int postac_hp;
void menu()
{

	cout << "Menu gry" << endl;
	cout << "[1] Wczytaj gre" << endl;
	cout << "[2]Nowa  gra" << endl;
	cout << "[3]Opcje" << endl;
	cout << "[4]wyjdz" << endl;
	cout << "Twoj wybor: ";


}
void generator_postaci()
{
	string zmienna_nazwy;

	fstream test;
	test.open("exp.txt", ios::out, ios::trunc);
	test << "0";
	test.close();
	test.open("gold.txt", ios::out, ios::trunc);
	test << "0";
	test.close();


	char klasa;
	ofstream plik;
	plik.open("postac.txt");
	cout << "Podaj nazwe postaci: ";
	cin >> zmienna_nazwy;

	int kontrolna = 0;
	while (kontrolna != 1)
	{
		cout << "[1]Wojownik" << endl;
		cout << "[2]Mag" << endl;
		cout << "[3]Paladyn" << endl;
		cout << "Wybierz klase z powyzszych: ";
		cin >> klasa;
		plik << "1" << endl;

		switch (klasa)
		{
			//poprawiæ statystyki tbd
		case '1':

			plik << "100" << endl;
			plik << "600" << endl;
			plik << "450" << endl;
			plik << "wojownik" << endl;
			plik << zmienna_nazwy << endl;
			kontrolna = 1;

			break;
		case '2':
			plik << "80" << endl;
			plik << "800" << endl;
			plik << "350" << endl;
			plik << "mag" << endl;
			kontrolna = 1;
			break;
		case '3':
			plik << "150" << endl;
			plik << "200" << endl;
			plik << "700;" << endl;
			plik << "paladyn" << endl;
			kontrolna = 1;
			break;
		default:
			cout << "Zla opcja, wybierz ponownie" << endl;
			system("PAUSE");
			system("cls");
			break;

		}
	}
	system("cls");


}

void opcje()
{
	system("cls");
	cout << "Opcje:" << endl;
	cout << "-----------------------------" << endl;
	if (muzyka == 0)
	{
		cout << "1.Wlacz muzyke" << endl;
	}
	else
	{
		cout << "1.Wylacz muzyke" << endl;
	}
	//	cout << "2.Odtworz pliki aplikacji" << endl;
	cout << "3.Wyjdz" << endl;
	cout << "Twoj wybor: ";


}

void miasto()
{

	cout << "Jestes w miescie, gdzie idziesz?" << endl;
	cout << "-----------------------------" << endl;
	cout << "1.Karczma" << endl;
	cout << "2.Kowal" << endl;
	cout << "3.Wroc do lochu" << endl;
	cout << "4.Zapisz i wyjdz" << endl;
	cout << "Twoj wybor: ";
}
void karczma()
{
	system("CLS");
	//co to robiæ
	cout << "Jesteœ w karczmie:" << endl;
	cout << "-----------------------------" << endl;
	cout << "[1]Potka HP-15 gold(regeneruje 20% hp)" << endl;
	cout << "[2]Potka MP-15 gold(regeneruje 20% many)" << endl;
	cout << "3.Wyjdz" << endl;
	cout << "Twoj wybor: ";



}

void kowal()
{

	//co to robiæ
	cout << "Jesteœ u kowala:" << endl;
	cout << "-----------------------------" << endl;
	cout << "1.Kup przedmioty" << endl;
	cout << "2.Sprzedaj przedmioty" << endl;
	cout << "3.Wyjdz" << endl;
	cout << "Twoj wybor: ";
}
void loch()
{
	//co to robiæ

	cout << "Jestes w lochu, co dalej" << endl;
	cout << "-----------------------------" << endl;
	cout << "1.Idz w glab lochu" << endl;
	cout << "2.Otworz ekwipunek" << endl;
	cout << "3.Wroc do miasta" << endl;
	cout << "Twoj wybor: ";

}



char ekwipunek()
{
	string linia;
	fstream plik;
	char wynik;
	cout << "Ekwipunek" << endl;
	cout << "--------------" << endl;

	plik.open("gold.txt", ios::in);
	getline(plik, linia);
	cout << "Posiadasz " << linia << " Golda!" << endl;
	plik.close();

	plik.open("ekwipunek.txt", ios::in);
	getline(plik, linia);
	cout << "[1]." << linia << endl;
	getline(plik, linia);
	cout << "[2]." << linia << endl;
	plik.close();
	cout << "[3].Wyjdz" << endl;
	cout << "Twoj wybor: ";
	cin >> wynik;
	return wynik;
}

bool fileExists(const string& fileName)
{

	fstream plik(fileName.c_str(), ios::in | ios::_Nocreate);
	if (plik.is_open())
	{
		plik.close();
		return true;
	}
	plik.close();
	return false;
}

void walka()
{
	cout << "Jestes w walce z " << nazwa_przeciwnika << endl;
	cout << "-----------------------------" << endl;
	cout << "Statystyki gracza HP:" << postac_hp << " DMG:" << postac_dps << " DF:" << postac_df << endl;
	cout << "Statystyki przeciwnika HP:" << przeciwnik_hp << " DMG:" << przeciwnik_dmg << " DF:" << przeciwnik_df << endl;
	cout << "-----------------------------" << endl;
	cout << "Opcje taktyczne:" << endl;
	cout << "1.Zaatakuj" << endl;
	cout << "2.Uzyj przedmiotu" << endl;
	cout << "3.Wycofaj sie" << endl;
	cout << "-----------------------------" << endl;
	cout << "Twoj wybor: ";

}

void lvlup()
{
	system("cls");
	int lvl = 0;
	string nick;
	string klasa;
	int hp = 0;
	int dmg = 0;
	int df = 0;
	fstream plik;
	plik.open("postac.txt");
	plik >> lvl;
	plik >> hp;
	plik >> dmg;
	plik >> df;
	plik >> nick;
	plik >> klasa;
	hp = hp + 10;
	dmg = dmg + 10;
	df = df + 10;
	lvl++;
	cout << "Gratulacje osiagles " << lvl << " poziom" << endl;
	system("PAUSE");
	plik.close();
	plik.open("postac.txt", ios::out | ios::trunc);
	plik << lvl << endl;
	plik << hp << endl;
	plik << dmg << endl;
	plik << df << endl;
	plik << nick << endl;
	plik << klasa << endl;
}
int obrazenia()
{
	int mnoznik_obrazen;
	srand(time(NULL));
	mnoznik_obrazen = ((rand() % 20) + 4);
	return mnoznik_obrazen;
}

void generowanie_przeciwnika()
{
	int id_przeciwnika;
	ifstream dane;

	srand(time(NULL));
	id_przeciwnika = ((rand() % 10));
	switch (id_przeciwnika)
	{
	case 0:
		dane.open("przeciwnik_0.txt");
		nazwa_przeciwnika = "Nieumarly Rycerz";
		break;
	case 1:
		dane.open("przeciwnik_1.txt");
		nazwa_przeciwnika = "Potezny szkieletor";
		break;
	case 2:
		dane.open("przeciwnik_2.txt");
		nazwa_przeciwnika = "Lesny goblin";
		break;
	case 3:
		dane.open("przeciwnik_3.txt");
		nazwa_przeciwnika = "Bagienny cyklop";
		break;
	case 4:
		dane.open("przeciwnik_4.txt");
		nazwa_przeciwnika = "Zielony ork";
		break;
	case 5:
		dane.open("przeciwnik_5.txt");
		nazwa_przeciwnika = "Pustynny demon";
		break;
	case 6:
		dane.open("przeciwnik_6.txt");
		nazwa_przeciwnika = "Pajak Grobowy";
		break;
	case 7:
		dane.open("przeciwnik_7.txt");
		nazwa_przeciwnika = "Nikczemny mag";
		break;
	case 8:
		dane.open("przeciwnik_8.txt");
		nazwa_przeciwnika = "Wilkolak";
		break;
	case 9:
		dane.open("przeciwnik_9.txt");
		nazwa_przeciwnika = "Zombie";
		break;


	}

	dane >> przeciwnik_hp;
	dane >> przeciwnik_df;
	dane >> przeciwnik_dmg;
}

void generowanie_postaci()
{
	ifstream postac;
	int lvl;
	postac.open("postac.txt");
	postac >> lvl;
	postac >> postac_hp;
	postac >> postac_dps;
	postac >> postac_df;
	postac.close();
}

void wygrales(char &kontrolna, float nagroda_exp, float exp, int gold_win, int gold_2)
{
	kontrolna = '3';
	system("cls");
	cout << "Gratulacje, pokonales:" << nazwa_przeciwnika << endl;
	cout << "Twoje nagrody:" << endl;
	cout << "XP:" << nagroda_exp << endl;
	cout << "Gold:" << gold_win << endl;
	cout << "Status gold " << gold_2 << endl;
	cout << "Status exp: " << exp << "/1000" << endl;

	system("PAUSE");
	system("cls");
}
void ucieczka(char &kontrolna, float exp)
{
	kontrolna = '3';
	system("cls");
	cout << "Wycofujesz sie" << endl;
	cout << "Sprobuj ponownie gdy bedziesz silniejszy" << endl;
	cout << "Otrzymujesz 25% standardowej ilosci exp oraz 0 zlota" << endl;
	cout << "Status exp: " << exp << "/1000" << endl;
	system("PAUSE");
	system("cls");
}

void porazka(char &kontrolna, float exp)
{
	kontrolna = '3';
	system("cls");
	cout << "Porazka" << endl;
	cout << "Wycofujesz sie" << endl;
	cout << "Sprobuj ponownie gdy bedziesz silniejszy" << endl;
	cout << "Otrzymujesz 10% standardowej ilosci exp oraz 0 zlota" << endl;
	cout << "Status exp: " << exp << "/1000" << endl;
	system("PAUSE");
	system("cls");
}
int exp_giv()
{
	int liczba_exp;
	srand(time(NULL));
	liczba_exp = ((rand() % 120) + 40);
	return liczba_exp;

}

int give_gold()
{
	int liczba_gold;
	srand(time(NULL));
	liczba_gold = ((rand() % 200));
	return liczba_gold;
}

void ekwipunek_walka()
{
	string linia;
	fstream plik;
	char wynik;
	cout << "Ekwipunek" << endl;
	cout << "--------------" << endl;

	plik.open("gold.txt", ios::in);
	getline(plik, linia);
	cout << "Posiadasz " << linia << " Golda!" << endl;
	plik.close();

	plik.open("ekwipunek.txt", ios::in);
	getline(plik, linia);
	cout << "[1]." << linia << " Cena:50 gold" << endl;
	getline(plik, linia);
	cout << "[2]." << linia << "Cena:50 gold" << endl;
	plik.close();
	cout << "[3].Wyjdz" << endl;
	cout << "Twoj wybor: ";


}