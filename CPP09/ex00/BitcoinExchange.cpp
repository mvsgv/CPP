#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){
    *this = copy;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &target){
    if (this != &target)
        this->_BitcoinPriceTag = target._BitcoinPriceTag;
    return *this;
}
BitcoinExchange::~BitcoinExchange(){}

bool BitcoinExchange::validDate(std::string date){
    int year, month, day;
    char dash1, dash2;

    std::stringstream ss(date);
    if (!(ss >> year >> dash1 >> month >> dash2 >> day))
        return false;
    if (dash1 != '-' || dash2 != '-')
        return false;
    if (!ss.eof())
        return false;
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    int maxDay;
    switch (month){
        case 2:
        {
            bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            maxDay = leap ? 29 : 28;
            break;
        }
        case 4: case 6: case 9: case 11:
            maxDay = 30;
            break;
        default:
            maxDay = 31;
    }
    return day <= maxDay;
}

int   BitcoinExchange::parseCSV(std::string filename){
    
    std::ifstream file(filename.c_str());    

    if(!file){
        throw std::runtime_error ("Error: Can't open file");
    }
    std::string line, date, price;
    std::getline(file, line); //skip first line -> date and exchange rate
    while(getline(file, line)){
        char *endptr;
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        std::getline(ss, price);
        float pricef = std::strtof(price.c_str(), &endptr);
        //si je n ai pas reussi a convertir endptr ou si les bitcoins sont en negatif
        if (endptr == price.c_str() || pricef < 0.0)
            throw std::runtime_error("Error: incorrect pricing: " + price);
        while(*endptr){
            //si j ai des espaces apres la convertion de mes bitcoins -> 42f  \0
            if (!std::isspace(*endptr)){
                throw std::runtime_error("Error: invalid charachter: " + price);
            } ++endptr;
        }
        if (_BitcoinPriceTag.find(date) != _BitcoinPriceTag.end())
            throw std::runtime_error("Error: unexpected date duplicates: " + date);
        if (!validDate(date))
            throw std::runtime_error("Error: incorrect date: " + date);
        _BitcoinPriceTag[date] = pricef;
    }
    return 0;
}
void  BitcoinExchange::printExchangeCalculations(std::string value){
    std::ifstream file(value.c_str());
    std::string line, date, nb;

    if (!file)
        throw std::runtime_error("Error: could not open file."); 
    
    std::getline(file, line); // Skip header (date | value)
    while(std::getline(file, line)){
        if (line.empty()) continue;
        
        std::istringstream ss(line);
        if (!std::getline(ss, date, '|') || !std::getline(ss, nb)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Nettoyage des espaces pour le parsing
        date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
        nb.erase(std::remove(nb.begin(), nb.end(), ' '), nb.end());

        if (!validDate(date)){
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        char *endptr;
        float nbf = std::strtof(nb.c_str(), &endptr);
        if (endptr == nb.c_str() || *endptr != '\0') {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (nbf < 0){
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (nbf > 1000){
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        // Récupération du taux de change (lower_bound)
        std::map<std::string, float>::iterator it = _BitcoinPriceTag.lower_bound(date);
        if (it == _BitcoinPriceTag.end() || it->first != date) {
            if (it == _BitcoinPriceTag.begin()) {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }
            --it; 
        }
        std::cout << date << " => " << nbf << " = " << it->second * nbf << std::endl;
    }
    file.close();
}