//EL PROGRAMA NECESITA ARCHIVOS PARA QUE FUNCIONE
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <dos.h>
#include <time.h>

using namespace std;

//CODIGO PARA CONTACTOS
struct Contacto{
	char nombre[50];
	int numero;
};
struct NodoContacto{
	Contacto info;
	NodoContacto *sgte;
	NodoContacto *ant;
};
typedef NodoContacto *PNodoContacto;
//FIN CODIGO PARA CONTACTOS

//CODIGO PARA EL REPRODUCTOR
struct Cancion{
	string nombre;
	string autor;
	string album;
	string genero;
};
struct NodoRepro{
	Cancion dato;
	NodoRepro *sgte;
	NodoRepro *ant;
}*ultimo,*primero;

struct NodoLRepro{
	string dato;
	NodoLRepro *p;
};
struct Nodo{
	int info;
	Nodo *sgte;
};

typedef Nodo *PNodo;
typedef NodoRepro *PNodoR;
typedef NodoLRepro *PNodoLR;
//FIN CODIGO PARA EL REPRODUCTOR

//CODIGO PARA EL PEDIDO
struct Pedido{
	char nombre[50];
	int codigo;
};
struct NodoPedido{
	Pedido dato;
	NodoPedido *sgte;
};
typedef NodoPedido *PNodoPedido;
struct Cola{
	PNodoPedido primero;
	PNodoPedido ultimo;
};
//FIN CODIGO PARA EL PEDIDO

//CODIGO BLOC DE NOTAS 
struct Notas{
	char Asunto[50];
	char Texto[200];
	char *p;
};
struct NodoNotas{
	NodoNotas *sgteNotas;
	Notas infoNotas;
};
typedef NodoNotas *PNodoNotas;
//FIN CODIGO BLOC DE NOTAS


//FUNCIONES PRINCIPALES
void menu();
void insertarfinal(PNodo &L, int valor);
void listar(PNodo L);
void gotoxy(int x,int y);
void pixelinicio();
void pixeliphone();
//FIN FUNCIONES PRINCIPALES

//FUNCIONES CALCULADORA
void suma();
void resta();
void multi();
void divi();
void calculadora();
//FIN FUNCIONES CALCULADORA

//FUNCIONES DE CONTACTOS
void insertarFinal(PNodoContacto &, PNodoContacto &, Contacto);
void eliminar(PNodoContacto &, PNodoContacto &, int);
void imprimir(PNodoContacto);
void contactos();
//FIN FUNCIONES DE CONTACTOS

//FUNCIONES DEL REPRODUCTOR
void Spotify();
void insertarF(PNodoLR &, string);
void imprimir(PNodoLR actual);
void insertarcancion(PNodoR &,string,string,string,string) ;
void cancionactual(PNodoR );
void reproductor(PNodoR *&,char );
void muestra_contenido_de(const std::string &a_carpeta);
char opciones();
void menuRepro();	
void cuadro();
void cuadro2();
void cuadro3();
void spot();
char x_op;
PNodoR cancion=NULL;
PNodoLR lista=NULL;
int contadorRepro=0;	
//FIN FUNCIONES DEL REPRODUCTOR

//FUNCIONES DE JUEGO DE PILAS
void push(PNodo &p, int alt1);
int pop(PNodo &p);
void juegoResul(PNodo &p,int n);
void juego_pilas();
//FIN DE FUNCIONES DE JUEGO DE PILAS

//FUNCIONES DE PEDIDO DELIVERY
void inicializa(Cola &c);
bool esVacia(Cola c);
void encolar(Cola &c, Pedido x);
Pedido desencolar(Cola &c);
void imprime(Cola &c);
void pedido();
//FIN FUNCIONES DE PEDIDO DELIVERY

