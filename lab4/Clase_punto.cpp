#include <iostream>

/*1. Implemente una clase Punto, la cual representa un punto en el plano cartesiano.
• La clase deberá tener dos variables enteras privadas, “x” y “y”
• Implementar un constructor por defector, el cual inicializará las variables en 0.
• Implementar un contructor que reciba dos argumentos enteros e inicialice las variables miembro con dichos
argumentos.

• Implementar las siguientes funciones:

– Función para obtener “x”: int Punto::getX() const
– Función para obtener “y”: int Punto::getY() const
– Función para modificar “x”: void Punto::setX(const int nuevo_x)
– Función para modificar “y”: void Punto::setY(const int nuevo_y)
2. Implementa la clase ArregloDePuntos la cual representará un arreglo dinámico de Punto. Este arreglo debe
redimensionar dinámicamente su tamaño.
• La clase debe tener como varibles miembro privadas: un puntero de tipo Punto y un entero para el tamaño del
arreglo.
• Contructores

*/

using namespace std;

class Punto{
private:
    int x;
	int y;
public:
    Punto();
    int getX() const;
    int getY() const;
    void setX(const int nuevo_x);
    void setY(const int nuevo_y);
};


Punto::Punto()
{
    x=0;
    y=0;
}
int Punto::getX() const
{
    return x;
}

int Punto::getY() const
{
    return y;
}

void Punto::setX(const int nuevo_x)
{
    x=nuevo_x;
}

void Punto::setY(const int nuevo_y)
{
    y=nuevo_y;
}

int main()
{
    return 0;
}
