#include <iostream>
#include <ctime> //time
#include <cstdlib> //rand
#include <random> //c++11


int main(int argc, char const *argv[])
{

    /*
    srand (time(0));
    std::cout << rand () % 6 + 1;
    */

   std::random_device rd;
   std::mt19937 rnd (rd ());
   //std::cout <<  rnd ();

   std::uniform_int_distribution d(1,6);


    double sum = 0;
    int count= 1000;
    for (size_t i = 0; i < count; i++)
    {
        sum +=d(rnd);
    }
    std::cout << sum/count << std::endl;


    std::binomial_distribution bd (5,.9);

    std::cout << bd (rnd);

    return 0;
}