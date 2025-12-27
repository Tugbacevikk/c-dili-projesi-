#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Ozanin ismini ve özelliklerini tutar
typedef struct {
    char isim[50];          // Ozanin ismi
    char calgi[50];        // Ozanin çalgisi
    int can;               // Ozanin can durumu
    int tok;               // Tokluk durumu
    int uyku;              // Uyku durumu
    int hijyen;            // Hijyen durumu
    int altin;             // Ozanin sahip oldugu altin miktari
    int deneyim;           // Ozanin deneyim puani
    int seviye;            // Ozanin seviyesi
    int guc;               // Güç durumu
    int ceviklik;          // çeviklik durumu
    int karizma;           //karizma durumu
    int toplayicilik;      //toplayicilik durumu
    int dayaniklilik;
} Ozan;

// Ozanin durumunu gösterir
void durumGoster(Ozan *ozan) {
    printf("\n--- Ozan Durumu ---\n");
    printf("isim: %s\n", ozan->isim);
    printf("Çalgi: %s\n", ozan->calgi);
    printf("Can: %d\n", ozan->can);
    printf("Tokluk: %d\n", ozan->tok);
    printf("Uyku: %d\n", ozan->uyku);
    printf("temizlik: %d\n", ozan->hijyen);
    printf("Altin: %d\n", ozan->altin);
    printf("Deneyim: %d\n", ozan->deneyim);
    printf("guc: %d\n", ozan->guc);
    printf("ceviklik: %d\n", ozan->ceviklik);
    printf("karizma: %d\n", ozan->karizma);
    printf("toplayicilik %d\n", ozan->toplayicilik);
    printf("dayaniklilik %d\n", ozan->dayaniklilik);
    printf("Seviye: %d\n", ozan->seviye);


    printf("----------------------\n");
}

// Degerleri sinirlandirma fonksiyonu
void sinirla(Ozan *ozan) {
    if (ozan->can > 100) ozan->can = 100;
    if (ozan->can < 0) ozan->can = 0;

    if (ozan->tok > 100) ozan->tok = 100;
    if (ozan->tok < 0) ozan->tok = 0;

    if (ozan->uyku > 100) ozan->uyku = 100;
    if (ozan->uyku < 0) ozan->uyku = 0;

    if (ozan->hijyen > 100) ozan->hijyen = 100;
    if (ozan->hijyen < 0) ozan->hijyen = 0;

    if (ozan->guc > 25) ozan->guc = 25;
    if (ozan->guc < 3) ozan->guc = 3;

    if (ozan->ceviklik > 25) ozan->ceviklik = 25;
    if (ozan->ceviklik < 3) ozan->ceviklik = 3;

    if (ozan->karizma > 25) ozan->karizma = 25;
    if (ozan->karizma < 3) ozan->karizma = 3;

    if (ozan->toplayicilik > 25) ozan->toplayicilik = 25;
    if (ozan->toplayicilik < 3) ozan->toplayicilik = 3;

    if (ozan->dayaniklilik > 25) ozan->dayaniklilik = 25;
    if (ozan->dayaniklilik < 3) ozan->dayaniklilik = 3;}


// Ozanin seviye atlama fonksiyonu
    void seviyeAtla(Ozan *ozan) {
     if(ozan->deneyim <100) {
        printf("seviye atlamak için yeterli deneyim yok");
     }
    if (ozan->deneyim >= 100) { // 100 deneyim puaninda seviye atla
        ozan->seviye++;
        ozan->deneyim -= 100; // Deneyimi sifirla
        printf("Tebrikler! %d. seviyeye yükseldin!\n", ozan->seviye);


         }


    }

