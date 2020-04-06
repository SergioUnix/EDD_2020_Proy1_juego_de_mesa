#ifndef MAIN_AUXILIAR_H_INCLUDED
#define MAIN_AUXILIAR_H_INCLUDED


 cout<<" /////////////////////  datos de la cola " <<endl;
 Cola *prueba= new Cola();
 prueba->elementos_default();
 cout<<" boolean de la cola " << true<<endl;
 prueba->imprimir();
 prueba->generar_txt();

  cout<<" /////////////////////  datos del arbol binario" <<endl<<endl;

auto trees = new BSTree<std::string>{};
	trees->insert("zorro");
	trees->insert("Ariel");
	trees->insert("Madelyn");
	trees->insert("Juan");
   // trees->generar_txt();  //creo archivo txt y genero la imagen del ABB
	//trees->Pre();  //crea el recorrido y lo muestra en ghrapviz
	//trees->In();   //crea el recorrido y lo muestra en ghrapviz
	//trees->Post(); //crea el recorrido y lo muestra en ghrapviz

    std::cout << "Element Ariel: " << trees->search("Ariel") << std::endl; //si encuentra el nombre devuelve TRUE y lo muestra como 1
	std::cout << "Element 111: " << trees->search("Perez")<< std::endl ;   //si No encuentra el nombre devuelve FALSE y lo muestra como 0
	//cout<<trees->grafic()<<endl<<endl<<endl;
	//cout<<trees->grafic()<<endl<<endl<<endl;




cout<<" /////////////////////  prueba de lista circular  " <<endl<<endl;

circular *diccionario= new circular();
diccionario->add_ordenado("Usuario6");
diccionario->add_ordenado("Usuario9");
diccionario->add_ordenado("Usuario1");
diccionario->add_ordenado("Usuario2");
diccionario->add_ordenado("Usuario3");

cout<< diccionario->get_element_at(0) << diccionario->get_element_at(1)<< diccionario->get_element_at(2)<< diccionario->get_element_at(3)<<diccionario->get_element_at(4)<<endl<<endl;
cout<< diccionario->get_element_at(-12)<<endl; //como es circular entra a la lista



cout<<" /////////////////////  prueba de lista Simple ordenada " <<endl<<endl;
Lista *lista= new Lista();
lista->add_ordenado("Heidy");
lista->add_ordenado("Carlos");
lista->add_ordenado("Antonio");
lista->add_ordenado("Eduardo");
lista->add_ordenado("Rodrigo");
//lista->generar_txt();  //genero txxt y muestro imagen en ghrapviz

cout<<"1. Lista Doblemente Enlazada Fichas del jugador "<<endl;
ListaDoble *dic= new ListaDoble();
dic->add_first("Arturo");
dic->add_first("Jose");
dic->add_first("Manuel");
cout<<dic->lista_imprimir()<<endl;
cout<<dic->getSize()<<endl;



Cubo <string> *cpu= new Cubo<string>();
cpu->insertar_elemento(20,8,"C","Jugador1");
cpu->insertar_elemento(3,7,"P","jugador2");
cpu->insertar_elemento(1,5,"S","jugador2");
cpu->insertar_elemento(2,6,"U","jugador1");
cpu->generar_txt();





ListaDoble *dic= new ListaDoble();
dic->add_ordenado("Arturo");
dic->add_ordenado("Jose");
dic->add_ordenado("Manuel");
cout<<dic->lista_imprimir()<<"   "<<dic->getSize()<<endl;
cout<<"-----------------------"<<endl;
dic->remove_at(0);
cout<<dic->lista_imprimir()<<" despues de eliminar el primer elemento  "<<dic->getSize()<<endl;
dic->remove_at(0);
cout<<dic->lista_imprimir()<<" despues de eliminar el segundo elemento   "<<dic->getSize()<<endl;
dic->remove_at(0);
 system("pause");




#endif // MAIN_AUXILIAR_H_INCLUDED
