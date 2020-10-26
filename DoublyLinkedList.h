#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "Node.h"
#include "Queue.h"
using namespace std;

template<class T>
class DoublyLinkedList{

  private:

    Node<T>* head;
    Node<T>* tail;
    int size;
    void mergeSort(int first, int last);
    void merge(int first, int mid, int last);

  public:

    void operator=(initializer_list<T> list);
    void operator=(DoublyLinkedList<T> list);
    T& operator[](int index);
    DoublyLinkedList();
    void addFirst(T data);
    void addLast(T data);
    bool isEmpty();
    void print();
    void sort();
    T getData(int pos);
    void updateAt(int pos, T newData);
    int getSize();
    void clear();
    void deleteLast();
    

};

template<class T>
void DoublyLinkedList<T>::clear() {
    int i = 1;
    while (i<=size) {
        Node<T>* aux = head;
        head = aux->next;
        delete aux;
        i++;
    }
    size = 0;
    tail = NULL;
}


template<class T>
T& DoublyLinkedList<T>::operator[](int index) {
    if (index >= 1 && index <= size) {
        if (index <= size / 2) {
            Node<T>* aux = head;
            int i = 1; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->next;
                i++;
            }
        } else {
            Node<T>* aux = tail;
            int i = size; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->prev;
                i--;
            }
        }
    }
    throw out_of_range("Invalid position");
}

template<class T>
void DoublyLinkedList<T>::operator=(initializer_list<T> list) {
    if (isEmpty()) {
        for (T i : list) {
            addLast(i);
        }
    } else {
        throw runtime_error("Error: DoublyLinkedList no esta vacia");
    }
}

template<class T>
void DoublyLinkedList<T>::deleteLast(){
  if (!isEmpty()){
    Node<T>* aux = tail;
    tail = tail->prev;
    if (tail == NULL){ //if the list is emptied
        head = NULL;
    }
    delete aux;
    size--;
  }
}

template<class T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> list) {
    clear();
    for (int i=1; i<=list.size; i++) {
        addLast(list[i]);
    }
}

//Retorna el tamaño de la lista
template<class T>
int DoublyLinkedList<T> :: getSize(){

  return size;

}

//Actualiza un valor por posición en la lista
template<class T>
void DoublyLinkedList<T> :: updateAt(int pos, T newData){

  if(!isEmpty() && pos <= size){

    Node<T>* aux;

    if(pos == 0){

      head->data = newData;
      return;

    }

    else if(pos == size - 1){

      tail->data = newData;
      return;

    }

    else{

      if(pos < size / 2){

        aux = head;

        for(int iC = 0; iC < pos; iC++){

          aux = aux->next;

        }

      }

      else{

        aux = tail;

        for(int iC = size - 1; iC > pos; iC--){

          aux = aux->prev;

        }

      }

      aux->data = newData;

    }

  }

  //No se cumplen los criterios y retorna falso.
  else{

    cout << "Opción inválida" << endl;
    return;

  }

}

//Constructor por default
template<class T>
DoublyLinkedList<T> :: DoublyLinkedList(){

  head = NULL;
  tail = NULL;
  size = 0;

}

//Agrega un valor al final de la lista
template<class T>
void DoublyLinkedList<T> :: addLast(T data){

  Node<T>* aux = new Node(data);

  if(head == NULL){

    head = tail = aux;
    head->prev = NULL;
    tail->next = NULL;
    size = size + 1;

  } 
  
  else{

    tail->next = aux;
    aux->prev = tail;
    tail = aux;
    tail->next = NULL;
    size = size + 1;
  
  }

}

//Agrega un valor al inicio de la lista
template<class T>
void DoublyLinkedList<T> :: addFirst(T data){

  Node<T>* aux = new Node(data);

  if(head == NULL){

    head = tail = aux;
    size = size + 1;

  } 
  
  else{

    aux->next = head;
    aux->prev = NULL;
    head->prev = aux;
    head = aux;
    size = size + 1;
  
  }

}

//Comprueba si la lista está vacía
template<class T>
bool DoublyLinkedList<T> :: isEmpty(){

  return size == 0;

}

//Imprime los valores de la lista
template<class T>
void DoublyLinkedList<T> :: print(){

  Node<T>* aux = head;
  if(isEmpty()) {
      
    cout << "La lista está vacía" << endl;

    return;

  }

  while(aux != NULL){

    cout << aux->data << endl;;
    aux = aux->next;

  }
  
}

//Método merge del mergesort
template<class T>
void DoublyLinkedList<T> :: merge(int first, int mid, int last){

  Queue<T> listL;
  Queue<T> listR;
  int pos, f1, f2, i, j;
  pos = first;
  f1 = mid - first + 1;
  f2 = last - mid;

  for(i = 0; i < f1; i++) {

    listL.enqueue(getData(first + i));

  } 
  for(j = 0; j < f2; j++) {

    listR.enqueue(getData(mid + 1 + j));

  } 

  i = 0;
  j = 0;

  while(i < f1 && j< f2) {

    if(listL.front() < listR.front()){

      updateAt(pos, listL.dequeue());
      i = i + 1;

    } 
    
    else{

      updateAt(pos, listR.dequeue());
      j = j + 1;

    }

    pos = pos + 1;

  }

  while(i < f1){

    updateAt(pos, listL.dequeue());
    i = i + 1;
    pos = pos + 1;

  }

  while(j < f2){

    updateAt(pos, listR.dequeue());
    j = j + 1;
    pos = pos + 1;

  }

}

//Método recursivo para hacer sort
//Complejidad de O(n * log n) 
template<class T>
void DoublyLinkedList<T> :: mergeSort(int first, int last){

  if(first < last){

    int mid = (first + last) / 2;
    mergeSort(first, mid);
    mergeSort(mid + 1, last);

    merge(first, mid, last);

  }

}

template<class T>
void DoublyLinkedList<T> :: sort(){

  mergeSort(0, size - 1);

}

//Retorna el dato en cierta posición
template<class T>
T DoublyLinkedList<T> :: getData(int pos){

  if(!isEmpty() && pos <= size){

    Node<T>* aux = head;

    if(pos == 0){

      return head->data;

    }

    else if(pos == size - 1){

      return tail->data;

    }

    else{

      Node<T>*aux;

      if(pos < size / 2){

        aux = head;

        for(int iC = 0; iC < pos; iC++){

          aux = aux->next;

        }

      }

      else{

        aux = tail;

        for(int iC = size - 1; iC > pos; iC--){

          aux = aux->prev;

        }

      }

      return aux->data;

    }

  }

  //No se cumplen los criterios y retorna falso.
  else{

    throw runtime_error("Posición inválida");

  }

}

#endif
