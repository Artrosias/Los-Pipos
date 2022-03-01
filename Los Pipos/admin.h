
#include <stdio.h>
#include <string.h>

int stringcompare(char*,char*);
int nuovi_brani ();
int eliminazione_brani ();
int admin ()
{
  char str1[] = "palla";
  char str2[5];
  printf("Indovinello: Trottolin che trottolava, senza gambe camminava, senza fondo si sedeva, tu sai dir come faceva?\r\n ");
  printf ("\t\t\t\t\tATTENZIONE!\r\n Se sbaglerai, nel menu' principale tornerai!\r\n");
  printf ("Risposta:");
  scanf("%s",str2);
  int compare=stringcompare(str1,str2);
  if(compare==0) {
  printf("La rispsota data e' corretta!\r\n");
  printf ("Entrando nella modalita' Admin, potrai accedere alle seguenti opzioni:\r\n");
printf ("\t1 - Aggiungi canzoni\r\n \t2 - Rimuovi canzoni\r\n \t3 - Torna nel menu' principale\r\n");
for (int n = 1; n > 0; ++n) {
int sceltaR;
scanf ("%d", &sceltaR);
switch (sceltaR) {
  case 1 :
  nuovi_brani ();
  break;
  case 2 :
  eliminazione_brani ();
  break;
  case 3 :
  return 0;
  break;
return 0;
}
  }
 } else {
 printf("Mi dispiace, ma hai sbagliato la rispsota!\r\n");
return 0;
 }
 return 0;
}

int stringcompare(char *a,char *b)
{
   int flag=0;
    while(*a!='\0' && *b!='\0')
    {
        if(*a!=*b)
        {
            flag=1;
        }
        a++;
        b++;
    }

    if(flag==0)
    return 0;
    else
    return 1;
}

// aggiunta dei brani in modalita' admin
int nuovi_brani () {
int counter = 0;
int n;
char est4 [max] = ".csv";
char nick [max] = "canzoni";
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

// rimozione brani in modalita' admin
int eliminazione_brani () {
  char est5 [max] = ".csv";
  char nick [max] = "canzoni";
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
