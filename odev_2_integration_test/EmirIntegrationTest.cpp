#include "pch.h"
#include "../yazilimTestiOdev2/Banka.h"
#include <fstream>
#include <string>
#include "../yazilimTestiOdev2/json.hpp"


TEST(EmirIntegrationTest, emirOlustur) {
    std::fstream newfile;
    Emir* emir;
    newfile.open("emirler1.json", std::ios::in);
    nlohmann::json jf;
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    for (auto& td : jf["Emirler"])
    {
        emir = new Emir ( td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Islem"].get<std::string>(), td["Adet"].get<int>(),"provizyon" );
        if (emir == nullptr)
            break;
        delete emir;
    }


    EXPECT_TRUE(emir != nullptr);
}

TEST(EmirIntegrationTest, emir_isle_tamamlanmis) {
    std::fstream newfile;
    Emir* emir;
    newfile.open("emirler1.json", std::ios::in);
    nlohmann::json jf;
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    std::string donus;
    for (auto& td : jf["Emirler"])
    {
        emir = new Emir(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Islem"].get<std::string>(), td["Adet"].get<int>(), "tamamlanan");
        donus = emir->isleme_al(10, 10, 10);
        delete emir;
        if (donus == "gecersiz")
            break;
    }
    ASSERT_EQ(donus, "gecersiz");
}

TEST(EmirIntegrationTest, emir_isle_hatali_emir_islem_tipi) {
    std::fstream newfile;
    Emir* emir;
    newfile.open("emirler7.json", std::ios::in);
    nlohmann::json jf;
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    std::string donus;
    for (auto& td : jf["Emirler"])
    {
        emir = new Emir(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Islem"].get<std::string>(), td["Adet"].get<int>(), "provizyon");
        donus = emir->isleme_al(10, 10, 10);
        delete emir;
        if (donus == "islem_tipi_bulunamadi")
            break;
    }
    ASSERT_EQ(donus, "islem_tipi_bulunamadi");
}


TEST(EmirIntegrationTest, emir_isle_hatali_adet) {
    std::fstream newfile;
    Emir* emir;
    newfile.open("emirler6.json", std::ios::in);
    nlohmann::json jf;
    if (newfile.is_open()) {
        jf = nlohmann::json::parse(newfile);
        newfile.close();
    }
    std::string donus;
    for (auto& td : jf["Emirler"])
    {
        emir = new Emir(td["_id"].get<std::string>(), td["Sembol"].get<std::string>(), td["Islem"].get<std::string>(), td["Adet"].get<int>(), "provizyon");
        donus = emir->isleme_al(10, 20, 10);
        delete emir;
        if (donus == "satis_islem_basarisiz")
            break;
    }
    ASSERT_EQ(donus, "satis_islem_basarisiz");
}
