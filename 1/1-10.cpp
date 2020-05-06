#include <iostream>
#include <math.h>
using namespace std;

//ejercicio1:
//Encuentra la suma de todos los múltiplos de 3 o 5 por debajo de 1000.
//Answer: 233168

int suma_de_multiplos_de_3_o_5(int x)
{
    int Suma=0;
    for (int i=0; i<x; i++)
    {
        if (i%3==0)                 //todos los numeros multiplos de 3 se suman
            Suma += i;
        if ((i%5==0)&&(i%3!=0))      //los multiplos de 5 pero no de 3 se suman
            Suma += i;
    }
    return Suma;
}

//ejercicio2:
//Al considerar los términos en la secuencia de Fibonacci cuyos valores
//no exceden los cuatro millones, encuentre la suma de los términos de valor par.
//Answer: 4613732

int suma_par_fibonnaci(int x)
{
    int Suma=0;
    int a=1, b=2, c=3;
    while (a<=x)
    {
        c=a+b;
        a=b;
        b=c;
        if (a%2==0)
            Suma += a;
    }
    return Suma;
}

//ejercicio3:
//¿Cual es el factor primo mas grande del número 600851475143?
//Answer: 6857
int es_primo(long long int x) //esta funcion se usara mas adelante
{
    if ((x==1))
        return 0;
    if ((x==2))
        return 1;
    for (int i=2; i<x; i++) //recorre los numeros que estan entre 1 y el mismo. 1<i<x
    {                       //si encuentra que uno es divisible entre el numero
        if (x%i==0)         //retorna 0 (no es primo), si supera el for retorna 1 (es primo)
            return 0;
    }
    return 1;
}

long long int mayor_factor_primo(long long int x)
{
    int max_primo=0; //se divide la busqueda en dos (inferior y superior), donde el numero de division es la raiz cuadrada de x
    for(long long int i=2 ; i<sqrt(x) ; i++) //i va esta la raiz cuadrada (recorre toda la parte inferior
    {
        if ((x%i)==0)   //si i es dividor de x entonces:
        {                //se divide a x/i para saber su otro dividor (que se encuentra en la parte superior
            if (es_primo(x/i)==1)  //si este otro divisor es primo
                return i;           //retorna como mayor primo
            else if(es_primo(i)==1) //si no, se verifica que la i sea primo y lo almacena
                 max_primo=i;       //como max_primo, en caso que el numero mayor primo este en la parte inferior
        }
    }
    return max_primo; //si no se encontro el mayor primo en la parte superior
}



//ejercicio4:
//Encuentra el palindromo más grande hecho del producto de dos números de 3 dígitos.
//Answer: 906609

int inverse (int x)     //el numero es ¿invertido? 789->987
{
    int inv=0, n;
    while(x!=0)
    {
     n=x%10;
     inv=inv*10+n;
     x/=10;
    }
    return inv;
}

int palindromico_max(int x, int y) //x & y definen el rango entre que numeros se buscara el palindromo
{
    int max=0;
    for(int i= x ; i>= y; i--)
        for(int j = x ; j >= y ; j--)
            if( (j*i)==(inverse(j*i)))  //verifica si el producto y su inverso son iguales (es palindromo)
               if ((j*i)>max)           //si es palindromo, se compara con el mayor almacenado
                    max=j*i;
    return max;

}
//ejercicio5
//¿Cuál es el número positivo mas pequeno que es divisible por todos los números del 1 al 20?
//Answer: 232792560

int divisible_entre(int x, int y)
{
    for(int i=1 ; i<=y ; i++)
    {
        if (x%i!=0)
            return 0;
    }
    return 1;
}

int menor_divisible(int x)
{
    int i=1;
    while (true)
    {
        i++;
        if (divisible_entre(i, x)==1)
            return i;
    }
}

//ejercicio6
//Encuentra la diferencia entre la suma de los cuadrados de los primeros
//cien números naturales y el cuadrado de la suma
//Answer: 25164150

