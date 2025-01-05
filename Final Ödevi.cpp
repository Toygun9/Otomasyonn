#include <stdio.h>
#include <string.h>


typedef struct {
    char isim[50];
    char adres[100];
    char urun[50];
    char odemeBilgileri[50];
} Musteri;

void bilgileriDosyayaKaydet(Musteri *musteri);

int main() {
    printf("Hoþgeldiniz.....\n");
    Musteri musteri;
    int islem;

    do {
        
        printf("Müþteri adresini giriniz: ");
        scanf("%99s", musteri.adres);

        printf("Ýþlem Menüsü:\n1. Yeni Sipariþ Al\n2. Ödemeye Yönlendir\n3. Kayýt Düzelt\nLütfen iþlem seçinin: ");
        scanf("%d", &islem);

        switch (islem) {
            case 1:
                printf("Müþteri ismini girin: ");
                scanf("%s", musteri.isim);
                printf("Müþterinin istediði ürünü girin: ");
                scanf("%s", musteri.urun);
                printf("Yeni sipariþ sisteme kaydedildi.\n");
                break;
            case 2:
                printf("Ödeme için gerekli bilgileri girin: ");
                scanf("%s", musteri.odemeBilgileri);
                printf("Müþteri ödeme için yönlendirildi.\n");
                break;
            case 3:
                printf("Yeni müþteri adresini girin: ");
                scanf("%s", musteri.adres);
                printf("Müþteri bilgileri güncellendi.\n");
                break;
            default:
                printf("Geçersiz iþlem.\n");
        }

        bilgileriDosyayaKaydet(&musteri);

        printf("Müþterinin baþka bir iþlemi var mý (evet/hayýr): ");
        scanf("%4s", devam);

    } while (strcmp(devam, "evet") == 0);

    printf("Sistem Kapanýyor.\n");
    return 0;
}

void bilgileriDosyayaKaydet(Musteri *musteri) {
    FILE *dosya = fopen("musteri_kayitlari.txt", "a");

    if (dosya == NULL) {
        printf("Dosya bulunamadý!\n");
        return;
    }

    fprintf(dosya, "Müþteri Adý: %s\nAdres: %s\nÜrün: %s\nÖdeme Bilgileri: %s\n-----------------------------\n", 
            musteri->isim, musteri->adres, musteri->urun, musteri->odemeBilgileri);

    fclose(dosya);
    printf("Bilgiler dosyaya kaydedildi.\n");
}

