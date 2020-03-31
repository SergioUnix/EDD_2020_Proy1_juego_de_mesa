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
int tablero_tamano;                     //guardo el tamaño de la matriz Dispersa
auto jugadores = new BSTree<std::string>{}; //Arbol donde guardo los nombres de los jugadores
Cola *fichas= new Cola();


/////variables para un juego
ListaDoble *Lista_jugador1= new ListaDoble();
ListaDoble *Lista_jugador2= new ListaDoble();




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





void game(){
system("cls");
Lista_jugador1=new ListaDoble(); Lista_jugador2=new ListaDoble(); string Nombre1=""; string Nombre2="";
Cola *copia_fichas= new Cola();  copia_fichas=fichas;
char nom[30],nom2[30],palabra1[33],palabra2[33];
int opcion=1;

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
system("pause"); system("cls");
}

cout<<"EL JUEGO EMPIEZA AHORA...."<<endl;
system("pause");
 do{


        switch(opcion){
            case 1:  system("cls");
            cout<<"Fichas Disponibles Jugador 1\n"<<endl;
            cout<< Lista_jugador1->lista_imprimir()<<endl;
            cout<<"Escribe letras a Ingresar\n"<<endl;
            cin>>palabra1;
            opcion=2;


            break;
            case 2:  system("cls");
            cout<<"Fichas Disponibles Jugador 2\n"<<endl;
            cout<<Lista_jugador2->lista_imprimir()<<endl;
            cout<<"Escribe letras a Ingresar\n"<<endl;
            cin>>palabra2;
            opcion=1;
            break;
            case 3:  system("cls");

            break;
            case 4:  system("cls");

            break;
        }
            }while(opcion!=9);






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
                        case 8: cout<<"digite su edad"<<endl;
                        //cin>>ed;
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
































    return 0;
}






