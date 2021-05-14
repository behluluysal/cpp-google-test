#include "pch.h"
#include "../yazilimTestiOdev2/Banka.h"
#include <fstream>
#include <string>
#include "../yazilimTestiOdev2/json.hpp"

TEST(BankaAdvancedIntegrationTest, hisse_satis_kar_hesapla) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    newfile.open("emirler1.json", std::ios::in);
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

    newfile.open("portfoy.json", std::ios::in);
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Portfoy"])
    {
        b.portfoy_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Maliyet"].get<float>(), td["Adet"].get<int>());
    }

    b.emirleri_gerceklestir();

    float kar = b.emir_getir("6083d99c82183862cf3c4f")->kar;

    ASSERT_EQ(kar, 344.0f);
}

TEST(BankaAdvancedIntegrationTest, hisse_satis_art_arda_hesapla) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    newfile.open("emirler2.json", std::ios::in);
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

    newfile.open("portfoy.json", std::ios::in);
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Portfoy"])
    {
        b.portfoy_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Maliyet"].get<float>(), td["Adet"].get<int>());
    }

    b.emirleri_gerceklestir();

    float kar = b.emir_getir("6083d99c82183862cf3c4f")->kar;

    ASSERT_EQ(kar, 240.799988f);
}


void test()
{

}