//ozanin cani 0 oldugunda oyundan cikan program
    void olumKontrol(Ozan *ozan) {
    if (ozan->can <= 0) {
        printf("\n*** oyun sona erdi ***\n", ozan->isim);
        exit(0); // Programdan çıkış yap
    }
}


   // Hayata kalip kalmamayi kontrol eden fonksiyon
  void hayattakalma(Ozan *ozan) {
    int canAzalma = 0; // Her turdaki toplam can kaybi

    // Tokluk sıfırsa can kaybı
    if (ozan->tok <= 0) {
        canAzalma += 20; // Tokluk sıfırsa 20 can kaybı
        printf("Uyarı: Tokluk seviyen sıfıra ulaştı! Canın azalıyor.\n");
    } else if (ozan->tok < 20) {
        printf("Uyarı: Tokluk seviyen kritik seviyede (%d)!\n", ozan->tok);
    }

    // Uyku sıfırsa can kaybı
    if (ozan->uyku <= 0) {
        canAzalma += 10; // Uyku sıfırsa 10 can kaybı
        printf("Uyarı: Uyku seviyen sıfıra ulaştı! Canın azalıyor.\n");
    } else if (ozan->uyku < 20) {
        printf("Uyarı: Uyku seviyen kritik seviyede (%d)!\n", ozan->uyku);
    }

    // Hijyen sİfİrsa can kaybı
    if (ozan->hijyen <= 0) {
        canAzalma += 5; // Hijyen sıfırsa 5 can kaybı
        printf("Uyarı: Hijyen seviyen sıfıra ulaştı! Canın azalıyor.\n");
    } else if (ozan->hijyen < 20) {
        printf("Uyarı: Hijyen seviyen kritik seviyede (%d)!\n", ozan->hijyen);
    }

    // Toplam can kaybını uygulama
    if (canAzalma > 0) {
        ozan->can -= canAzalma;
        printf("Uyarı: %d can kaybettin! Kalan can: %d\n", canAzalma, ozan->can);
    }

    // Can durumu kontrolü
    olumKontrol(ozan); // Ozanin ölüp ölmedigini kontrol et
}



// Kamp alaninda yapilacak aktiviteler
void kamp(Ozan *ozan) {
    int secim;
    printf("\nKamp Alaninda Ne Yapmak istersin?\n");
    printf("1. Kamp atesinin basinda calgi cal/sarki soyle\n");
    printf("2. Nehirde yikan\n");
    printf("3. cadirina girip uyu\n");
    printf("4. cadirda biraz kestir");
    printf("5. köy meydanina dön\n");
    printf("Seciminizi yapin: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            printf("sarki söyledin\n");
            ozan->deneyim += 20;  // deneyim artı
            ozan->tok-=10;
            ozan->uyku-=5;
            break;
        case 2:
            printf("Nehirde yikandin\n");
            ozan->hijyen += 10;   // Hijyen artirma
            ozan->uyku-=5;
            break;
        case 3:
            printf("uzun bir Uyku çektin. \n");
            ozan->uyku += 30; // Uyku artirma
            ozan->hijyen-=10;
            ozan->guc+=20;
            ozan->tok-20;
            break;
              case 4:
            printf("kestirme molasi \n");
            ozan->uyku += 10; // Uyku artırma
            ozan->guc+=10;

            break;
        case 5:
            printf("Koy meydanina dondun.\n");
            return;
        default:
            printf("Gecersiz secim. Lütfen tekrar deneyin.\n");
            break;
    }
    sinirla(ozan); // Deðerleri sinirla
    seviyeAtla(ozan); // Seviye atlama kontrolü
    olumKontrol(ozan);  // Ölüp ölmediğini kontrol et
    hayattakalma(ozan);
}