//FUNCION BLOCK DE NOTAS 
void BlockNotas(PNodoNotas &LNotas);
void InsertarBlockNotas(PNodoNotas &LNotas, Notas x);
void ReporteTexto(PNodoNotas LNotas);
//FIN FUNCION BLOCK DE NOTAS 
int main(int argc, char *argv[]) {
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	pixelinicio();
    pixeliphone();
	gotoxy(2,55);
	system("pause");
	menu();
	return 0;
}	
//FUNCIONES PRINCIPALES
void menu(){
	int op,cont=0;
	PNodoNotas LNotas=NULL;
	do{
		system("cls");
		pixelinicio();
		pixeliphone();
		gotoxy(23,19);cout<<"------------------"<<endl;
		gotoxy(23,20);cout<<"MENU DE PROGRAMAS"<<endl;
		gotoxy(23,21);cout<<"------------------"<<endl;
		gotoxy(23,23);cout<<"1. Block de Notas"<<endl;
		gotoxy(23,24);cout<<"2. Calculadora"<<endl;
		gotoxy(23,25);cout<<"3. Contactos"<<endl;
		gotoxy(23,26);cout<<"4. Juego de Cartas"<<endl;
		gotoxy(23,27);cout<<"5. Pedidos por Delivery"<<endl;
		gotoxy(23,28);cout<<"6. Spotify"<<endl;
		gotoxy(23,29);cout<<"Ingrese una opcion: ";
		cin>>op;
		fflush(stdin);
		switch(op) 
		{
		case 1:
			system("cls");
			BlockNotas(LNotas);
			break;
		case 2:
			system("cls");
			calculadora();
			break;
		case 3:
			system("cls");
			contactos();
			break;
		case 4:
			system("cls");
			juego_pilas();
			break;
		case 5:
			system("cls");
			pedido();
			break;
		case 6:
			system("cls");
			Spotify();
			break;
		}
	}while(op!=7);
}

void insertarfinal(PNodo &L, int valor){
	PNodo nuevo = new Nodo;
	nuevo->info = valor;
	nuevo->sgte = NULL;
	if(L==NULL){
		L=nuevo;
	}
	else{
		PNodo p=L;
		while(p->sgte!=NULL){
			p=p->sgte;
		}
		p->sgte = nuevo;
	}
}
	
void listar(PNodo L){
	PNodo p=L;
	while(p!=NULL){
		cout<<p->info<<endl;
		p=p->sgte;
	}
}

void gotoxy(int x,int y){  
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
}

void pixeliphone(){
	gotoxy(15,10);cout<<"  ___ ____  _   _  ___  _   _ _____  "<<endl;
	gotoxy(15,11);cout<<"	|_ _|  _ "<<char(92)<<"| | | |/ _ "<<char(92)<<"| "<<char(92)<<" | | ____| "<<endl;
	gotoxy(15,12);cout<<"	 | || |_) | |_| | | | |  "<<char(92)<<"| |  _|   "<<endl;
	gotoxy(15,13);cout<<"	 | ||  __/|  _  | |_| | |"<<char(92)<<"  | |___  "<<endl;
	gotoxy(15,14);cout<<"	|___|_|   |_| |_|"<<char(92)<<"___/|_| "<<char(92)<<"_|_____| "<<endl;
}

void pixelinicio(){
	for(int i=0;i<45;i++){
		gotoxy(10+i,5);cout<<"="<<endl;
	}
	for(int i=0;i<45;i++){
		gotoxy(10+i,54);cout<<"="<<endl;
	}
	for(int i=0;i<50;i++){
		gotoxy(10,5+i);cout<<"="<<endl;
	}
	for(int i=0;i<50;i++){
		gotoxy(55,5+i);cout<<"="<<endl;
	}
}
//FIN FUNCIONES PRINCIPALES

