#include "pch.h"
#include "../yazilimTestiOdev2/Hisse.h"

//test adi, metod adi +test
TEST(HisseUnitTest, hisse_olustur) {
	Hisse* hisse = new Hisse("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);
	EXPECT_TRUE(hisse != nullptr);
	delete hisse;
}
