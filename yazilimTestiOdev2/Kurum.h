#pragma once
#include <string>
class Kurum
{
public:
	std::string _id;
	std::string _sembol;

	explicit Kurum(std::string id, std::string sembol)
	{
		_id = id;
		_sembol = sembol;
	}
};