//FUNCIONES CALCULADORA
void suma(){
	int a, b;
	pixelinicio();
	pixeliphone();
	gotoxy(23,19);cout<<"Ingrese dato a: ";cin>>a;
	gotoxy(23,21);cout<<"Ingrese dato b: ";cin>>b;
	gotoxy(23,24);cout<<"La suma es de "<<a+b<<"."<<endl<<endl;
	gotoxy(2,55);system("pause");
}
void resta(){
	int a, b;
	pixelinicio();
	pixeliphone();
	gotoxy(23,19);cout<<"Ingrese dato a: ";cin>>a;
	gotoxy(23,21);cout<<"Ingrese dato b: ";cin>>b;
	gotoxy(23,24);cout<<"La resta es de "<<a-b<<"."<<endl<<endl;
	gotoxy(2,55);system("pause");
}
void multi(){
	int a, b;
	pixelinicio();
	pixeliphone();
	gotoxy(23,19);cout<<"Ingrese dato a: ";cin>>a;
	gotoxy(23,21);cout<<"Ingrese dato b: ";cin>>b;
	gotoxy(23,24);cout<<"La multiplicacion es de "<<a*b<<"."<<endl<<endl;
	gotoxy(2,55);system("pause");
}
void divi(){
	int a, b;
	pixelinicio();
	pixeliphone();
	gotoxy(23,19);cout<<"Ingrese dato a: ";cin>>a;
	gotoxy(23,21);cout<<"Ingrese dato b: ";cin>>b;
	gotoxy(23,24);cout<<"La division es de "<<a/b<<"."<<endl<<endl;
	gotoxy(2,55);system("pause");
}
void calculadora(){
	int o;
	do{
		system("cls");
		pixelinicio();
		pixeliphone();
		gotoxy(23,19);cout<<"   CALCULADORA "<<endl;
		gotoxy(23,21);cout<<"1. Suma"<<endl;
		gotoxy(23,22);cout<<"2. Resta"<<endl;
		gotoxy(23,23);cout<<"3. Multiplicacion"<<endl;
		gotoxy(23,24);cout<<"4. Division"<<endl;
		gotoxy(23,25);cout<<"5. Regresar al menu"<<endl<<endl;
		gotoxy(23,27);cout<<"Ingrese su opcion: ";cin>>o;
		switch(o){
		case 1:
			system("cls");
			suma();
			break;
		case 2:
			system("cls");
			resta();
			break;
		case 3:
			system("cls");
			multi();
			break;
		case 4:
			system("cls");
			divi();
			break;
		}
	}while(o!=5);
}
//FIN FUNCIONES CALCULADORA 

//FUNCIONES DE CONTACTOS
void insertarFinal(PNodoContacto &primero, PNodoContacto &ultimo, Contacto x){
	PNodoContacto nuevo = new NodoContacto;
	nuevo->info = x;
	if(primero==NULL){
		nuevo->sgte=NULL;
		nuevo->ant=NULL;
		primero = nuevo;
		ultimo = nuevo;
	}else{
		nuevo->sgte = NULL;
		nuevo->ant = ultimo;
		ultimo->sgte = nuevo;
		ultimo = nuevo;
	}
}

void eliminar(PNodoContacto &primero, PNodoContacto &ultimo, int n){
	PNodoContacto q, temp;
	while(primero!=NULL){
		while(primero->sgte!=NULL){
			q = primero->sgte;
			while(q!=NULL){
				if(primero->info.numero==n){
					temp = q->sgte;
					q->ant->sgte = q->sgte;
					q->sgte->ant = q->ant;
					delete q;
					q = temp;
					gotoxy(23,22);cout<<"El contacto ha sido eliminado"<<endl;
				}
				else{
					gotoxy(23,22);cout<<"El contacto no ha sido registrado"<<endl;
				}
			}
		}
	}
}

void imprimir(PNodoContacto primero){
	while(primero!=NULL){
		cout<<"- Nombre: "<<primero->info.nombre<<" / Numero: "<<primero->info.numero<<endl;
		primero = primero->sgte;
	}
}

