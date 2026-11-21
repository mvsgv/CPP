#include <iostream>
#include <string>
/*
Quelle est la difference entre Reference et Pointeur ?
POINTEUR * 
-Est une variable separee qui contient l'adresse d'une autre variable
-Peut etre reasignee vers un autre objet
-Peut etre NULL
-Arithmetique possible ptr++, ptr--

REFERENCE &
-Alias/surnom pour une variable existante
-Ne peut etre reasignee apres initialisation
-Ne peut etre NULL
-Acces direct sans ref

Difference entre & pour reference et & pour adresse

Dans ce cas d'utilisation:
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;          &str =  adresse de str
    &str signifie "donne moi 'addresse de la variable str"
    resultat ---> un pointeur (adresse memoire)

Dans ce cas d'utilisation:
    std::string  &stringREF = str;    stingREF est une reference a str
    &stringREF est un alias pour str
    resultat ---> un nom alternatif pour la meme variable

en bref l alias sert a acceder a la valeur sans passer par le *.
ca simplifie la syntaxe. 
*/

int main(){
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str; // & = adresse de
    std::string  &stringREF = str; // & = reference a 

    std::cout << "Memory address held by the string: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
    
    std::cout << "Value of string variable: " << str << std::endl;
    std::cout << "Value pointed by stringPTR: " << *stringPTR <<std::endl;
    std::cout << "Value pointed by stringREF: " << stringREF << std::endl; //acces direct a la valeur  
}