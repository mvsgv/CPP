#include "ScalarConverter.hpp"

/*Je déclares un opérateur d’affectation et un constructeur de copie.
Mais ma classe n’a pas de membres à copier ou à affecter.
Pour éviter un avertissement du compilateur sur une variable 
non utilisée (target ou copy), j'ajoutes (void)target; ou (void)copy;*/


ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &target){
    (void)target;
    return (*this);
}
ScalarConverter::ScalarConverter(const ScalarConverter &copy){
    (void)copy;
}

bool ScalarConverter::ischar(const std::string &c){
    if (c.length() == 1 && std::isprint(static_cast<unsigned char>(c[0])) &&
        !std::isdigit(static_cast<unsigned char>(c[0]))) // appeler statcast pour eviter undef behavior
        return true;
    return false;
}

bool ScalarConverter::isint(const std::string &i){
    if (i == "-" || i == "+")
        return false;

    std::stringstream ss(i);//declarer et init strinstream
    long long val;//variable qui recoit la valeur lue, j utilise un long pour detecter les valeurs hors plage
    if(!(ss >> val))//si la lecture echoue//Read token from stringstream into variable
        return false;
    //Si la lecture réussit, val contient l'entier lu (lecture s'arrête au premier caractère non numérique)
    ss>>std::ws;//consomme et supprime tout les espces tab etc
    if (!ss.eof())
        return false;
    return true;
}

bool ScalarConverter::isfloat(const std::string &f){
    if (f.empty() || f[f.length() - 1] != 'f')
        return false;
    std::string cutter = f.substr(0, f.size() - 1);
    if (cutter.empty() || cutter == "-" || cutter == "+")
        return false;
    std::stringstream ss(cutter);
    double val;//double pour les non entier
    if (!(ss >> val))
        return false;
    ss>>std::ws;
    return ss.eof();

}

bool ScalarConverter::isdouble(const std::string &d){
    if (d.empty() || d[d.length() - 1] == 'f')
        return false;
    if (d == "+" || d == "-")
        return false;
    std::stringstream ss(d);
    double val;
    if (!(ss>>val))
        return false;
    ss>>std::ws;
    return (ss.eof());
}

void ScalarConverter::convert(std::string type) {

    if (type == "nan" || type == "nanf" || type == "+inf" || type == "-inf" ||
        type == "+inff" || type == "-inff"){
            checkforspecials(type);
            return;
    }

    if(ischar(type)){
        char c = type[0];
        conversion(static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
        return;
    }

    if (isint(type)){
        std::stringstream ss(type);
        long val = 0;
        ss >> val;
        if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: overflow" << std::endl;
            std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(val) << std::endl;
        }else
            conversion(val, static_cast<float>(val), static_cast<double>(val));
        return;
    }
    
    if (isfloat(type)){
        std::string choppedF = type.substr(0, type.length() - 1);
        double fl;
        std::istringstream (choppedF)>>fl;
        if (fl > std::numeric_limits<int>::max() || 
                fl < std::numeric_limits<int>::min()){
                    std::cout << "char: impossible"<< std::endl;
                    std::cout << "int: overflow"<< std::endl;
                    std::cout << "float: " << static_cast<float>(fl)<< "f" <<  std::endl;
                    std::cout << "double: " << fl << std::endl;
                    std::cout << "float: " << static_cast<float>(fl)<< "f" <<  std::endl;
                    std::cout << "double: " << fl << std::endl;
        }
        else    
            conversion(static_cast<int>(fl), fl, static_cast<double>(fl));
        return;
    }

    if(isdouble(type)){
        double db;
        std::stringstream ss(type);
        ss >> db;
        if (db > std::numeric_limits<int>::max() || 
            db < std::numeric_limits<int>::min()){
                std::cout << "char: impossible"<< std::endl;
                std::cout << "int: overflow"<< std::endl;
                std::cout << "float: " << static_cast<float>(db)<< "f" <<  std::endl;
                std::cout << "double: " << db << std::endl;
        }else
            conversion(static_cast<int>(db),  static_cast<double>(db), db);
        return;
    }

    if (isdouble(type)){
        double db;
        std::istringstream (type)>>db;
        if (db > std::numeric_limits<int>::max() || 
                db < std::numeric_limits<int>::min()){
                    std::cout << "char: impossible"<< std::endl;
                    std::cout << "int: overflow"<< std::endl;
                    std::cout << "float: " << static_cast<float>(db)<< "f" <<  std::endl;
                    std::cout << "double: " << db <<  std::endl;
        }
        else    
            conversion(static_cast<int>(db), static_cast<float>(db), db);
        return;
    }
    else
        std::cout << "Error: unexpected input" << std::endl;
    return;
}


void    ScalarConverter::conversion(int i, float f, double d){
    //char et int
    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else{
        char sc = static_cast<char>(i);
        if (!std::isprint(static_cast<unsigned char>(sc)))
            std::cout << "char: Non displayable" << std::endl;
        else 
            std::cout << "char:'"<< sc << "'" << std::endl;
    }
    std::cout << "int: " << i << std::endl;
    //float et double
    if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;  
    if (d == static_cast<int>(d))
        std::cout << "double: " << d << ".0"<< std::endl;
    else
        std::cout << std::fixed <<  std::setprecision(1) << "double: " << d << std::endl; 
}


void ScalarConverter::checkforspecials(std::string special){

    std::cout << "char: impossible"<< std::endl;
    std::cout << "int: impossible"<< std::endl;
    if (special == "nan" || special == "nanf")
        std::cout << "float: nanf" << std::endl << "double: nan"<< std::endl;
    else if (special == "+inf" || special == "+inff")
        std::cout << "float: +inff" << std::endl << "double: +inf" << std::endl;
    else if (special == "-inf" || special == "-inff")
        std::cout << "float: -inff" << std::endl << "double: -inf" << std::endl;
    return;
}
