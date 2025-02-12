// dosyalar04.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_LENGTH 20
typedef struct ucusDat
{
    int ucusNo; // 1 - 1000
    char kalkisYeri[MAX_LENGTH + 1]; //20 karakter
    char varisYeri[MAX_LENGTH + 1]; //20 karakter
    int kalkisSaati; //tamsayi
    int kalkisDakikasi; //tamsayi
    int koltukKapasitesi; //tamsayi
    int bosKoltuk; //tamsayi
    //int doluluk;
    float BbiletFiyati; //gerçel
}ucusDat;
typedef struct biletxt
{
    int ucusNo;
    char Tc[12];
    float bilet_fiyati;

}bilet;
void ucusBilgileriListele(FILE *dosya1)
{
    ucusDat u;
    int okunan, ucusKodu, ucusNo;
    bool bulundu = false;
    do 
    {           
        printf("Lutfen ucus kodunuzu giriniz :");
        scanf("%d", &ucusKodu);
        if (ucusKodu < 1 || ucusKodu>1000)
        {
            printf("Ucus kodunuzu yanlış girdiniz. ");        
        }        
    }
    while (ucusKodu < 1 || ucusKodu>1000);
    
    while ((okunan = fread(&u, sizeof(ucusDat), 1, dosya1)) != 0)
    {
        if (ucusKodu == u.ucusNo)
        {
            bulundu = true;
            printf("Ucus No: %d   ", u.ucusNo);
            printf("Kalkis Yeri: %s   ", u.kalkisYeri);
            printf("Varis Yeri: %s   ", u.varisYeri);
            printf("Kalkis Zamani: %d:%d   ", u.kalkisSaati, u.kalkisDakikasi);
            printf("Ucak Kapasitesi: %d   ", u.koltukKapasitesi);
            printf("Bos Koltuk Sayisi: %d   ", u.bosKoltuk);
            printf("Doluluk :%d\n", (100 - ((100 * u.bosKoltuk) / u.koltukKapasitesi)));
        }
      
    }  
    if (bulundu == false)
    {
        printf("Bu ucus numarasina ait ucus bulunamadi!..");
    }
    fclose(dosya1);
}
void satilanBiletleriListele(FILE *dosya1, FILE *dosya2)
{
    ucusDat u;
    bilet b;
    int okunan, ucusKodu, ucusNo ,tc ,biletFiyati;
    bool bulundu = false;
    do
    {
        printf("Lutfen ucus kodunuzu giriniz :");
        scanf("%d", &ucusKodu);
        if (ucusKodu < 1 || ucusKodu>1000)
        {
            printf("Ucus kodunuzu yanlış girdiniz. ");
        }
    } while (ucusKodu < 1 || ucusKodu>1000);

    while ((okunan = fread(&u, sizeof(ucusDat), 1, dosya1)) != 0)
    {
        if (ucusKodu == u.ucusNo)
        {            
            bulundu = true;
            printf("Ucus No: %d   ", u.ucusNo);
            printf("Kalkis Yeri: %s   ", u.kalkisYeri);
            printf("Varis Yeri: %s   ", u.varisYeri);
            printf("Kalkis Zamani: %d:%d   ", u.kalkisSaati, u.kalkisDakikasi);
            printf("Ucak Kapasitesi: %d   ", u.koltukKapasitesi);
            printf("Bos Koltuk : %d   ", u.bosKoltuk);
            printf("Doluluk : %% %d\n", (100 - ((100 * u.bosKoltuk) / u.koltukKapasitesi)));
        }
        

    }
    if (bulundu == false)
    {
        printf("Bu ucus numarasina ait ucus bulunamadi!..");
    }

    //dosya başına almak için
    while (fscanf(dosya2, "%d %s %2.f",&b.ucusNo ,&b.Tc, &b.bilet_fiyati) == 3)
    {   rewind(dosya2);
        if (ucusKodu == b.ucusNo)
        {            
            printf("Tc Kimlik Numarasi = %s\n",b.Tc);
            printf("Başlangıç Bilet Fiyati = %2.f\n", b.bilet_fiyati);
        }
    }
    fclose(dosya1);
    fclose(dosya2);
}
void kalkisYeri(FILE* dosya)
{
    #define MAX_LENGTH 20
    char kalkisYeri[MAX_LENGTH + 1];
    printf("Lutfen kalkis yeri giriniz :");
    scanf("%s", &kalkisYeri);
    ucusDat u;
    int okunan;
    while ((okunan = fread(&u, (int)sizeof(ucusDat), 1, dosya)) != 0) {
        if (strcmp(u.kalkisYeri, kalkisYeri) == 0) {
            printf("Ucus No: %d   ", u.ucusNo);
            printf("Kalkis Yeri: %s   ", u.kalkisYeri);
            printf("Varis Yeri: %s   ", u.varisYeri);
            printf("Kalkis Zamani: %d:%d   ", u.kalkisSaati, u.kalkisDakikasi);
            printf("Ucak Kapasitesi: %d   ", u.koltukKapasitesi);
            printf("Bos Koltuk Sayisi: %d   ", u.bosKoltuk);
            printf("Doluluk : %d   ", (100 - ((100 * u.bosKoltuk) / u.koltukKapasitesi)));
            //printf("bbf : %.2f", u.BbiletFiyati);
            printf("\n");
        }
    }
}
void yolcuBiletleriListele(FILE *dosya1, FILE *dosya2)
{
    #define MAX_LENGTH 11
    ucusDat u;
    bilet b;
    int  okunan1 ,okunan2;
    char tc[ MAX_LENGTH + 1];
    printf("Lutfen tc kimliğinizi giriniz : ");
    scanf("%s",tc);
    rewind(dosya2);
    while ((okunan1 = fread(&u, sizeof(ucusDat), 1, dosya1)) != 0 && (okunan2 = fread(&b, sizeof(bilet), 1, dosya2)) != 0)
    {
        fseek(dosya2, 0, SEEK_SET);
        if (strcmp(tc , b.Tc) == 0 && b.ucusNo == u.ucusNo)
        {
            fseek(dosya2, 0, SEEK_CUR);
            printf("Ucus No: %d\n", u.ucusNo);
            printf("Kalkis Yeri: %s\n", u.kalkisYeri);
            printf("Varis Yeri: %s\n", u.varisYeri);
            printf("Kalkis Zamani: %d:%d\n", u.kalkisSaati, u.kalkisDakikasi);
            printf("Ucak Kapasitesi: %d\n", u.koltukKapasitesi);
            printf("Bos Koltuk Sayisi: %d\n", u.bosKoltuk);
            printf("Doluluk : %d\n", (100 - ((100 * u.bosKoltuk) / u.koltukKapasitesi)));
            break;
        }
    }   
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
    printf("1-Bir uçuşun bilgilerinin listelenmesi\n\n");
    printf("2-Bir uçuşun bilgilerinin ve satılan biletlerin listelenmesi\n\n");
    printf("3-Bir yerden kalkan uçakların bilgilerinin listelenmesi\n\n");
    printf("4-Koltuk doluluk oranı %50'nin altında olan uçuşların listelenmesi\n\n");
    printf("5-Bir yolcunun biletlerinin listelenmesi\n\n");
    printf("\n");
    int islemNo;
    printf("Lutfen islem Numarasi giriniz :");
    scanf("%d", &islemNo);
    switch (islemNo)
    {
        case 1:
            ucusBilgileriListele(dosya_dat);
            break;
        case 2:
            satilanBiletleriListele(dosya_dat, dosya_txt);
            break;
        case 3:
            kalkisYeri(dosya_dat);
            break;
        case 4:
            yolcuBiletleriListele(dosya_dat, dosya_txt);
            break;

    default:
        printf("Gecersiz islem numarasi !..");
        break;
    }
    
    
    
    return 0;
}
