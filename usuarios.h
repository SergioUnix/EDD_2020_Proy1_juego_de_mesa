#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED


using namespace std;

class User
{
    class Nodo{
    public:
        Nodo(std::string dat, std::string x,std::string y,std::string nom)
        {
            next = 0;
            dato = dat;
            corX=x;
            corY=y;
            nombre=nom;


        }

        Nodo *getNext(){ return next;}
        void setNext(Nodo *n) { next = n;}
        std::string getDato(){ return dato;}

void print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    std::cout << dato<< "-> ";}

Nodo *next;

     private:

        std::string dato;
         std::string corX;
          std::string corY;
           std::string nombre;

    };
    /////////////////////sigue la lista
     public:
         User()
         {
             first = 0;
             size = 0;
         }

         int getSize(){return size;}
         void add_ordenado(std::string dato, std::string corX,std::string corY,std::string nombre);
         void add_first(std::string dato, std::string corX,std::string corY,std::string nombre);
         void add_last(std::string dato, std::string corX,std::string corY,std::string nombre);
         void remove_at(int index);







int comparar(std::string a,std::string b) {
    int n1 = a.length();
    int n2 = b.length();
    // declaring character arrayCubo <std::string> *cub;

    char char_a[n1 + 1];
    char char_b[n2 + 1];
    // copying the contents of the
    // string to char array
    strcpy(char_a, a.c_str());
    strcpy(char_b, b.c_str());
    return strcmp(char_a,char_b);
}


void print()
{
    Nodo *temp=this->first;
    if (this->isEmpty()) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (temp->getNext()==0) cout << "NULL";
                temp = temp->next;
        }
  }
  cout << endl << endl;
}






     private:
         bool isEmpty(){return size == 0;}
         int size;
         Nodo *first;
};



void User::add_first(std::string dato,std::string corX,std::string corY,std::string nombre)
{
    Nodo *n = new Nodo(dato,corX,corY,nombre);
    if(this->isEmpty())
    {
        this->first = n;
        this->size++;
    }
    else
    {
        n->setNext(this->first);

        this->first = n;
        this->size++;
    }
}





void User::add_last(std::string dato,std::string corX,std::string corY,std::string nombre)
{
    Nodo *n = new Nodo(dato,corX,corY,nombre);
    Nodo *aux=this->first;
    Nodo *aux_ant=0;
    bool bandera=false;
    if(this->isEmpty())
    {
        this->first = n;
        this->size++;
    }
    else
    {
               while(true){

               if(aux->getNext()==0){break;}
               aux=aux->getNext();
               }
        aux->setNext(n);
        this->size++;
    }
}








void User::add_ordenado(std::string dato,std::string corX,std::string corY,std::string nombre)
{ Nodo *n = new Nodo(dato,corX,corY,nombre);
    Nodo *aux=this->first;
    Nodo *aux_ant=0;
    bool bandera=false;
   // bool bandera2=false;

    if(this->isEmpty())
    {
        this->first = n;
        this->size++;
    }
    else
    {

        while(true){

                if(this->comparar(aux->getDato(),n->getDato())>0){
                //std::cout<<"comparo  ----------------------------------- "<<this->comparar(aux->getDato(),n->getDato())<<"---"<<aux->getDato()<<"--"<<n->getDato()<<this->getSize()<<std::endl;
               // std::cout<<"comparo  ----------------------------------- "<<aux->getDato()<<std::endl;

                bandera=true;

                break;
                }
                if(aux->getNext()==0){break;}

                aux_ant=aux;
               aux=aux->getNext();


        }

        if(aux==this->first&&bandera==true){
        n->setNext(this->first);
        this->first = n;
        this->size++;

         }else if(bandera==true&&this->getSize()>1){

        aux_ant->setNext(n);
        n->setNext(aux);
        this->size++;


    }else{
        aux->setNext(n);
        this->size++;
}


}}




#endif // USUARIOS_H_INCLUDED