// Han'daki aktiviteler
void han(Ozan *ozan) {
    int secim;
    printf("\n handa ne yapmak istersin?\n");
    printf("1. Yiyecek satin al ve ye\n");
    printf("2. icecek satin al, ic ve eglen\n");
    printf("3. Enstrüman cal ve sarki söyle\n");
    printf("4. Köy meydanina dön\n");
    printf("Seciminizi yapin: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            printf("Yiyecek satin aldin. Tokluk seviyen artti.\n");
            ozan->tok += 20;      // Tokluk artirma
            ozan->altin -= 5;     // Yiyecek fiyati
            break;
        case 2:
            printf("icecek satin aldin. .\n");
            ozan->altin -= 3;     // içecek fiyati
            break;
        case 3:
            printf("sarki söyledin Deneyim kazandin.\n");
            ozan->deneyim += 20;  // Tecrübe artýrma
            break;
        case 4:
            printf("Köy meydanina döndün.\n");
            return;
        default:
            printf("Gecersiz secim. Lütfen tekrar deneyin.\n");
            break;
    }
    sinirla(ozan); // Deðerleri sinýrla
    seviyeAtla(ozan); // Seviye atlama kontrolü
    olumKontrol(ozan);  // Ölüp ölmediğini kontrol et
    hayattakalma(ozan);
}

