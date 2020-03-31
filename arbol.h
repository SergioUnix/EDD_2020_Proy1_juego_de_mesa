#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "listasimple.h"  ////se instancio esta lista para enviar una lista de usuario para luego graficarlos, en recorridos esta
#include <dirent.h>
#include <experimental/optional>
#include "bs_tree_node.h"

template <class T>
class BSTree {
private:
	BSTreeNode<T>* root;

	BSTreeNode<T>* insert_node(BSTreeNode<T>* node, const T& key);
	void traverse_nodes_in_order(BSTreeNode<T>* node);
	void traverse_nodes_Pre_order(BSTreeNode<T>* node);
	void traverse_nodes_Post_order(BSTreeNode<T>* node);
	void recorrido_grap(BSTreeNode<T>* node,std::string lado, std::string padre);
	void ListaImprimir(BSTreeNode<T>* node);

	BSTreeNode<T>* search_node(BSTreeNode<T>* node, const T& key);

public:




	void insert(const T& key);
	void traverse_in_order();
	void traverse_Pre_order();
	void traverse_Post_order();
	void ListaUsuarios();
	void In();
	~BSTree();

	void Pre();
	void Post();

	std::string  grafic();
	void generar_txt();

	bool search(const T& key);
	std::string grafic_codigo();


	std::string grafico="";
    std::string direcciones="";
    std::string  texto="";
    Lista* InOrder= new Lista();
    Lista* PreOrder= new Lista();
    Lista* PostOrder= new Lista();


};


template<class T>
BSTree<T>::~BSTree(){
}





template<class T>
BSTreeNode<T> * BSTree<T>::insert_node(BSTreeNode<T>* node, const T& key) {
	if (node == nullptr)
	{
		node = new BSTreeNode<T>{};
		node->key = key;
		node->left = nullptr;
		node->right = nullptr;
		node->parent = nullptr;
	}
	else if (node->key < key)
	{
		node->right = insert_node(node->right, key);
		node->right->parent = node;
	}
	else
	{
		node->left = insert_node(node->left, key);
		node->left->parent = node;
	}

	return node;
}

template<class T>
void BSTree<T>::insert(const T& key) {
	root = insert_node(root, key);
}
//////////////////////////   Lista Para seleccionar Jugador
template<class T>
void BSTree<T>::ListaImprimir(BSTreeNode<T>* node) {
	if (!node) {
		return;
	}

	ListaImprimir(node->left);
	std::cout <<"--"<< node->key << "\n";
	ListaImprimir(node->right);
}

template<class T>
void BSTree<T>::ListaUsuarios() {
	ListaImprimir(root);
	std::cout << std::endl;
}













//////////////////////////InOrder
template<class T>
void BSTree<T>::traverse_nodes_in_order(BSTreeNode<T>* node) {
	if (!node) {
		return;
	}

	traverse_nodes_in_order(node->left);
	std::cout << node->key << " ";          InOrder->add_last(node->key);
	traverse_nodes_in_order(node->right);
}

template<class T>
void BSTree<T>::traverse_in_order() {
	traverse_nodes_in_order(root);
	std::cout << std::endl;
}
template<class T>
void BSTree<T>::In() {InOrder= new Lista(); traverse_in_order(); this->InOrder->generar_txt();  }


//////////////////////////PreOrder
template<class T>
void BSTree<T>::traverse_nodes_Pre_order(BSTreeNode<T>* node) {
	if (!node) {
		return;
	}
	std::cout << node->key << " ";       PreOrder->add_last(node->key);
	traverse_nodes_Pre_order(node->left);
	traverse_nodes_Pre_order(node->right);
}

template<class T>
void BSTree<T>::traverse_Pre_order() {
	traverse_nodes_Pre_order(root);
	std::cout << std::endl;
}

template<class T>
void BSTree<T>::Pre() {	PreOrder= new Lista();traverse_Pre_order(); this->PreOrder->generar_txt();  }




//////////////////////////PostOrder
template<class T>
void BSTree<T>::traverse_nodes_Post_order(BSTreeNode<T>* node) {
	if (!node) {
		return;
	}

    traverse_nodes_Post_order(node->left);
	traverse_nodes_Post_order(node->right);
	std::cout << node->key << " ";           PostOrder->add_last(node->key);

}

template<class T>
void BSTree<T>::traverse_Post_order() {
	traverse_nodes_Post_order(root);
	std::cout << std::endl;
}

template<class T>
void BSTree<T>::Post() {PostOrder= new Lista(); traverse_Post_order(); this->PostOrder->generar_txt();  }





template<class T>
BSTreeNode<T>* BSTree<T>::search_node(BSTreeNode<T>* node, const T& key) {
	if (!node) {
		return nullptr;
	}
	else if (node->key == key) {
		return node;
	}
	else if (node->key < key) {
		return search_node(node->right, key);
	}
	else {
		return search_node(node->left, key);
	}
}

template<class T>
bool BSTree<T>::search(const T& key) {
	return search_node(root, key);
}









/////////////////////////   Crear txt de ghrapviz
template<class T>
void BSTree<T>::recorrido_grap(BSTreeNode<T>* node,string lado,string padre) {
	if (!node) {


	return;
	}
    if(lado=="raiz"){direcciones="";  //el if lo que hace es que si esta llenas estas variables me las borre y haga una nueva asignacion, esto es porque c++ guarda su valor aun
	grafico="";}


	recorrido_grap(node->left,"0",node->key); //se va por la Izquierda

	if(lado!="raiz"&& padre!="raiz"){direcciones =direcciones+ padre+":C"+lado+"->"+node->key+"\n";} ////if que guarda las direcciones de los nodos
	grafico=grafico + node->key+ "[ label =\"<C0>|"+node->key+"|<C1>\"]; \n"; // concateno los nodos

	recorrido_grap(node->right,"1",node->key);//Se va por la derecha




}



template<class T>
std::string  BSTree<T>::grafic() {
	recorrido_grap(root,"raiz","raiz");
	string linea1="digraph grafica{ \nrankdir=TB; \nnode [shape = record, style=filled, fillcolor=seashell2]; \n";
	return linea1+grafico+direcciones+"} \n";
	std::cout << std::endl;






}

//comprueba si un directorio existe
bool is_dir(string dir){
DIR* directorio;
if(directorio=opendir(dir.c_str()))
    {closedir(directorio);
    return true;
    }else { return false;}

    }


////metodo pregunta si existe el archivo .txt
bool is_file(string file){
FILE * archivo;
if(archivo=fopen(file.c_str(),"r")){
    fclose(archivo);
    return true;
}else{
return false;
}
}
//metodo que elimina el .txt
void eliminar(string ruta){
string comando;
if(is_dir(ruta))
    {
        comando="rmdir" + ruta+ " /s /q";
        system(comando.c_str());

    }else if(is_file(ruta)){
    comando="del"+ruta;
    }else{ cout <<" el elemento no existe"<<endl;
    }
}


template<class T>
void BSTree<T>::generar_txt() {
texto= grafic();


std::ofstream archivo;
archivo.open("arbol_binario.txt", std::ios:: out);

archivo<<texto;
archivo.close();

        std::string sentencia="dot -Tpng arbol_binario.txt -o arbol_binario.png";
        std::string sentencia2="start arbol_binario.png";
        system(sentencia.c_str());
        system(sentencia2.c_str());



}









#endif // ARBOL_H_INCLUDED
