#include <string>
#include <iostream>
#include <fstream>
#include <vector>
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
int busquedaSecuencialPrimero(vector<T> lista, T data){

  int pos;

  for(int i = 0; i < lista.size(); i++){

    if(lista[i] > data){

      return i;

    }

  }

  throw runtime_error("El dato no se encuentra");

}

//Función que recibe la lista y el dato final a buscar, y lo compara uno por uno de derecha a izquierda para encontrar uno que sea menor. Retorna la posición del valor final del vector para comenzar a desplegar en el rango.
template <class T>
int busquedaSecuencialUltimo(vector<T> lista, T data){

  int pos;

  for(int i = lista.size() - 1; i > 0; i--){

    if(lista[i] < data){

      return i;

    }

  }

  throw runtime_error("El dato no se encuentra");

}

//Función que imprime vectores
template <class T>
void imprimir(vector<T> lista){

  for(int i = 0; i < lista.size(); i++){

    cout << lista[i] << endl;

  }

}

template<class T>
void merge(vector<T> &lista, int inicio, int medio, int fin){

  int size1 = medio - inicio + 1;

  int size2 = fin - medio;

  vector<T> A;
  vector<T> B;

  for(int iN = 0; iN < size1; iN++){

    A.push_back(lista[iN + inicio]); 

  }

  for(int iC = 0; iC < size2; iC++){

    B.push_back(lista[iC + medio + 1]); 
        
  }

  int iN = 0;
  int iC = 0;
  int iK = inicio;


  while(iN < size1 && iC < size2){ 

    if(A[iN] < B[iC]) { 

      lista[iK] = A[iN]; 
      iN++; 

    } 

    else { 

      lista[iK] = B[iC]; 
      iC++; 

    } 

    iK++; 

  }

  while(iN < size1) { 

    lista[iK] = A[iN]; 
    iN++; 
    iK++; 

  } 

  while(iC < size2) { 

    lista[iK] = B[iC]; 
    iC++; 
    iK++; 

  } 
 
}

//Complejidad de O(n * log n) 
template<class T>
vector<T> mergeSort(vector<T> &lista, int inicio, int fin){


  if(inicio < fin){

    int medio = (fin + inicio) / 2;

    mergeSort(lista, inicio, medio);

    mergeSort(lista, medio + 1, fin);

    merge(lista, inicio, medio, fin);

  }

  return lista;

}


int main() {

  string line;

  vector<logs> dataI;

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
    dataI.push_back(log);

  }

  input.close();

  inferior = 0;

  superior = dataI.size() - 1;

  dataI = mergeSort(dataI, inferior, superior);

  cout << "Lista ordenada:" << endl << endl;

  ofstream output;

  output.open("bitacoraOrdenada.txt");

  //Se pasa la nueva bitacora ordenada al archivo bitacoraOrdenada.txt
  for(int iN = 0; iN <= dataI.size() - 1; iN ++){

    output << dataI[iN].str() << endl;

    cout << dataI[iN].str() << endl;

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

    cout << dataI[iN].str() << endl;

  }

  return 0;

}