// Macera aktiviteleri
void macera(Ozan *ozan) {
    int zorluk;
    printf("\nMaceraya çiktin şimdi nereye gitmek istersin \n");
    printf("1. yakin çevreden sifali bitki topla ve avlan\n");
    printf("2. ormani keşfe çik kolay\n");
    printf("3. kayaliklari keşfe cik \n");
    printf("4. vadiye keşfe çik zor\n");
    printf("5.köy meydanina dön\n");
    printf("Seçiminizi yapin: ");
    scanf("%d", &zorluk);

    int kazanc = 0; // Kazanilan altin ve deneyim
    switch (zorluk) {

         case 1: {
    kazanc = rand() % 1 + 4; // Altın kazancı
    printf("Kazandığın altın miktarı: %d\n", kazanc);

    int bitkiBulmaIhtimali = ozan->toplayicilik / 4; // Toplayıcılık / 4 oranında şans
    int rastgeleSayi = rand() % 100;

    // Şifalı bitki bulma kontrolü
    if (rastgeleSayi < bitkiBulmaIhtimali) {
        printf("Toplayıcılık yeteneğin sayesinde şifalı bir bitki buldun! Canın 10 arttı.\n");
        ozan->can += 10;
    }

    // Meyve toplama kontrolü
    rastgeleSayi = rand() % 100; // Yeni bir rastgele sayı üretilir
    if (rastgeleSayi < bitkiBulmaIhtimali) {
        printf("Toplayıcılık yeteneğin sayesinde meyve buldun! Tokluğun 10 arttı.\n");
        ozan->tok += 10;
    }

    // Av hayvanı avlama kontrolü
    rastgeleSayi = rand() % 100; // Yeni bir rastgele sayı üretilir
    if (rastgeleSayi < (bitkiBulmaIhtimali / 2)) { // Yarı şans ile avlanma
        printf("Av hayvanı avladın! Tokluğun 50 arttı.\n");
        ozan->tok += 50;
    }

    // Eğer hiçbir şey bulunamazsa kullanıcı bilgilendirilir
    if (rastgeleSayi >= (bitkiBulmaIhtimali / 2) &&
        rastgeleSayi >= bitkiBulmaIhtimali) {
        printf("Bugün ne şifalı bitki bulabildin ne de meyve veya av hayvanı yakalayabildin.\n");
    }

    sinirla(ozan); // Değerleri sinirla
    break;
}
case 2: {  // Kolay keşif
    int haydutGuc = rand() % 3 + 1;  // 1-3 arasında güç
    int haydutCeviklik = rand() % 3 + 1;  // 1-3 arasında çeviklik
    int haydutDayaniklilik = rand() % 3 + 1;  // 1-3 arasında dayanıklılık

    printf("Kolay keşif! Haydutla karşılaşıyorsun...\n");
    printf("Haydut Gücü: %d, Haydut Çevikliği: %d, Haydut Dayanıklılığı: %d\n", haydutGuc, haydutCeviklik, haydutDayaniklilik);

    // Ozan'a seçim yapması için seçenekler sunuluyor
    printf("Haydutla savaşmak istersen 'S', kaçmak istersen 'K' tuşuna bas.\n");
    char secim;
    scanf(" %c", &secim);

    if (secim == 'S' || secim == 's') {
        // Savaş başlıyor
        while (ozan->can > 0 && haydutDayaniklilik > 0) {
            int ozanHasar = 4 * ozan->guc;  // Ozan'ın verdiği hasar
            int haydutHasar = 4 * haydutGuc;  // Haydut'un verdiği hasar

            // Alınan hasarı hesapla
            int ozanAlinanHasar = haydutHasar - (haydutHasar * ozan->dayaniklilik * 4 / 100);
            int haydutAlinanHasar = ozanHasar - (ozanHasar * haydutDayaniklilik * 4 / 100);

            // Ozan ilk saldırıyı yapacaksa
            if (ozan->ceviklik > haydutCeviklik) {
                haydutDayaniklilik -= haydutAlinanHasar;
                printf("Hayduta %d hasar verdin. Haydut'un canı: %d\n", haydutAlinanHasar, haydutDayaniklilik);
            } else if (ozan->ceviklik < haydutCeviklik) {
                ozan->can -= ozanAlinanHasar;
                printf("Ozan'a %d hasar verdi. Ozan'ın canı: %d\n", ozanAlinanHasar, ozan->can);
            } else {
                // Çeviklikler eşitse, %50 ihtimalle kim başlayacak?
                if (rand() % 2 == 0) {
                    haydutDayaniklilik -= haydutAlinanHasar;
                    printf("Hayduta %d hasar verdin. Haydut'un canı: %d\n", haydutAlinanHasar, haydutDayaniklilik);
                } else {
                    ozan->can -= ozanAlinanHasar;
                    printf("Ozan'a %d hasar verdi. Ozan'ın canı: %d\n", ozanAlinanHasar, ozan->can);
                }
            }

            // Eğer Ozan'ın canı sıfırsa savaş sonlanır
            if (ozan->can <= 0) {
                printf("Ozan hayatını kaybetti! Haydutlar seni yendi.\n");
                break;
            } else if (haydutDayaniklilik <= 0) {
                kazanc = rand() % 11 + 15; // 15-25 altın
                printf("Kolay maceradan %d altın kazandın ve haydutları yendin!\n", kazanc);
                ozan->deneyim += 15;  // Deneyim kazancı
                break;
            }

            // Kaçma seçeneği
            printf("Kaçmak istersen 'K', savaşmaya devam etmek için 'S' tuşuna bas.\n");
            scanf(" %c", &secim);
            if (secim == 'K' || secim == 'k') {
                int kacarMi = rand() % 100 + 1;
                int kacinmaIhtimali = ozan->ceviklik * 4 / 100;

                if (kacarMi <= kacinmaIhtimali * 100) {
                    printf("Kaçmayı başardın! Haydutlarla savaşmaya gerek yok.\n");
                    break;
                } else {
                    printf("Kaçmayı başaramadın! Savaş devam ediyor...\n");
                }
            }
        }
    } else if (secim == 'K' || secim == 'k') {
        int kacarMi = rand() % 100 + 1;
        int kacinmaIhtimali = ozan->ceviklik * 4 / 100;

        if (kacarMi <= kacinmaIhtimali * 100) {
            printf("Kaçmayı başardın! Haydutlarla savaşmaya gerek yok.\n");
        } else {
            printf("Kaçmayı başaramadın! Savaş başlıyor...\n");
        }
    }
    break;
}

case 3: {  // Orta keşif
    int haydutGuc = rand() % 3 + 4;  // 4-6 arasında güç
    int haydutCeviklik = rand() % 3 + 4;  // 4-6 arasında çeviklik
    int haydutDayaniklilik = rand() % 3 + 4;  // 4-6 arasında dayanıklılık

    printf("Orta keşif! Haydutla karşılaşıyorsun...\n");
    printf("Haydut Gücü: %d, Haydut Çevikliği: %d, Haydut Dayanıklılığı: %d\n", haydutGuc, haydutCeviklik, haydutDayaniklilik);

    // Ozan'a seçim yapması için seçenekler sunuluyor
    printf("Haydutla savaşmak istersen 'S', kaçmak istersen 'K' tuşuna bas.\n");
    char secim;
    scanf(" %c", &secim);

    if (secim == 'S' || secim == 's') {
        // Savaş başlıyor
        while (ozan->can > 0 && haydutDayaniklilik > 0) {
            int ozanHasar = 4 * ozan->guc;
            int haydutHasar = 4 * haydutGuc;

            // Alınan hasarı hesapla
            int ozanAlinanHasar = haydutHasar - (haydutHasar * ozan->dayaniklilik * 4 / 100);
            int haydutAlinanHasar = ozanHasar - (ozanHasar * haydutDayaniklilik * 4 / 100);

            if (ozan->ceviklik > haydutCeviklik) {
                haydutDayaniklilik -= haydutAlinanHasar;
                printf("Hayduta %d hasar verdin. Haydut'un canı: %d\n", haydutAlinanHasar, haydutDayaniklilik);
            } else if (ozan->ceviklik < haydutCeviklik) {
                ozan->can -= ozanAlinanHasar;
                printf("Ozan'a %d hasar verdi. Ozan'ın canı: %d\n", ozanAlinanHasar, ozan->can);
            } else {
                if (rand() % 2 == 0) {
                    haydutDayaniklilik -= haydutAlinanHasar;
                    printf("Hayduta %d hasar verdin. Haydut'un canı: %d\n", haydutAlinanHasar, haydutDayaniklilik);
                } else {
                    ozan->can -= ozanAlinanHasar;
                    printf("Ozan'a %d hasar verdi. Ozan'ın canı: %d\n", ozanAlinanHasar, ozan->can);
                }
            }

            // Kaçma seçeneği
            printf("Kaçmak istersen 'K', savaşmaya devam etmek için 'S' tuşuna bas.\n");
            scanf(" %c", &secim);
            if (secim == 'K' || secim == 'k') {
                int kacarMi = rand() % 100 + 1;
                int kacinmaIhtimali = ozan->ceviklik * 4 / 100;

                if (kacarMi <= kacinmaIhtimali * 100) {
                    printf("Kaçmayı başardın! Haydutlarla savaşmaya gerek yok.\n");
                    break;
                } else {
                    printf("Kaçmayı başaramadın! Savaş devam ediyor...\n");
                }
            }
        }
    }
    break;
}

case 4: {  // Zor keşif
    int haydutGuc = rand() % 4 + 7;  // 7-10 arasında güç
    int haydutCeviklik = rand() % 4 + 7;  // 7-10 arasında çeviklik
    int haydutDayaniklilik = rand() % 4 + 7;  // 7-10 arasında dayanıklılık

    printf("Zor keşif! Haydutla karşılaşıyorsun...\n");
    printf("Haydut Gücü: %d, Haydut Çevikliği: %d, Haydut Dayanıklılığı: %d\n", haydutGuc, haydutCeviklik, haydutDayaniklilik);

    // Ozan'a seçim yapması için seçenekler sunuluyor
    printf("Haydutla savaşmak istersen 'S', kaçmak istersen 'K' tuşuna bas.\n");
    char secim;
    scanf(" %c", &secim);

    if (secim == 'S' || secim == 's') {
        // Savaş başlıyor
        while (ozan->can > 0 && haydutDayaniklilik > 0) {
            int ozanHasar = 4 * ozan->guc;
            int haydutHasar = 4 * haydutGuc;

            // Alınan hasarı hesapla
            int ozanAlinanHasar = haydutHasar - (haydutHasar * ozan->dayaniklilik * 4 / 100);
            int haydutAlinanHasar = ozanHasar - (ozanHasar * haydutDayaniklilik * 4 / 100);

            if (ozan->ceviklik > haydutCeviklik) {
                haydutDayaniklilik -= haydutAlinanHasar;
                printf("Hayduta %d hasar verdin. Haydut'un canı: %d\n", haydutAlinanHasar, haydutDayaniklilik);
            } else if (ozan->ceviklik < haydutCeviklik) {
                ozan->can -= ozanAlinanHasar;
                printf("Ozan'a %d hasar verdi. Ozan'ın canı: %d\n", ozanAlinanHasar, ozan->can);
            } else {
                if (rand() % 2 == 0) {
                    haydutDayaniklilik -= haydutAlinanHasar;
                    printf("Hayduta %d hasar verdin. Haydut'un canı: %d\n", haydutAlinanHasar, haydutDayaniklilik);
                } else {
                    ozan->can -= ozanAlinanHasar;
                    printf("Ozan'a %d hasar verdi. Ozan'ın canı: %d\n", ozanAlinanHasar, ozan->can);
                }
            }

            // Kaçma seçeneği
            printf("Kaçmak istersen 'K', savaşmaya devam etmek için 'S' tuşuna bas.\n");
            scanf(" %c", &secim);
            if (secim == 'K' || secim == 'k') {
                int kacarMi = rand() % 100 + 1;
                int kacinmaIhtimali = ozan->ceviklik * 4 / 100;

                if (kacarMi <= kacinmaIhtimali * 100) {
                    printf("Kaçmayı başardın! Haydutlarla savaşmaya gerek yok.\n");
                    break;
                } else {
                    printf("Kaçmayı başaramadın! Savaş devam ediyor...\n");
                }
            }
        }
    }
    break;
}
             case 5:
            printf("Köy meydanina döndün.\n");
            return;
        default:
            printf("Geçersiz seçim. Lütfen tekrar deneyin.\n");
            return;
    }
    ozan->altin += kazanc;   // Altýný güncelle
    ozan->deneyim += 30;      // Tecrübe artýrma
    sinirla(ozan); // Degerleri sinirla
    olumKontrol(ozan);  // Ölüp ölmediğini kontrol et
    seviyeAtla(ozan); // Seviye atlama kontrolü
    hayattakalma(ozan);
}

