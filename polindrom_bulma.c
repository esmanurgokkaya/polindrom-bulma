#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>		// bu k�s�mda kodda kullan�lan baz� fonksiyonlar i�in gerekli k�t�phaneleri tan�mlad�m

struct Node {			// tek y�nl� ba�l� liste i�in bir d���n olu�turulur
	char data ;			// kelimemizi tutmas� i�in char tipinde de�i�ken tan�mlan�r
	struct Node* next;	// bir sonraki de�i�kenin de yerini tutabilmesi i�in bir struct daha olu�turulur
};

// bu fonksiyon bizim kullan�c�dan ald���m�z kelimenin polindrom olup olmad���n� kontrol eder.
bool Kontrol( struct Node* head){		// main i�inde kelimemizi att���m�z listenin head bilgisini parametre olarak al�r
	// kontrolleri yapabilmemiz i�in gerekli de�i�kenler tan�mlan�r
	int i,uzunluk = 0;		
	char kelime[50];	
	
	// bu k�s�mda ba�l� listedeki elemanlar bizi diziye aktar�l�r 
	struct Node* current = head;
	while (current != NULL){		// e�er o dizi bo�sa d�ng�ye girer
		kelime[uzunluk++] = current->data;		// kelime dizisiine elemanlar aktar�l�r
		current = current->next;		/* kelime aktar�ld�ktan sonra currenta di�er eleman�n bilgisi aktar�l�r 
										ve b�ylece d�ng� tekrar d�nd���nde bo� olup olmad��� kontrol edilir*/
	}
	// bu while d�ng�s� bitti�inde uzunluk  bilgisi de al�nm��  olur 
	
	// bu for kelime uzunnlu�unun yar�s� kadar d�nerek kelimenin ba� ve sonunu kontrol eder
	for (i = 0; i < uzunluk / 2; i++){
		if(kelime[i] != kelime[uzunluk - 1 - i]){	// kelimenin ba�tan ve sondan olacak �ekilde kontrolu yap�l�r
			return false;			// ayn� olmad��� durumlar ele al�n�r e�er e�it de�ilse false d�ner ve kelime polindrom olmaz
		}
	}
	
	// d�ng� kontrol�nden sonra e�er hi� if i�ine girmemi�se ��kar ve true d�ner kelime polindrom olmu� olur
	return true;
}


int main(int argc, char *argv[]) {
	
	struct Node* head = NULL;		// taan�mlanan d���n bir head de�i�kenini ba�lang�� alarak tan�mlan�r ve null de�erini al�r 
	int i;
	char kelime[50];
	// kullan�c�ya ��kt�lar verilerek kelime al�n�r
	printf("**********POLINDROM KELIME BULMA**********\n");
	printf("Polindrom olup olmadigini kontrol etmek icin bir kelime giriniz\n>>> ");
	scanf(" %s",kelime);
	// al�nan kelimenin uzunlu�u hesaplan�r
	int uzunluk = strlen(kelime);
	
	// kelimenin uzunlu�u kadar d�nerek kelime i�in bellekte yer a��l�r ve bir listeye aktar�l�r
	for(i = 0; i < uzunluk; i++ ){
	struct Node* yeni_node = (struct Node*)malloc(sizeof(struct Node));		// yeni bir de�i�kenle bellekte yer a��l�r
	yeni_node->data = kelime[i] ;		// de�i�kene s�ras�yla kelimenin elemanlar� gelir
	yeni_node->next = head;			// s�radaki elemana head de�eri aktar�l�r b�ylece birbirlerinin yerini tutarlar
	head = yeni_node;			// head bilgisine yeni_node atanarak d�ng� i�inde listenin de�er ve s�radaki eleman�n  yerini tutmas� sa�lan�r
}
	// bu if k�sm�nda kontrol fonksiyonuna head bilgisi verilir ve true d�nd���nde kelime polindrom d�nmedi�inde polindrom de�il yaz�s� yazd�r�l�r
	if(Kontrol(head)){
		printf("\n%s bir polindrom kelimedir\n",kelime);
	}
	else {
		printf("\n%s bir polindrom kelime degildir\n",kelime);
	}
	return 0;
}


