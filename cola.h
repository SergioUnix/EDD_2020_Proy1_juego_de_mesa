#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED


using namespace std;

class Cola {
private:
    class Nodo {
    public:
        int info;  // es el puntaje de la ficha
        string letra;

        Nodo *sig;


    };

    Nodo *raiz;
    Nodo *fondo;
public:
    Cola();
    ~Cola();
    void insertar(int x,string le);
    std::string extraer();
    void imprimir();
    bool vacia();
    void elementos_default();
    std::string  grafic();
	void generar_txt();
	bool exist(string cadena);
	int valor(string cadena);
	int getSize();


};


Cola::Cola()
{
    raiz = NULL;
    fondo = NULL;
}

Cola::~Cola()
{
    Nodo *reco = raiz;
    Nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        delete bor;
    }
}

void Cola::insertar(int x,string le) ////ingreso el puntaje y la letra
{
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info = x;
    nuevo->letra= le;
    nuevo->sig = NULL;
    if (vacia())
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}
std::string Cola::extraer()
{
    if (!vacia())
    {
        std::string informacion = raiz->letra; //extraigo la letra
        Nodo *bor = raiz;
        if (raiz == fondo)
        {
            raiz = NULL;
            fondo = NULL;
        }
        else
        {
            raiz = raiz->sig;
        }
        delete bor;
        return informacion;
    }
    else
        return "";
}



////tamano de la cola
int Cola::getSize()
{
    int result=0;
    Nodo *aux = raiz;

    while (aux != NULL)
    {
        result++;
        aux = aux->sig;
    }
    return result;
}




void Cola::imprimir()
{
    Nodo *aux = raiz;
    cout << "Listado de todos los elementos de la cola.\n";
    while (aux != NULL)
    {
        cout << aux->letra << "-";
        aux = aux->sig;
    }
    cout << "\n";
}

///// Busco el dato dentro de la cola
bool Cola::exist(string cadena)
{ bool result=false;
    Nodo *aux = raiz;
    while (aux != NULL)
    {
      if(cadena==aux->letra){result=true;}
        aux = aux->sig;
    }
    return result;
}
////////////devuelve el valor de la letra ingresada
int Cola::valor(string cadena)
{ int t=NULL;
    Nodo *aux = raiz;
    while (aux != NULL)
    {
      if(cadena==aux->letra){t=aux->info;}
        aux = aux->sig;
    }
    return t;
}


bool Cola::vacia()
{
    if (raiz == NULL)
        return true;
    else
        return false;
}
void Cola::elementos_default()
{
    // string cadena="ALOTGCDEIBOCNAORDEIEOFLGUIANSEÑHOMADRHTIICEJRLSUIONRALMEASNOAEDOPSNUOECQARTSEOBPUSTUESAVEEADXAYZA";
     //string cadena="alotgcdeibocnaordeieoflguianse;homadrhtiicejrlsuionralmeasnoaedopsnuoecqartseobpustuesaveeadxayza";
     string cadena="osoalotosogcdesodaibocsodanaoraguadeieaaguaoflguiansehomadrhtiicejrlsuionralmeasnoaedopsnuoecqartseobpustuesaveeadxayza";
     int n1 = cadena.length();
     char char_a[n1 + 1];
     strcpy(char_a, cadena.c_str());
     string aux;

  for (int i = 0; i < cadena.size(); i++){
    aux=cadena[i];

    if(cadena[i]=='a'||cadena[i]=='e'||cadena[i]=='o'||cadena[i]=='i'||cadena[i]=='s'||cadena[i]=='n'||cadena[i]=='l'||cadena[i]=='r'||cadena[i]=='u'||cadena[i]=='t'){ insertar(1,aux);  }
    if(cadena[i]=='d'||cadena[i]=='g'){ insertar(2,aux);  }
    if(cadena[i]=='c'||cadena[i]=='b'||cadena[i]=='m'||cadena[i]=='p'){ insertar(3,aux);  }
    if(cadena[i]=='h'||cadena[i]=='f'||cadena[i]=='v'||cadena[i]=='y'){ insertar(4,aux);  }
    if(cadena[i]=='q'){ insertar(5,aux);  }
    if(cadena[i]=='j'||cadena[i]=='ñ'||cadena[i]=='x'){ insertar(8,aux);  }
    if(cadena[i]=='z'){ insertar(10,aux);  }

     }


}



  std::string  Cola::grafic(){
         Nodo *aux = raiz;
        std::string  linea1="digraph G {\nrankdir=LR\nnode [shape=record, color=blue margin = 0 fontcolor = white fontsize = 8 width = 0.01 height=0.01 style = filled, fillcolor = black]\n hashTable [label=\"";
        std::string ultimaLinea="];\n}";
        std::string nodos="";
        int a=0;
    while (aux != NULL)
    {

if(aux->sig!=NULL){
nodos=nodos+"<f0>|"+aux->letra+" X  "+std::to_string(aux->info) +" pts|";
}
else{nodos=nodos+"<f0>|"+aux->letra+" X  "+std::to_string(aux->info) +" pts\""; }


        aux = aux->sig;
        a++;
    }
        std::string grafo= linea1+nodos+ultimaLinea;
        return grafo;
    };

void Cola::generar_txt(){
std::string texto= grafic();
std::ofstream archivo;
archivo.open("cola.txt", std::ios:: out);

archivo<<texto;
archivo.close();

        std::string sentencia="dot -Tpng cola.txt -o cola.png";
        std::string sentencia2="start cola.png";
        std::string salir="EXIT";
        system(sentencia.c_str());
        system(sentencia2.c_str());
        system(salir.c_str());


};





#endif // COLA_H_INCLUDED
