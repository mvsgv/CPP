#include "PhoneBook.hpp"

void PhoneBook::Welcome(void){

    std::cout << "_____________________________________________"<< std::endl;
    std::cout <<"|        Welcome to the Phonebook             |"<< std::endl;
    std::cout <<"|_____________________________________________|"<< std::endl;
    };

void    Contact::clear(){
    index = -1;
    first_name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
    darkest_secret = "";
}
std::string LengthColumn(const std::string& text){

    if (text.length() > 10){
        return text.substr(0, 9) + ".";
    }
    else{
        return std::string(10 - text.length(), ' ') + text;
    }
}

void    PhoneBook::Search(){
    
    std::cout << "___________________________________________"<< std::endl;
    std::cout <<"|   INDEX  |FIRST NAME|LAST  NAME| NICKNAME |"<< std::endl;
    std::cout <<"|__________|__________|__________|__________|"<< std::endl;
    for(int i = 0; i < 8; i++){
        if(!contacts[i].getFirstName().empty()){
            std::cout   <<"|" << LengthColumn(std::string(1, '0' + i))
                        <<"|" << LengthColumn(contacts[i].getFirstName())
                        <<"|" << LengthColumn(contacts[i].getLastName())
                        <<"|" << LengthColumn(contacts[i].getNickname()) 
                        <<"|" << std::endl;
        }
    }
    std::cout << "____________________________________________"<<std::endl;
    std::cout << "Enter index number"<<std::endl;
    int number;
    std::string tmp;
    std::getline (std::cin, tmp);
    if (tmp.length() != 1 || !std::isdigit(static_cast<unsigned char>(tmp[0]))) {
        std::cout << "Error: wrong index number." << std::endl;
        return;
    }
    number = tmp[0] - '0'; // convert single digit char to int
    if (number < 0 || number > 8 || contacts[number].getFirstName().empty()){
        std::cout << "Error: wrong index number."<<std::endl;
        return;
    }
    std::cout <<"_____________________________________________"<< std::endl;
    std::cout <<"|Details of contact at index: "<< number << std::endl;
    std::cout <<"|First name: "<< contacts[number].getFirstName() <<std::endl;
    std::cout <<"|Last name: "<< contacts[number].getLastName()<<std::endl;
    std::cout <<"|Nickname: "<< contacts[number].getNickname()<<std::endl;
    std::cout <<"|Phone Number: "<< contacts[number].getPhoneNumber()<<std::endl;
    std::cout <<"|Darkest Secret: "<< contacts[number].getDarkestSecret()<<std::endl;
    std::cout <<"|____________________________________________"<< std::endl;
}

void    PhoneBook::add(){

    if (nextIndex < 0 || nextIndex >= 8) nextIndex = 0;
    int i = nextIndex;
    std::string input;

    std::cout << "First name" << std::endl;
    std::getline (std::cin, input);
    if (input.empty())
    {
        std::cout << "Error: empty line unauthorized" << std::endl;
        contacts[i].clear();
        return;
    }   
    contacts[i].setFirstName(input);  

    std::cout << "Last name" << std::endl;
    std::getline (std::cin, input);
    if (input.empty())
    {
        std::cout << "Error: empty line unauthorized" << std::endl;
        contacts[i].clear();    
        return ;
    }   
    contacts[i].setLastName(input);

    std::cout << "Nickname" << std::endl;
    std::getline (std::cin, input);
    if (input.empty())
    {
        std::cout << "Error: empty line unauthorized" << std::endl;
        contacts[i].clear();
        return ;
    }   
    contacts[i].setNickname(input);

    std::cout << "Phone number"<< std::endl;
    std::getline (std::cin, input);
    if (input.empty())
    {
        std::cout << "Error: empty line unauthorized" << std::endl;
        contacts[i].clear();
        return ;
    }   
    contacts[i].setPhoneNumber(input);

    std::cout << "Darkest secret"<< std::endl;
    std::getline (std::cin, input);
    if (input.empty())
    {
        std::cout << "Error: empty line unauthorized" << std::endl;
        contacts[i].clear();
        return ;
    }   
    contacts[i].setDarkestSecret(input);

    contacts[i].setIndex(i);
    nextIndex = (nextIndex + 1) % 8;


}
