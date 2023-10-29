#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//SORU2: LÝSTEYE RASTGELE ÜRETÝLMÝÞ 100 SAYI EKLENSÝN,GÝRÝLEN TÜM SAYILARI BÜYÜKTEN KÜÇÜÐE SIRALAYAN VE EKRANA BASAN C KODUNU YAZINIZ

// Ýki sayýnýn karþýlaþtýrmasý yapýlýr:
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int sayilar[100];

    // 100 rastgele sayýlar üretir:
    int i;
    for (i = 0; i < 100; i++) {
        sayilar[i] = rand() % 1000; // 0 ile 999 arasýnda rastgele sayýlar üretir:
    }

    // Sayýlarý büyükten küçüðe sýralama
    qsort(sayilar, 100, sizeof(int), compare);

    // Sýralanmýþ sayýlarý ekrana yazdýrýr
    printf("Sýralanmýþ Sayýlar:\n");
    for (i = 0; i < 100; i++) {
        printf("%d -> ", sayilar[i]);
    }
    return 0;
}
