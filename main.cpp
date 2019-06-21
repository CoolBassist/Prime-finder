#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

int prime_finder(int number);

int main()
{
    int start_s=clock();
    int current_number = 1;
    int const number_of_primes_to_look_for = 1000000;
    int number_of_primes_found = 0;
    std::vector<int> primes_found;
    while(number_of_primes_found != number_of_primes_to_look_for)
    {
        if(prime_finder(current_number))
        {
            primes_found.push_back(current_number);
            number_of_primes_found += 1;
        }
        current_number+=2;
    }
    int stop_s=clock();
    std::cout << "The first " << number_of_primes_to_look_for << " primes are: ";
    for(int i = 0; i < number_of_primes_to_look_for-1; i++) std::cout << primes_found[i] << ", ";
    std::cout << primes_found[number_of_primes_to_look_for-1] << ".";
    std::cout << "\nTime elapsed: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << std::endl;
    return 0;
}

int prime_finder(int number)
{
    int sq_rt = sqrt(number);

    if(number % 2 == 0)
        return 0;
    
    for(int i = 3; i <= sq_rt; i+=2)
        if(number % i == 0)
            return 0;

    return 1;
}
