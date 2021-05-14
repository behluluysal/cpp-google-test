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

TEST(BankaAdvancedIntegrationTest, hisse_satis_art_arda_adet_kontrol) {
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
    b.portfoy_yazdir();
    int adet = b.portfoy_getir("AKBNK")->_adet;

    ASSERT_EQ(adet, 50);
}


TEST(BankaAdvancedIntegrationTest, hisse_satis_zarar_hesapla) {
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
    float zarar = b.emir_getir("6083d99543ab796362cf3c")->zarar;

    ASSERT_EQ(zarar, 226.800049f);
}

TEST(BankaAdvancedIntegrationTest, toplam_kar_hesapla) {
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
    b.portfoy_yazdir();
    float kar = b._kar - b._zarar;

    ASSERT_EQ(kar, 117.199951f);
}

TEST(BankaAdvancedIntegrationTest, toplam_kar_hesapla_emirler2) {
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
    b.portfoy_yazdir();
    float kar = b._kar - b._zarar;

    ASSERT_EQ(kar, 258.0f);
}

TEST(BankaAdvancedIntegrationTest, toplam_kar_hesapla_emirler3) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    newfile.open("emirler3.json", std::ios::in);
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
    b.portfoy_yazdir();
    float kar = b._kar - b._zarar;

    ASSERT_EQ(kar, 344.0f);
}

TEST(BankaAdvancedIntegrationTest, islem_sonrasi_portfoy_sayisi_emirler1) {
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
    b.portfoy_yazdir();

    int a = 0;
    for (int i = 0; i < b.portfoy_elemanlari.size(); ++i)
        a++;

    ASSERT_EQ(a, 2);
}

TEST(BankaAdvancedIntegrationTest, islem_sonrasi_portfoy_sayisi_emirler2) {
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
    b.portfoy_yazdir();

    int a = 0;
    for (int i = 0; i < b.portfoy_elemanlari.size(); ++i)
        a++;

    ASSERT_EQ(a, 4);
}

TEST(BankaAdvancedIntegrationTest, islem_sonrasi_portfoy_sayisi_emirler3) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    newfile.open("emirler3.json", std::ios::in);
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
    b.portfoy_yazdir();

    int a = 0;
    for (int i = 0; i < b.portfoy_elemanlari.size(); ++i)
        a++;

    ASSERT_EQ(a, 3);
}

TEST(BankaAdvancedIntegrationTest, emirler1_size_hesapla) {
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


    ASSERT_EQ(b.emirler.size(), 3);
}

TEST(BankaAdvancedIntegrationTest, emirler2_size_hesapla) {
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


    ASSERT_EQ(b.emirler.size(), 2);
}

TEST(BankaAdvancedIntegrationTest, emirler3_size_hesapla) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    newfile.open("emirler3.json", std::ios::in);
    nlohmann::json jf;
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Emirler"])
    {
        b.emir_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Islem"].get<std::string>(), td["Adet"].get<int>());
    }


    ASSERT_EQ(b.emirler.size(), 3);
}

TEST(BankaAdvancedIntegrationTest, hisseler_size_hesapla) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    nlohmann::json jf;
    newfile.open("hisseler.json", std::ios::in);
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Hisseler"])
    {
        b.hisse_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Ad"].get<std::string>(), td["Fiyat"].get<float>());
    }


    ASSERT_EQ(b.hisse_listesi.size(), 100);
}

TEST(BankaAdvancedIntegrationTest, portfoy_size_hesapla) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    nlohmann::json jf;
    newfile.open("portfoy.json", std::ios::in);
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Portfoy"])
    {
        b.portfoy_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Maliyet"].get<float>(), td["Adet"].get<int>());
    }


    ASSERT_EQ(b.portfoy_elemanlari.size(), 4);
}

TEST(BankaAdvancedIntegrationTest, portfoy_hisse_adet_hesapla) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    nlohmann::json jf;
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
    b.portfoy_yazdir();
    int a = 0;
    for (int i = 0; i < b.portfoy_elemanlari.size(); ++i)
        a += b.portfoy_elemanlari[i]._adet;

    ASSERT_EQ(a, 1920);
}

TEST(BankaAdvancedIntegrationTest, emirler3_islem_adet_hesapla) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    newfile.open("emirler3.json", std::ios::in);
    nlohmann::json jf;
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Emirler"])
    {
        b.emir_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Islem"].get<std::string>(), td["Adet"].get<int>());
    }

    int a = 0;
    for (int i = 0; i < b.emirler.size(); ++i)
        a += b.emirler[i]._adet;

    ASSERT_EQ(a, 650);
}

TEST(BankaAdvancedIntegrationTest, emirler2_islem_adet_hesapla) {
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

    int a = 0;
    for (int i = 0; i < b.emirler.size(); ++i)
        a += b.emirler[i]._adet;

    ASSERT_EQ(a, 150);
}

