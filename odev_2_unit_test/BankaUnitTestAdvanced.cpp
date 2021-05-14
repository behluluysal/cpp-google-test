#include "pch.h"
#include "../yazilimTestiOdev2/Banka.h"
#include "../yazilimTestiOdev2/Portfoy.h"
#include "../yazilimTestiOdev2/Hisse.h"
#include "../yazilimTestiOdev2/Emir.h"


TEST(BankaAdvancedUnitTest, banka_olustur) {
	Banka* banka = new Banka(0, 0, 0);
	EXPECT_TRUE(banka != nullptr);
	delete banka;
}

TEST(BankaAdvancedUnitTest, hisse_satis_kar_hesapla) {
	Banka* banka = new Banka(0, 0, 0);

    banka->portfoy_ekle("6083d9954308183862cf3c4f", "AKBNK", 3.15, 200);
    banka->portfoy_ekle("6083d9954308196362cf3c50", "AKSA", 16.25, 120);
    banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
    banka->portfoy_ekle("6083d1634308183462cf3c9d", "TUPRS", 86.5, 1100);

    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 200);
    banka->emir_ekle("6083d99543ab796362cf3c", "AKSA", "SATIS", 120);
    banka->emir_ekle("6083d99543abb16362cf3c", "TATGD", "ALIS", 250);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c9d", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3ca9", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();

    float kar = banka->emir_getir("6083d99c82183862cf3c4f")->kar;

	ASSERT_EQ(kar, 344.0f);
	delete banka;
}

TEST(BankaAdvancedUnitTest, hisse_satis_zarar_hesapla) {
    Banka* banka = new Banka(0, 0, 0);

    banka->portfoy_ekle("6083d9954308183862cf3c4f", "AKBNK", 3.15, 200);
    banka->portfoy_ekle("6083d9954308196362cf3c50", "AKSA", 16.25, 120);
    banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
    banka->portfoy_ekle("6083d1634308183462cf3c9d", "TUPRS", 86.5, 1100);

    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 200);
    banka->emir_ekle("6083d99543ab796362cf3c", "AKSA", "SATIS", 120);
    banka->emir_ekle("6083d99543abb16362cf3c", "TATGD", "ALIS", 250);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c9d", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3ca9", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    float zarar = banka->emir_getir("6083d99543ab796362cf3c")->zarar;

    ASSERT_EQ(zarar, 226.800049f);
    delete banka;
}

TEST(BankaAdvancedUnitTest, toplam_kar_hesapla) {
    Banka* banka = new Banka(0, 0, 0);

    banka->portfoy_ekle("6083d9954308183862cf3c4f", "AKBNK", 3.15, 200);
    banka->portfoy_ekle("6083d9954308196362cf3c50", "AKSA", 16.25, 120);
    banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
    banka->portfoy_ekle("6083d1634308183462cf3c9d", "TUPRS", 86.5, 1100);

    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 200);
    banka->emir_ekle("6083d99543ab796362cf3c", "AKSA", "SATIS", 120);
    banka->emir_ekle("6083d99543abb16362cf3c", "TATGD", "ALIS", 250);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c9d", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3ca9", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();
    float kar = banka->_kar- banka->_zarar;

    ASSERT_EQ(kar, 117.199951f);
    delete banka;
}

TEST(BankaAdvancedUnitTest, toplam_zarar_hesapla) {
    Banka* banka = new Banka(0, 0, 0);

    banka->portfoy_ekle("6083d9954308183862cf3c4f", "AKBNK", 3.15, 200);
    banka->portfoy_ekle("6083d9954308196362cf3c50", "AKSA", 16.25, 200);
    banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
    banka->portfoy_ekle("6083d1634308183462cf3c9d", "TUPRS", 86.5, 1100);

    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 200);
    banka->emir_ekle("6083d99543ab796362cf3c", "AKSA", "SATIS", 200);
    banka->emir_ekle("6083d99543abb16362cf3c", "TATGD", "ALIS", 250);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();
    float zarar = banka->_zarar - banka->_kar;

    ASSERT_EQ(zarar, 34.000000f);         
    delete banka;
}

