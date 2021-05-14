#include "pch.h"
#include "../yazilimTestiOdev2/Banka.h"
#include "../yazilimTestiOdev2/Portfoy.h"
#include "../yazilimTestiOdev2/Hisse.h"
#include "../yazilimTestiOdev2/Emir.h"
//test adi, metod adi +test
TEST(BankaUnitTest, banka_olustur) {
	Banka* banka = new Banka(0,0,0);
	EXPECT_TRUE(banka != nullptr);
	delete banka;
}

TEST(BankaUnitTest, hisse_ekle) {
	Banka* banka = new Banka(0, 0, 0);
	std::string donus="";
	donus = banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
	ASSERT_EQ(donus , "basarili");
	delete banka;
}

TEST(BankaUnitTest, emir_ekle) {
	Banka* banka = new Banka(0, 0, 0);
	std::string donus = "";
	donus = banka->emir_ekle("6083d99c82183862cf3c4f", "TATGD", "ALIS", 250);
	ASSERT_EQ(donus, "basarili");
	delete banka;
}

TEST(BankaUnitTest, portfoy_ekle) {
	Banka* banka = new Banka(0, 0, 0);
	std::string donus = "";
	donus = banka->portfoy_ekle("6083d1634308183462cf3c9d", "TUPRS", 86.5, 1100);
	ASSERT_EQ(donus, "basarili");
	delete banka;
}

TEST(BankaUnitTest, emirleri_gerceklestir) {
	Banka* banka = new Banka(0, 0, 0);
	std::string donus = "";
	banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
	banka->emir_ekle("6083d99c82183862cf3c4f", "TATGD", "ALIS", 250);
	donus = banka->emirleri_gerceklestir();
	ASSERT_EQ(donus, "islem_basarili");
	delete banka;
}

TEST(BankaUnitTest, kayitsiz_hisse_alis_emri) {
	Banka* banka = new Banka(0, 0, 0);
	std::string donus = "";
	banka->emir_ekle("6083d99c82183862cf3c4f", "TATGD", "ALIS", 250);
	donus = banka->emirleri_gerceklestir();
	ASSERT_EQ(donus, "hisse bulunamadi TATGD");
	delete banka;
}

TEST(BankaUnitTest, kayitsiz_hisse_satis_emri) {
	Banka* banka = new Banka(0, 0, 0);
	std::string donus = "";
	banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
	banka->emir_ekle("6083d99c82183862cf3c4f", "TATGD", "SATIS", 250);
	donus = banka->emirleri_gerceklestir();
	ASSERT_EQ(donus, "hisse bulunamadi TATGD");
	delete banka;
}

TEST(BankaUnitTest, kayitsiz_portfoy_satis_emri) {
	Banka* banka = new Banka(0, 0, 0);
	std::string donus = "";
	banka->emir_ekle("6083d99c82183862cf3c4f", "TATGD", "SATIS", 250);
	donus = banka->emirleri_gerceklestir();
	ASSERT_EQ(donus, "portfoy bulunamadi TATGD");
	delete banka;
}

TEST(BankaUnitTest, yeni_hisse_alis_emri) {
	Banka* banka = new Banka(0, 0, 0);
	std::string donus = "";
	banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
	banka->emir_ekle("6083d99c82183862cf3c4f", "TATGD", "ALIS", 250);
	donus = banka->emirleri_gerceklestir();
	ASSERT_EQ(donus, "islem_basarili");
	delete banka;
}

TEST(BankaUnitTest, hisse_alis_emri) {
	Banka* banka = new Banka(0, 0, 0);
	std::string donus = "";
	banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
	banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
	banka->emir_ekle("6083d99c82183862cf3c4f", "TATGD", "ALIS", 250);
	donus = banka->emirleri_gerceklestir();
	ASSERT_EQ(donus, "islem_basarili");
	delete banka;
}

TEST(BankaUnitTest, ekli_portfoy_getir) {
	Banka* banka = new Banka(0, 0, 0);
	Portfoy* p;
	banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
	p = banka->portfoy_getir("TATGD");
	EXPECT_TRUE(p != nullptr);
	delete banka;
}

TEST(BankaUnitTest, ekli_olmayan_portfoy_getir) {
	Banka* banka = new Banka(0, 0, 0);
	Portfoy* p;
	banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
	p = banka->portfoy_getir("eklidegil");
	EXPECT_TRUE(p == nullptr);
	delete banka;
}

TEST(BankaUnitTest, ekli_hisse_getir) {
	Banka* banka = new Banka(0, 0, 0);
	Hisse* p;
	banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
	p = banka->hisse_getir("TATGD");
	EXPECT_TRUE(p != nullptr);
	delete banka;
}

TEST(BankaUnitTest, ekli_olmayan_hisse_getir) {
	Banka* banka = new Banka(0, 0, 0);
	Hisse* p;
	banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
	p = banka->hisse_getir("eklidegil");
	EXPECT_TRUE(p == nullptr);
	delete banka;
}

TEST(BankaUnitTest, ekli_emir_getir) {
	Banka* banka = new Banka(0, 0, 0);
	Emir* p;
	banka->emir_ekle("6083d99c82183862cf3c4f", "TATGD", "ALIS", 250);
	p = banka->emir_getir("6083d99c82183862cf3c4f");
	EXPECT_TRUE(p != nullptr);
	delete banka;
}

TEST(BankaUnitTest, ekli_olmayan_emir_getir) {
	Banka* banka = new Banka(0, 0, 0);
	Emir* p;
	banka->emir_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
	p = banka->emir_getir("eklidegil");
	EXPECT_TRUE(p == nullptr);
	delete banka;
}

TEST(BankaUnitTest, portfoy_hesapla) {
	Banka* banka = new Banka(0, 0, 0);
	std::string donus = "";
	donus = banka->portfoy_hesapla();
	ASSERT_EQ(donus, "basarili");
	delete banka;
}

TEST(BankaUnitTest, portfoy_yazdir) {
	Banka* banka = new Banka(0, 0, 0);
	std::string donus = "";
	donus = banka->portfoy_yazdir();
	ASSERT_EQ(donus, "basarili");
	delete banka;
}