int diferencia_cuadrados_y_al_cuadrado (int x)
{
    int suma1=0 , suma2=0;
    for (int i=1 ; i<=x ; i++)
    {
        suma1 += i;
        suma2 += pow(i,2);
    }
    suma1 *= suma1;
    return suma1-suma2;
}


//ejercicio 7
//¿Cual es el número primo 10 001?
//Answer: 104743

int primo_numero(int x)
{
    int i=0,cont=0;
    while (cont<x)
    {
        i++;
        if (es_primo(i))
            cont++;
    }
    return i;
}

//ejercicio 8
//Encuentra los trece dígitos adyacentes en el número de
//1000 dígitos que tienen el mayor producto. ¿Cuál es el valor de este producto?
//Answer: 23514624000

//1ra forma (usando un for)
long long digitos_adyacentes(char *x,int y)
{
    long long cont=0 ,maxproducto=1, producto=1,j=-1;
    for (int i=0 ; i<1000-y ;i++)
    {
        cont++;
        producto *= (*(x+i)-48); //el caracter ASCI es convertido a numero
        if ((cont==y))
        {
            if (producto>=maxproducto)
                maxproducto=producto;
            j++;
            i=j;
            cont=0;
            producto=1;
        }
    }
    return maxproducto;

}

//2ra forma (usando 2 for)   //123456789
long long digitos_adyacentes2(char *x,int y)
{
    long long producto=1, maxproducto=0;
    for (int i=0 ; i<1000-y ;i++)
    {
        for (int j=0 ; j<y ;j++)
        {
            if ((*(x+i+j)-48)==0)
            {
                producto=0;
                break;
            }
            producto *= *(x+i+j)-48;
        }
        if (producto>maxproducto)
                maxproducto=producto;
        producto=1;
    }
    return maxproducto;
}

//ejercicio9
//Existe exactamente un triplete pitagórico para el cual a + b + c = 1000.
//Encuentre el producto abc .
//Answer: 31875000

long long triplete_pitagorico(int x)       //x es el suma de a+b+c
{
    for (int i=1 ; i<= x/3 ; i++)
    {
        for (int j=i+1 ; j<=x ; j++)
        {
            long long k = x - (i+j);
            if ((k<=i)||(k<=j))
                break;
            if ( k*k == i*i + j*j ){
                cout<<"Los numeros a b y c son: "<<i<<"_"<<j<<"_"<<k<<endl;
                return j * i * k;
                }
        }
    }
    return 0; //en caso no encuentre

}

//ejercicio 10
//Encuentra la suma de todos los números primos por debajo de dos millones
//Answer:142913828922

long long int suma_de_primos_hasta2(int x) //Criba de Eratóstenes
{                                           //no consiste en buscar los numeros primos
    int *M = new int [x];  //2-20           //sino descartar los que no lo son
    for (int i=0; i<x-1;i++)
        M[i]=i+2;

    long long suma=0;

    for (int i=0;i<x-1;i++)
    {
        if (*(M+i)!=0)
        {
            if ((*(M+i))*(*(M+i))>x)
                break;
            for (int j=i+1;j<x-1;j++)
                if (*(M+j)==0)
                    continue;
                else if (*(M+j)%*(M+i)==0)
                    *(M+j)= 0;
        }
    }
    for (int i=0; i<x-1;i++)
    {
        suma+=M[i];
    }
    return suma;

}


int main()
{
    //01/cout<<suma_de_multiplos_de_3_o_5(1000)<<endl;
    //02/cout<<suma_par_fibonnaci(4000000)<<endl;
    //03/cout<<mayor_factor_primo(600851475143)<<endl;
    //04/cout<<palindromico_max(1000,100)<<endl;
    //05/cout<<menor_divisible(20)<<endl;
    //06/cout<<diferencia_cuadrados_y_al_cuadrado(100)<<endl;
    //07/cout<<primo_numero(10001)<<endl;
    //08/cout<<digitos_adyacentes("7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450",13)<<endl;
    //08/cout<<digitos_adyacentes2("7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450",13)<<endl;
    //09/cout<<triplete_pitagorico(1000)<<endl;
    //10/
    cout<<suma_de_primos_hasta2(2000000)<<endl;
}

