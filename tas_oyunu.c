/* B�LG�SAYAR PROGRAMLAMAYA G�R�� D�NEM PROJES� TA� OYUNU 
		B��RA YORULMAZ -- 18110131018	*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
	srand(time(0));
	printf("OYUNA BASLANGIC TASLARI\n");
	//birinci oyuncu ta�lar�
	int i;
    int j;
    printf("1.OYUNCU TASLARI\n");
	int oyuncu1[2][20]={ 
	                   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //mavi1
	                   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //k�rm�z�1
					};
   	for(i=0;i<2;i++){
   		if(i==0) printf("M: ");
		else     printf("K: ");
   		for(j=0;j<20;j++){ 
   	   		printf("%d ",oyuncu1[i][j]);
		}
		printf("\n");
   	}
  
	//ikinci oyuncu ta�lar�
   	int k;
   	int l;
   	printf("2.OYUNCU TASLARI\n");
   		int oyuncu2[2][20]={ 
	                   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //mavi2
	                   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //k�rm�z�2
					};
   	for(k=0;k<2;k++){
   			if(k==0) printf("M: ");
			else     printf("K: ");
   		for(l=0;l<20;l++){ 
   	   		printf("%d ",oyuncu2[i][j]);
		}printf("\n");
   	}
   	
    	int oyuncu = rand()%2; // oyuna ba�layacak oyuncu random se�ilir.
		int renk   = rand()%2;	//Ba�lang��ta verilecek ta��n mavi veya k�rm�z� olmas�na rastgele karar verilir.
		int sayi   = 1+(rand()%10); //1-10 aras� toplardan hangisinin verilece�i rastgele se�ilir
		int sec    = rand()%2; // iki uygun ta� da varsa oynanacak ta� random se�ilir.
		int adim   = 1;  // hamle say�s�n� g�sterir.
		
		printf("\n\n--Oyun Basliyor--\n");

		printf("\nBaslayan oyuncu: %s\n",oyuncu==0?"1.oyuncu":"2.oyuncu");	
		printf("Renk: %s\n", renk==0?"Mavi":"Kirmizi");
	    printf("Sayi: %d\n", sayi);
	    printf("Adim: %d\n", adim);

	while(1==1){
		// 1. oyuncu i�in t�m ko�ullar 
		if(oyuncu==0){
			if((oyuncu2[renk ==0?1:0][sayi-5]==!0)&&(oyuncu1[renk][sayi*2-1]==!0)&&(sayi-5>0)&&(sayi*2-1<20)){
				if((sec==1)&&(sayi*2<20)){
					oyuncu1[renk][sayi-1]=0;
					oyuncu2[renk][sayi-1]=2;
					oyuncu=1;
					sayi=sayi*2;
					adim++;
				}
				else{//sec==0 i�in
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
		
		// 2. oyuncu i�in t�m ko�ullar 
		else{//oyuncu==1  ise 2. oyuncu oyuna ba�lar 
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
	
		// HER ADIMDA TA�LAR VE ADIMLAR EKRANA BASTIRILIYOR
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