void contactos(){
	Contacto x;
	PNodoContacto primero = NULL, ultimo = NULL;
	int o, num;
	do{
		system("cls");
		pixelinicio();
		pixeliphone();
		gotoxy(23,19);cout<<"    MENU DE CONTACTOS"<<endl<<endl;;
		gotoxy(23,21);cout<<"1. Añadir contacto"<<endl;
		gotoxy(23,22);cout<<"2. Borrar contacto"<<endl;
		gotoxy(23,23);cout<<"3. Lista de contactos"<<endl;
		gotoxy(23,24);cout<<"4. Regresar al menu"<<endl<<endl;
		gotoxy(23,26);cout<<"Ingrese una opcion: ";cin>>o;
		switch(o){
		case 1:
			system("cls");
			pixelinicio();
			pixeliphone();
			cin.get();
			gotoxy(23,19);cout<<"Nombre del contacto: ";
			gotoxy(23,20);cin.getline(x.nombre,50);
			gotoxy(23,22);cout<<"Numero del contacto: ";
			gotoxy(23,23);cin>>x.numero;
			insertarFinal(primero,ultimo,x);
			gotoxy(23,25);cout<<"Contacto agregado."<<endl<<endl;
			gotoxy(2,55);system("pause");
			break;
		case 2:
			system("cls");
			pixelinicio();
			pixeliphone();
			gotoxy(20,19);cout<<"Numero del contacto a eliminar: ";
			gotoxy(23,20);cin>>num;
			eliminar(primero,ultimo,num);
			gotoxy(2,55);system("pause");
			break;
		case 3:
			system("cls");
			pixelinicio();
			pixeliphone();
			gotoxy(23,19);cout<<"   LISTA DE CONTACTOS"<<endl<<endl;
			imprimir(primero);
			gotoxy(2,55);system("pause");
			break;
		}
	} while(o!=4);
}
//FIN FUNCIONES DE CONTACTOS

//FUNCIONES DEL REPRODUCTOR
void Spotify(){
	int suma ; 
	string nombrec,autorc,albumc,generoc;
	//INGRESO DE DATOS
	char carpeta[] ="C:\\prueba" ;
	gotoxy(55,3);cout<<"LISTA DE CANCIONES\n"<<endl;
	muestra_contenido_de(carpeta);
	cuadro();
	for(int i=1;i<=(contadorRepro-2);i++){
		cuadro2();
		gotoxy(5,4);cout<<"\tINGRESO DE DATOS:"<<endl;
		fflush(stdin);
		gotoxy(5,8);cout<<"Nombre : ";
		nombrec=lista->dato;
		cout<<nombrec<<endl;
		//getline(cin,nombrec);
		lista=lista->p;
		gotoxy(5,10);cout<<"Ingrese autor de cancion "<<i<<":"<<endl;
		gotoxy(5,11);getline(cin,autorc);
		gotoxy(5,13);cout<<"Ingrese album de cancion "<<i<<":"<<endl;
		gotoxy(5,14);getline(cin,albumc);
		gotoxy(5,16);cout<<"Ingrese genero de cancion "<<i<<":"<<endl;
		gotoxy(5,17);getline(cin,generoc);
		insertarcancion(cancion,nombrec,autorc,albumc,generoc);
		system("cls");
	}
	cuadro3();
	// PANTALLA DE CARGA.
	for(int i=1;i<=50;i++)
	{
		Sleep(50);gotoxy(22+i,20);cout<<char(176);
		Sleep(50);gotoxy(22+i,20);cout<<char(177);
		Sleep(50);gotoxy(22+i,20);cout<<char(178);
		Sleep(50);gotoxy(22+i,20);cout<<char(219);
		gotoxy(44,22);cout<<"CARGANDO";
		suma=2*i;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 249);
		gotoxy(46,20);cout<<suma<<"%";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	system("cls");
	if(suma == 100)
	{
		cancionactual(cancion);
		menu();
	}
	else
	{
		exit(0);
	}
	gotoxy(2,28);
}