TEST(BankaAdvancedUnitTest, portfoy_adet_hesapla) {
    Banka* banka = new Banka(0, 0, 0);

    banka->portfoy_ekle("6083d9954308183862cf3c4f", "AKBNK", 3.15, 200);
    banka->portfoy_ekle("6083d9954308196362cf3c50", "AKSA", 16.25, 200);
    banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
    banka->portfoy_ekle("6083d1634308183462cf3c9d", "TUPRS", 86.5, 1100);

    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 200);
    banka->emir_ekle("6083d99543ab796362cf3c", "AKSA", "SATIS", 200);
    banka->emir_ekle("6083d99543abb16362cf3c", "TATGD", "ALIS", 250);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    int adet = banka->portfoy_getir("TATGD")->_adet;

    ASSERT_EQ(adet, 750);
    delete banka;
}

TEST(BankaAdvancedUnitTest, portfoy_adet_hesapla2) {
    Banka* banka = new Banka(0, 0, 0);

    banka->portfoy_ekle("6083d9954308183862cf3c4f", "AKBNK", 3.15, 200);
    banka->portfoy_ekle("6083d9954308196362cf3c50", "AKSA", 16.25, 200);
    banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
    banka->portfoy_ekle("6083d1634308183462cf3c9d", "TUPRS", 86.5, 1100);

    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 200);
    banka->emir_ekle("6083d99543ab796362cf3c", "AKSA", "SATIS", 200);
    banka->emir_ekle("6083d99543abb16362cf3c", "TATGD", "ALIS", 250);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    int adet = banka->portfoy_getir("TUPRS")->_adet;

    ASSERT_EQ(adet, 1100);
    delete banka;
}

TEST(BankaAdvancedUnitTest, portfoy_maliyet_hesapla) {
    Banka* banka = new Banka(0, 0, 0);

    banka->portfoy_ekle("6083d9954308183862cf3c4f", "AKBNK", 3.15, 200);
    banka->portfoy_ekle("6083d9954308196362cf3c50", "AKSA", 16.25, 200);
    banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
    banka->portfoy_ekle("6083d1634308183462cf3c9d", "TUPRS", 86.5, 1100);

    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 200);
    banka->emir_ekle("6083d99543ab796362cf3c", "AKSA", "SATIS", 200);
    banka->emir_ekle("6083d99543abb16362cf3c", "TATGD", "ALIS", 250);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    float maliyet = banka->portfoy_getir("TATGD")->_maliyet;

    ASSERT_EQ(maliyet, 8.75666714f);
    delete banka;
}

TEST(BankaAdvancedUnitTest, portfoy_maliyet_hesapla2) {
    Banka* banka = new Banka(0, 0, 0);

    banka->portfoy_ekle("6083d9954308183862cf3c4f", "AKBNK", 3.15, 200);
    banka->portfoy_ekle("6083d9954308196362cf3c50", "AKSA", 16.25, 200);
    banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
    banka->portfoy_ekle("6083d1634308183462cf3c9d", "TUPRS", 86.5, 1100);

    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 200);
    banka->emir_ekle("6083d99543ab796362cf3c", "AKSA", "SATIS", 200);
    banka->emir_ekle("6083d99543abb16362cf3c", "TATGD", "ALIS", 250);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    float maliyet = banka->portfoy_getir("TUPRS")->_maliyet;

    ASSERT_EQ(maliyet, 86.5000000f);
    delete banka;
}

TEST(BankaAdvancedUnitTest, emir_provizyonda_takildi_mi) {
    Banka* banka = new Banka(0, 0, 0);

    banka->portfoy_ekle("6083d9954308183862cf3c4f", "AKBNK", 3.15, 200);
    banka->portfoy_ekle("6083d9954308196362cf3c50", "AKSA", 16.25, 200);
    banka->portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
    banka->portfoy_ekle("6083d1634308183462cf3c9d", "TUPRS", 86.5, 1100);

    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "hata", 200);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    std::string durum = banka->emir_getir("6083d99c82183862cf3c4f")->_durum;

    ASSERT_EQ(durum, "provizyon");
    delete banka;
}



TEST(BankaAdvancedUnitTest, satin_alim_gerceklestir) {
    Banka* banka = new Banka(0, 0, 0);


    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "ALIS", 200);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    int adet = banka->portfoy_getir("AKBNK")->_adet;

    ASSERT_EQ(adet, 200);
    delete banka;
}

TEST(BankaAdvancedUnitTest, art_arda_satis_adet) {
    Banka* banka = new Banka(0, 0, 0);


    banka->portfoy_ekle("6083d9954308183462cf3c9d", "AKBNK", 8.5, 200);

    banka->emir_ekle("6083d99c82183862cf3c4d", "AKBNK", "SATIS", 100);
    banka->emir_ekle("6083d99c82183862cf3c4g", "AKBNK", "SATIS", 99);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    int adet = banka->portfoy_getir("AKBNK")->_adet;

    ASSERT_EQ(adet, 1);
    delete banka;
}

