#include <iostream>
#include "json.hpp";
#include "listadoble.h"
#include "circular.h"
#include "cola.h"
#include "arbol.h"
#include <conio.h>
#include <string.h>


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


circular *diccionario= new circular();
int tablero_tamano;



void analizarDatos(string nombre_de_archivo) {
    diccionario->limpiar();
    std::ifstream file(nombre_de_archivo);
    file >> Juego;


    //////////Dimension de la matriz
    Tama_matrix = Juego["dimension"];    //extrae las dimensiones del tablero
    tablero_tamano = Tama_matrix;// guarda mi tamaño del tablero
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



void menu(){
    int ed, opcion, contador=0;
    char nom[30],usuario[30];
    do{
        cout<<"MENU"<<endl;
        cout<<"1. cargar archivo"<<endl;
        cout<<"2. Ingresar Jugador \n"<<endl;
        cout<<"8.salir \n\n"<<endl;
        cout<<"Ingresa Opcion  \n"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1: cout<<"digite su edad"<<endl;
            cin>>ed;
            cout<<"digite su nombre"<<endl;
            cin>>nom;
            cout<<"\n";
            system("pause");
            break;
            case 2:
            cout<<"Ingresa nombre Jugador"<<endl;
            cin>>usuario;
            cout<<"\n";
            system("pause");
            break;
            case 3: cout<<"mostrar el arbol\n\n";

            cout<<"\n";
            system("pause");
        }
        system("cls");
    }while(opcion!=8);
}









int main()
{// menu();


 //analizarDatos("configuracion.json");
 cout<<" /////////////////////  datos de la cola " <<endl;
 Cola *prueba= new Cola();
 prueba->elementos_default();
 cout<<" boolean de la cola " << true<<endl;
 prueba->imprimir();

  cout<<" /////////////////////  datos del arbol binario" <<endl<<endl;

auto trees = new BSTree<std::string>{};
	trees->insert("zorro");
	trees->insert("Ariel");
	trees->insert("Madelyn");
	trees->insert("Juan");
	//trees->remove("Juan");
	trees->traverse_in_order();
	trees->traverse_Pre_order();
	trees->traverse_Post_order();


    std::cout << "Element Ariel: " << trees->search("Ariel") << std::endl;
	std::cout << "Element 111: " << trees->search("Perez") << std::endl;
	//std::cout << trees->grafic_codigo();

    return 0;
}






