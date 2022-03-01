#include <stdio.h>
#include "RLM.h"
#include "canzoni.h"
#include "admin.h"
#include "ospite.h"
int scelta;
int scelta2;


int main () {
  int n = 0;
  while (n >= 0) {
 printf ("\t\t\tBenvenuto a Los Pipos!\r\n");
 printf ("Scegli una tra le seguenti opzioni:\r\n");
 printf ("Se desideri chiudere il programma, inserisci il numero 5!\r\n");
 printf ("\t1 - Registrazione\r\n \t2 - Login\r\n \t3 - Modifica\r\n \t4 - Ospite\r\n \t");
 scanf ("%d", &scelta);
   if (scelta == 1) {
   registrazione ();
   } else if (scelta == 2) {
   login ();
   } else if (scelta == 3) {
   modifica ();
   } else if (scelta == 4) {
     ospite ();
     return main ();
   } else if (scelta == 5) {
   printf ("Ciao!!!");
   return 0;
   } else {
     printf ("il valore inserito, non e' valido\r\n!");
     return main ();
   }
   printf ("Benvenuto al tuo database di Musica On Demand!\r\n");
 printf ("Scegli che tipo di azione desideri effettuare!\r\n");
 printf ("\t1 - Canzoni\r\n \t2 - Aggiungi Preferiti\r\n \t3 - Rimuovi preferiti\r\n");
 scanf ("%d", &scelta2);
   if (scelta2 == 0) {
     admin ();
   } else if (scelta2 == 1) {
   canzoni ();
   } else if (scelta2 == 2) {
     canzoni_preferite ();
     return main ();
   } else if (scelta2 == 3) {
     rimozione_brani ();
     return main ();
   } else {
     printf ("Il valore inserito non e' corretto\r\n");
   }

  ++n;
}
  return 0;
}
