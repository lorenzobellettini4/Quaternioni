#ifndef QUATERNIONE_H
#define QUATERNIONE_H
#include <iostream>

class Quaternione {
 
 public:
  
  //Costruttori
  Quaternione(); //default
  Quaternione(double, double, double, double); //parametrico
  Quaternione(double, double, double); //quaternione immaginario puro
  Quaternione(const Quaternione&); //costruttore di copia
  

  //Setters
  void Seta(double);
  void Setb(double);
  void Setc(double);
  void Setd(double);
  //Getters
  double Geta() const;
  double Getb() const;
  double Getc() const;
  double Getd() const;
 


  //Ridefinizione Operatori

  	//binari

  Quaternione operator+(Quaternione&); //somma
  Quaternione operator-(Quaternione&); //differenza
  Quaternione operator*(Quaternione&); //non simmetrico
  Quaternione operator*(double); //simmetrico
  Quaternione operator/(Quaternione &); //divisione del primo per il secondo - quoziente destro
  Quaternione operator%(Quaternione &); //divisione del secondo per il primo - quoziente sinistro

  Quaternione operator+=(Quaternione&); //assegnamento composto a somma
  Quaternione operator-=(Quaternione&); //assegnamento composto a differenza
  Quaternione operator*=(Quaternione&); //assegnamento composto a prodotto
  
  Quaternione operator&&(Quaternione&);//Rotazione
  Quaternione operator||(Quaternione&);//Prodotto di Hamilton
 
 	 //unari

  Quaternione operator!(); //Coniugato   
  Quaternione operator~(); //Inverso 




  //friends

  //imput-output
  friend std::ostream& operator<<(std::ostream&, Quaternione);
  friend std::istream& operator>>(std::istream&, Quaternione&);

  //confronto
  friend bool operator == (Quaternione, Quaternione);
  friend bool operator != (Quaternione, Quaternione);



  //Altro
  Quaternione Unitario(); //Unitario
  double Norma(); //Norma del quaternione


  


 private:
 
  double C_[4];//coefficienti del quaternione  

 };

#endif
