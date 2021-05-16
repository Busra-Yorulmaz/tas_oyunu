/* BÝLGÝSAYAR PROGRAMLAMAYA GÝRÝÞ DÖNEM PROJESÝ TAÞ OYUNU 
		BÜÞRA YORULMAZ -- 18110131018	*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
	srand(time(0));
	printf("OYUNA BASLANGIC TASLARI\n");
	//birinci oyuncu taþlarý
	int i;
    int j;
    printf("1.OYUNCU TASLARI\n");
	int oyuncu1[2][20]={ 
	                   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //mavi1
	                   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //kýrmýzý1
					};
   	for(i=0;i<2;i++){
   		if(i==0) printf("M: ");
		else     printf("K: ");
   		for(j=0;j<20;j++){ 
   	   		printf("%d ",oyuncu1[i][j]);
		}
		printf("\n");
   	}
  
	//ikinci oyuncu taþlarý
   	int k;
   	int l;
   	printf("2.OYUNCU TASLARI\n");
   		int oyuncu2[2][20]={ 
	                   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //mavi2
	                   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //kýrmýzý2
					};
   	for(k=0;k<2;k++){
   			if(k==0) printf("M: ");
			else     printf("K: ");
   		for(l=0;l<20;l++){ 
   	   		printf("%d ",oyuncu2[i][j]);
		}printf("\n");
   	}
   	
    	int oyuncu = rand()%2; // oyuna baþlayacak oyuncu random seçilir.
		int renk   = rand()%2;	//Baþlangýçta verilecek taþýn mavi veya kýrmýzý olmasýna rastgele karar verilir.
		int sayi   = 1+(rand()%10); //1-10 arasý toplardan hangisinin verileceði rastgele seçilir
		int sec    = rand()%2; // iki uygun taþ da varsa oynanacak taþ random seçilir.
		int adim   = 1;  // hamle sayýsýný gösterir.
		
		printf("\n\n--Oyun Basliyor--\n");

		printf("\nBaslayan oyuncu: %s\n",oyuncu==0?"1.oyuncu":"2.oyuncu");	
		printf("Renk: %s\n", renk==0?"Mavi":"Kirmizi");
	    printf("Sayi: %d\n", sayi);
	    printf("Adim: %d\n", adim);

	while(1==1){
		// 1. oyuncu için tüm koþullar 
		if(oyuncu==0){
			if((oyuncu2[renk ==0?1:0][sayi-5]==!0)&&(oyuncu1[renk][sayi*2-1]==!0)&&(sayi-5>0)&&(sayi*2-1<20)){
				if((sec==1)&&(sayi*2<20)){
					oyuncu1[renk][sayi-1]=0;
					oyuncu2[renk][sayi-1]=2;
					oyuncu=1;
					sayi=sayi*2;
					adim++;
				}
				else{//sec==0 için
					oyuncu1[renk][sayi-1]=0;
					oyuncu2[renk][sayi-1]=2;
					oyuncu=1;
					renk=renk ==0?1:0;
					sayi=sayi-4;
					adim++;
				}	
			}
			else if((oyuncu2[renk ==0?1:0][sayi-5]==!0)&&(sayi-5>0)){
					oyuncu1[renk][sayi-1]=0;
					oyuncu2[renk][sayi-1]=2;
					oyuncu=1;
					renk=renk ==0?1:0;
					sayi=sayi-4;
					adim++;
			}
				
			else if((oyuncu1[renk][sayi*2-1]==!0)&&(sayi*2-1<20)){
					oyuncu1[renk][sayi-1]=0;
					oyuncu2[renk][sayi-1]=2;
					oyuncu=1;
					sayi=sayi*2;
					adim++;
				}
			else{
			printf("\n--Oyun Bitti--\n\n");
			break;
		}
		}
		
		// 2. oyuncu için tüm koþullar 
		else{//oyuncu==1  ise 2. oyuncu oyuna baþlar 
			if((oyuncu1[renk ==0?1:0][sayi-5]==!0) && (oyuncu2[renk][sayi*2-1]==!0) && (sayi-5>0)&&(sayi*2-1<20) )	{
				if(sec==1){
					oyuncu2[renk][sayi-1]=0;
					oyuncu1[renk][sayi-1]=2;
					renk=renk ==0?1:0;
					sayi=sayi-4;	
					oyuncu=0;
					adim++;
				}
				else{//sec==0
					oyuncu2[renk][sayi-1]=0;
					oyuncu1[renk][sayi-1]=2;
					sayi=sayi*2;
					oyuncu=0;
					adim++;
				}
			}
			else if((oyuncu2[renk ==0?1:0][sayi-5]==!0)&&(sayi-5>0)){
					oyuncu2[renk][sayi-1]=0;
					oyuncu1[renk][sayi-1]=2;
					renk=renk ==0?1:0;
					sayi=sayi-4;
					oyuncu=0;
					adim++;
			}
			else if((oyuncu2[renk][sayi*2-1]==!0)&&(sayi*2<20-1)){
					oyuncu2[renk][sayi-1]=0;
					oyuncu1[renk][sayi-1]=2;
					sayi=sayi*2;
					oyuncu=0;
					adim++;
			}
			
			else{
			printf("\n--Oyun Bitti--\n\n");
			break;
			}
		}	
	
		// HER ADIMDA TAÞLAR VE ADIMLAR EKRANA BASTIRILIYOR
		printf("\n1.OYUNCU TAHTASI\n"); 
	   	for(i=0;i<2;i++){
 			if(i ==0)printf("M: ");	
			if(i==1) printf("K: ");
 			for(j=0;j<20;j++){ 		
				printf("%d ",oyuncu1[i][j]);		 
	 		}
		 	printf("\n");
 		}	
 		printf("2.OYUNCU TAHTASI\n"); 
		for(k=0;k<2;k++){
 			if(k==0)printf("M: ");	
			if(k==1)printf("K: ");
 			for(l=0;l<20;l++){ 		
				printf("%d ",oyuncu2[k][l]);		 
		 	}
		 	printf("\n");
 		} 		
		printf("\nOyuncu: %d\n", oyuncu+1);
		printf("Renk: %s\n", renk==0?"Mavi":"Kirmizi");
		printf("Sayi: %d\n", sayi);	
		printf("Adim: %d\n", adim);	
	}

printf("Tolam adim sayisi: %d\n", adim);	
printf("Kazanan: %d. oyuncu\n", oyuncu+1);	

getch();
return 0;		
}
