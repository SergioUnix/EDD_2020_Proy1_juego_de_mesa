#include <iostream>
#include "json.hpp";
#include "listadoble.h"
#include "circular.h"
#include "cola.h"
#include "arbol.h"
#include "listasimple.h"
#include "cubo.h"
#include <conio.h>
#include <string.h>
#include "usuarios.h"
#include "score.h"


using namespace std;
using json = nlohmann::json;
json Juego;
json Tama_matrix;
json Dobles;
json Triple;
json TotalPalabras;
int posX = 0;
int posY = 0;

using namespace std;

///////////////////////////      Variables Globales del juego
circular *diccionario= new circular();  //Guardo las palabras del diccionario
int tablero_tamano;                     //guardo el tama�o de la matriz Dispersa
auto jugadores = new BSTree<std::string>{}; //Arbol donde guardo los nombres de los jugadores
Cola *fichas= new Cola();

Score * scoreboard= new Score();



/////variables para un juego
ListaDoble *Lista_jugador1= new ListaDoble();
ListaDoble *Lista_jugador2= new ListaDoble();

Cubo <string> *tablero= new Cubo<string>();  //tablero del juego





void analizarDatos(string nombre_de_archivo) {

//diccionario= new circular();
//jugadores = new BSTree<std::string>{};
//fichas= new Cola();

    diccionario->limpiar();
    std::ifstream file(nombre_de_archivo);
    file >> Juego;


    //////////Dimension de la matriz
    Tama_matrix = Juego["dimension"];    //extrae las dimensiones del tablero
    tablero_tamano = Tama_matrix;// guarda mi tama�o del tablero
    cout << "Tama";
    printf("%co",164);
    cout<<" de la matriz: "<<tablero_tamano<<"\n \n" << endl;


  ///////////////////////////  //Coordenadas
    Dobles= Juego["casillas"]["dobles"];

    cout << "COORDENADAS DOBLES \n";
    for (const auto coordenada : Dobles) {
      posX = coordenada["x"];
      posY = coordenada["y"];
      cout<<"Pos " << posX << "," << posY << endl;
    }
 /////////////////////////////// Coordenadas
    Triple = Juego["casillas"]["triples"]; //Obtengo las coordenada x y del triple
    cout << "COORDENADAS TRIPLES" << endl;
    for (const auto coordenada : Triple) {
      posX = coordenada["x"];
      posY = coordenada["y"];
      cout<<"Pos " << posX << "," << posY << endl;
    }
  ///////////////////////// Palabras
    TotalPalabras = Juego["diccionario"]; //Obtengo las coordenada x y del triple
    cout << "Palabras obtenidas en el diccionario:" << endl;
    for (const auto palabra : TotalPalabras) {
        cout <<  palabra["palabra"] <<"\n";
      diccionario->add_ordenado(palabra["palabra"]);
    }
    cout << "\n \n Se termino de leer el Archivo...  \n \n" << endl;
    system("pause");
    system("cls");

}





