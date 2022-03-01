
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 100
int canzoniO ();

int ospite () {
  printf ("Benvenuto alla modalita' ospite!\r\n");
  printf ("In questa modalita' potrai solo osservare le canzoni contenute all'interno del nostro database!\r\n");
  printf ("\t1 - Canzoni\r\n \t2 - Premi qualsiasi tasto per uscire\r\n");
  int sceltaO;
  scanf ("%d", &sceltaO);
  if (sceltaO == 1) {
    printf ("Ecco a te!\r\n");
    canzoniO ();
  } else {
    printf ("Arriverderci!!!\r\n");
    return 0;
  }
  return 0;
}

int canzoniO () {

	FILE*canzoni;
	int a;

	char t[2];//Risposta per effettuare un'altra ricerca senza riavviare il programma

	char ricerca_1[3];
    char ricerca_2[2];
	char ricerca_3[2];
	char ricerca_4[3];
	char indice[100];



		canzoni=fopen("canzoni.csv","r");

do{

	printf("Cosa vorresti cercare?\n");
	printf("\t1-Genere\t\n");
	printf("\t2-Artista\t\n");
	printf("\t3-Album\t\n");
	printf("\t4-Brano\t\n");
  printf ("\tSe hai cambiato idea, inserisci il numero 5 per uscire!\r\n");

do
{
scanf("%d",&a);
	switch(a){
		    case 1:{
		    	printf("Che genere vuoi cercare?\t\n");
		    	scanf("%s",ricerca_1);
		    	for(int x=0;x<strlen(ricerca_1);x++)
				    {
		             ricerca_1[x]=toupper(ricerca_1[x]);
	                }

	                 while(!feof(canzoni) ){
	    	              fscanf(canzoni,"%s\n",indice);
	    	             if(indice[0]==ricerca_1[0] && indice[1]==ricerca_1[1] && indice[2]==ricerca_1[2])
			               {
	    	               printf("%s\n",indice);
	    	               printf("\n");
	                       }
	                                     }

				break;
		     	    }
		    case 2:{
		    	 printf("Che artista vuoi cercare?\t\n");
		    	scanf("%s",ricerca_2);
		    	for(int x=0;x<strlen(ricerca_2);x++)
				    {
		             ricerca_2[x]=toupper(ricerca_2[x]);
	                }

	                 while(!feof(canzoni) ){
	    	              fscanf(canzoni,"%s\n",indice);
	    	             if(indice[3]==ricerca_2[0] && indice[4]==ricerca_2[1] )
			               {
	    	               printf("%s\n",indice);

	                       }
	                                     }

				break;
			        }
			case 3:{
		    	 printf("Che album vuoi cercare?\t\n");
		    	scanf("%s",ricerca_3);
		    	for(int x=0;x<strlen(ricerca_3);x++)
				    {
		             ricerca_3[x]=toupper(ricerca_3[x]);
	                }

	                 while(!feof(canzoni) ){
	    	              fscanf(canzoni,"%s\n",indice);
	    	             if(indice[5]==ricerca_3[0] && indice[6]==ricerca_3[1] )
			               {
	    	               printf("%s\n",indice);
                           printf("\n");
	                       }
	                                     }

				break;
			}
			case 4:{
		    	printf("Che brano vuoi cercare?\t\n");
		    	scanf("%s",ricerca_4);
		    	for(int x=0;x<strlen(ricerca_4);x++)
				    {
		             ricerca_4[x]=toupper(ricerca_4[x]);
	                }

	                 while(!feof(canzoni) ){
	    	              fscanf(canzoni,"%s\n",indice);
	    	             if(indice[7]==ricerca_4[0] && indice[8]==ricerca_4[1] && indice[9]==ricerca_4[2])
			               {
	    	               printf("%s\n",indice);
	                       }
	                                     }

				break;
		     	    }
               case 5 :
               printf ("ciao!!!");
               return 0;
               break;
	}
	printf("\n\n");
	if(a != 2 && a != 2 && a != 3 && a != 4){
	}
}
while(a != 1 && a != 2 && a != 3 && a != 4);{
}
printf("Vuoi fare un'altra ricerca?\r\n Se desideri uscire, premi 5!\r\n");
scanf("%s",t);
for(int x=0;x<strlen(t);x++)
				    {
		             t[x]=toupper(t[x]);
	                }
}
while(t[0]=='S' && t[1]=='I');{
}
	fclose(canzoni);
return 0;
}
