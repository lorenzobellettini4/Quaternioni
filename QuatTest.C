//Il programma testa la classe "Quaternione.h" svolgendo le operazioni più rilevanti tra quaternioni.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Quaternione.h"

using namespace std;

int main () 
{

 time_t t;
 time_t a;


//Primo quaternione q

 cout << '\n' << "Inserire i coefficienti del quaternione:" << '\n';

time(&a);
while (time(&t) < a + 0.5);
cout << " NB:" << '\n' << " I primi tre numeri inseriti saranno i coefficienti della parte immaginaria del quaternione, " << endl;
cout <<" mentre il quarto sarà il coefficiente della sua parte reale: " << '\n' << endl;

 
 Quaternione q;
 cin >> q;
 if (cin.fail()) return 0;


 cout << '\n' << "Questo è il quaternione inserito: " << q << '\n';


 time(&a);
 while (time(&t) < a + 3);
 cout << "Questo è il suo corrispondente coniugato: " << !q << '\n';
 time(&a);
 while (time(&t) < a + 3); 
 cout << "Questo è il suo corrispondente unitario: " << q.Unitario() << '\n';
  
 time (&a);
 while (time(&t) < a + 3);
 cout  << "Questa è la sua norma: " << setprecision(3) << q.Norma() << endl;

//Secondo quaternione r

 time (&a);
 while (time(&t) < a + 3);
 cout << '\n' << "Inserire i coefficienti di un secondo quaternione: " << endl;
  
 Quaternione r; 

 cin >> r;
 if (cin.fail()) return 0;
 
 cout << '\n' << "Questo è il quaternione inserito: " << r << endl;

 
 time (&a);
 while (time(&t) < a + 3);

 if(q == r) cout << "Hai inserito due quaternioni uguali fra loro." << endl;
 else cout << "I quaternioni inseriti sono diversi fra loro." << '\n' << endl; 

 time (&a);
 while (time(&t) < a + 3);
 cout << "Ora svolgerò varie operazioni fra i quaternioni inseriti." << '\n' << endl;
 
 time (&a);
 while (time(&t) < a + 3);
 cout  << "Somma: " << q+r << '\n';

 time (&a);
 while (time(&t) < a + 3);        
 cout << "Differenza: " << (q-r) << '\n';

 time (&a);
 while (time(&t) < a + 3);      
 cout << "Prodotto del primo per il secondo: " << (q*r) << '\n';

 time (&a);
 while (time(&t) < a + 4);     
 cout << "Prodotto del secondo per il primo: " << (r*q) << '\n';

 time (&a);   
 while (time(&t) < a + 4);
 cout << "Quoziente destro del primo rispetto al secondo: " << (q/r) << '\n';

 time (&a);
 while (time(&t) < a + 4); 
 cout << "Quoziente sinistro del primo rispetto al secondo: " << (q%r) << '\n';
 cout << endl;

time (&a);      
while (time(&t) < a + 3);
cout  <<"Rotazione spaziale ponendo come vettore da ruotare la parte immaginaria del primo quaternione inserito e come quaternione unitario di rotazione il secondo quaternione inserito:" << '\n';

 time (&a);
 while (time(&t) < a + 3);
 cout << (q&&r) << '\n';

time (&a);
while (time(&t) < a + 2);
cout << "Ora svolgerò l'operazione opposta, ovvero ruoterò il secondo quaternione in base alla rotazione imposta dal primo quaternione reso unitario:" << '\n';

 time (&a);
 while (time(&t) < a + 3);
 cout << (r&&q) << '\n' << endl;
 
 time (&a);
 while (time(&t) < a + 3);
  cout << "Il Prodotto di Hamilton si può svolgere solo fra due quaternioni immaginari puri. " << '\n' << endl;

 //controlliamo:
 double dq = q.Getd();
 double dr = r.Getd();

 time (&a);
 while (time(&t) < a + 4); 

 if (dq == 0) cout << "Il primo quaternione inserito è già immaginario puro. " << endl;

 else 
{
  cout << "Il primo quaternione non è immaginario puro. " << endl;
  time(&a);
  while (time(&t) < a+2);
  cout << "Perciò creerò un quaternione immaginario puro. " << endl;
  srand(time(NULL));
 
  q.Seta(rand()%10);
  q.Seta(rand()%10);
  q.Seta(rand()%10);
  q.Setd(0);

  time(&a);
  while (time(&t) < a+4);
  cout <<'\n' <<  "Ho creato questo quaternione: " << '\n' << q << endl; 
 }


 time(&a);
 while (time(&t) < a+4);
 if (dr == 0) 
 cout << "Il secondo quaternione inserito è già immaginario puro. " << '\n' << endl;
 else { 
  cout << "Il secondo quaternione non è immaginario puro. " << endl; 
  time(&a);
  while (time(&t) < a+4);
  cout << "Perciò creerò un quaternione immaginario puro. " << endl;
  srand(time(NULL));
 
  r.Seta(rand()%10);
  r.Setb(rand()%10);
  r.Setc(rand()%10);
  r.Setd(0);

  time(&a);
  while (time(&t) < a+4);
  cout << '\n' <<  "Ho creato questo quaternione: " << '\n' << r << endl; 

 }


 time (&a);
 while (time(&t) < a + 4);
 cout << "Questo è il prodotto di Hamilton fra i due quaternioni: " << (q||r) << '\n';

 time (&a);
 while (time(&t) < a + 3);
 cout  << "Viceversa: " << (r||q) << endl;

 time (&a);
 while (time(&t) < a + 3);
 cout << "Abbiamo finito le operazioni da svolgere. Arrivederci." << '\n' << endl;

 return 0;     


}

