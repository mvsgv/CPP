#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2){
        std::cout << "Usage: ./btc file.csv" << std::endl;
        return 1;
    }
    BitcoinExchange Bit;
    try
    {
        Bit.parseCSV("data.csv");
        Bit.printExchangeCalculations(av[1]);
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
}