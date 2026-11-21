#include <iostream>
#include <fstream>
#include <string>
//ifstream - ouvrir et lire le fichier
//ofstrean - ecrire dans un fichier
/*
GETLINE is used to read a string or a line from an input stream.
It extracts the characters from the input stream and 
appends it to the given string object until the delimiting character is encountered 

FIND is a built-in function used to find the first occurrence of an element in the given range.
It works with any container that supports iterators, such as arrays, vectors,lists, and more.
find(first, last, val);

What is string::npos?

    It is a constant static member value with the highest possible value for an element of type size_t.
    It actually means until the end of the string.
    It is used as the value for a length parameter in the string’s member functions.
    As a return value, it is usually used to indicate no matches.

ERASE() is a built-in function that is used to delete elements from the vector.
It removes an element of a specific position or range of elements from the vector

    */
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage : ./replace file_in s1 s2" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: cannot open input file," << std::endl;
        return 1;
    }
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "Error: cannot open output file" << std::endl;
        return 1;
    }
    std::string line;
    while(std::getline(infile, line))
    {
        size_t i = 0;
        while ((i = line.find(s1, i)) != std::string::npos) // je cherche la prochaine occurence de s1 a partir de mon index
        {
            line.erase(i, s1.length());// Supprime de la string line les caractères à partir de la position `i`.
            line.insert(i, s2);
            i += s2.length();//javance ma position de la longueur de s2
        }
        outfile << line << std::endl;//ecrire dans le fichier de sortie
    }
    return 0;
}