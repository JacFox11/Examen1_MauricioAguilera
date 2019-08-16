#include <vector>
#include <ctime>
#include <cstdlib>
#include "Asalto.cpp"
#include "Soporte.cpp"

void llamar(int);
string token(string, string, int);
int func(string);
void listar();

vector <Soldado*> equipo1;
vector <Soldado*> equipo2;

int main(){
	char op='0';
	llamar(1);
	llamar(2);
	while (op!='3'){
		system("cls");
		cout<<"...:::MENU PRINCIPAL:::..."<<endl;
		cout<<"1. Imprimir lista de soldados:"<<endl<<
		"2. Iniciar simulacion"<<endl<<
		"3. Salir"<<endl<<
		"Ingrese una opcion: ";
		cin>>op;
		switch (op){
			case '1':{
				cout<<"Equipo 1:"<<endl;
				for (int i=0; i<equipo1.size() ; i++){
					if (typeid(*equipo1.at(i) ) == typeid(Asalto)){
						((Asalto*)equipo1.at(i))->print();
					}else{
						((Soporte*)equipo1.at(i))->print();
					}
				}
				cout<<endl<<"Equipo 2:"<<endl;
				for (int i=0; i<equipo2.size() ; i++){
					if (typeid(*equipo2.at(i) ) == typeid(Asalto)){
						((Asalto*)equipo2.at(i))->print();
					}else{
						((Soporte*)equipo2.at(i))->print();
					}
				}
				system("pause");
				break;
			}
			case '2':{
				int x=2;
				while (equipo1.size() >1 && equipo2.size() >1){
					if (x==2){
						x=1;
					}else{
						x=2;
					}
					if (x==1){
						srand(time(0));
						int p=(rand() % (equipo1.size()))-1;
						srand(time(0));
						int p2=(rand() % equipo2.size())-1;
						if (typeid(*equipo1.at(p) ) == typeid(Asalto)){
							((Asalto*)equipo2.at(p2))->Defensa(equipo1.at(p), ((Asalto*)equipo1.at(p))->Atacar(equipo2.at(p2) ));
						}else{
							((Soporte*)equipo2.at(p2))->Defensa(equipo1.at(p), ((Asalto*)equipo1.at(p))->Atacar(equipo2.at(p2) ));
						}
						
						if (equipo2.at(p2)->getVida() <=0){
							equipo2.erase(equipo2.begin() + p2);
						}
					}else{
						srand(time(0));
						int p=(rand() % equipo2.size())-1;
						srand(time(0));
						int p2=(rand() % equipo1.size())-1;
						if (typeid(*equipo1.at(p) ) == typeid(Asalto)){
							((Asalto*)equipo1.at(p2))->Defensa(equipo2.at(p), ((Asalto*)equipo2.at(p))->Atacar(equipo1.at(p2) ));
						}else{
							((Soporte*)equipo1.at(p2))->Defensa(equipo2.at(p), ((Asalto*)equipo2.at(p))->Atacar(equipo1.at(p2) ));
						}
						((Asalto*)equipo1.at(p2))->Defensa(equipo2.at(p), ((Asalto*)equipo2.at(p))->Atacar(equipo1.at(p2) ));
						if (equipo1.at(p2)->getVida() <=0){
							equipo1.erase(equipo1.begin() + p);
						}
					}
				}
				ofstream escribir;
				escribir.open("./Ganadador.txt",ios::app);
				if (x==1){
					escribir<<"Ha ganado el equipo 1"<<endl;
					for (int i=0; i<equipo1.size() ; i++){
						escribir<<equipo1.at(i)->getNombre()<<", "<<equipo1.at(i)->getVida()<<setw(10)<<equipo1.at(i)->getAtaque()<<endl;   
					}
					
				}else{
					escribir<<"Ha ganado el equipo 2"<<endl;
					for (int i=0; i<equipo1.size() ; i++){
						escribir<<equipo2.at(i)->getNombre()<<", "<<equipo2.at(i)->getVida()<<setw(10)<<equipo2.at(i)->getAtaque()<<endl;   
					}
				}
				
				escribir.close();
				break;
			}
			case '3':{
				cout<<"Gracias por participar en esta simulacion"<<endl;
				system("pause");
				break;
			}
			default:{
				cout<<"La opcion no existe"<<endl;
				system("pause");
				break;
			}
		}
	}
	return 0;
}

