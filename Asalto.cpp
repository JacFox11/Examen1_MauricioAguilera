#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <string.h>
#include "Soldado.cpp"
using namespace std;

#ifndef Asalto_CPP
#define Asalto_CPP

class Asalto : public Soldado{
	private:
		int velocidad;
		int extra;
		
	public:
		Asalto(): Soldado(){
		}
		
		Asalto(int velocidad, int extra): Soldado(nombre, vida, ataque){
			this->velocidad=velocidad;
			this->extra=extra;
		}
		
		int getVelocidad(){
			return velocidad;
		}
		
		void setVelocidad(int velocidad){
			this->velocidad=velocidad;
		}
		
		int getExtra(){
			return extra;
		}
		
		void setExtra(int extra){
			this->extra=extra;
		}
		
		int Atacar(Soldado* op){
			if (typeid(op)== typeid(Asalto)){
				return ataque * 10;
			}else{
				return ataque * (10 +(velocidad*2));
			}
		}
		
		void Defensa(Soldado* op, int atk){
			if (typeid(*op)== typeid(Asalto)){
				vida=vida- atk;
			}else{
				vida=vida- (atk/extra);
			}
		}
		
		void print(){
			cout<<nombre<<", Vida: "<<vida<<", Ataque: "<<ataque<<", Fuerza extra: "<<extra<<", Velocidad: "<<velocidad<<endl;
		}
		
		~Asalto(){
		}
		
		
};

#endif
