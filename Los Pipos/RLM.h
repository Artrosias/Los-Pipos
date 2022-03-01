
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_ZIFE 100
#define max 100
// creazione di una struttura dati per le 3 tipologie di operazioni
typedef struct {
  char nickname [max];
  char password [max];
  char cognome [max];
  char nome [max];
  char genere [1];
  char email [max];
  int eta;
  char data [11];
} registrazioni;
// inizio registrazione
int registrazione () {
  FILE *pl;
  registrazioni s;
 char est [max] = ".csv"; // stringa di caratteri usata per l'estensione del file
 printf ("Inserisci il nickname per la tua registrazione:\r\n");
 scanf ("%s", *&s.nickname);
  strcat (s.nickname, est);
 // controllo nickname
 if ((pl = fopen (s.nickname, "r")) == NULL ) {
   printf ("Il nickname inserito e' valido\r\n");
 }
 else {
   printf ("Il nickname è stato già preso\r\n");
   return registrazione ();
 }
 // fase di registrazione
  if ((pl = fopen (s.nickname, "a+")) == NULL ) {
    printf ("Il file non e' stato creato correttamente");
  }
  else {
   registrazioni s;
   printf ("Inserisci la tua password:\r\n");
    scanf ("%s", *&s.password);
    printf ("inserisci il tuo nome:\r\n");
    scanf ("%s", *&s.nome);
    printf ("Inserisci il tuo cognome:\r\n");
    scanf ("%s", *&s.cognome);
     printf ("Inserisci il genere [m/f]:\r\n");
    scanf ("%s", *&s.genere);
    printf ("Inserisci l'eta':\r\n");
    scanf ("%d", &s.eta);
    printf ("Inserisci il tuo indirizzo e-mail:\r\n");
    scanf ("%s", *&s.email);
    printf ("Inserisci la data di nascita:\r\n");
    scanf ("%s", *&s.data);
   fprintf (pl, "%s,%s,%s,%s,%d,%s,%s\r\n", s.password,s.nome,s.cognome,s.genere,s.eta,s.email,s.data);
  }
  fclose(pl);

  return 0;
}
// inizio fase di login
int login () {
  char check [max];
  char pass [max];
  char est2 [max] = ".csv";
  int logNok = 0;
  registrazioni s;
  // in questa fase di login chiederemo di inserire il nickname registrato per eseguire un accesso diretto
  printf ("Inserisci il nickname registrato:\r\n");
  scanf ("%s", *&check);
  strcat (check, est2);
  FILE *pg;
  if ((pg = fopen (check, "r")) == 0) {
    printf ("Il nickname inserito non e' valido!\r\n");
    return login ();
  }
  else {
    printf ("Hai effettuato il Login con successo!\r\n");
  }

  return 0;
}
// fase di modifica
int modifica () {
  FILE *nf; // vecchio file dove eseguiremo la modifica
  FILE *nf2; // nuovo file dove saranno presenti le modifiche effettuate con rimpiazzo
  char buffer [max];
  char vp [max];
  char np [max];
  char est3 [max] = ".csv";
  registrazioni s;
  printf ("Inserisci il nickname del tuo account per la modifica:\r\n");
  scanf ("%s", *&s.nickname);
  strcat (s.nickname, est3);
  printf ("Inserisci la credenziale che desideri modificare:\r\n");
  scanf ("%s", *&vp);
  printf ("Inserisci la tua nuova credenziale:\r\n");
  scanf ("%s", *&np);
  nf = fopen (s.nickname, "r");
  nf2 = fopen ("replace.tmp", "w");
  if (nf == NULL || nf2 == NULL) {
    printf ("Non e' stato possibile attuare la modifica");
    return 0;
  }
  while ((fgets(buffer, max, nf)) != NULL) {
    char *pos, temp [max];
    int index = 0;
    int owlen;
    owlen = strlen (vp);
    while ((pos = strstr (buffer, vp)) != NULL) {
      strcpy (temp, buffer);
      index = pos - buffer;
      buffer [index] = '\0';
      strcat (buffer, np);
      strcat (buffer, temp + index + owlen);
    }
    fputs (buffer, nf2);
  }
  fclose(nf);
  fclose (nf2);
  remove (s.nickname);
  rename ("replace.tmp", s.nickname);
  return 0;
}
