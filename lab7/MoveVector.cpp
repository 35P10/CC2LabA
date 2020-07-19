#include<bits/stdc++.h>
#include <iostream>

using namespace std;

void printVector(vector <int> X)
{
    for(int i = 0; i < X.size(); i++)
        std :: cout << " " << X[i];
    std :: cout << "\n";
}


int main()
{
    std :: vector <int> vec1 {1, 2, 3, 4, 5};
    std :: vector <int> vec2 {7, 7, 7, 7, 7};

    printVector(vec1);

    printVector(vec2);

    std :: move (vec1.begin(), vec1.begin() + 4, vec2.begin() + 1);


    printVector(vec2);


    return 0;
}
