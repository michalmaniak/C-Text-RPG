#include "stdafx.h"
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#pragma comment(lib, "winmm.lib")
#include <windows.h>
#include <string>
#include <fstream>
#include "Header.h"



using namespace std;

int main()
{
	char wynik_z_menu;

	char zmienna_walki;
	int zmienna_kontrolna = 0;
	float exp = 0;
	char opcje1;
	char ekwipunek1;
	float exp_test = 0;
	int exp_2 = 0;
	fstream plik;
	int gold = 0;
	int gold_test = 0;
	int menu1 = 0;
	int blad = 0;
	char zmienna_kontrolna_karczmy;
	int zmienna_kontrolna_kowala = 0;
	int kappa = 0;
	char zmienna_kontrolna_lochu;
	char sterowanie_gry = 0;
	do
	{
		menu();
		cin >> wynik_z_menu;
		switch (wynik_z_menu)
		{
		case '1':
			if (fileExists("exp.txt") && fileExists("postac.txt") && fileExists("przeciwnik_0.txt") && fileExists("przeciwnik_1.txt") && fileExists("przeciwnik_2.txt") && fileExists("przeciwnik_3.txt") && fileExists("przeciwnik_4.txt") && fileExists("przeciwnik_5.txt") && fileExists("przeciwnik_6.txt") && fileExists("przeciwnik_7.txt") && fileExists("przeciwnik_8.txt") && fileExists("przeciwnik_9.txt") && fileExists("ekwipunek.txt") && fileExists("gold.txt"))
			{
				plik.open("exp.txt", ios::in);
				plik >> exp;
				plik.close();
				plik.open("gold.txt", ios::in);
				plik >> gold;
				plik.close();
				system("cls");
				zmienna_kontrolna = 0;
				do
				{
					miasto();
					cin >> sterowanie_gry;
					switch (sterowanie_gry)
					{
					case '1':
						system("cls");
						karczma();
						cin >> zmienna_kontrolna_karczmy;
						system("cls");
						//tu kod kupowania w karczmie (zmieniono w funkcji karczma
						break;
					case '2':
						system("cls");
						kowal();
						cin >> zmienna_kontrolna_kowala;
						system("cls");
						//tu kod kowala (albo w procedurze/funkcji
						break;
					case '3':
						zmienna_kontrolna_lochu = '0';
						do
						{
							system("cls");
							loch();
							cin >> zmienna_kontrolna_lochu;
							switch (zmienna_kontrolna_lochu)
							{
							case '1':
								generowanie_postaci();
								generowanie_przeciwnika();
								zmienna_walki = '0';
								while (zmienna_walki != '3')
								{
									system("cls");
									walka();
									blad = 0;
									cin >> zmienna_walki;
									switch (zmienna_walki)
									{
									case '1':
										przeciwnik_hp = przeciwnik_hp - ((postac_dps / przeciwnik_df)*obrazenia());
										if (przeciwnik_hp <= 0)
										{
											exp_test = exp_giv();
											exp = exp + exp_test;
											gold_test = give_gold();
											gold = gold + gold_test;
											blad = 1;
											exp_2 = exp;
											plik.open("exp.txt", ios::out | ios::trunc);
											plik << exp_2;
											plik.close();
											plik.open("gold.txt", ios::out | ios::trunc);
											plik << gold;
											plik.close();
											wygrales(zmienna_walki, exp_test, exp, gold_test, gold);

											if (exp >= 1000)
											{
												lvlup();
												exp = exp - 1000;
											}

										}
										postac_hp = postac_hp - ((przeciwnik_dmg / postac_df)*obrazenia());
										if (postac_hp <= 0 && blad == 0)
										{
											exp_test = exp_giv() / 10;
											exp = exp + exp_test;
											porazka(zmienna_walki, exp);
											plik.open("exp.txt", ios::out | ios::trunc);

											plik << exp;
											plik.close();

										}

										break;
									case '2':
										ekwipunek_walka();
										cin >> ekwipunek1;
										if (ekwipunek1 == '1' &&gold < 50)
										{
											cout << "Brak golda" << endl;
											system("PAUSE");
										}
										if (ekwipunek1 == '1' &&gold >= 50)
										{
											plik.open("gold.txt", ios::out);
											gold = gold - 50;
											plik << gold;
											plik.close();
											postac_hp = postac_hp + 20;
											cout << "Poprawnie uzyto przedmiotu" << endl;


										}
										break;
									case '3':
										exp_test = exp_giv() / 25;
										exp = exp + exp_test;
										ucieczka(zmienna_walki, exp);
										plik.open("exp.txt", ios::out | ios::trunc);
										plik << exp;
										plik.close();
										system("cls");
										break;

									}
								}

								break;
							case '2':
								system("cls");
								zmienna_kontrolna_lochu = ekwipunek();


								break;
							case '3':
								zmienna_kontrolna = 4;
								system("Cls");
								break;
							default:
								cout << "Zla opcja, wybierz ponownie" << endl;
								system("PAUSE");
								zmienna_kontrolna = 0;
								system("cls");
								break;
							}
							if (exp >= 1000)
							{
								lvlup();
								exp = exp - 1000;
							}
						} while (zmienna_kontrolna != 4);

						break;
					case '4':
						zmienna_kontrolna = '4';
						break;
					default:
						cout << "Zla opcja, wybierz ponownie" << endl;
						system("PAUSE");
						system("cls");

					}

				} while (zmienna_kontrolna != '4');
			}
			else
			{
				cout << "Postac nie stnieje lub brakuje wymaganych plikow" << endl;
				cout << "Jesli nie wiesz dlaczego wystepuje blad skontaktuj sie z tworca aplikacji" << endl;
				system("PAUSE");
			}
			system("cls");


			break;

		case '2':
			system("cls");
			generator_postaci();

			break;
		case '3':
			do
			{
				opcje();
				cin >> opcje1;
				switch (opcje1)
				{
				case '1':
					if (muzyka == 0)
					{
						PlaySound(TEXT("recycle.wav"), NULL, SND_ASYNC);
						muzyka = 1;
						system("cls");
					}
					else
					{
						PlaySound(NULL, 0, 0);
						muzyka = 0;
						system("cls");
					}
					break;
				case '2':
					//	odtwarzanie();
					break;
				}
			} while (opcje1 != '3');
			system("cls");
			break;
		case '4':
			system("cls");

			break;
		case '5':
			system("cls");
			lvlup();
			break;
		default:

			cout << "Zla opcja, wybierz ponownie" << endl;
			system("PAUSE");
			system("cls");
			break;
		}
	} while (wynik_z_menu != '4');
	return 0;
}
