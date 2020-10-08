#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "DoublyLinkedList.h"
using namespace std;


//Struct que almacena los datos de la bitácora, donde cada línea es un logs
struct logs{

  //Los atributos de cada logs
  string mes, dia, sDia, hora, ip, razon, sMes;

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
    if(convertir() > f2.convertir()){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }

  bool operator>=(logs f2){

    bool resp;
    if(convertir() >= f2.convertir()){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }


  bool operator<(logs f2){

    bool resp;
    if(convertir() < f2.convertir()){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }

  bool operator<=(logs f2){

    bool resp;
    if(convertir() <= f2.convertir()){

      resp = true;

    }

    else{

      resp = false;

    }

    return resp;

  }

  bool operator==(logs f2){

    bool resp;
    if(convertir() == f2.convertir()){

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
  this->ip = ip;
  this->razon = razon;

}

logs :: logs(){

  mes = "Mes";
  dia = "Dia";
  hora = "Hora";
  ip = "Ip";
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

  string str = mes + " " + dia + " " + hora + " " + ip + " " + razon;

  return str;

}

//Función que recibe la lista y el dato inicial a buscar, y lo compara uno por uno de izquierda a derecha para encontrar uno que sea mayor. Retorna la posición del valor inicial del vector para comenzar a desplegar en el rango.
template <class T>
int busquedaSecuencialPrimero(DoublyLinkedList<T> lista, T data){

  int pos;

  for(int i = 0; i < lista.getSize(); i++){

    if(lista.getData(i) > data){

      return i;

    }

  }

  throw runtime_error("El dato no se encuentra");

}

template <class T>
int busquedaSecuencialUltimo(DoublyLinkedList<T> lista, T data){

  int pos;

  for(int i = lista.getSize() - 1; i > 0; i--){

    if(lista.getData(i) < data){

      return i;

    }

  }

  throw runtime_error("El dato no se encuentra");

}

//Función que imprime vectores
template <class T>
void imprimir(vector<T> lista){

  for(int i = 0; i < lista.getSize(); i++){

    cout << lista[i] << endl;

  }

}

//Busqueda binaria intento (no pude pero casi)
/*int getClosest1(vector<logs> &lista, int primero, int segundo, logs data){ 

  if (data.convertir() - lista[primero].convertir() >= lista[segundo].convertir() - data.convertir()){ 

    return segundo; 

  }

  else{

    return primero;  

  }

} 

int busquedaBinaria1(vector<logs> &lista, int n, logs data){

  if (data <= lista[0]){

    return 0; 

  }

  if (data >= lista[n - 1]){

    return n - 1;

  }

  int min = 0, max = n, mid = 0;

  while (min < max){ 

    mid = (min + max) / 2; 

    if (lista[mid] == data){

      return mid; 

    }

    if (data < lista[mid]){ 

      if (mid > 0 && data > lista[mid - 1]){

        return getClosest1(lista, mid - 1, mid, data);

      } 

      max = mid; 

    } 

    else { 

      if (mid < n - 1 && data < lista[mid + 1]) {

        return getClosest1(lista, mid, mid + 1, data);

      }

      min = mid + 1;  

    } 

  } 
 

} 

*/

int main() {

  string line;

  DoublyLinkedList<logs> dataI;

  string sMes, sDia, sHora; 

  int inferior, superior;
  
	ifstream input;

	input.open("bitacora.txt");
  string mes, dia, hora, ip, mensaje;
  int pos1, pos2;

  //Lee el archivo y pasa cada línea a un elemento del vector

  while(input >> mes){
    //Se Actualizan Las Variables Del Main
    input >> dia >> hora >> ip;
    getline(input, mensaje);

    logs log(mes, dia, hora, ip, mensaje);
    dataI.addLast(log);

  }

  input.close();

  inferior = 0;

  superior = dataI.getSize() - 1;

  dataI.sort();

  cout << "Lista ordenada:" << endl << endl;

  ofstream output;

  output.open("bitacoraOrdenada.txt");

  //Se pasa la nueva bitacora ordenada al archivo bitacoraOrdenada.txt
  
  for(int iN = 0; iN <= dataI.getSize() - 1; iN ++){

    output << dataI.getData(iN).str() << endl;

    cout << dataI.getData(iN).str() << endl;

  }

  output.close();

  cout << endl << "Búsqueda primer dato" << endl << endl;

  cout << "Ingrese el mes en número (1 - 12): ";

  cin >> sMes;

  if(sMes == "1"){

    sMes = "Jan";

  }

  else if(sMes == "2"){

    sMes = "Feb";

  }

  else if(sMes == "3"){

    sMes = "Mar";

  }

  else if(sMes == "4"){

    sMes = "Apr";

  }

  else if(sMes == "5"){

    sMes = "May";

  }

  else if(sMes == "6"){

    sMes = "Jun";

  }

  else if(sMes == "7"){

    sMes = "Jul";

  }

  else if(sMes == "8"){

    sMes = "Aug";

  }

  else if(sMes == "9"){

    sMes = "Sep";

  }

  else if(sMes == "10"){

    sMes = "Oct";

  }

  else if(sMes == "11"){

    sMes = "Nov";

  }

  else if(sMes == "12"){

    sMes = "Dec";

  }

  cout << "Ingrese el número del día: ";

  cin >> sDia;

  cout << "Ingrese la hora en formato 00:00:00: ";

  cin >> sHora;

  logs primer;

  primer.mes = sMes;
  primer.dia = sDia;
  primer.hora = sHora;

  
  pos1 = busquedaSecuencialPrimero(dataI, primer);
  
  cout << endl << "Búsqueda segundo dato" << endl << endl;

  cout << "Ingrese el mes en número (1 - 12): ";


  cin >> sMes;

  if(sMes == "1"){

    sMes = "Jan";

  }

  else if(sMes == "2"){

    sMes = "Feb";

  }

  else if(sMes == "3"){

    sMes = "Mar";

  }

  else if(sMes == "4"){

    sMes = "Apr";

  }

  else if(sMes == "5"){

    sMes = "May";

  }

  else if(sMes == "6"){

    sMes = "Jun";

  }

  else if(sMes == "7"){

    sMes = "Jul";

  }

  else if(sMes == "8"){

    sMes = "Aug";

  }

  else if(sMes == "9"){

    sMes = "Sep";

  }

  else if(sMes == "10"){

    sMes = "Oct";

  }

  else if(sMes == "11"){

    sMes = "Nov";

  }

  else if(sMes == "12"){

    sMes = "Dec";

  }

  cout << "Ingrese el número del día: ";

  cin >> sDia;

  cout << "Ingrese la hora en formato 00:00:00: ";

  cin >> sHora;

  logs ultimo;

  ultimo.mes = sMes;
  ultimo.dia = sDia;
  ultimo.hora = sHora;

  pos2 = busquedaSecuencialUltimo(dataI, ultimo);

  cout << endl;

  for(int iN = pos1; iN <= pos2; iN ++){

    cout << dataI.getData(iN).str() << endl;

  }
  

  return 0;

}