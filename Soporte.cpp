#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <string.h>
#include "Soldado.cpp"
using namespace std;

#ifndef Soporte_CPP
#define Soporte_CPP

class Soporte : public Soldado{
	private:
		int blindaje;
		int camuflaje;
		
	public:
		Soporte(): Soldado(){
		}
		
		Soporte(int blindaje, int camuflaje): Soldado(nombre, vida, ataque){
			this->blindaje=blindaje;
			this->camuflaje=camuflaje;
		}
		
		int getBlindaje(){
			return blindaje;
		}
		
		void setBlindaje(int blindaje){
			this->blindaje=blindaje;
		}
		
		int getcamuflaje(){
			return camuflaje;
		}
		
		void setcamuflaje(int camuflaje){
			this->camuflaje=camuflaje;
		}
		
		int Atacar(Soldado* op){
			if (typeid(*op)== typeid(Soporte)){
				return ataque * 10;
			}else{
				return ataque * (15 + camuflaje);
			}
		}
		
		void Defensa(Soldado* op, int atk){
			if (typeid(*op)== typeid(Soporte)){
				vida=vida- atk;
			}else{
				vida=vida- (atk/(blindaje*2));
			}
		}
		
		void print(){
			cout<<nombre<<", Vida: "<<vida<<", Ataque: "<<ataque<<", Blindaje: "<<blindaje<<", Camuflaje: "<<camuflaje<<endl;
		}
		
		~Soporte(){
		}
		
		
};

#endif
