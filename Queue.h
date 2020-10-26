#ifndef Queue_h
#define Queue_h

#include "Node.h"
using namespace std;

template<class T>
class Queue{

  private:
    Node<T>* f;
    Node<T>* r;

  public:
    Queue();
    void enqueue(T data);
    T dequeue();
    T front();
    void print();



};

//Función que imprime los datos del queue en orden 
template<class T>
void Queue<T> :: print(){

  Node<T>* aux = f;
  
  while(aux != NULL){

    cout << aux->data << endl;;
    aux = aux->next;

  }

}

//Crea un objeto tipo queue con constructor default
template<class T>
Queue<T> :: Queue(){

  f = NULL;
  r = NULL;

}

//Nos retorna el valor f, conocido como front (el valor siguiente o más viejo de la queue)
template<class T>
T Queue<T> :: front(){

  return f->data;

}

//Agrega un valor en el rear de la lista (Después del dato agregado más recientemente)
template<class T>
void Queue<T> :: enqueue(T data){

  Node<T>* aux = new Node(data);

  if(f == NULL && r == NULL){

    f = r = aux;

  }

  else{

    r->next = aux;
    aux->prev = r;
    r = aux;
    r->next = NULL;

    

  }

}

//Elimina el valor más antiguo de la lista y retorna su valor
template<class T>
T Queue<T> :: dequeue(){

  if(f == NULL && r == NULL){

    throw("List is empty");

  }

  else if(f == r){

    T aux;

    aux = f->data;
    f = r = NULL;
    return aux;

  }

  else{

    T aux;
    Node<T>* aux2 = f;

    aux = aux2->data;

    f = aux2->next;
    delete aux2;
    return aux;


  }

}

#endif