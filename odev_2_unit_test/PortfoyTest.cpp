#include "pch.h"
#include "../yazilimTestiOdev2/Portfoy.h"

//test adi, metod adi +test
TEST(PortfoyUnitTest, portfoy_olustur) {
	Portfoy* portfoy = new Portfoy("6083d1634308183462cf3c9d", "TUPRS", 86.5, 1100);
	EXPECT_TRUE(portfoy != nullptr);
	delete portfoy;
}
