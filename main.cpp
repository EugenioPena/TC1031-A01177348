#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Heap.h"
using namespace std;

//Struct que almacena los datos de la bitácora, donde cada línea es un logs
struct logs{

  //Los atributos de cada logs
  string mes, dia, sDia, hora, ip, port, razon, sMes;

  //Constructor por parámetros
  logs(string, string, string, string, string);

  //Constructor default
  logs();

  //Convierte el logs a un número dependiendo de la fecha, donde entre más tarde la fecha mayor el número
  int convertir();

  //Imprime el logs en el formato adecuado
  string str();

  //Sobrecarga de operadores para las comparaciones en el ordenamiento
  bool operator>(logs f2){

    bool resp;
    if(ip > f2.ip){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }

  bool operator>=(logs f2){

    bool resp;
    if(ip >= f2.ip){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }


  bool operator<(logs f2){

    bool resp;
    if(ip < f2.ip){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }

  bool operator<=(logs f2){

    bool resp;
    if(ip <= f2.ip){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }

  bool operator==(logs f2){

    bool resp;
    if(ip == f2.ip){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }

};

logs :: logs(string mes, string dia, string hora, string ip, string razon){

  this->mes = mes;
  this->dia = dia;
  this->hora = hora;
  this->razon = razon;

  int pos = ip.find(":");
  string sIp = ip;
  port = sIp.substr(pos + 1);
  this->ip = sIp.substr(0, pos);

}

logs :: logs(){

  mes = "Mes";
  dia = "Dia";
  hora = "Hora";
  ip = "Ip";
  port = "port";
  razon = "Razon";

}

int logs :: convertir(){

  if(mes == "Jan"){

    sMes = "1";

  }

  else if(mes == "Feb"){

    sMes = "2";

  }

  else if(mes == "Mar"){

    sMes = "3";

  }

  else if(mes == "Apr"){

    sMes = "4";

  }

  else if(mes == "May"){

    sMes = "5";

  }

  else if(mes == "Jun"){

    sMes = "6";

  }

  else if(mes == "Jul"){

    sMes = "7";

  }

  else if(mes == "Aug"){

    sMes = "8";

  }

  else if(mes == "Sep"){

    sMes = "9";

  }

  else if(mes == "Oct"){

    sMes = "10";

  }

  else if(mes == "Nov"){

    sMes = "11";

  }

  else if(mes == "Dec"){

    sMes = "12";

  }

  if(dia == "1"){

    sDia = "01";

  }

  else if(dia == "2"){

    sDia = "02";

  }

  else if(dia == "3"){

    sDia = "03";

  }

  else if(dia == "4"){

    sDia = "04";

  }

  else if(dia == "5"){

    sDia = "05";

  }

  else if(dia == "6"){

    sDia = "06";

  }

  else if(dia == "7"){

    sDia = "07";

  }

  else if(dia == "8"){

    sDia = "08";

  }

  else if(dia == "9"){

    sDia = "09";

  }

  else{

    sDia = dia;

  }


  string hr, min, seg;

  hr = hora.substr(0, 2);

  min = hora.substr(3, 2);

  seg = hora.substr(6, 2);

  string total = sMes + sDia + hr + min + seg;

  return stoi(total);

}

string logs :: str(){

  string str = mes + " " + dia + " " + hora + " " + ip + ":" + port + " " + razon;

  return str;

}

struct ips{

  string direccion;
  int cantidad;

  ips(string direccion, int cantidad);

  ips();

  string str();

  bool operator>(ips f2){

    bool resp;
    if(cantidad > f2.cantidad){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }

  bool operator>=(ips f2){

    bool resp;
    if(cantidad >= f2.cantidad){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }


  bool operator<(ips f2){

    bool resp;
    if(cantidad < f2.cantidad){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }

  bool operator<=(ips f2){

    bool resp;
    if(cantidad <= f2.cantidad){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }

  bool operator==(ips f2){

    bool resp;
    if(cantidad == f2.cantidad){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }


};

ips :: ips(string direccion, int cantidad){

  this->direccion = direccion;
  this->cantidad = cantidad;

}

ips :: ips(){

  direccion = "IP";
  cantidad = 0;

}

string ips :: str(){

  string sCantidad = to_string(cantidad);

  string str = "Ip: " + direccion + " Cantidad de veces: " + sCantidad;

  return str;

}





template<class T>
void HeapSort(DoublyLinkedList<T> &list, string order = "ascending"){

  if(!list.isEmpty()){

    Heap<T> heapAux(list);
    list.clear();
    while(!heapAux.isEmpty()){

      T aux = heapAux.remove();

      if(order == "ascending"){

        list.addFirst(aux);

      }else{

        list.addLast(aux);

      }


    }

  }

}

using namespace std;
int main(){

  string line;

  DoublyLinkedList<logs> dataI;

  string sMes, sDia, sHora; 

	ifstream input;

	input.open("bitacora2.txt");

  string mes, dia, hora, ip, mensaje;

  //Lee el archivo y pasa cada línea a un elemento del vector

  while(input >> mes){
    //Se Actualizan Las Variables Del Main
    input >> dia >> hora >> ip;
    getline(input, mensaje);

    logs log(mes, dia, hora, ip, mensaje);
    dataI.addLast(log);

  }

  input.close();

  HeapSort(dataI);

  int seleccion;

  cout << "Ingrese el número 1 para ver la lista ordenada: ";

  cin >> seleccion;

  while(seleccion != 1){

    cout << "Ingrese el número 1 para ver la lista ordenada: ";

    cin >> seleccion;

  }

  cout << "Lista ordenada:" << endl << endl;

  int veces = 0;

  DoublyLinkedList<ips> list;
  
  for(int iN = 0; iN <= dataI.getSize() - 1; iN++){

    cout << dataI.getData(iN).str() << endl;

    veces = veces + 1;

    if(dataI.getData(iN).ip != dataI.getData(iN - 1).ip){

      ips ip(dataI.getData(iN - 1).ip, veces - 1);
      list.addLast(ip);
      veces = 1;

    }

  }

  cout << "Ingrese el número 1 para ver la lista de ips agrupadas: ";

  cin >> seleccion;

  while(seleccion != 1){

    cout << "Ingrese el número 1 para ver la lista de ips agrupadas: ";

    cin >> seleccion;

  }

  cout << endl << "Lista de ips agrupadas: " << endl;

  for(int iN = 0; iN <= list.getSize() - 1; iN++){

    cout << list.getData(iN).str() << endl;

  }

  Heap<ips> heap(list);

  cout << "Ingrese el número 1 para ver las 5 ips más repetidas en orden: ";

  cin >> seleccion;

  while(seleccion != 1){

    cout << "Ingrese el número 1 para ver las 5 ips más repetidas en orden: ";

    cin >> seleccion;

  }

  cout << endl << "Las 5 ips más repetidas en orden son: " << endl << heap.remove().str() << endl << heap.remove().str() << endl << heap.remove().str() << endl << heap.remove().str() << endl << heap.remove().str();


}