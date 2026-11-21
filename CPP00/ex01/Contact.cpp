#include "PhoneBook.hpp"

int   Contact::setIndex(int id){
    this->index = id;
    return id;
}

void    Contact::setFirstName(const std::string &str){
    this->first_name = str;
}

void    Contact::setLastName(const std::string &str){
    this->last_name = str;
}

void    Contact::setNickname(const std::string &str){
    this->nickname =str;
}

void    Contact::setPhoneNumber(const std::string &str){
    this->phone_number =str;
}

void    Contact::setDarkestSecret(const std::string &str){
    this->darkest_secret = str;
}

int     Contact::getIndex() const{
    return index;
}

std::string Contact::getFirstName() const{
    return first_name;
}

std::string Contact::getLastName() const{
    return last_name;
}

std::string Contact::getNickname() const{
    return nickname;
}

std::string Contact::getPhoneNumber() const{
    return phone_number;
}

std::string Contact::getDarkestSecret() const{
    return darkest_secret;
}