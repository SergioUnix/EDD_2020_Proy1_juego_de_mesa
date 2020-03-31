#ifndef CIRCULAR_H_INCLUDED
#define CIRCULAR_H_INCLUDED
#include<string.h>
#include<fstream>


class circular
{
    class Nodo{
    public:
        Nodo(std::string x)
        {
            next = 0;
            before = 0;
            dato = x;

        }

        Nodo *getNext(){ return next;}
        Nodo *getBefore() {return before;}
        void setNext(Nodo *n) { next = n;}
        void setBefore(Nodo *n){ before = n;}

        std::string getDato(){ return dato;}




     private:
        Nodo *next;
        Nodo *before;
        std::string dato;

    };
    /////////////////////sigue la lista
     public:
         circular()
         {
             first = 0;
             last = 0;
             size = 0;
         }

         int getSize(){return size;}
         void add_ordenado(std::string dato);
         void add_first(std::string dato);
         void add_last(std::string dato);
         void add_at(std::string dato, int index);
         void remove_at(int index);
         void limpiar();
        std::string cantidad_artistas();
         std::string grafic();
         void generar_txt();
         std::string get_element_at(int index);





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




     private:
         bool isEmpty(){return size == 0;}
         int size;
         Nodo *first;
         Nodo *last;
};

void circular::limpiar()
{this->size=0;
this->first =0;
this->last=0;



}










void circular::add_ordenado(std::string dato)
{

    Nodo *n = new Nodo(dato);
    Nodo *aux=this->first;
    bool bandera=false;

    if(this->isEmpty())
    {
        this->first = n;
        this->last = n;
        this->size++;
    }
    else
    {

        while(true){
                if(this->comparar(aux->getDato(),n->getDato())>0){   ///// verifica que dato va despues , ordena los strings y si levanta una bandera
                //std::cout<<"comparo  ----------------------------------- "<<this->comparar(aux->getDato(),n->getDato())<<"---"<<aux->getDato()<<"--"<<n->getDato()<<this->getSize()<<std::endl;
               // std::cout<<"comparo  ----------------------------------- "<<aux->getDato()<<std::endl;

                bandera=true;
                break;
                }
                if(aux->getNext()==this->first||aux->getNext()==0){break;} ///si llega aca ya llego al ultimo nodo
               aux=aux->getNext();


        }

        if(aux==this->first&&bandera==true&&this->getSize()==1){
        n->setNext(this->first);
        this->first->setBefore(n);
        this->first = n;
        this->first->setBefore(this->last); // aca seteo el puntero primer puntero para que apunte hacia el ultimo porque es circular
        this->size++;


        }else if(aux==this->last&&bandera==false&&this->getSize()==1){
        this->last->setNext(n);
        n->setBefore(this->last);
        this->last = n;
         this->last->setNext(this->first); // aca seteo el puntero ultimo puntero para que apunte hacia el primero porque es circular
         this->first->setBefore(this->last);
        this->size++;

        }
        else if(aux==this->last&&bandera==true&&this->getSize()>1){
        n->setNext(aux);
        n->setBefore(aux->getBefore());
        aux->getBefore()->setNext(n);
        aux->setBefore(n);
        this->size++;


        }else if(aux==this->last&&bandera==false&&this->getSize()>1){
        this->last->setNext(n);
        n->setBefore(this->last);
        this->last = n;
         this->last->setNext(this->first); // aca seteo el puntero ultimo puntero para que apunte hacia el primero porque es circular
         this->first->setBefore(this->last);
        this->size++;

        }else if(aux==this->first&&bandera==true&&this->getSize()>1){

        n->setNext(this->first);
        this->first->setBefore(n);
        this->first = n;
         this->first->setBefore(this->last); // aca seteo el puntero primer puntero para que apunte hacia el ultimo porque es circular
         this->last->setNext(this->first);

        this->size++;
        }else if(bandera==true&&this->getSize()>1){
          n->setNext(aux);
         n->setBefore(aux->getBefore());
         aux->getBefore()->setNext(n);
        aux->setBefore(n);
        this->size++;

    }else{
}


}}

void circular::add_first(std::string dato)
{
    Nodo *n = new Nodo(dato);
    if(this->isEmpty())
    {
        this->first = n;
        this->last = n;
        this->size++;
    }
    else
    {
        n->setNext(this->first);
        this->first->setBefore(n);
        this->first = n;
        this->first->setBefore(this->last); // aca seteo el puntero primer puntero para que apunte hacia el ultimo porque es circular
        this->last->setNext(this->first); // aca seteo el puntero ultimo puntero para que apunte hacia el primeroo porque es circular
        this->size++;
    }
}

