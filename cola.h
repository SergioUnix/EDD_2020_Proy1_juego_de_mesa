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
        std::string informacion = raiz->letra; ///extraigo la letra
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
    string cadena="ABCDEFGHIJLMNOPQRSTUVXYZ";
     int n1 = cadena.length();
     char char_a[n1 + 1];
     strcpy(char_a, cadena.c_str());
     string aux;

  for (int i = 0; i < cadena.size(); i++){
    aux=cadena[i];
      insertar(5,aux);


     }

}



#endif // COLA_H_INCLUDED