string token(string cadena, string divisor, int pos){
       if(cadena.size()>0){
         char oracion[cadena.size()]; 
         for (int i=0;i<=cadena.size();i++)
         {
               oracion[i]=cadena[i];
         }                    
         char *ptrtoken; 
         int num=1;
         const char* d=divisor.c_str();
         ptrtoken = strtok(oracion , d);             
         while(ptrtoken){
             if(num==pos){ 
                return ptrtoken;                    
             }                 
             ptrtoken = strtok(NULL, d);
             num++;
         }
         return "";
       }else{
             return "";
       }
}

void listar(){
	fstream leer;
	string linea;
	leer.open("./Soldados.txt");
	while (!leer.eof() ){
		getline(leer, linea);
		for (int i=0; i<linea.size() ; i++){
			if (token(linea,"/",i)=="&"){
				
			}
			cout<<token(linea,"/", i)<<endl;
		}
	}
}

void llamar(int team){
	fstream leer;
	string linea;
	leer.open("./Soldados.txt");
	int c1=1;
	int c2=1;
	getline(leer, linea);
	linea=token(linea,"&", team);
	if (team==1){
		while (linea.size() >= c2){
			if (token(linea, "/",c1)=="Asalto"){
				equipo1.push_back(new Asalto());
				c2+=token(linea,"/", c1).size();
				
				c1++;
				equipo1.at(equipo1.size()-1)->setNombre(token(linea, "/", c1));
				c2+=token(linea,"/", c1).size()+2;
				c1++;
				
				equipo1.at(equipo1.size()-1)->setVida(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+2;
				c1++;
				
				equipo1.at(equipo1.size()-1)->setAtaque(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+2;
				c1++;
				
				((Asalto*)equipo1.at(equipo1.size()-1))->setVelocidad(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+2;
				c1++;
				
				((Asalto*)equipo1.at(equipo1.size()-1))->setExtra(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
				
				
			}else{
				equipo1.push_back(new Soporte());
				c2+=token(linea,"/", c1).size()+1;
				
				c1++;
				equipo1.at(equipo1.size()-1)->setNombre(token(linea, "/", c1));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
				
				equipo1.at(equipo1.size()-1)->setVida(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
				
				equipo1.at(equipo1.size()-1)->setAtaque(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
				
				((Soporte*)equipo1.at(equipo1.size()-1))->setBlindaje(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
				
				((Soporte*)equipo1.at(equipo1.size()-1))->setCamuflaje(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
			}
		}
	}else{
		while (linea.size() >= c2){
			if (token(linea, "/",c1)=="Asalto"){
				equipo2.push_back(new Asalto());
				c2+=token(linea,"/", c1).size();
				
				c1++;
				equipo2.at(equipo2.size()-1)->setNombre(token(linea, "/", c1));
				c2+=token(linea,"/", c1).size()+2;
				c1++;
				
				equipo2.at(equipo2.size()-1)->setVida(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+2;
				c1++;
				
				equipo2.at(equipo2.size()-1)->setAtaque(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+2;
				c1++;
				
				((Asalto*)equipo2.at(equipo2.size()-1))->setVelocidad(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
				
				((Asalto*)equipo2.at(equipo2.size()-1))->setExtra(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
				
				
			}else{
				equipo2.push_back(new Soporte());
				c2+=token(linea,"/", c1).size()+1;
				
				c1++;
				equipo2.at(equipo2.size()-1)->setNombre(token(linea, "/", c1));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
				
				equipo2.at(equipo2.size()-1)->setVida(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
				
				equipo2.at(equipo2.size()-1)->setAtaque(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
				
				((Soporte*)equipo2.at(equipo2.size()-1))->setBlindaje(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
				
				((Soporte*)equipo2.at(equipo2.size()-1))->setCamuflaje(func(token(linea, "/", c1)));
				c2+=token(linea,"/", c1).size()+1;
				c1++;
			}
		}
	}
}

int func(string num){
	string strnum1(num);
	int num1;
	stringstream convert;
	
	convert << strnum1;
	convert>>num1;
	
	convert.str("");
	convert.clear();
	
	return num1;
}
