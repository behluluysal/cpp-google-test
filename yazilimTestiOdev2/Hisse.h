#pragma once
#include "Kurum.h"
#include <string>


class Hisse : public Kurum
{
public:
	std::string _ad;
	float _fiyat;

	Hisse(std::string a, std::string b, std::string ad, float fiyat) : Kurum(a,b)
	{
		_ad = ad;
		_fiyat = fiyat;
	}

	~Hisse() 
	{

	}
};

