#include <iostream>
#include <math.h>
#include <ctime>

int primer_finder(int number);

int main()
{
    int start_s=clock();
    int current_number = 0;
    int number_of_primes_found = 0;
    while(1)
    {
        if(primer_finder(current_number))
        {
            std::cout << current_number << " is a prime number" << std::endl;
            number_of_primes_found += 1;
        }
        current_number++;

        if(number_of_primes_found == 100000)
        {
            int stop_s=clock();
            std::cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << std::endl;
            return 0;
        }
    }
    return 0;
}

int primer_finder(int number)
{
    for(int i = 2; i <= sqrt(number); i++)
    {
        if(number % i == 0)
            return 0;
    }
    return 1;
}