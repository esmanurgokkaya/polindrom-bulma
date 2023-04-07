#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>		// bu kýsýmda kodda kullanýlan bazý fonksiyonlar için gerekli kütüphaneleri tanýmladým

struct Node {			// tek yönlü baðlý liste için bir düðün oluþturulur
	char data ;			// kelimemizi tutmasý için char tipinde deðiþken tanýmlanýr
	struct Node* next;	// bir sonraki deðiþkenin de yerini tutabilmesi için bir struct daha oluþturulur
};

// bu fonksiyon bizim kullanýcýdan aldýðýmýz kelimenin polindrom olup olmadýðýný kontrol eder.
bool Kontrol( struct Node* head){		// main içinde kelimemizi attýðýmýz listenin head bilgisini parametre olarak alýr
	// kontrolleri yapabilmemiz için gerekli deðiþkenler tanýmlanýr
	int i,uzunluk = 0;		
	char kelime[50];	
	
	// bu kýsýmda baðlý listedeki elemanlar bizi diziye aktarýlýr 
	struct Node* current = head;
	while (current != NULL){		// eðer o dizi boþsa döngüye girer
		kelime[uzunluk++] = current->data;		// kelime dizisiine elemanlar aktarýlýr
		current = current->next;		/* kelime aktarýldýktan sonra currenta diðer elemanýn bilgisi aktarýlýr 
										ve böylece döngü tekrar döndüðünde boþ olup olmadýðý kontrol edilir*/
	}
	// bu while döngüsü bittiðinde uzunluk  bilgisi de alýnmýþ  olur 
	
	// bu for kelime uzunnluðunun yarýsý kadar dönerek kelimenin baþ ve sonunu kontrol eder
	for (i = 0; i < uzunluk / 2; i++){
		if(kelime[i] != kelime[uzunluk - 1 - i]){	// kelimenin baþtan ve sondan olacak þekilde kontrolu yapýlýr
			return false;			// ayný olmadýðý durumlar ele alýnýr eðer eþit deðilse false döner ve kelime polindrom olmaz
		}
	}
	
	// döngü kontrolünden sonra eðer hiç if içine girmemiþse çýkar ve true döner kelime polindrom olmuþ olur
	return true;
}


int main(int argc, char *argv[]) {
	
	struct Node* head = NULL;		// taanýmlanan düðün bir head deðiþkenini baþlangýç alarak tanýmlanýr ve null deðerini alýr 
	int i;
	char kelime[50];
	// kullanýcýya çýktýlar verilerek kelime alýnýr
	printf("**********POLINDROM KELIME BULMA**********\n");
	printf("Polindrom olup olmadigini kontrol etmek icin bir kelime giriniz\n>>> ");
	scanf(" %s",kelime);
	// alýnan kelimenin uzunluðu hesaplanýr
	int uzunluk = strlen(kelime);
	
	// kelimenin uzunluðu kadar dönerek kelime için bellekte yer açýlýr ve bir listeye aktarýlýr
	for(i = 0; i < uzunluk; i++ ){
	struct Node* yeni_node = (struct Node*)malloc(sizeof(struct Node));		// yeni bir deðiþkenle bellekte yer açýlýr
	yeni_node->data = kelime[i] ;		// deðiþkene sýrasýyla kelimenin elemanlarý gelir
	yeni_node->next = head;			// sýradaki elemana head deðeri aktarýlýr böylece birbirlerinin yerini tutarlar
	head = yeni_node;			// head bilgisine yeni_node atanarak döngü içinde listenin deðer ve sýradaki elemanýn  yerini tutmasý saðlanýr
}
	// bu if kýsmýnda kontrol fonksiyonuna head bilgisi verilir ve true döndüðünde kelime polindrom dönmediðinde polindrom deðil yazýsý yazdýrýlýr
	if(Kontrol(head)){
		printf("\n%s bir polindrom kelimedir\n",kelime);
	}
	else {
		printf("\n%s bir polindrom kelime degildir\n",kelime);
	}
	return 0;
}


