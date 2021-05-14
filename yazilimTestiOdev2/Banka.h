#pragma once
#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>

#include "Hisse.h"
#include "Emir.h"
#include "Portfoy.h"


class Banka
{
public:
	std::vector<Hisse> hisse_listesi;
	std::vector<Emir> emirler;
	std::vector<Portfoy> portfoy_elemanlari;
	float _kar;
	float _zarar;
	float toplam;

	Banka(float a, float b, float c)
	{
		_kar = a;
		_zarar = b;
		toplam = c;
	}
	~Banka()
	{

	}
	//d
	std::string hisse_ekle(std::string id, std::string sembol, std::string ad, float fiyat)
	{
		try
		{
			Hisse eklenecek_hisse = Hisse(id, sembol, ad, fiyat);
			hisse_listesi.push_back(eklenecek_hisse);
			return "basarili";
		}
		catch (const std::exception&)
		{
			return "hata";
		}
	}
	//d
	std::string emir_ekle(std::string id, std::string sembol, std::string islem, int adet)
	{
		try
		{
			Emir eklenecek_emir = Emir(id, sembol, islem, adet, "provizyon");
			emirler.push_back(eklenecek_emir);
			return "basarili";
		}
		catch (const std::exception&)
		{
			return "hata";
		}
	}
	//d
	std::string portfoy_ekle(std::string id, std::string sembol, float maliyet, int adet)
	{
		try
		{
			Portfoy eklenecek_portfot = Portfoy(id, sembol, maliyet, adet);
			portfoy_elemanlari.push_back(eklenecek_portfot);
			return "basarili";
		}
		catch (const std::exception&)
		{
			return "hata";
		}
	}
	//d
	std::string portfoy_yazdir()
	{
		try
		{
			portfoy_hesapla();
			clear_portfoy();
			clear_emirler();
			std::cout << std::endl << std::endl << "Guncel Portfoy:" << std::endl;
			for (int i = 0; i < portfoy_elemanlari.size(); ++i)
			{
				std::cout << "Hisse: " << portfoy_elemanlari[i]._sembol <<std::endl<< "Adet: " << portfoy_elemanlari[i]._adet<<std::endl << "Maliyet: " << portfoy_elemanlari[i]._maliyet << std::endl;
				std::cout << "--------------------------" << std::endl;
			}
			return "basarili";
		}
		catch (const std::exception& e)
		{
			return "hata";
		}
	} 
	//d
	std::string emirleri_gerceklestir()
	{
		try
		{
			for (int i = 0; i < emirler.size(); ++i)
			{
				if (portfoy_getir(emirler[i]._sembol) == NULL && emirler[i]._islem == "SATIS")
					return "portfoy bulunamadi " + emirler[i]._sembol;
				if (hisse_getir(emirler[i]._sembol) == NULL)
					return "hisse bulunamadi " + emirler[i]._sembol;

				if (emirler[i]._islem == "ALIS" && portfoy_getir(emirler[i]._sembol) == NULL)
				{
					portfoy_ekle("yeni eklendi", emirler[i]._sembol, hisse_getir(emirler[i]._sembol)->_fiyat, emirler[i]._adet);
					emirler[i]._durum = "tamamlanan";
					emirler[i]._maliyet = hisse_getir(emirler[i]._sembol)->_fiyat;
				}
				else if (emirler[i]._islem == "ALIS")
				{
					emirler[i].isleme_al(portfoy_getir(emirler[i]._sembol)->_maliyet, hisse_getir(emirler[i]._sembol)->_fiyat, portfoy_getir(emirler[i]._sembol)->_adet);
					portfoy_getir(emirler[i]._sembol)->portfoy_guncelle(emirler[i]._adet, emirler[i]._maliyet);
				}
				else
					emirler[i].isleme_al(portfoy_getir(emirler[i]._sembol)->_maliyet, hisse_getir(emirler[i]._sembol)->_fiyat, portfoy_getir(emirler[i]._sembol)->_adet);
			}
			return "islem_basarili";
		}
		catch (const std::exception&)
		{
			return "islem_basarisiz";
		}
	}
	//d
	Portfoy* portfoy_getir(std::string aranacak_sembol)
	{
		try
		{
			for (int i = 0; i < portfoy_elemanlari.size(); ++i)
			{
				if (aranacak_sembol == portfoy_elemanlari[i]._sembol)
				{
					//std::cout << "_id: " << portfoy_elemanlari[i]._id << " -- Sembol: " << portfoy_elemanlari[i]._sembol << " -- Maliyet: " << portfoy_elemanlari[i]._maliyet  <<" -- Adet: " << portfoy_elemanlari[i]._adet << std::endl;
					return &portfoy_elemanlari[i];
				}
			}
			return NULL;
		}
		catch (const std::exception& e)
		{
			return NULL;
		}
	}
	//d
	Emir* emir_getir(std::string aranacak_id)
	{
		try
		{
			for (int i = 0; i < emirler.size(); ++i)
			{
				if (aranacak_id == emirler[i]._id)
				{
					return &emirler[i];
				}
			}
			return NULL;
		}
		catch (const std::exception& e)
		{
			return NULL;
		}
	}
	//d
	Hisse* hisse_getir(std::string aranacak_sembol)
	{
		try
		{
			for (int i = 0; i < hisse_listesi.size(); ++i)
			{
				if (aranacak_sembol == hisse_listesi[i]._sembol)
				{
					//std::cout << "_id: " << hisse_listesi[i]._id << " -- Sembol: " << hisse_listesi[i]._sembol << " -- Ad: " << hisse_listesi[i]._ad << " -- Fiyat: " << hisse_listesi[i]._fiyat << std::endl;
					return &hisse_listesi[i];
				}
			}
			return NULL;
		}
		catch (const std::exception& e)
		{
			return NULL;
		}
	}
	//d
	std::string portfoy_hesapla()
	{
		float kar = 0;
		float zarar = 0;
		std::cout << "Satislar Kar/Zarar"<<std::endl;

		for (int i = 0; i < emirler.size(); ++i)
		{
			if (emirler[i]._durum == "tamamlanan")
			{
				if (emirler[i]._islem == "SATIS")
				{
					kar += emirler[i].kar;
					zarar += emirler[i].zarar;
					portfoy_getir(emirler[i]._sembol)->_adet -= emirler[i]._adet;
					std::cout << emirler[i]._sembol<<" : ";
					if (emirler[i].kar > emirler[i].zarar)
					{
					std::cout << emirler[i].kar << " TL Kar"<<std::endl;
					}
					else if (emirler[i].zarar > emirler[i].kar)
					{
						std::cout << emirler[i].zarar << " TL Zarar"<<std::endl;
					}
					else
					{
						std::cout << 0 << " TL Kar/Zarar" << std::endl;
					}
				}
				else if (emirler[i]._islem == "ALIS")
				{
					portfoy_getir(emirler[i]._sembol)->_adet = emirler[i]._adet;
					portfoy_getir(emirler[i]._sembol)->_maliyet = emirler[i]._maliyet;
				}
			}
		}
		std::cout << "Toplam Kar/Zarar: ";
		if (kar > zarar)
		{
			std::cout << "+ " << kar-zarar << " TL" << std::endl;
		}
		else if (zarar > kar)
		{
			std::cout << "- " << zarar-kar << " TL" << std::endl;
		}
		else
		{
			std::cout << "+- " << 0 << " TL" << std::endl;
		}

	

		std::cout << std::endl << "Provizyondaki Islemler :" << std::endl;
		for (int i = 0; i < emirler.size(); ++i)
		{
			if (emirler[i]._durum == "provizyon")
			{
				std::cout << "Islem id: " << emirler[i]._id<<std::endl;
			}
		}
		
		_kar = kar;
		_zarar = zarar;
		return "basarili";
	}

	std::string clear_portfoy()
	{
		try
		{
			bool flag = true;
			do
			{
				if (portfoy_elemanlari.size() == 0)
				{
					flag = false;
				}
				for (int i = 0; i < portfoy_elemanlari.size(); ++i)
				{
					if (portfoy_elemanlari[i]._adet == 0)
					{
						portfoy_elemanlari.erase(portfoy_elemanlari.begin() + i);
						break;
					}
					flag = false;
				}
			} while (flag);
			return "basarili";
		}
		catch (const std::exception&)
		{
			return "hata";
		}
	}

	std::string clear_emirler()
	{
		try
		{
			bool flag = true;
			do
			{
				if (emirler.size() == 0)
				{
					flag = false;
				}
				for (int i = 0; i < emirler.size(); ++i)
				{
					if (emirler[i]._durum == "tamamlanan")
					{
						emirler.erase(emirler.begin() + i);
						break;
					}
				}
				flag = false;
			} while (flag);
			return "basarili";
		}
		catch (const std::exception&)
		{
			return "hata";
		}
	}
};

