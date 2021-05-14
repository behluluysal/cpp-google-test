#include "pch.h"
#include "../yazilimTestiOdev2/Emir.h"

//test adi, metod adi +test
TEST(EmirUnitTest, emir_olustur) {
	Emir* emir = new Emir("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 200, "provizyon");
	EXPECT_TRUE(emir != nullptr);
	delete emir;
}

TEST(EmirUnitTest, emir_isle_tamamlanmis) {
	Emir* emir = new Emir("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 200, "tamamlanan");
	std::string donus = emir->isleme_al(10, 10, 10);
	ASSERT_EQ(donus, "gecersiz");
	delete emir;
}

TEST(EmirUnitTest, emir_isle_hatali_emir_durum) {
	Emir* emir = new Emir("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 200, "hatali_durum_girisi");
	std::string donus = emir->isleme_al(10, 10, 10);
	ASSERT_EQ(donus, "hata");
	delete emir;
}

TEST(EmirUnitTest, emir_isle_hatali_emir_islem_tipi) {
	Emir* emir = new Emir("6083d99c82183862cf3c4f", "AKBNK", "hatali_islem_tipi", 200, "provizyon");
	std::string donus = emir->isleme_al(10, 10, 10);
	ASSERT_EQ(donus, "islem_tipi_bulunamadi");
	delete emir;
}

TEST(EmirUnitTest, emir_isle_hatali_adet) {
	Emir* emir = new Emir("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 11, "provizyon");
	std::string donus = emir->isleme_al(10, 10, 10);
	ASSERT_EQ(donus, "satis_islem_basarisiz");
	delete emir;
}

TEST(EmirUnitTest, emir_isle_satis_zararli) {
	Emir* emir = new Emir("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 10, "provizyon");
	std::string donus = emir->isleme_al(11, 10, 10);
	ASSERT_EQ(donus, "satis_islem_basarili");
	delete emir;
}

TEST(EmirUnitTest, emir_isle_satis_karli) {
	Emir* emir = new Emir("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 10, "provizyon");
	std::string donus = emir->isleme_al(10, 11, 10);
	ASSERT_EQ(donus, "satis_islem_basarili");
	delete emir;
}

TEST(EmirUnitTest, emir_isle_alis) {
	Emir* emir = new Emir("6083d99c82183862cf3c4f", "AKBNK", "ALIS", 10, "provizyon");
	std::string donus = emir->isleme_al(10, 10, 10);
	ASSERT_EQ(donus, "alis_islem_basarili");
	delete emir;
}