void circular::add_last(std::string dato)
{
    if(this->isEmpty())
    {
        this->add_first(dato);
    }
    else
    {
        Nodo *n = new Nodo(dato);
        this->last->setNext(n);
        n->setBefore(this->last);
        this->last = n;
        this->last->setNext(this->first); // aca seteo el puntero ultimo puntero para que apunte hacia el primero porque es circular
        this->first->setBefore(this->last); // aca seteo el puntero primer puntero para que apunte hacia el ultimo porque es circular
        this->size++;
    }
}

void circular::add_at(std::string dato, int index)
{
    if(index >= 0 && index <= this->size)
    {
        if(index == 0){ this->add_first(dato); return;}
        if(index == this->size) {this->add_last(dato); return;}
        Nodo *aux = this->first;
        int x = 0;
        while(aux!=0)
        {
            if(x == index){break;}
            aux = aux->getNext();
            x++;
        }
        Nodo *n = new Nodo(dato);
        aux->getBefore()->setNext(n);
        n->setBefore(aux->getBefore());
        n->setNext(aux);
        aux->setBefore(n);
        this->size++;
    }
}

std::string circular::get_element_at(int index)
{ int help=index;
    while(help>=this->size){
        help= help-this->size;
    }
     while(help<0){
        help= help+this->size;
    }

    if(help >= 0 && help < size)
    {
        Nodo *iterador = this->first;
        int x = 0;
for(int k=0;k <this->size;k++){
            if(help == x){return iterador->getDato(); break;}
            iterador = iterador->getNext();
            x++;
        }
    }
    return "";
}


std::string circular::cantidad_artistas()
{
    std::string result;

        Nodo *iterador = this->first;
        int x = 1;
        while(iterador!=0)
        {
            result = result +std::to_string(x)+ "."+iterador->getDato()+" \n";
            iterador = iterador->getNext();
            x++;
        }

    return result;
}





void circular::remove_at(int index)
{
        if(index >= 0 && index < this->size)
    {
        if(index == 0){Nodo *aux = this->first->getNext();  aux->setBefore(this->last); this->first =aux;       this->size--;    return;}
        if(index == this->size-1) {Nodo *aux = this->last->getBefore();  aux->setNext(this->first); this->last=aux;       this->size--;             return;}
        Nodo *aux = this->first;
        int x = 0;
        while(aux!=0)
        {
            if(x == index){break;}
            aux = aux->getNext();
            x++;
        }

        aux->getBefore()->setNext(aux->getNext());
        aux->getNext()->setBefore(aux->getBefore());
        this->size--;
    }

    // return 0;
}

std::string circular::grafic()
{
        std::string linea1=" digraph G {\n";
       std:: string linea2="nodesep=.02;\n";
        std::string linea3="rankdir=LR;\n";
        std::string linea4="node [shape=record,width=.1,height=.1];\n";
        std::string linea5="";
        std::string linea6="node [width =1.5];\n";

        Nodo *node = this->first;
        //node =self.head
        int index=1;
        std::string nodos="";
        std::string direccion="";

       // if(aux->getNext()==this->first||aux->getNext()==0){break;} ///si llega aca ya llego al ultimo nodo
         //      aux=aux->getNext();

         while(true){
         nodos=nodos+ "node"+std::to_string(index) +"[label = \"{<n> |" + node->getDato() +"| <p> }\"];\n";
         if(index==1){direccion=direccion+"node" + std::to_string(index)+":n -> node"+std::to_string(this->size)+":p;\n";
         direccion=direccion+"node"+std::to_string(index)+":p -> node"+std::to_string(index+1)+":n;\n" ;
         }else if(index==this->size){direccion=direccion+"node" + std::to_string(index)+":n -> node"+std::to_string(index-1)+":p;\n";
         direccion=direccion+"node"+std::to_string(index)+":p -> node"+std::to_string(1)+":n;\n" ;
         }else{

         direccion=direccion+"node" + std::to_string(index)+":n -> node"+std::to_string(index-1)+":p;\n";
         direccion=direccion+"node"+std::to_string(index)+":p -> node"+std::to_string(index+1)+":n;\n" ;
         }
         index=index+ 1;

         if(node->getNext()==this->first||node->getNext()==0){break;}
         node=node->getNext();

        }

        std::string lineafinal="}\n";
        std::string grafo= linea1+linea2+linea3+linea4+linea5+linea6+nodos+direccion+lineafinal;
        return grafo;

}


void circular::generar_txt(){
std::string texto= grafic();
std::ofstream archivo;
archivo.open("circular.txt", std::ios:: out);

archivo<<texto;
archivo.close();

        std::string sentencia="dot -Tpng circular.txt -o circular.png";
        std::string sentencia2="start circular.png";
        std::string salir="EXIT";
        system(sentencia.c_str());
        system(sentencia2.c_str());
        system(salir.c_str());


};



#endif // CIRCULAR_H_INCLUDED
