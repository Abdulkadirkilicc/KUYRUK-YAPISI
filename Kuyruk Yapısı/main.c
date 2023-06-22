#include<stdio.h>
#include<stdlib.h>

// Kuyruk veri yapýsýný tanýmladýk
struct Dugum {
    int veri;
    struct Dugum* sonraki;
};

// Yeni bir düðüm oluþturmak  fonksiyon tanýmladýk
struct Dugum* yeniDugum(int veri) {
    struct Dugum* gecici = (struct Dugum*)malloc(sizeof(struct Dugum));
    gecici->veri = veri;
    gecici->sonraki = NULL;
    return gecici;
}

// Kuyruðun baþýna eleman ekleme iþlemi için fonksiyon  tanýmladýk
void kuyrugaEkle(struct Dugum** bas_ref, struct Dugum** son_ref, int veri) {
    struct Dugum* gecici = yeniDugum(veri);

    if (*bas_ref == NULL) {
        *bas_ref = *son_ref = gecici;
        return;
    }

    (*son_ref)->sonraki = gecici;
    *son_ref = gecici;
}

// Kuyruktan eleman çýkarma iþlemi fonksiyon tanýmladýk
void kuyruktanSil(struct Dugum** bas_ref, struct Dugum** son_ref) {
    if (*bas_ref == NULL) {
        printf("Kuyruk bos.\n");
        printf("\n");
        return;
    }

    struct Dugum* gecici = *bas_ref;
    *bas_ref = (*bas_ref)->sonraki;

    if (*bas_ref == NULL) {
        *son_ref = NULL;
    }

    free(gecici);
	printf("\n");
}

// Kuyruktaki tüm elemanlarý gösterme iþlemi için fonksiyon tanýmladýk
void Goruntuleme(struct Dugum* bas) {
    if (bas == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }

    printf("Kuyruktaki elemanlar: ");
    while (bas != NULL) {
        printf("%d ", bas->veri);
        bas = bas->sonraki;
    }
    printf("\n");
}

int main() {
    struct Dugum* bas = NULL;
    struct Dugum* son = NULL;

    int secim, veri;
    while (1) {
        printf("Lutfen asagidaki islemlerden birini seciniz:\n");
        printf("1. Ekle\n2. Silme\n3. Goruntuleme\n4. Cikis\n");
        printf("Seciminiz:");
        scanf("%d", &secim);

        switch(secim) {
            case 1:
                printf("Eklemek istediginiz degeri giriniz: ");
                scanf("%d", &veri);
                kuyrugaEkle(&bas, &son, veri);
                printf("\n");
                break;
            case 2:
                kuyruktanSil(&bas, &son);
                break;
            case 3:
                Goruntuleme(bas);
                printf("\n");
                break;
            case 4:
            	printf("Cikis Yaptiniz.");
                exit(0);
            default:
                printf("Gecersiz secenek.\n");
                printf("\n");
        }
    }

    return 0;
}