void game(){
Lista_jugador1= new ListaDoble();
Lista_jugador2= new ListaDoble();
tablero= new Cubo<string>();

User* fichas_ingresadas= new User(); // control de usuarios

system("cls");
Lista_jugador1=new ListaDoble(); Lista_jugador2=new ListaDoble(); string Nombre1=""; string Nombre2="";
Cola *copia_fichas= new Cola();  copia_fichas=fichas;
char nom[30],nom2[30],palabra1[33],palabra2[33],cadena[333];
char caracter[10];
int opcion=1, numero=0, corX=-1, corY=-1;
std:: string s=""; std::string car="";
std:: string v=""; std::string car2 ="";

while(true){
cout<<" Seleccionar Jugadores "<<endl;
jugadores->ListaUsuarios();
cout<<"Ingresa nombre Jugador 1"<<endl;
cin>>nom;
cout<<"Ingresa nombre Jugador 2"<<endl;
cin>>nom2;
if(jugadores->search(nom)==true && jugadores->search(nom2)==true){ Nombre1=nom; Nombre2=nom2;
for(int i=0;i<7;i++){
    Lista_jugador1->add_first(copia_fichas->extraer());
    Lista_jugador2->add_first(copia_fichas->extraer());
}
 break; }
 system("cls");
}

cout<<"EL JUEGO EMPIEZA AHORA...."<<endl<<endl;
system("pause");
do{


        switch(opcion){
            case 1:  system("cls");
            if(Lista_jugador1->getSize()<7){
            while(fichas->getSize()>0){Lista_jugador1->add_first(copia_fichas->extraer());  if(Lista_jugador1->getSize()>6){break;};   if(fichas->getSize()<1){break;}        }}//siempre mantiene con 7 cada Lista
            cout<<"JUGADOR  1 "<<Nombre1<<endl;
            cout<<"Diccionario: ";
            diccionario->lista_imprimir();
            cout<<"Instrucciones:  Salir--\"salir\" Pasar de turno--\"pasar\"  "<<endl<<endl;
            cout<<"Fichas Disponibles   :";
            cout<< Lista_jugador1->lista_imprimir()<<endl<<endl;
            //Lista_jugador1->generar_txt();
            cout<<"\n\n Inserte la palabra que desea armar:  ";
            cin>>palabra1;
                        s=palabra1;
                        if(s=="salir"){cout<<"Se termino el Juego \n\n"; opcion=9;  system("pause"); break; }else if(s=="pasar"){  opcion=2; break;}else{opcion=2;}
                        if(diccionario->exist(palabra1)==true){
                                cout<<"Numero de Letras que ingresara:  ";
                                cin >>numero;
                                while(numero>0){
                                do{cout<<"Coordenada X  :";  cin>>corX;      }while(((corX>0)!=true) || ((corX<tablero_tamano)!=true));
                                do{cout<<"Coordenada Y  :"; cin>>corY;       }while(((corY>0)!=true) || ((corY<tablero_tamano)!=true));


                                cout<<std::to_string(corY)<<"imprimir"<<(corY<20)<<endl;
                                cout<<"Coordenada Letra :";
                                cin>>caracter;    car=caracter; cout<<"\n\n";

                                if(Lista_jugador1->existC(car)==false){cout<<"Caracter no existe en la cola \n\n";  opcion=2; break; } // si no ingresa un caracter que tiene en la lista doble se sale
                                tablero->insertar_elemento(corX,corY,car,Nombre1);//ingreso caracter a la matriz
                                tablero->generar_txt();  //grafico la matriz
                                fichas_ingresadas->add_first(car,corX,corY,Nombre1);
                                Lista_jugador1->removeC(car);
                                numero--;corX=-1; corY=-1;
                                }
                        }else{cout<<"La palabra no EXISTE en el diccionario \n\n"; opcion=2; break;   }


                    if(Lista_jugador1->getSize()<1){            cout<<"Finalizo el Juego \n\n";  opcion=9;  system("pause");}


            opcion=2;
            cout<<"FINALIZO SU TURNO \n\n";
            system("pause");

            break;
            case 2:  system("cls");
            if(Lista_jugador2->getSize()<7){
            while(fichas->getSize()>0){Lista_jugador2->add_first(copia_fichas->extraer());  if(Lista_jugador2->getSize()>6){break;};   if(fichas->getSize()<1){break;}        }}//siempre mantiene con 7 cada Lista

            cout<<"JUGADOR  2 "<<Nombre2<<endl;
            cout<<"Diccionario:" ;
            diccionario->lista_imprimir();
            cout<<"Instrucciones:  Salir--\"salir\" Pasar de turno--\"pasar\"  "<<endl<<endl;
            cout<<"Fichas Disponibles   :";
            cout<<Lista_jugador2->lista_imprimir();
            //Lista_jugador2->generar_txt();
            cout<<"\n\n Ingresar la palabra que desea armar: ";
            cin>>palabra2;

                        v=palabra2;
                        if(v=="salir"){cout<<"Se termino el Juego \n\n"; opcion=9;  system("pause"); break; }else if(v=="pasar"){ opcion=1; break;}else{opcion=1;}
                        if(diccionario->exist(palabra2)==true){
                                cout<<"Numero de Letras que ingresara:  ";
                                cin >>numero;
                                while(numero>0){
                                do{cout<<"Coordenada X  :";cin>>corX;    }while(((corX>0)!=true) || ((corX<tablero_tamano)!=true));
                                do{cout<<"Coordenada Y  :";cin>>corY;    }while(((corY>0)!=true) || ((corY<tablero_tamano)!=true));


                                cout<<"Coordenada Letra :";
                                cin>>caracter;  car2=caracter;cout<<"\n\n";

                                if(Lista_jugador2->existC(car2)==false){cout<<"Caracter no existe en la cola \n\n"; opcion=1; break; } // si no ingresa un caracter que tiene en la lista
                                tablero->insertar_elemento(corX,corY,car2,Nombre2);//ingreso caracter a la matriz
                                tablero->generar_txt();  //grafico la matriz
                                fichas_ingresadas->add_first(car2,corX,corY,Nombre2);
                                Lista_jugador2->removeC(car2);
                                numero--;corX=-1; corY=-1;
                                }
                        }else{cout<<"La palabra no EXISTE en el diccionario \n\n"; opcion=1;   system("pause"); break;  }



                            if(Lista_jugador2->getSize()<1){            cout<<"Finalizo el Juego \n\n";  opcion=9;  system("pause");}


            opcion=1;
             cout<<"FINALIZO SU TURNO \n\n";
            system("pause");

            break;

        }
            }while(opcion!=9);


    ////////////////// Aca ya termino el Juego empiezo a manipular los puntos

    fichas_ingresadas->print();

    fichas_ingresadas->add_first("o",2,5,Nombre2);
    fichas_ingresadas->add_first("s",4,10,Nombre2);
    fichas_ingresadas->add_first("o",10,15,Nombre2);

    fichas_ingresadas->add_first("o",5,2,Nombre1);
    fichas_ingresadas->add_first("s",10,4,Nombre1);
    fichas_ingresadas->add_first("o",15,10,Nombre1);

    int punteo_jugador1=0;
    int punteo_jugador2=0;


//        for (const auto coordenada : Dobles) {
 //   posX = coordenada["x"];
  //  posY = coordenada["y"];

 //   fichas_ingresadas->mulDobles(posX,posY);
  //  }

  //  for (const auto coordenada : Triple) {
   // posX = coordenada["x"];
  //  posY = coordenada["y"];
  //  fichas_ingresadas->mulTriples(posX,posY);
  //  }


punteo_jugador1=fichas_ingresadas->punteoTotal(Nombre1);
punteo_jugador2=fichas_ingresadas->punteoTotal(Nombre2);
scoreboard->add_ordenado(Nombre1,punteo_jugador1);
scoreboard->add_ordenado(Nombre2,punteo_jugador2);






















}









