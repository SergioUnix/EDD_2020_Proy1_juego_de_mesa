#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include<string.h>
#include<fstream>


class ListaDoble
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
         ListaDoble()
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
         void removeC(std::string cadena);

         std::string cantidad_artistas();
         std::string grafic();
         void generar_txt();
         std::string get_element_at(int index);

         std::string lista_imprimir();
         bool existC(std::string a);





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


void ListaDoble::add_ordenado(std::string dato)
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
                if(this->comparar(aux->getDato(),n->getDato())>0){
                //std::cout<<"comparo  ----------------------------------- "<<this->comparar(aux->getDato(),n->getDato())<<"---"<<aux->getDato()<<"--"<<n->getDato()<<this->getSize()<<std::endl;
                //std::cout<<"comparo  ----------------------------------- "<<aux->getDato()<<std::endl;

                bandera=true;
                break;
                }
                if(aux->getNext()==0){break;}
               aux=aux->getNext();


        }

        if(aux==this->first&&bandera==true&&this->getSize()==1){
        n->setNext(this->first);
        this->first->setBefore(n);
        this->first = n;
        this->size++;


        }else if(aux==this->last&&bandera==false&&this->getSize()==1){
        this->last->setNext(n);
        n->setBefore(this->last);
        this->last = n;
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
        this->size++;

        }else if(aux==this->first&&bandera==true&&this->getSize()>1){

        n->setNext(this->first);
        this->first->setBefore(n);
        this->first = n;
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

void ListaDoble::add_first(std::string dato)
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
        this->size++;
    }
}

void ListaDoble::add_last(std::string dato)
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
        this->size++;
    }
}

void ListaDoble::add_at(std::string dato, int index)
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

std::string ListaDoble::get_element_at(int index)
{
    if(index >= 0 && index < size)
    {
        Nodo *iterador = this->first;
        int x = 0;
        while(iterador!=0)
        {
            if(index == x){return iterador->getDato();}
            iterador = iterador->getNext();
            x++;
        }
    }
    return "";
}





std::string ListaDoble::lista_imprimir()
{
   std::string result="";
        Nodo *iterador = this->first;
        int x = 0;
        while(iterador!=0)
        {
            result =result+ iterador->getDato()+" --";
            iterador = iterador->getNext();
            x++;
        }

    return result;
}

bool ListaDoble::existC(std::string a){
        bool result=false;
        Nodo *auxiliar = this->first;
        int x = 0;
        while(auxiliar!=0)
        {
            if(a==auxiliar->getDato()){  result=true;   }

            auxiliar = auxiliar->getNext();
            x++;
        }

    return result;
}












std::string ListaDoble::cantidad_artistas()
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





void ListaDoble::remove_at(int index)
{
        if(index >= 0 && index < this->size)
    {
        if(index == 0){Nodo *aux = this->first->getNext();  aux->setBefore(0); this->first =aux;       this->size--;    return;}
        if(index == this->size-1) {Nodo *aux = this->last->getBefore();  aux->setNext(0); this->last=aux;       this->size--;             return;}
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




////REmover atravez de un string dado
void ListaDoble::removeC(std::string cadena)
{

        Nodo *iterador = this->first;
        int x = 0;
        while(iterador!=0)
        {
            if(iterador->getDato() == cadena){remove_at(x); break;}

            iterador = iterador->getNext();
            x++;
        }


}













std::string ListaDoble::grafic()
{
        std::string linea1="digraph G {\n";
       std:: string linea2="nodesep=.02;\n";
        std::string linea3="rankdir=LR;\n";
        std::string linea4="node [shape=record,width=.1,height=.1];\n";
        std::string linea5="node [width =0.5 height=0.3];\n";
        std::string linea6="node0[label = \"{null |<p>}\"   width = 1.5 style = filled, fillcolor = turquoise3         ];\n";

        Nodo *node = this->first;
        //node =self.head
        int index=1;
        std::string nodos="";
        std::string direccion="";

        while(node!=0){
         nodos=nodos+ "node"+std::to_string(index) +"[label = \"{<n> |" + node->getDato() +"| <p> }\"  width = 1.5 style = filled, fillcolor = turquoise3     ];\n";
         direccion=direccion+"node" + std::to_string(index)+":n -> node"+std::to_string(index-1)+":p;\n";
         direccion=direccion+"node"+std::to_string(index)+":p -> node"+std::to_string(index+1)+":n;\n" ;
         index=index+ 1;
         node=node->getNext();
        }
        nodos =nodos+"node"+std::to_string(index) + "[label = \"{<n> null }\"  width = 1.5 style = filled, fillcolor = turquoise3   ];\n";
        std::string lineafinal="}\n";
        direccion="node0 ->node1:n;\n"+direccion;
        std::string grafo= linea1+linea2+linea3+linea4+linea5+linea6+nodos+direccion+lineafinal;
        return grafo;

}


void ListaDoble::generar_txt(){
std::string texto= grafic();
std::ofstream archivo;
archivo.open("listaDoble.txt", std::ios:: out);

archivo<<texto;
archivo.close();

        std::string sentencia="dot -Tpng listaDoble.txt -o listaDoble.png";
        std::string sentencia2="start listaDoble.png";
        std::string salir="EXIT";
        system(sentencia.c_str());
        system(sentencia2.c_str());
        system(salir.c_str());


};






#endif // LISTADOBLE_H_INCLUDED