void insertarF(PNodoLR &lista, string valor){
	PNodoLR ultimo = new NodoLRepro;
	PNodoLR nuevoNodo = new NodoLRepro;
	nuevoNodo->dato=valor;
	nuevoNodo->p=NULL;
	if (lista == NULL){
		lista=nuevoNodo;
	}else{
		ultimo=lista;
		
		while(ultimo->p!=NULL){
			ultimo = ultimo->p;
		}
		
		ultimo->p=nuevoNodo;
	}
}
void insertarcancion(PNodoR &cancion ,string nombrec,string autorc,string albumc,string generoc){
	
	PNodoR nuevoNodo;
	nuevoNodo = new NodoRepro; 
	nuevoNodo->dato.nombre=nombrec;
	nuevoNodo->dato.autor=autorc;
	nuevoNodo->dato.album=albumc;
	nuevoNodo->dato.genero=generoc;
	
	if(primero == NULL){ 
		primero = nuevoNodo;
		ultimo = nuevoNodo;
		nuevoNodo-> sgte = primero;
		nuevoNodo->ant = ultimo; 
		cancion = nuevoNodo; 
	}  
	else{ 
		ultimo->sgte = nuevoNodo; 
		nuevoNodo->ant=ultimo;
		nuevoNodo->sgte=primero;
		ultimo=nuevoNodo;
		primero->ant=ultimo;
		cancion=primero;
	}	
}

void cancionactual(PNodoR cancion){
	
	const string ubicacion="C:\\prueba\\";
	
	std::string ubic = ubicacion + (cancion->dato.nombre);
	
	system(ubic.c_str());
	
	system("cls");
	gotoxy(25,17);cout<<"CANCION ACTUAL: "<<endl;
	gotoxy(25,19);cout<<"NOMBRE: "<<cancion->dato.nombre<<endl;
	gotoxy(25,20);cout<<"AUTOR: "<<cancion->dato.autor<<endl;
	gotoxy(25,21);cout<<"ALBUM: "<<cancion->dato.album<<endl;
	gotoxy(25,22);cout<<"GENERO: "<<cancion->dato.genero<<endl;
}

void reproductor(PNodoR &cancion,char sas){
	fflush(stdin);
	switch(sas) {
	case 's' :{//siguiente
		cancion = cancion->sgte; 
		cancionactual(cancion);
		menuRepro();
	}
		break;
	case 'S' :{//siguiente
		cancion = cancion->sgte; 
		cancionactual(cancion);
		menuRepro();
	}
		break;
	case 'a' :{ //atras*/
		cancion = cancion->ant; 
		cancionactual(cancion); 
		menuRepro();
	}
		break;
	case 'A' :{ //atras*/
		cancion = cancion->ant; 
		cancionactual(cancion); 
		menuRepro();
	}
		break;
	case 'r' :{ //salir
		system("C:\\Users\\Kevin\\Desktop\\T3\\cerrarwm.bat");
	}
	}
}

void muestra_contenido_de(const std::string &a_carpeta){
	
	/*WIN32_FIND_DATA ffd{};
	
	//inicio
	//if (auto handle = FindFirstFile((a_carpeta + "/*.*").c_str(), &ffd)){
		do {
			if(contadorRepro>1){
				gotoxy(55,contadorRepro+4);
				std::cout << ffd.cFileName << '\n';
				insertarF(lista,ffd.cFileName);
			}
			contadorRepro++;
		}while (FindNextFile(handle, &ffd) != 0);
	}*/				//fin
}

char opciones(){
	char x;
	cuadro3();
	spot();
	gotoxy(25,9);cout<<"SIGUIENTE CANCION   === S"<<endl;
	gotoxy(25,11);cout<<"ANTERIOR CANCION    === A"<<endl;
	gotoxy(25,13);cout<<"SALIR == R"<<endl;
	gotoxy(4,26);cout<<"OPCION :  ";cin>>x;
	while(x!='s' && x!='a' && x!='r' && x!='S' && x!='A' && x!='R'){
		gotoxy(25,22);cout<<"Ingrese una opcion valida (s-a-r):"<<endl;cin>>x;
	}
	return x;
}

