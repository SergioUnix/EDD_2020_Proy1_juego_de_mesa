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

bool Cola::vacia()
{
    if (raiz == NULL)
        return true;
    else
        return false;
}
void Cola::elementos_default()
{
     string cadena="ALOTGCDEIBOCNAORDEIEOFLGUIANSEÑHOMADRHTIICEJRLSUIONRALMEASNOAEDOPSNUOECQARTSEOBPUSTUESAVEEADXAYZA";
     int n1 = cadena.length();
     char char_a[n1 + 1];
     strcpy(char_a, cadena.c_str());
     string aux;

  for (int i = 0; i < cadena.size(); i++){
    aux=cadena[i];

    if(cadena[i]=='A'||cadena[i]=='E'||cadena[i]=='O'||cadena[i]=='I'||cadena[i]=='S'||cadena[i]=='N'||cadena[i]=='L'||cadena[i]=='R'||cadena[i]=='U'||cadena[i]=='T'){ insertar(1,aux);  }
    if(cadena[i]=='D'||cadena[i]=='G'){ insertar(2,aux);  }
    if(cadena[i]=='C'||cadena[i]=='B'||cadena[i]=='M'||cadena[i]=='P'){ insertar(3,aux);  }
    if(cadena[i]=='H'||cadena[i]=='F'||cadena[i]=='V'||cadena[i]=='Y'){ insertar(4,aux);  }
    if(cadena[i]=='Q'){ insertar(5,aux);  }
    if(cadena[i]=='J'||cadena[i]=='Ñ'||cadena[i]=='X'){ insertar(8,aux);  }
    if(cadena[i]=='Z'){ insertar(10,aux);  }

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
