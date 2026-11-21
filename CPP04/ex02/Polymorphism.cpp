/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorphism.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.42.be		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:12:43 by mariameviss       #+#    #+#             */
/*   Updated: 2025/10/27 15:23:43 by mariameviss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.hpp"

Animal::Animal(){
	_type = "Default";
    std::cout << "Default constructor for Animal called." << std::endl;
}

Animal::Animal(std::string type){
	_type = type;
    std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal &copy){
    this->_type = copy._type;
    std::cout << "Copy constructor for Animal called." << std::endl;
}

Animal	&Animal::operator=(const Animal &target){
    this->_type = target._type;
	std::cout << "Copy assignment operator for Animal called." << std::endl;
    return *this;
}

Animal::~Animal(){
    std::cout << "Destructor for Animal called." << std::endl;
}

std::string	Animal::getType() const{
	return (_type);
}