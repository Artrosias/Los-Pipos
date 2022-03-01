
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 100


int canzoni () {

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

// aggiunta brani preferiti
int canzoni_preferite () {
int counter = 0;
int n;
char est4 [max] = ".csv";
char nick [max];
// lettura profilo
printf ("Inserisci il nickname di registrazione:\r\n");
scanf ("%s", *&nick);
strcat (nick, est4);
FILE *ps;
if ((ps = fopen (nick, "a+")) == NULL ) {
  printf ("Impossibile aprire il file");
  return 0;
}
else {
  char canzone [max];
  printf ("Quanti brani vorresti nella tua lista?\r\n");
  scanf ("%d", &n);
  for (counter = 0; counter < n; ++counter) {
    printf ("inserici il %d brano\r\n", counter );
    scanf ("%s", *&canzone);
    fprintf (ps, "%s\r\n", canzone);
  }
}
fclose(ps);
return 0;
}
// rimozione brani preferiti
int rimozione_brani () {
  char est5 [max] = ".csv";
  char nick [max];
  printf ("Inserisci il nickname del tuo account:\r\n");
  scanf ("%s", *&nick);
  FILE *nf;
  FILE *nf2;
  char buffer [max];
  char pn [max];
  char pv [max];
  pn [0] = '\0';
  printf ("Inserisci il brano che desideri eliminare:\r\n");
  scanf ("%s", *&pv);
  strcat (nick, est5);
  nf = fopen (nick, "r");
  nf2 = fopen ("replace.tmp", "w");
  if (nf == NULL || nf2 == NULL ) {
    printf ("Impossibile aprire il file");
    return 0;
  }
  while ((fgets(buffer, max, nf)) != NULL ) {
    char *pos, temp [max];
    int index = 0;
    int owlen;
    owlen = strlen (pv);
    while ((pos = strstr(buffer, pv)) != NULL ) {
      strcpy (temp, buffer);
      index = pos - buffer;
      buffer [index] = '\0';
      strcat (buffer, pn);
      strcat (buffer, temp + index + owlen);

    }
    fputs (buffer, nf2);
  }
fclose(nf);
fclose(nf2);
remove(nick);
rename("replace.tmp", nick);
return 0;
}
