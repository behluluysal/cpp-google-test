/*
    @author Süleyman Behlül UYSAL
    @date   14.05.2021
    @no     g171210080
*/

#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"


#include "Banka.h"

int main()
{
    Banka b = Banka(0, 0, 0);
    std::fstream newfile;

    newfile.open("emirler6.json", std::ios::in);
    nlohmann::json jf;
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close(); 
    }
    for (auto& td : jf["Emirler"])
    {
        b.emir_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Islem"].get<std::string>(), td["Adet"].get<int>());
    }

    newfile.open("hisseler.json", std::ios::in);
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close(); 
    }
    for (auto& td : jf["Hisseler"])
    {
        b.hisse_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Ad"].get<std::string>(), td["Fiyat"].get<float>());
    }

    newfile.open("portfoy2.json", std::ios::in);
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Portfoy"])
    {
        b.portfoy_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Maliyet"].get<float>(), td["Adet"].get<int>());
    }
            
    b.emirleri_gerceklestir();
    b.portfoy_yazdir();
}