void sifahane(Ozan *ozan) {
    int secim;
    printf("\nsifahane Alaninda Ne Yapmak istersin?\n");
    printf("1. sifacıdan yaralariniğ sarmasini iste\n");
    printf("2. sifacidan merhem iste\n");
    printf("3. Köy meydanina dön\n");
    printf("Seçiminizi yapin: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            printf("Yaralarin iyilesti, saglik ve deneyim kazandin.\n");
            ozan->deneyim += 20;  // Tecrübe artirma
            ozan->guc += 5;
            ozan->can += 15;
            break;
        case 2:
            printf("sifacidan merhem aldin, yaralarin sarildi.\n");
            ozan->guc += 10;   // Güç artirma
            ozan->deneyim+=5;
            ozan->can +=5;
            break;
        case 3:
            printf("Köy meydanina döndün.\n");
            return;
        default:
            printf("Geçersiz seçim. Lütfen tekrar deneyin.\n");
            break;
    }
    sinirla(ozan); // Degerleri sinirla
    seviyeAtla(ozan); // Seviye atlama kontrolü
    olumKontrol(ozan);  // Ölüp ölmediğini kontrol et
    hayattakalma(ozan);
}


void komsuyagit(Ozan *ozan){

        printf("1. Komşuya yardım et ve altın kazan.\n");
        printf("2. Komşudan parayla yiyecek al.\n");
        printf("3.köy meydanina geri dön");



        int secim;
        printf("Seçiminizi yapın: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1: // Komşuya yardım et ve altın kazan
                printf("Komşuya yardım ettin! 50 altın kazandın.\n");
                ozan->altin += 50;  // Altın ekleniyor
                ozan->guc += 10;    // Güç kazanılıyor
                break;

            case 2: // Komşudan parayla yiyecek al
                if (ozan->altin >= 20) { // Yeterli altın var mı?
                    printf("Komşudan yiyecek aldın! 30 altın harcadın.\n");
                    ozan->altin -= 20;  // Altın düşürülüyor
                    ozan->tok += 10;    // Tokluk artırılıyor
                    ozan->hijyen -= 5;  // Hijyen azalıyor
                } else {
                    printf("Yeterli altının yok!\n");
                }
                break;
          case 3:
            printf("Köy meydanina döndün.\n");
            return;
        default:
            printf("Geçersiz seçim. Lütfen tekrar deneyin.\n");
            break;
    }
    sinirla(ozan); // Degerleri sinirla

    olumKontrol(ozan);  // Ölüp ölmediğini kontrol et
    hayattakalma(ozan);
}