void menu(){

    jugadores->insert("zorro");
	jugadores->insert("Ariel");
	jugadores->insert("Madelyn");
	jugadores->insert("Juan");
    int ed, opcion, contador=0, rep,ver;
    char nom[30],usuario[30],juga[30];
    bool veri;

    do{
        cout<<"MENU"<<endl;
        cout<<"1. Cargar Archivo"<<endl;
        cout<<"2. Ingresar Jugador \n"<<endl;
        cout<<"3. - JUGAR -\n"<<endl;
        cout<<"5. Reportes \n"<<endl;
        cout<<"8.salir \n\n"<<endl;
        cout<<"Ingresa Opcion  \n"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:  system("cls");
            //cin>>ed;
            analizarDatos("configuracion.json");
            cout<<"Datos Cargados"<<endl;
            //cout<<"\n";
            //system("pause");
            break;
            case 2: system("cls");
            cout<<"Ingresa nombre Jugador"<<endl;
            cin>>usuario;
            if(jugadores->search(usuario)==false){jugadores->insert(usuario); }else{cout<<"No se Guardo escoja Otro Nombre"<<endl;}


            break;

            case 3:
            game();

            break;
            case 5:    system("cls");
                       do{cout<<"Seleccionar Reporte"<<endl;
                       cout<<"1. Lista Doblemente Enlazada Circular: Diccionario "<<endl;
                       cout<<"2. Cola: Fichas disponibles del Juego"<<endl;
                       cout<<"3. Arbol Binario de Busqueda: Jugadores"<<endl;
                       cout<<"4. Recorrido Preorden del ABB"<<endl;
                       cout<<"5. Recorrido InOrder del ABB"<<endl;
                       cout<<"6. Recorrido PostOrder del ABB"<<endl;
                       cout<<"7. Historial de Puntaje por Jugador: Lista Simple Ordenada "<<endl;
                       cout<<"8. Scoreboard : Lista Simple Ordenada"<<endl;
                       cout<<"9. SALIR DEL MENU"<<endl<<endl;
                       cout<<"Ingresar Opcion:"<<endl;
                       cin>>rep;
                        switch(rep){
                        case 1:
                        diccionario->generar_txt();
                            break;
                        case 2:
                        fichas->generar_txt();
                            break;
                        case 3:
                        jugadores->generar_txt();  //creo archivo txt y genero imagen
                            break;
                        case 4:
                        jugadores->Pre();
                            break;
                        case 5:
                        jugadores->In();
                            break;
                        case 6:
                        jugadores->Post();
                            break;
                        case 7: cout<<"Ingrese el Nombre del jugador\n";
                        cin>>juga;
                            break;
                        case 8:
                        scoreboard->generar_txt();
                            break;
                        }
                        system("cls");
                        }while(rep!=9);
            cout<<"\n";
            system("pause");
            break;
            case 6:

            cout<<"\n";
            system("pause");
            break;
            case 7: cout<<"mostrar el arbol\n\n";

            cout<<"\n";
            system("pause");
        }
        system("cls");
    }while(opcion!=8);
}










int main()
{
fichas->elementos_default(); //Ingreso fichas a la Cola




menu();

//int f=5;
//int g=7;

//if(((f==4)==true)&&((g==7)==true))cout<<"funciona la igualdad\n\n";




























    return 0;
}






