#include "Quaternione.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctype.h>

using namespace std;

//Costruttori


//costruttore di default
Quaternione::Quaternione() 
{
 for (int i=0; i<4; i++) 
	C_[i] = 0;

}


//costruttore parametrico
Quaternione::Quaternione(double a, double b, double c, double d) 
{
 C_[0] = a;
 C_[1] = b;
 C_[2] = c; 
 C_[3] = d; 
}


//immaginario puro
Quaternione::Quaternione(double a, double b, double c) 
{
 C_[0] = a;
 C_[1] = b;
 C_[2] = c;
 C_[3] = 0;
}


//costruttore di copia
Quaternione::Quaternione(const Quaternione& n) 
{
 for (int i=0; i<4; i++) 
	C_[i] = n.C_[i];
}




//Setters

void Quaternione::Seta(double a) 
{
 C_[0] = a; 
}

void Quaternione::Setb(double b) 
{
 C_[1] = b;
}

void Quaternione::Setc(double c) 
{
 C_[2] = c;
}

void Quaternione::Setd(double d) 
{
 C_[3] = d;
}



//Getters


double Quaternione::Geta() const 
{
 return C_[0];
}

double Quaternione::Getb() const 
{
 return C_[1];
}

double Quaternione::Getc() const 
{
 return C_[2];
}

 double Quaternione::Getd() const 
{
 return C_[3];
}




//Ridefinizione Operatori

Quaternione Quaternione::operator+ (Quaternione& n) 
{

 Quaternione somma;

 for (int i=0; i<4; i++) 
	somma.C_[i] = C_[i] + n.C_[i];
  
 return somma;
}


Quaternione Quaternione::operator- (Quaternione& n) 
{

 Quaternione differenza;

 for (int i = 0; i<4; i++)
	differenza.C_[i] = C_[i] - n.C_[i];
 
 return differenza;
}


Quaternione Quaternione::operator* (Quaternione& n) 
{
 
 Quaternione prodotto; 

 prodotto.C_[0] = C_[0]*n.C_[3] + C_[1]*n.C_[2] - C_[2]*n.C_[1] + C_[3]*n.C_[0];
 prodotto.C_[1] = -C_[0]*n.C_[2] + C_[1]*n.C_[3] + C_[2]*n.C_[0] + C_[3]*n.C_[1];
 prodotto.C_[2]= C_[0]*n.C_[1] - C_[1]*n.C_[0] + C_[2]*n.C_[3] + C_[3]*n.C_[2];
 prodotto.C_[3] = -C_[0]*n.C_[0] -C_[1]*n.C_[1] -C_[2]*n.C_[2] +C_[3]*n.C_[3];

 return prodotto;
}

	
Quaternione Quaternione::operator* (double x) 
{

 Quaternione p(*this);
 for (int i=0;  i<4; i++) 
	p.C_[i] *= x;

 return p;
}


//quoziente destro
Quaternione Quaternione::operator/ (Quaternione& h) {

 Quaternione s = ~h;

 Quaternione quoziente = *this * s;
 return quoziente;
}


//quoziente sinistro
Quaternione Quaternione::operator% (Quaternione& h) {
 
 Quaternione s = ~h;

 Quaternione quoziente = s * *this;
 return quoziente;
}



//assegnamento composto a somma
Quaternione Quaternione::operator+=(Quaternione& r) {
 *this = (*this) + r;
 return *this;
} 


//assegnamento composto a differenza 
Quaternione Quaternione::operator-=(Quaternione& r) {
 *this = (*this) - r;
 return *this;
}


//assegnamento composto a prodotto
Quaternione Quaternione::operator*=(Quaternione& r) {
 *this = (*this) * r;
 return *this;
}



//Rotazione spaziale
Quaternione Quaternione::operator&&(Quaternione& p) {
 
 Quaternione ruotato = Quaternione(*this); //faccio una copia, visto che posso dover cambiarlo per ruotarlo
 if(Getd() != 0) 
	ruotato.Setd(0);
 
 Quaternione u;
 u = p.Unitario();

 Quaternione pconiug;
 pconiug = !ruotato;

 Quaternione l;
 l = ruotato * u;

 Quaternione r = l * pconiug;

 return r;
}



//Prodotto di Hamilton : crea corrispondenza fra quaternioni immaginari puri e vettori in R^3
Quaternione Quaternione::operator||(Quaternione& r) 
{

 Quaternione prodotto;

 //check: 
 if (Getd() == 0 && r.Getd() == 0) 
{
   
 //parte immaginaria: prodotto vettoriale
 //parte reale: prodotto scalare
 
 prodotto = *this * r;
 
 return prodotto; //NB. il prodotto fra due quaternioni immaginari puri non è un immaginario puro!
 }
 

  else 
{
   cout << "uno dei quaternioni forniti non è immaginario puro" << '\n' 
    << "Non è possibile creare una corrispondenza con vettori in R3" << endl; 
 }

}




//Coniugato
Quaternione Quaternione::operator!() 
{
 
 Quaternione coniugato;

 for (int i=0; i<3; i++) 
	{
 	coniugato.C_[i] = -C_[i];
 	coniugato.C_[3] = C_[3]; 
	}

 return coniugato;
}



//Inverso del quaternione dato
Quaternione Quaternione::operator~() 
{

 Quaternione q;

 Quaternione c = !*this;

 for (int i=0; i<4; i++) 
	q.C_[i] = c.C_[i]/pow(c.Norma(), 2);
 
 return q;
}






//friends 

//input-output
ostream& operator<< (ostream& c, Quaternione r) 
{ 
 
 
 if (r.Geta()==0 && r.Getb()==0 && r.Getc()==0 && r.Getd()==0) 
	cout << "Quaternione nullo" << endl;

 else if (r.Getd()==0) 
{
  cout  << "(immaginario puro)" << '\n'
   << setprecision(3) << r.C_[0] << "i + " << setprecision(3) << r.C_[1] << "j + " << setprecision(3) << r.C_[2] << "k " << endl;
 }

 else cout << setprecision(3) <<r.C_[0] << "i + " << setprecision(3) << r.C_[1] <<"j + " << setprecision(3) << r.C_[2] << "k + " <<setprecision(3) << r.C_[3] << endl;

 return c;
 
}


istream& operator >>(istream &g, Quaternione &q) 
{
 
 double digit; 

 for (int i=0; i<4; i++) 
{
  cout << "Elemento " << i+1 << ": " ;
  cin >> digit;
	
  	if(cin.good()) q.C_[i] = digit;

  	else 
	{ 
   	cerr << "Solo valori numerici, per favore" << endl; 
  	break;
 	 }
 }
 return g;

}



//Confronto
bool operator == (Quaternione r, Quaternione q) {
 
 Quaternione s = r - q;

 if(s.Geta()==0 && s.Getb()==0 && s.Getc()==0 && s.Getd()==0) 
   return true;
 else return false;

}



bool operator != (Quaternione r, Quaternione q) {
 
 Quaternione s = r - q;
 if(s.Geta()!=0 || s.Getb()!=0 || s.Getc()!=0 || s.Getd()!=0)
   return true;
 else return false;

}




//Altro




//Norma del quaternione
double Quaternione::Norma() 
{
 
 double tot;

 for (int i=0; i<4; i++) 
	tot += pow(C_[i], 2);

 return sqrt(tot);
  
}


//Trasforma il quaternione dato nell'unitario corrispondente
Quaternione Quaternione::Unitario() 
{

 Quaternione u;

 double norma = Norma();

 for (int i=0; i<4; i++) 
	u.C_[i] = C_[i]/norma;

 return u; 

}