int main() {
    srand(time(NULL)); // Rastgele sayi üretimi için

    Ozan ozan; // Ozan deðiþkenini tanimlama
    ozan.can = 100;         // Ozanin baþlangiç cani
    ozan.tok = 50;          // Ozanin baþlangiç tok durumu
    ozan.uyku = 50;         // Ozanin baþlangiç uyku durumu
    ozan.hijyen = 100;      // Ozanin baþlangiç hijyen durumu
    ozan.altin = 10;        // Ozanin baþlangiç altýn miktarý
    ozan.deneyim = 0;       // Ozanin baþlangiç deneyim puaný
    ozan.seviye = 1;        // Ozanin baþlangiç seviyesi
    ozan.guc = 5;           // Ozanin baþlangiç güç seviyesi
    ozan.toplayicilik=15;
    ozan.ceviklik=15;
    ozan.karizma=10;


    printf("Ozanin ismini girin: ");
    scanf("%s", ozan.isim);  // Ozanýn ismini alma
    printf("Ozanin çalgisini girin: ");
    scanf("%s", ozan.calgi);  // Ozanýn çalgýsýný alma

    int secim;
    while (1) {
        printf("\n--- Ana Menü ---\n");
        printf("1. Kamp alanina git\n");
        printf("2. Sifahaneye git\n");
        printf("3. Hana git\n");
        printf("4. Maceraya atil\n");
        printf("5. Durumu göster\n");
        printf("6.komsuya git");
         printf("7. seviye atla\n");
        printf("8. Oyundan cik\n");
        printf("Seçiminizi yapin: ");

        if (scanf("%d", &secim) != 1) { // Hatalý giriþ kontrolü
            printf("Geçersiz secim \n");
            while (getchar() != '\n'); // Giriþ akýþýný temizle
            continue;
        }

        switch (secim) {
            case 1:
                kamp(&ozan);  // Kamp fonksiyonu çaðrýlýr
                break;
            case 2:
                sifahane(&ozan); // Þifahane fonksiyonu çaðrýlýr
                break;
            case 3:
                han(&ozan); // Han fonksiyonu çaðrýlýr
                break;
            case 4:
                macera(&ozan); // Macera fonksiyonu çaðrýlýr
                break;
            case 5:
                durumGoster(&ozan); // Durumu gösterme fonksiyonu çaðrýlýr
                break;

                break;
               case 6:

                 komsuyagit(&ozan);

              case 7:
                seviyeAtla(&ozan);
                break;
            case 8:
                printf("Oyundan cikis yapiliyor %s!\n", ozan.isim);
                exit(0); // Programdan çýkýþ
            default:
                printf("Gecersiz secim lütfen 1 ile 8 arasinda bir secim yapin.\n");
                break;
        }
    }

    return 0;
}