TEST(BankaAdvancedUnitTest, art_arda_satis_maliyet) {
    Banka* banka = new Banka(0, 0, 0);


    banka->portfoy_ekle("6083d9954308183462cf3c9d", "AKBNK", 12, 200);

    banka->emir_ekle("6083d99c82183862cf3c4d", "AKBNK", "SATIS", 100);
    banka->emir_ekle("6083d99c82183862cf3c4g", "AKBNK", "SATIS", 99);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    float maliyet = banka->portfoy_getir("AKBNK")->_maliyet;

    ASSERT_EQ(maliyet, 12.0f);
    delete banka;
}


TEST(BankaAdvancedUnitTest, art_arda_alim) {
    Banka* banka = new Banka(0, 0, 0);


    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "ALIS", 100);
    banka->emir_ekle("6083d99c82183862cf3c4d", "AKBNK", "ALIS", 100);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    int adet = banka->portfoy_getir("AKBNK")->_adet;

    ASSERT_EQ(adet, 200);
    delete banka;
}

TEST(BankaAdvancedUnitTest, art_arda_alim_maliyet) {
    Banka* banka = new Banka(0, 0, 0);


    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "ALIS", 100);
    banka->emir_ekle("6083d99c82183862cf3c4d", "AKBNK", "ALIS", 100);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    float maliyet = banka->portfoy_getir("AKBNK")->_maliyet;

    ASSERT_EQ(maliyet, 4.87f);
    delete banka;
}

TEST(BankaAdvancedUnitTest, art_arda_al_sat) {
    Banka* banka = new Banka(0, 0, 0);


    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "ALIS", 100);
    banka->emir_ekle("6083d99c82183862cf3c4d", "AKBNK", "ALIS", 100);
    banka->emir_ekle("6083d99c82183862cf3c4g", "AKBNK", "SATIS", 99);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    int adet = banka->portfoy_getir("AKBNK")->_adet;

    ASSERT_EQ(adet, 101);
    delete banka;
}

TEST(BankaAdvancedUnitTest, alim_sonrasi_maliyet) {
    Banka* banka = new Banka(0, 0, 0);

    banka->portfoy_ekle("6083d9954308183462cf3c9d", "AKBNK", 12, 100);
    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "ALIS", 100);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 6);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    float maliyet = banka->portfoy_getir("AKBNK")->_maliyet;

    ASSERT_EQ(maliyet, 9.0f);
    delete banka;
}

TEST(BankaAdvancedUnitTest, satis_sonrasi_maliyet) {
    Banka* banka = new Banka(0, 0, 0);

    banka->portfoy_ekle("6083d9954308183462cf3c9d", "AKBNK", 12, 100);
    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "SATIS", 50);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 6);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    float maliyet = banka->portfoy_getir("AKBNK")->_maliyet;

    ASSERT_EQ(maliyet, 12.0f);
    delete banka;
}

TEST(BankaAdvancedUnitTest, art_arda_al_sat_maliyet_hesapla) {
    Banka* banka = new Banka(0, 0, 0);


    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "ALIS", 100);
    banka->emir_ekle("6083d99c82183862cf3c4d", "AKBNK", "ALIS", 100);
    banka->emir_ekle("6083d99c82183862cf3c4g", "AKBNK", "SATIS", 99);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);
    banka->hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    banka->hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    float maliyet = banka->portfoy_getir("AKBNK")->_maliyet;

    ASSERT_EQ(maliyet, 4.86999989f);
    delete banka;
}

TEST(BankaAdvancedUnitTest, sifir_maliyet_test) {
    Banka* banka = new Banka(0, 0, 0);


    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "ALIS", 100);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 0);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    float maliyet = banka->portfoy_getir("AKBNK")->_maliyet;

    ASSERT_EQ(maliyet, 0);
    delete banka;
}

TEST(BankaAdvancedUnitTest, sifir_satis_test) {
    Banka* banka = new Banka(0, 0, 0);


    banka->emir_ekle("6083d99c82183862cf3c4f", "AKBNK", "ALIS", 100);

    banka->hisse_ekle("6083d9954308183462cf3c4f", "AKBNK", "AKBANK", 4.87);

    banka->emirleri_gerceklestir();
    banka->portfoy_hesapla();

    float maliyet = banka->portfoy_getir("AKBNK")->_maliyet;

    ASSERT_EQ(maliyet, 4.87f);
    delete banka;
}