void menuRepro(){
	x_op = opciones();
	reproductor(cancion,x_op);
}

void cuadro(){
	for(int i=0;i<74;i++){
		gotoxy(50,2+i/4);cout<<"=";
	}
}
	
void cuadro2(){
	for(int i=0;i<74;i++){
		gotoxy(2+i,2);cout<<"=";
		gotoxy(2,2+i/4);cout<<"=";
		gotoxy(76,2+i/4);cout<<"=";
		gotoxy(3+i,20);cout<<"=";
	}
}

void cuadro3(){
	for(int k=0;k<74;k++){
		gotoxy(2+k,2);cout<<"=";
		gotoxy(2+k,28);cout<<"=";
	}
	for(int i=0;i<27;i++){
		gotoxy(2,2+i);cout<<"=";
		gotoxy(75,2+i);cout<<"=";
	}
	for(int j=0;j<74;j++){
		gotoxy(2+j,24);cout<<"=";
	}
	for(int m=0;m<22;m++){
		gotoxy(20,2+m);cout<<"=";
	}
}
void spot(){
	gotoxy(10,4);cout<<"###"<<endl;
	gotoxy(10,5);cout<<"#"<<endl;
	gotoxy(10,6);cout<<"###"<<endl;
	gotoxy(10,7);cout<<"  #"<<endl;
	gotoxy(10,8);cout<<"###"<<endl;
	
	gotoxy(10,10);cout<<"###"<<endl;
	gotoxy(10,11);cout<<"# #"<<endl;
	gotoxy(10,12);cout<<"###"<<endl;
	gotoxy(10,13);cout<<"#"<<endl;
	
	gotoxy(10,15);cout<<"###"<<endl;
	gotoxy(10,16);cout<<"# #"<<endl;
	gotoxy(10,17);cout<<"# #"<<endl;
	gotoxy(10,18);cout<<"###"<<endl;
	
	gotoxy(10,20);cout<<"###"<<endl;
	gotoxy(10,21);cout<<" # "<<endl;
	gotoxy(10,22);cout<<" # "<<endl;
	gotoxy(10,23);cout<<" # "<<endl;
}
//FIN FUNCIONES DE REPRODUCTOR
	
//FUNCIONES DE JUEGO DE PILAS
void push(PNodo &p, int alt1){
	PNodo nuevo = new Nodo;
	nuevo->info=alt1;
	nuevo->sgte=p;
	p=nuevo;
}

int pop(PNodo &p){
	int x=p->info;
	PNodo temp=p;
	p=p->sgte;
	delete temp;
	return x;
}

void juegoResul(PNodo &p, int n){
	int i,j,alt1,intento,carta,correcto=0,incorrecto=0;
	pixelinicio();
	pixeliphone();
	for(i=0;i<n;i++){
		alt1=rand()%5;
		push(p,alt1);
	}
	system("cls");
	for(j=0;j<10;j++){
		do{
			cout<<"Ingrese el intento "<<j+1<<" :"<<endl;
			cout<<"1->(Trebol)"<<endl;
			cout<<"2->(Corazon)"<<endl;
			cout<<"3->(Diamante)"<<endl;
			cout<<"4->(Espada)"<<endl;
			cin>>intento;
		}while(intento>=5);
		carta=pop(p);
		if(intento==carta){
			cout<<"CORRECTO"<<endl;
			correcto++;
		}
		else{
			cout<<"INCORRECTO"<<endl;
			incorrecto++;
		}
	}
	system("cls");
	cout<<"  RESULTADOS"<<endl;
	cout<<"-_-_-_-_-_-_-_-"<<endl<<endl;
	cout<<"Aciertos: "<<correcto<<endl;
	cout<<"Desaciertos: "<<incorrecto<<endl;
	for(int s=0;s<8;s++){
		Sleep(700);
		cout<<"."<<endl;
	}
	if(correcto>incorrecto){
		cout<<"USTED A GANADO";
	}
	else{
		cout<<"USTED A PERDIDO";
	}
	cout<<endl;
	system("pause");
}

