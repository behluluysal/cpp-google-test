#pragma once
#include "Kurum.h"
#include <string>

class Emir : public Kurum
{
public:
	std::string _islem;
	int _adet;
	float kar;
	float zarar;
	float _maliyet;
	std::string _durum;

	Emir(std::string a, std::string b, std::string islem, int adet,std::string durum) : Kurum(a, b)
	{
		_adet = adet;
		_islem = islem;
		kar = 0;
		zarar = 0;
		_durum = durum;
		_maliyet = 0;
	}
	~Emir()
	{

	}

	std::string isleme_al(float alinan_fiyat, float hisse_fiyati, int portfoydeki_adet)
	{
		try
		{
			if (_durum == "provizyon")
			{
				if (_islem == "SATIS")
				{
					if (_adet > portfoydeki_adet)
						return "satis_islem_basarisiz";

					float harcanan = alinan_fiyat * _adet;
					float kazanilan = hisse_fiyati * _adet;

					if (kazanilan >= harcanan)
					{
						kar = kazanilan - harcanan;
						zarar = 0;
						_durum = "tamamlanan";
						return "satis_islem_basarili";
					}
					else
					{
						kar = 0;
						zarar = harcanan - kazanilan;
						_durum = "tamamlanan";
						return "satis_islem_basarili";
					}
				}
				else if (_islem == "ALIS")
				{
					float eski_maliyet = portfoydeki_adet * alinan_fiyat;
					float eklenen_maliyet = _adet * hisse_fiyati;
					_adet += portfoydeki_adet;
					_maliyet = (eski_maliyet + eklenen_maliyet) / _adet;
					_durum = "tamamlanan";
					return "alis_islem_basarili";
				}
				else
					return "islem_tipi_bulunamadi";
			}
			else if (_durum == "tamamlanan")
			{
				return "gecersiz";
			}
			else
				return "hata";
			
		}
		catch (const std::exception&)
		{
			return "hata";
		}
	}
};

