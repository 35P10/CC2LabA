#include <iostream>

using namespace std;


class myClass
{
private:
    int *ptr;
    int length;

public:

myClass()
{
    ptr = new int (5);
    length = 6;
}

myClass(int new_ptr,int new_length)
{
    ptr = new int (new_ptr);
    length = new_length;
}

//ConstructorDeMovimiento
myClass(myClass&& other)
{
   this->length = other.length;
   this->ptr = other.ptr;
   other.length = 0;
   other.ptr = nullptr;
}


///ConstructorDeMovimientoUsandoStd::move
/*
   myClass(myClass&& other) {
      ptr = other.ptr;
      other.ptr = nullptr;
      length = std::move(other.length);
   }
*/

//OperadorDeAsignacionDeMovimientoUsandoStd::move
   myClass& operator=(myClass&& other) {
      if(this != &other) {
         if(ptr) {
            delete ptr;
         }
         ptr = other.ptr;
         other.ptr = nullptr;

         length = std::move(other.length);
      }
   }

///OperadorDeAsignacionDeMovimiento
/*
   myClass& operator=(myClass&& other) {
      if(this != &other) {
         if(ptr) {
            delete ptr;
         }
         ptr = other.ptr;
         other.ptr = nullptr;

         length = other.length;
         other.length = 0;

      }
   }
*/

   ~myClass(){
      if(ptr) {
          delete ptr;
       }
   }

   void printClass()
{
    if (ptr)
    cout<<"Ptr: "<<*ptr<<endl;
    else
    cout<<"Ptr: NULL"<<endl;
    cout<<"length: "<<length<<endl;
}


};

int main()
{
    cout<<"Usando std::move y constructor De Movimiento"<<endl;
    myClass A((myClass()));
    cout<<"MyClass A: "<<endl;A.printClass();
    cout<<"Se moverá el contenido a A a B"<<endl;
    myClass B = std::move(A);
    cout<<"MyClass B: "<<endl;B.printClass();
    cout<<"MyClass A: "<<endl;A.printClass();

    cout<<"Usando operadordeasignacion"<<endl;
    myClass C = myClass(10,9);
    cout<<"MyClass C: "<<endl;C.printClass();

return 0;
}