void juego_pilas(){
	PNodo p=NULL;
	int n,op1;
	srand((unsigned)time(NULL));
	do{
		system("cls");
		pixelinicio();
		pixeliphone();		
		gotoxy(13,19);cout<<"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_";
		gotoxy(23,20);cout<<"ADIVINA - LA - CARTA";
		gotoxy(13,21);cout<<"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_";
		gotoxy(13,23);cout<<"~Este juego consiste en adivinar el"; 
		gotoxy(12,24);cout<<"          primer simbolo de la carta~";
		gotoxy(13,25);cout<<"~Si aciertas la mayoria de las 10";
		gotoxy(13,26);cout<<" primeras cartas que salgan, ganaste~";
		gotoxy(23,28);cout<<"ELIJE LA DIFICULTAD";
		gotoxy(13,30);cout<<"(1)--------------->EASY";
		gotoxy(13,31);cout<<"(2)--------------->NORMAL";
		gotoxy(13,32);cout<<"(3)--------------->HARD";
		gotoxy(13,33);cout<<"(4)--------------->REGRESAR AL MENU";
		gotoxy(13,34);cout<<"Ingrese su opcion: ";cin>>op1;
		switch(op1){
		case 1:
			n = 10;
			juegoResul(p,n);
			break;
		case 2:
			n = 20;
			juegoResul(p,n);
			break;
		case 3:
			n = 30;
			juegoResul(p,n);
			break;
		}
	}while(op1!=4);
}
//FIN FUNCIONES JUEGO DE PILAS
	
//FUNCIONES PEDIDO DELIVERY
void inicializa(Cola &c){
	c.primero = NULL;
	c.ultimo = NULL;
}

bool esVacia(Cola c){
	if(c.primero==NULL)
		return true;
	else
		return false;
}

void encolar(Cola &c, Pedido x){
	PNodoPedido nuevo = new NodoPedido;
	nuevo->dato = x;
	nuevo->sgte = NULL;
	if(esVacia(c)){
		c.primero = nuevo;
		c.ultimo = nuevo;
	}else{
		c.ultimo->sgte = nuevo;
		c.ultimo = nuevo;
	}
}

Pedido desencolar(Cola &c){
	Pedido x = c.primero->dato;
	PNodoPedido temp;
	temp = c.primero;
	c.primero = c.primero->sgte;
	delete temp;
	return x;
}

void imprime(Cola &c){
	PNodoPedido p;
	p = c.primero;
	while(p!=NULL){
		cout<<"- Pedido: "<<p->dato.nombre<<" / "<<endl;
		cout<<"  Codigo: "<<p->dato.codigo<<endl;
		cout<<endl;
		p = p->sgte;
	}
}

