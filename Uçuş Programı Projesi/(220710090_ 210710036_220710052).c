// dosyalar05.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    #define MAX_LENGTH 20
    int ucusNo; // 1 - 1000
    char kalkisYeri[MAX_LENGTH + 1]; //20 karakter
    char varisYeri[MAX_LENGTH + 1]; //20 karakter
    int kalkisSaati; //tamsayi
    int kalkisDakikasi; //tamsayi
    int koltukKapasitesi; //tamsayi
    int bosKoltuk; //tamsayi
    float BbiletFiyati; //gerçel
}Ucus;
typedef struct bilet
{
    int ucusNo;
    int tc;//11 karakter
    float biletFiyat;

}bilet;

void veriEkleme(FILE* dosya, FILE* Bilet)
{
    int ucusNo_;
    printf("Lutfen ucus numarasi giriniz :");
    scanf("%d", &ucusNo_);
    Ucus u;
    bilet b;
    int okunan;
    bool bulundu = false;
    fseek(dosya, 0, SEEK_SET);//işaretci, dosyanın başını gösterir
    while ((okunan = fread(&u, (int)sizeof(Ucus), 1, dosya)) != 0 && (okunan = fread(&b, (int)sizeof(bilet), 1, Bilet)) != 0) {
        if (u.ucusNo == ucusNo_) {
            printf("Bu numaraya ait bir ucus mevcut.");
        }
        if (bulundu == false)
        {
            bulundu = true;
            if (ucusNo_ < 1 || ucusNo_>1000)
                printf("gecersiz ucus kodu...\n");

            printf("Tc kimlik no :");
            scanf("%d", b.tc);
            printf("Ucus numaranızı giriniz :");
            scanf("%d", &u.ucusNo);
            printf("Kalkıs Yeri= \n");
            scanf("%s", u.kalkisYeri);
            printf("Varıs  Yeri= \n");
            scanf("%s", u.varisYeri);
            printf("Kalkis Zamani: ");
            scanf("%d:%d", &u.kalkisSaati, &u.kalkisDakikasi);

            fseek(dosya, (int)sizeof(Ucus), SEEK_END);//işaretci, mevcut konumu gösterir. belirtilen konuma göre işaretci ayarlanır. - :geriye dogru sizeof(ucus) byte kadar ilerle.
            // okunan son ucus verisinin boyutu kadar geri sarılır.
            fwrite(&u, sizeof(Ucus), 1, dosya);
            fwrite(&b, sizeof(bilet), 1, Bilet);
            printf("Dosya verileri guncellendi .\n");

        }
    }
}
void UcusKaydiSilme(FILE *dosya , FILE *Bilet)
{
    int ucusNo_ ;
    char onay;
    printf("Lutfen ucus numarasi giriniz :");
    scanf("%d", &ucusNo_);
    Ucus u;
    bilet b;
    int okunan;
    bool bulundu = false;
    fseek(dosya, 0, SEEK_SET);//işaretci, dosyanın başını gösterir
    while ((okunan = fread(&u, (int)sizeof(Ucus), 1, dosya)) != 0 && (okunan = fread(&b, (int)sizeof(bilet), 1, Bilet)) != 0) {
        if (u.ucusNo == ucusNo_) {
            printf("Bu numarali ucus mevcut.\n");
            printf("Silme islemini onaylamak istiyorsaniz 'E' ,istemiyorsaniz 'H' harfi giriniz : ");
            scanf("%c", &onay);
            if (onay== 'E' || onay == 'e')
            {

            }
            else if (onay == 'H' || onay == 'h')
            {
                printf("Silme islemi reddedildi ..");
            }
            else
            {
                printf("gecersiz harf girdiniz.");
            }


        }


    }
}

