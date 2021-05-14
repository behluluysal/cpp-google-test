#pragma once
#include "Kurum.h"
#include <string>

class Portfoy : public Kurum
{
public:
	float _maliyet;
	int _adet;

	Portfoy(std::string a, std::string b, float maliyet, int adet) : Kurum(a,b)
	{
		_adet = adet;
		_maliyet = maliyet;
	}
	~Portfoy()
	{

	}
};

