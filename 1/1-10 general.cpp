#include <iostream>
#include <math.h>
using namespace std;

///ejercicio1:
///If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
///Find the sum of all the multiples of 3 or 5 below 1000.

int suma_de_multiplos_de_3_o_5(int x)
{
    int Suma=0;
    for (int i=0; i<x; i++)
    {
        if (i%3==0)
            Suma += i;
        if ((i%5==0)&&(i%3!=0))
            Suma += i;
    }
    return Suma;
}

///ejercicio2:

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

///ejercicio3:

int es_primo(int x)
{
    if ((x==1))
        return 0;
    //if ((x==2))
        //return 1;
    for (int i=2; i<x; i++)
    {
        if (x%i==0)
            return 0;
    }
    return 1;
}

int mayor_factor_primo(int x)
{
    for(int i=x-1 ; i>0 ; i--)
        if (x%i==0)
            if (es_primo(i)==1)
                return i;
}

///ejercicio4:

int inverse (int x)
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

int palindromico_max(int x)
{
    int max=0;
    for(int i=pow(10,x) ; i>=pow(10,x-1); i--)
        for(int j=pow(10,x) ; j>=pow(10,x-1); j--)
            if( (j*i)==(inverse(j*i)))
               if ((j*i)>max)
                    max=j*i;
    return max;

}
///ejercicio5

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

///ejercicio6

int suma_cuadrados(int x)
{
    int suma=0;
    for (int i=1 ; i<=x ; i++)
        suma += pow(i,2);

    return suma;
}

int suma_al_cuadrado(int x)
{
    int suma=0;
    for (int i=1 ; i<=x ; i++)
        suma += i;
    return suma*suma;
}

int diferencia_cuadrados_y_al_cuadrado (int x)
{
    return suma_al_cuadrado(x)-suma_cuadrados(x);
}

///ejercicio 7

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

///ejercicio 8

long long digitos_adyacentes(char *x)
{
    long long cont=0 ,maxproducto=1, producto=1,j=-1;
    for (int i=0 ; i<1000-13 ;i++)
    {
        cont++;
        producto *= (*(x+i)-48);
        if (cont==13)
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

long long digitos_adyacentes2(char *x)
{
    long long producto=1, maxproducto=0;
    for (int i=0 ; i<1000-13 ;i++)
    {
        for (int j=0 ; j<13 ;j++)
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

///ejercicio9

long long triplete_pitagorico(int x)
{
    for (int i=1 ; i<= x/2 ; i++)
    {
        for (int j=i+1 ; j<=x ; j++)
        {
            long long k = x - (i+j);
            if ((k<=i)||(k<=j))
                break;
            if ( k*k == i*i + j*j ){
                cout<<i<<"_"<<j<<"_"<<k<<endl;
                return j * i * k;
                }
        }
    }
    return 0; //en caso no encuentre

}

///ejercicio 10

unsigned long long int sumadeprimoshasta(int x)
{
    unsigned long long int i=2, suma=0;
    while(i<x)
    {
        if (es_primo(i))
            suma += i;
        i++;
    }
    return suma;
}


int main()
{
    ///1/cout<<suma_de_multiplos_de_3_o_5(1000)<<endl;
    ///2/cout<<suma_par_fibonnaci(4000000);
    ///icout<<mayor_factor_primo(13195);
    ///cout<<palindromico_max(3);
    ///cout<<menor_divisible(20);
    ///cout<<diferencia_cuadrados_y_al_cuadrado (100);
    ///cout<<primo_numero(10001);
    ///cout<<digitos_adyacentes2("7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450");
    ///cout<<triplete_pitagorico(1000);
    cout<<sumadeprimoshasta(2000000);


}

