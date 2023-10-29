#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//SORU3: ÖÐRENCÝ NUMARASI,ÝSÝM VE YAÞININ SAKLI TUTULDUÐU,LÝSTEDEKÝ TÜM DÜÐÜMLERÝ DOLAÞAN,ÖÐRENCÝ BÝLGÝLERÝNÝN TÜMÜNÜ EKRANA YAZAN VE SAYAN FONKSÝYONU YAZINIZ:
//Öðreci özellikleri:
struct Ogrenci {
    int ogrenci_no;
    char isim[50];
    int yas;
    struct Ogrenci* sonraki;
};

//Öðrenci listeye eklenir:
void ogrenciEkle(struct Ogrenci** bas, int no, char isim[], int yas) {
    struct Ogrenci* yeni_ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeni_ogrenci->ogrenci_no = no;
    strcpy(yeni_ogrenci->isim, isim);
    yeni_ogrenci->yas = yas;
    yeni_ogrenci->sonraki = *bas;
    *bas = yeni_ogrenci;
}
//Liste yazdýrýlýr:
void ogrenciListesiniYazdir(struct Ogrenci* bas) {
    int sira = 1;
    struct Ogrenci* suanki = bas;
    while (suanki != NULL) {
        printf(" %d-> Isim: %s    Yas: %d    Ogrenci_no: %d\n", sira, suanki->isim, suanki->yas, suanki->ogrenci_no);
        sira++;
        suanki = suanki->sonraki;
    }
}

int main() {
    struct Ogrenci* bas = NULL;

    // öðrenci bilgileri eklenir: 
    ogrenciEkle(&bas, 209, "öznur", 19);
    ogrenciEkle(&bas, 207, "dilara", 15);
    ogrenciEkle(&bas, 205, "fadime", 16);
    ogrenciEkle(&bas, 203, "mehmet", 20);
    ogrenciEkle(&bas, 201, "fatma", 21);

    // Öðrenci listesini yazdýrma fonksiyonunu çaðýrýlýr:
    ogrenciListesiniYazdir(bas);


    return 0;
}
