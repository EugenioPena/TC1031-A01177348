#pragma once

#include <iostream>
using namespace std;
#include <string>

template<class T>
struct Node{

  T data; //Default será Nulo
  Node<T>* prev;//Default será Nulo
  Node<T>* next;//Default será Nulo

  Node();
  Node(T data);
  Node(T data, Node<T>* prev, Node<T>* next);
  
};


template<class T>
Node<T> :: Node(){

  data = NULL;
  next = NULL;
  prev = NULL;

}

template<class T>
Node<T> :: Node(T data){

  this->data = data;
  next = NULL;
  prev = NULL;

}

template<class T>
Node<T> :: Node(T data, Node<T>* prev, Node<T>* next){

  this->data = data;
  this->next = next;
  this->prev = prev;

}