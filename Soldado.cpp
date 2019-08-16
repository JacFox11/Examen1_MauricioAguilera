#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <string.h>
#include<typeinfo>
using namespace std;

#ifndef Soldado_CPP
#define Soldado_CPP

class Soldado{
	protected:
		string nombre;
		int vida;
		int ataque;
		
	public:
		Soldado(){
		}
		
		Soldado(string nombre, int vida, int ataque){
			this->nombre=nombre;
			this->vida=vida;
			this->ataque=ataque;
		}
		
		string getNombre(){
			return nombre;
		}
		
		void setNombre(string nombre){
			this->nombre=nombre;
		}
		
		int getVida(){
			return vida;
		}
		
		void setVida(int vida){
			this->vida=vida;
		}
		
		int getAtaque(){
			return ataque;
		}
		
		void setAtaque(int ataque){
			this->ataque=ataque;
		}
		
		/*virtual int Atacar()=0;
		
		virtual void Defensa()=0;
		
		virtual void print()=0;*/
		
		~Soldado(){
		}
		
		
};

#endif
