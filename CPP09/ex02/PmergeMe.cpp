#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &copy){
    if (this != &copy)
        this->_vector = copy._vector;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &target){
    if (this != &target){
        this->_vector = target._vector;
    }
    return *this;
}
PmergeMe::~PmergeMe(){}

void    PmergeMe::sortVector(std::vector<int> &container){
    // 1 je verifie si j ai un chiffre suppelement qui rend la decoupe en 2 impossible
    int size = container.size();
    if (size <= 1)
        return ;
    bool hasSup = size % 2 != 0;
    int sup = 0;
    if (hasSup){
        sup = container.back(); //j extrais le dernier element du contenair et le stocke dans supplement
        container.pop_back();
    }
    // 2 Je cree et trie les paires First sera la plus grand
    std::vector<std::pair<int, int> >pairs; //cree un tableau pour stocker les pairs
    for (size_t i = 0; i < container.size(); i += 2){
        if(container[i] > container[i + 1])
            pairs.push_back(std::make_pair(container[i], container[i+1]));
        else 
            pairs.push_back(std::make_pair(container[i+1], container[i]));
    }

    // 3 J'extrai la chaine final
    std::vector<int> finalChain;
    for (size_t i = 0; i < pairs.size(); i++)
        finalChain.push_back(pairs[i].first);

    // 4 Trie en recurssif tout mes chiffre First cad les plus grand
    sortVector(finalChain); 

    // 5 Reconstruction et insertion -> Jacobsthal
    std::vector<int> chainLeft;
    for (size_t i = 0; i < finalChain.size(); ++i){
        for (size_t j = 0; j < pairs.size(); ++j){
            if (pairs[j].first == finalChain[i]){
                chainLeft.push_back(pairs[j].second);
                break;
            }
        }
    }
    finalChain.insert(finalChain.begin(), chainLeft[0]); // Rajout du premier element de ma chaineLeft a ma FinalChain

    //6 Je cree ma chaine Jacobsthal 
    size_t jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};

    size_t leftID = 1;
    size_t jacobID = 1;
    while (leftID < chainLeft.size()){
        size_t target = jacobsthal[jacobID];
        if(target >= chainLeft.size()){
            target = chainLeft.size() - 1;
        }
        for(size_t i = target; i >= leftID; --i){
            if (i < chainLeft.size()){
                std::vector<int>::iterator it = std::lower_bound(finalChain.begin(), finalChain.end(), chainLeft[i]);
                finalChain.insert(it, chainLeft[i]);
            }
            if(i == leftID) break;
        }
        leftID = target + 1;
        jacobID++;
    }
    if (hasSup){
        std::vector<int>::iterator it = std::lower_bound(finalChain.begin(), finalChain.end(), sup);
        finalChain.insert(it, sup);
    }
    container = finalChain;
}

void    PmergeMe::sortDeque(std::deque<int> &container){
     // 1 je verifie si j ai un chiffre suppelement qui rend la decoupe en 2 impossible
    int size = container.size();
    if (size <= 1)
        return ;
    bool hasSup = size % 2 != 0;
    int sup = 0;
    if (hasSup){
        sup = container.back(); //j extrais le dernier element du contenair et le stocke dans supplement
        container.pop_back();
    }
    // 2 Je cree et trie les paires First sera la plus grand
    std::deque<std::pair<int, int> >pairs; //cree un tableau pour stocker les pairs
    for (size_t i = 0; i < container.size(); i += 2){
        if(container[i] > container[i + 1])
            pairs.push_back(std::make_pair(container[i], container[i+1]));
        else 
            pairs.push_back(std::make_pair(container[i+1], container[i]));
    }

    // 3 J'extrai la chaine final
    std::deque<int> finalChain;
    for (size_t i = 0; i < pairs.size(); i++)
        finalChain.push_back(pairs[i].first);

    // 4 Trie en recurssif tout mes chiffre First cad les plus grand
    sortDeque(finalChain); 

    // 5 Reconstruction et insertion -> Jacobsthal
    std::deque<int> chainLeft;
    for (size_t i = 0; i < finalChain.size(); ++i){
        for (size_t j = 0; j < pairs.size(); ++j){
            if (pairs[j].first == finalChain[i]){
                chainLeft.push_back(pairs[j].second);
                break;
            }
        }
    }
    finalChain.insert(finalChain.begin(), chainLeft[0]); // Rajout du premier element de ma chaineLeft a ma FinalChain

    //6 Je cree ma chaine Jacobsthal 
    size_t jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};

    size_t leftID = 1;
    size_t jacobID = 1;
    while (leftID < chainLeft.size()){
        size_t target = jacobsthal[jacobID];
        if(target >= chainLeft.size()){
            target = chainLeft.size() - 1;
        }
        for(size_t i = target; i >= leftID; --i){
            if (i < chainLeft.size()){
                std::deque<int>::iterator it = std::lower_bound(finalChain.begin(), finalChain.end(), chainLeft[i]);
                finalChain.insert(it, chainLeft[i]);
            }
            if(i == leftID) break;
        }
        leftID = target + 1;
        jacobID++;
    }
    if (hasSup){
        std::deque<int>::iterator it = std::lower_bound(finalChain.begin(), finalChain.end(), sup);
        finalChain.insert(it, sup);
    }
    container = finalChain;
}

void PmergeMe::run(int ac, char **av) {
    struct timeval startV, endV;
    gettimeofday(&startV, NULL);
    
    // Remplir le vecteur depuis av
    for (int i = 1; i < ac; ++i){
        _vector.push_back(std::atoi(av[i]));
    }
    
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); ++i) std::cout << _vector[i] << " ";
    std::cout << std::endl;

    sortVector(_vector);
    
    gettimeofday(&endV, NULL);
    double timeV = (endV.tv_sec - startV.tv_sec) * 1e6 + (endV.tv_usec - startV.tv_usec);

    //  DEQUE 
    struct timeval startD, endD;
    gettimeofday(&startD, NULL);
    
    for (int i = 1; i < ac; ++i) {
        _deque.push_back(std::atoi(av[i]));
    }
    sortDeque(_deque);
    
    gettimeofday(&endD, NULL);
    double timeD = (endD.tv_sec - startD.tv_sec) * 1e6 + (endD.tv_usec - startD.tv_usec);
    

    std::cout << "After:  ";
    for (size_t i = 0; i < _vector.size(); ++i) std::cout << _vector[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << timeV << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : " << timeD << " us" << std::endl;
}