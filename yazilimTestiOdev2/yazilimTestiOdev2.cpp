/*
    @author Süleyman Behlül UYSAL
    @date   14.05.2021
    @no     g171210080
*/

#include <iostream>
#include "Banka.h"
int main()
{
    Banka b = Banka(0, 0, 0);
    
    b.portfoy_ekle("6083d9954308183862cf3c4f","AKBNK",3.15,200);
    b.portfoy_ekle("6083d9954308196362cf3c50", "AKSA", 16.25, 120);
    b.portfoy_ekle("6083d9954308183462cf3c9d", "TATGD", 8.5, 500);
    b.portfoy_ekle("6083d1634308183462cf3c9d", "TUPRS", 86.5, 1100);

    b.emir_ekle("6083d99c82183862cf3c4f", "AKBNK","SATIS",200);
    b.emir_ekle("6083d99c82183862cf3c4f", "AKSA", "SATIS", 120);
    b.emir_ekle("6083d99c82183862cf3c4f", "TATGD", "ALIS", 250);

    b.hisse_ekle("6083d9954308183462cf3c4f","AKBNK","AKBANK",4.87);
    b.hisse_ekle("6083d9954308183462cf3c50", "AKSA", "AKSA", 14.36);
    b.hisse_ekle("6083d9954308183462cf3c4f", "TATGD", "TAT GIDA", 9.27);
    b.hisse_ekle("6083d9954308183462cf3c4f", "TUPRS", "TUPRAS", 86.5);

    b.emirleri_gerceklestir();
    b.portfoy_yazdir();
}
