#include <iostream>
#include <string>
using namespace std;

class Publicacion{

    protected:
    string editorial;
    string fechaDePublicacion;

    public:
    Publicacion(): editorial("Editorial"), fechaDePublicacion("Fecha"){}
    Publicacion(string editorial, string fechaDePublicacion) : editorial(editorial), fechaDePublicacion(fechaDePublicacion){}
    ~Publicacion(){}
    void setEditorial (string e) { editorial = e;}
    string getEditorial()  { return editorial; }
    virtual void mostrar() = 0; //Funcion virtual pura
}; //Clase publicacion

class Revista : public Publicacion{ //Herencia

    protected:
    string nombre;
    int numeroEjemplar;
    string periodicidad;

    public:
    Revista() : Publicacion("Horizontes Ilimitados", "12 de Febrero de 2007"), nombre("Perspectivas del Siglo"), numeroEjemplar(12), periodicidad("Mensual"){}
    Revista(string editorial, string fechaDePublicacion, string nombre, int numeroEjemplar, string periodicidad): Publicacion(editorial, fechaDePublicacion), nombre(nombre), numeroEjemplar(numeroEjemplar), periodicidad(periodicidad) {}
    ~Revista(){}
    void mostrar() {
        cout << "Fecha de publicacion:  " << fechaDePublicacion << endl;
        cout << "Numero de ejemplar: " << numeroEjemplar << endl;
        cout << "Peridicidad: " << periodicidad << endl;
     }
    
 }; //Clase Revista

class Libro : public Publicacion{ //Herencia

    protected:
    long  long codigoISBN;
    string nombreAutor;
    string titulo;
    public:
    Libro() : Publicacion("Ediciones SM Mexico", "13 de Diciembre de 2023"), codigoISBN(3210987654321), nombreAutor("David Cardona"), titulo("El Eco de las Estrellas Perdidas"){}
    Libro(string editorial, string fechaDePublicacion,long long codigoISBN, string nombreAutor, string titulo): Publicacion(editorial, fechaDePublicacion), codigoISBN(codigoISBN), nombreAutor(nombreAutor), titulo(titulo) {}
    ~Libro(){}
    long long getCodigo()  { return codigoISBN; }
    void mostrar() {
        cout << "Fecha de publicacion: " << fechaDePublicacion << endl;
        cout << "Codigo ISBN: " << codigoISBN << endl; 
        cout << "Autor: " << nombreAutor << endl;
        cout << "Titulo: " << titulo << endl;
    }
 }; //Clase Libro

int main()
{
    Publicacion*p;  
    p = new Revista();
    cout << "\nRevista de la editorial: "<< p->getEditorial()<< endl;
    p->mostrar();

    p = new Libro();
    cout << "\nLibro de la editorial: "<< p->getEditorial()<<  endl;
    p->mostrar();
   
   
    cout<< "\nPara buscar un libro introduzca el codigo ISBN: ";
    long long codigoISBN;
    cin >> codigoISBN;
    Libro* l;
    l = dynamic_cast <Libro *>(p);
 		if(l != NULL && codigoISBN == l->getCodigo()){ 
        cout<< "\nLibro encontrado:" << endl;
        cout << "\nLibro de la editorial: "<< p->getEditorial()<<  endl;
        p->mostrar();
       
    }
    else{
        cout<<"\nLibro no encontrado\n";
    }
   return 0; 
}
 