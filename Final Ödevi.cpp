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
    printf("Ho�geldiniz.....\n");
    Musteri musteri;
    int islem;

    do {
        
        printf("M��teri adresini giriniz: ");
        scanf("%99s", musteri.adres);

        printf("��lem Men�s�:\n1. Yeni Sipari� Al\n2. �demeye Y�nlendir\n3. Kay�t D�zelt\nL�tfen i�lem se�inin: ");
        scanf("%d", &islem);

        switch (islem) {
            case 1:
                printf("M��teri ismini girin: ");
                scanf("%s", musteri.isim);
                printf("M��terinin istedi�i �r�n� girin: ");
                scanf("%s", musteri.urun);
                printf("Yeni sipari� sisteme kaydedildi.\n");
                break;
            case 2:
                printf("�deme i�in gerekli bilgileri girin: ");
                scanf("%s", musteri.odemeBilgileri);
                printf("M��teri �deme i�in y�nlendirildi.\n");
                break;
            case 3:
                printf("Yeni m��teri adresini girin: ");
                scanf("%s", musteri.adres);
                printf("M��teri bilgileri g�ncellendi.\n");
                break;
            default:
                printf("Ge�ersiz i�lem.\n");
        }

        bilgileriDosyayaKaydet(&musteri);

        printf("M��terinin ba�ka bir i�lemi var m� (evet/hay�r): ");
        scanf("%4s", devam);

    } while (strcmp(devam, "evet") == 0);

    printf("Sistem Kapan�yor.\n");
    return 0;
}

void bilgileriDosyayaKaydet(Musteri *musteri) {
    FILE *dosya = fopen("musteri_kayitlari.txt", "a");

    if (dosya == NULL) {
        printf("Dosya bulunamad�!\n");
        return;
    }

    fprintf(dosya, "M��teri Ad�: %s\nAdres: %s\n�r�n: %s\n�deme Bilgileri: %s\n-----------------------------\n", 
            musteri->isim, musteri->adres, musteri->urun, musteri->odemeBilgileri);

    fclose(dosya);
    printf("Bilgiler dosyaya kaydedildi.\n");
}

