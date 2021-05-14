#include "pch.h"
#include "../yazilimTestiOdev2/Kurum.h"

//test adi, metod adi +test
TEST(KurumUnitTest, kurum_olustur) {
	Kurum* kurum = new Kurum("6083d1634308183462cf3c9d", "TUPRS");
	EXPECT_TRUE(kurum != nullptr);
	delete kurum;
}