void pedido(){
	Cola c, aux;
	inicializa(c);
	inicializa(aux);
	int o,v;
	Pedido x;
	do{
		system("cls");
		pixelinicio();
		pixeliphone();
		gotoxy(23,19);cout<<"PEDIDOS POR DELIVERY";
		gotoxy(19,21);cout<<"1. Ingresar una orden";
		gotoxy(19,22);cout<<"2. Revisar turno en la cola";
		gotoxy(19,23);cout<<"3. Canjear pedido";
		gotoxy(19,24);cout<<"4. Regresar al menu anterior";
		gotoxy(23,26);cout<<"Ingrese opcion(1-4): ";cin>>o;
		switch(o){
		case 1:
			system("cls");
			pixelinicio();
			pixeliphone();
			cin.get();
			gotoxy(19,19);cout<<"Ingrese lo que va a pedir: ";
			gotoxy(19,20);cin.getline(x.nombre,50);
			gotoxy(19,22);cout<<"Ingrese su numero de DNI: ";
			gotoxy(19,23);cin>>x.codigo;
			encolar(c,x);
			gotoxy(15,25);cout<<"Su pedido ha sido registrado.";
			gotoxy(15,26);cout<<"Su codigo ha sido generado con su DNI.";
			gotoxy(15,27);cout<<"Reclame la entrega con su codigo";
			gotoxy(15,28);cout<<"Gracias";
			gotoxy(2,55);system("pause");
			break;
		case 2:
			system("cls");
			cout<<"Cola de espera"<<endl;
			cout<<endl;
			imprime(c);
			cout<<endl;
			system("pause");
			break;
		case 3:
			system("cls");
			cout<<"Por favor, ingrese su codigo: ";
			cin>>v;
			bool encontrado = false;
			while(!esVacia(c) && !encontrado){
				x = desencolar(c);
				if(x.codigo==v){
					cout<<"Su pedido está listo y llegará pronto a su destino. Gracias.";
					encontrado = true;
					encolar(aux,x);
				}else{
					encolar(c,x);
				}
			}
			while(!esVacia(aux) && !encontrado){
				x = desencolar(aux);
				if(x.codigo==v){
					cout<<"Su pedido ya ha sido entregado."<<endl;
					encontrado = true;
				}else{
					encolar(aux,x);
				}
			}
			if(!encontrado)
				  cout<<"Su pedido no ha sido registrado."<<endl;
			cout<<endl;
			system("pause");
			break;
		}
	} while(o!=4);
}
//FIN PEDIDO COMIDA

//FUNCIONES BLOCK DE NOTAS 
void BlockNotas(PNodoNotas &LNotas){
	Notas x;
	int op;
	time_t   t,i;
	char *tiempo;
	i = time (&t);
	tiempo = ctime (&i);
	cout<<"\nBLOCK DE NOTAS:";
	cout<<"\n---------------";
	cout<<"\n\t1_Escribir Nota de texto ";
	cout<<"\n\t2_Ver Notas de Texto";
	cout<<"\n\n\tQue Opcion desea Realizar ? : ";
	cin>>op;
	system("cls");
	switch(op){
		case 1:
		cout<<"Inserte Asunto : ";cin.get();cin.getline(x.Asunto,50);
		cout<<"\nInserte Texto : ";cin.getline(x.Texto,200);
		cout<<"\nFecha Texto : "<<tiempo;
		x.p=tiempo;
		cout<<"\n\nGuardando...";
		InsertarBlockNotas(LNotas,x);
		Sleep(2000);break;
		case 2:
			ReporteTexto(LNotas);
		break;
		
		default : cout<<"Opcion incorrecta...Volviendo al menu  ";break;
	}
	Sleep(4000);
	
}
void InsertarBlockNotas(PNodoNotas &LNotas, Notas x)
{
	PNodoNotas nuevoNotas,pNotas;
	nuevoNotas= new NodoNotas;
	nuevoNotas->infoNotas=x;
	nuevoNotas->sgteNotas=NULL;
	if(LNotas==NULL)
		LNotas=nuevoNotas;
	else
		{
			pNotas=LNotas;
			while(pNotas->sgteNotas!=NULL)
				pNotas=pNotas->sgteNotas;
			pNotas->sgteNotas=nuevoNotas;
			
		}
}
void ReporteTexto(PNodoNotas LNotas){
	PNodoNotas pNota;
	cout<<"Datos de la Lista"<<endl;
	pNota=LNotas;
	while(pNota!=NULL)
	{
		cout<<"Asunto : "<<pNota->infoNotas.Asunto<<":\n"<<pNota->infoNotas.Texto<<"\nFecha"<<pNota->infoNotas.p<<endl;
		pNota=pNota->sgteNotas;
	}
	cout<<endl;
}

//FIN BLOCK NOTAS GAAAAAAAAA



