TEST(BankaAdvancedIntegrationTest, emirler1_islem_adet_hesapla) {
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

    int a = 0;
    for (int i = 0; i < b.emirler.size(); ++i)
        a += b.emirler[i]._adet;

    ASSERT_EQ(a, 570);
}

TEST(BankaAdvancedIntegrationTest, sifir_satis_test) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    newfile.open("emirler4.json", std::ios::in);
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


    b.emirleri_gerceklestir();
    b.portfoy_hesapla();

    float maliyet = b.portfoy_getir("AKBNK")->_maliyet;

    ASSERT_EQ(maliyet, 4.87f);
}

TEST(BankaAdvancedIntegrationTest, sifir_alis_test) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    newfile.open("emirler5.json", std::ios::in);
    nlohmann::json jf;
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Emirler"])
    {
        b.emir_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Islem"].get<std::string>(), td["Adet"].get<int>());
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

    newfile.open("hisseler.json", std::ios::in);
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Hisseler"])
    {
        b.hisse_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Ad"].get<std::string>(), td["Fiyat"].get<float>());
    }


    b.emirleri_gerceklestir();
    b.portfoy_hesapla();

    float maliyet = b.portfoy_getir("AKBNK")->_maliyet;

    ASSERT_EQ(maliyet, 3.15000010f);
}

TEST(BankaAdvancedIntegrationTest, yanlis_adet_satmaya_calis) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
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

    newfile.open("portfoy.json", std::ios::in);
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Portfoy"])
    {
        b.portfoy_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Maliyet"].get<float>(), td["Adet"].get<int>());
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


    b.emirleri_gerceklestir();
    b.portfoy_hesapla();
    int flag = 0;
    for (int i = 0; i < b.emirler.size(); ++i)
    {
        if (b.emirler[i]._durum == "provizyon")
        {
            flag = 1;
            break;
        }
    }
    ASSERT_EQ(flag, 1);
}

TEST(BankaAdvancedIntegrationTest, yanlis_durumlu_hisse_satmaya_calis) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    newfile.open("emirler6.json", std::ios::in);
    nlohmann::json jf;
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Emirler"])
    {
        b.emir_ekle(td["_id"].get<std::string>(), "hatali_islem", td["Islem"].get<std::string>(), td["Adet"].get<int>());
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

    newfile.open("hisseler.json", std::ios::in);
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Hisseler"])
    {
        b.hisse_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Ad"].get<std::string>(), td["Fiyat"].get<float>());
    }


    b.emirleri_gerceklestir();
    b.portfoy_hesapla();
    int flag = 0;
    for (int i = 0; i < b.emirler.size(); ++i)
    {
        if (b.emirler[i]._durum == "provizyon")
        {
            flag ++;
        }
    }
    ASSERT_EQ(flag, 3);
}

TEST(BankaAdvancedIntegrationTest, portfoy_maliyet_hesapla2) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    newfile.open("emirler3.json", std::ios::in);
    nlohmann::json jf;
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Emirler"])
    {
        b.emir_ekle(td["_id"].get<std::string>(), "hatali_islem", td["Islem"].get<std::string>(), td["Adet"].get<int>());
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

    newfile.open("hisseler.json", std::ios::in);
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Hisseler"])
    {
        b.hisse_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Ad"].get<std::string>(), td["Fiyat"].get<float>());
    }


    b.emirleri_gerceklestir();
    b.portfoy_hesapla();

    float maliyet = b.portfoy_getir("TUPRS")->_maliyet;

    ASSERT_EQ(maliyet, 86.5000000f);
}

TEST(BankaAdvancedIntegrationTest, alim_sonrasi_maliyet) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
    newfile.open("emirler3.json", std::ios::in);
    nlohmann::json jf;
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Emirler"])
    {
        b.emir_ekle(td["_id"].get<std::string>(), "hatali_islem", td["Islem"].get<std::string>(), td["Adet"].get<int>());
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

    newfile.open("hisseler.json", std::ios::in);
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Hisseler"])
    {
        b.hisse_ekle(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Ad"].get<std::string>(), td["Fiyat"].get<float>());
    }


    b.emirleri_gerceklestir();
    b.portfoy_hesapla();

    float maliyet = b.portfoy_getir("TATGD")->_maliyet;

    ASSERT_EQ(maliyet, 8.50000000f);
}

TEST(BankaAdvancedIntegrationTest, toplam_zarar_hesapla) {
    std::fstream newfile;
    Banka b = Banka(0, 0, 0);
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
    float zarar = b._zarar - b._kar;

    ASSERT_EQ(zarar, 3.50000000f);
}

