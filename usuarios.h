#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED


using namespace std;

class User
{
    class Nodo{
    public:
        Nodo(std::string dat, int x,int y,std::string nom,int val)
        {
            next = 0;
            dato = dat;
            valor_dato=val;
            corX=x;
            corY=y;
            nombre=nom;


        }


        Nodo *getNext(){ return next;}
        void setNext(Nodo *n) { next = n;}
        std::string getDato(){ return dato;}
        int getCorX(){return corX;}
        int getCorY(){return corY;}
        int getValor(){return valor_dato;}
        std::string getNombre(){return nombre;}
        void setValor(int a){valor_dato=a;}






void print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    std::cout << "- "<< dato<<std::to_string(corX)<<std::to_string(corY)<<nombre <<" -";}

Nodo *next;

     private:

        std::string dato;
        int valor_dato;
         int corX;
          int corY;
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
         void add_ordenado(std::string dato, int corX,int corY,std::string nombre);
         void add_first(std::string dato, int corX,int corY,std::string nombre);
         void add_last(std::string dato, int corX,int corY,std::string nombre);
         void remove_at(int index);


         void mulDobles(int x, int y);
         void mulTriples(int x, int y);
         int punteoTotal(std::string jugador);










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



void User::add_first(std::string dato,int corX,int corY,std::string nombre)
{ int val=0;
    if(dato=="a"||dato=="e"||dato=="o"||dato=="i"||dato=="s"||dato=="n"||dato=="l"||dato=="r"||dato=="u"||dato=="t"){ val=1;  }
    if(dato=="d"||dato=="g"){ val=2;  }
    if(dato=="c"||dato=="b"||dato=="m"||dato=="p"){ val=3;  }
    if(dato=="h"||dato=="f"||dato=="v"||dato=="y"){ val=4;  }
    if(dato=="q"){ val=5;  }
    if(dato=="j"||dato=="ñ"||dato=="x"){ val=8;  }
    if(dato=="z"){ val=10;  }







    Nodo *n = new Nodo(dato,corX,corY,nombre,val);
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





void User::add_last(std::string dato,int corX,int corY,std::string nombre)
{int val=0;
    if(dato=="a"||dato=="e"||dato=="o"||dato=="i"||dato=="s"||dato=="n"||dato=="l"||dato=="r"||dato=="u"||dato=="t"){ val=1;  }
    if(dato=="d"||dato=="g"){ val=2;  }
    if(dato=="c"||dato=="b"||dato=="m"||dato=="p"){ val=3;  }
    if(dato=="h"||dato=="f"||dato=="v"||dato=="y"){ val=4;  }
    if(dato=="q"){ val=5;  }
    if(dato=="j"||dato=="ñ"||dato=="x"){ val=8;  }
    if(dato=="z"){ val=10;  }


    Nodo *n = new Nodo(dato,corX,corY,nombre, val);
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







void User::mulDobles(int x,int y)
{

    Nodo *temp=this->first;
    if (this->isEmpty()) {

    } else {
        while (temp) {

         if(((x==temp->getCorX())==true)&&((y==temp->getCorY())==true)){
            temp->setValor(temp->getValor()*2);
            }



         temp = temp->next;
        }
  }

}

void User::mulTriples(int x,int y)
{

    Nodo *temp=this->first;
    if (this->isEmpty()) {

    } else {
        while (temp) {

         if(((x==temp->getCorX())==true)&&((y==temp->getCorY())==true)){
            temp->setValor(temp->getValor()*3);
            }



         temp = temp->next;
        }
  }



}




////  Obtener el punteo de cada jugador dado su nombre
int User::punteoTotal(std::string jugador)
{
    int result=0;
    Nodo *temp=this->first;
    if (this->isEmpty()) {

    } else {
        while (temp) {

         if((jugador==temp->getNombre())==true){
             result=result+temp->getValor();

            }



         temp = temp->next;
        }
  }
  return result;
}











void User::add_ordenado(std::string dato,int corX,int corY,std::string nombre)
{int val=0;
    if(dato=="a"||dato=="e"||dato=="o"||dato=="i"||dato=="s"||dato=="n"||dato=="l"||dato=="r"||dato=="u"||dato=="t"){ val=1;  }
    if(dato=="d"||dato=="g"){ val=2;  }
    if(dato=="c"||dato=="b"||dato=="m"||dato=="p"){ val=3;  }
    if(dato=="h"||dato=="f"||dato=="v"||dato=="y"){ val=4;  }
    if(dato=="q"){ val=5;  }
    if(dato=="j"||dato=="ñ"||dato=="x"){ val=8;  }
    if(dato=="z"){ val=10;  }


     Nodo *n = new Nodo(dato,corX,corY,nombre,val);
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