void kalkisZamanıDegisimi(FILE *dosya)
{
    int ucusNo,x;
    printf("Lutfen ucus numarasi giriniz :");
    scanf("%d", &ucusNo);
    Ucus u;
    int okunan;
    bool bulundu = false;
    fseek(dosya, 0, SEEK_SET);//işaretci, dosyanın başını gösterir
    while ((okunan = fread(&u, sizeof(Ucus), 1, dosya)) != 0) {
        if (x==7) {

            printf("Kalkis Zamani: %d:%d\n", u.kalkisSaati, u.kalkisDakikasi);
            bulundu = true;

            printf("Yeni Kalkis Zamani: ");
            scanf("%d:%d", &u.kalkisSaati, &u.kalkisDakikasi);

            fseek(dosya, (sizeof(Ucus), SEEK_CUR);//işaretci, mevcut konumu gösterir. belirtilen konuma göre işaretci ayarlanır. - :geriye dogru sizeof(ucus) byte kadar ilerle.
            // okunan son ucus verisinin boyutu kadar geri sarılır.
            fwrite(&u, sizeof(Ucus), 1, dosya);
            printf("Kalkis saatiniz guncellendi .\n");
            printf("Yeni kalkis bilgilerini gormek icin tekrardan ucus numaranizi giriniz.");
            printf("\n");
        }
    }
    if (bulundu == false)
    {
        printf("Bu numaraya ait ucus bulunmuyor :");
    }
}

int biletSatisi(FILE* dosya, FILE* Bilet)
{
#define MAX_LENGTH 11
    int ucusNo_;
    printf("Lutfen ucus numarasi giriniz :");
    scanf("%d", &ucusNo_);
    Ucus u;
    //bilet bl;
    int okunan, biletSayisi;
    float biletFiyati = 0;
    //float toplamFiyat = biletFiyati*biletSayisi;
    char onayHarfi, tc[MAX_LENGTH + 1];
    bool bulundu = false;
    fseek(Bilet, 0, SEEK_END);
    fseek(dosya, 0, SEEK_SET);//işaretci, dosyanın başını gösterir
    while ((okunan = fread(&u, (int)sizeof(Ucus), 1, dosya)) != 0) {
        if (u.ucusNo == ucusNo_) {

            printf("Girdiginiz numarada ucus mevcut.\n");
            printf("Almak istediginiz bilet sayisini giriniz : ");
            scanf("%d", &biletSayisi);
            if (u.bosKoltuk >= biletSayisi)
            {
                if (100 >= u.bosKoltuk && u.bosKoltuk > 90)
                {
                    biletFiyati = u.BbiletFiyati;
                }
                else if (90 >= u.bosKoltuk && u.bosKoltuk > 80)
                {
                    biletFiyati = u.BbiletFiyati * (1.1);
                }
                else if (80 >= u.bosKoltuk && u.bosKoltuk > 70)
                {
                    biletFiyati = u.BbiletFiyati * (1.2);
                }
                else if (70 >= u.bosKoltuk && u.bosKoltuk > 60)
                {
                    biletFiyati = u.BbiletFiyati * (1.3);
                }
                else if (60 >= u.bosKoltuk && u.bosKoltuk > 50)
                {
                    biletFiyati = u.BbiletFiyati * (1.4);
                }
                else if (50 >= u.bosKoltuk && u.bosKoltuk > 40)
                {
                    biletFiyati = u.BbiletFiyati * (1.5);
                }
                else if (40 >= u.bosKoltuk && u.bosKoltuk > 30)
                {
                    biletFiyati = u.BbiletFiyati * (1.6);
                }
                else if (30 >= u.bosKoltuk && u.bosKoltuk > 20)
                {
                    biletFiyati = u.BbiletFiyati * (1.7);
                }
                else if (20 >= u.bosKoltuk && u.bosKoltuk > 10)
                {
                    biletFiyati = u.BbiletFiyati * (1.8);
                }
                else if (10 >= u.bosKoltuk && u.bosKoltuk > 0)
                {
                    biletFiyati = u.BbiletFiyati * (1.9);
                }

                printf("bilet sayisi : %d   adet bilet fiyati : %.2f   toplam bilet fiyati : %.2f   \n", biletSayisi, biletFiyati, (biletSayisi * biletFiyati));
                printf("İslemi onayliyorsaniz 'E' , eger onaylamiyorsaniz 'H' harfini giriniz.");
                getchar();
                scanf("%c", &onayHarfi);

                if (onayHarfi == 'e' || onayHarfi == 'E')
                {
                    printf("Isleminiz onaylanmistir..");
                    printf("T.C. kimlik numaranizi giriniz :");
                    scanf("%11s", tc);
                    fseek(dosya, 0, SEEK_SET);
                    fseek(Bilet, 0, SEEK_END);
                    if (strlen(tc) == 11)
                    {
                        fprintf(Bilet, "%d  %s  %2.f\n", ucusNo_, tc, biletFiyati); //%*.*s 11 den 11 karaktere kadar string ifade
                        printf("veriler dosyaya yazildi..");
                        Ucus u;
                        int okunan;
                        bool bulundu = false;
                        fseek(dosya, 0, SEEK_SET);//işaretci, dosyanın başını gösterir
                        while ((okunan = fread(&u, (int)sizeof(Ucus), 1, dosya)) != 0) {
                            if (u.ucusNo == ucusNo_) {
                                bulundu = true;
                                printf("\n%d\n", u.bosKoltuk);
                                u.bosKoltuk = u.bosKoltuk - biletSayisi;
                                fseek(dosya, -(int)sizeof(Ucus), SEEK_CUR);//işaretci, mevcut konumu gösterir. belirtilen konuma göre işaretci ayarlanır. - :geriye dogru sizeof(ucus) byte kadar ilerle.
                                // okunan son ucus verisinin boyutu kadar geri sarılır.
                                fwrite(&u, sizeof(Ucus), 1, dosya);
                                printf("Bos koltuk sayisi guncellendi .\n");
                                printf("%d", u.bosKoltuk);

                            } break;
                        }
                        fclose(dosya);
                    }
                    else
                    {
                        printf("Kimlik numarasini hatali girdiniz!..");
                    }
                }
                else if (onayHarfi == 'h' || onayHarfi == 'H')
                {
                    printf("Isleminiz onaylanmamistir..");

                }
                else
                {
                    printf("Gecersiz harf girdiniz!..");

                }
            }
        }
    }
    free(tc);
    return 0;
}
int main()
{
    setlocale(LC_ALL, "Turkish");
    //C:\\Users\\90546\\OneDrive\\Masaüstü\\nesne_proje\\ucus_1.dat
    FILE* dosya_dat = fopen("C:\\Users\\90546\\OneDrive\\Belgeler\\nesne_proje\\ucus_1.dat", "rb+");
    FILE* dosya_txt = fopen("C:\\Users\\90546\\OneDrive\\Belgeler\\nesne_proje\\bilet.txt", "rb+");
    if (dosya_dat == NULL)
    {
        printf("dosya acilamadi:(");
        return 0;
    }
    if (dosya_txt == NULL)
    {
        printf("dosya acilamadi:(");
        return 0;
    }
    printf("HAVAYOLU BİLET SATIŞ SİSTEMİNE HOŞGELDİNİZ!\n");
    printf("\n");
    printf("1-Yeni bir uçuşun eklenmesi\n\n");
    printf("2-Bir uçuş kaydının silinmesi\n\n");
    printf("3-Bir uçuşun kalkış zamanının değiştirilmesi \n\n");
    printf("4-Yeni bir uçuşa ilişkin biletlerin satılması\n");
    printf("\n");
    int islemNo;
    printf("Islem numarası giriniz :");
    scanf("%d", &islemNo);
    switch (islemNo)
    {
        case 1:
            veriEkleme(dosya_dat, dosya_txt);
            break;
        case 2:
            UcusKaydiSilme(dosya_dat ,dosya_txt);
            break;
        case 3:
            kalkisZamanıDegisimi(dosya_dat);
            break;
        case 4:
            biletSatisi(dosya_dat ,dosya_txt);
            break;
    default:
        printf("Gecersiz islem numarası girdiniz!..");
        break;
    }


    fclose(dosya_dat);
    fclose(dosya_txt);

    return 0;
}



