#include <iostream>
#include <limits>
//#include <cstdint> not needed, already included inside std library

int main() {
    std::cout << "#=====================================================#" << std::endl;
    std::cout << "#==               SIGNED INT TYPES                  ==#" << std::endl;
    std::cout << "#=====================================================#" << std::endl;

    std::cout << "Short int length: " << sizeof(short int) << " Byte / " << sizeof(short int)*8 << " bit" << std::endl;
    std::cout << "Int length: " << sizeof(int) << " Byte / " << sizeof(int)*8 << " bit" << std::endl;
    std::cout << "Long int length: " << sizeof(long int)<< " Byte / " << sizeof(long int)*8 << " bit" << std::endl;
    std::cout << "Long Long int length: " << sizeof(long long int) << " Byte / " << sizeof(long long int)*8 << " bit" << std::endl;

    std::cout << "#=====================================================#" << std::endl;
    std::cout << "#==              UNSIGNED INT TYPES                 ==#" << std::endl;
    std::cout << "#=====================================================#" << std::endl;

    std::cout << "Int min value: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Int max value: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Unsigned int min/max values: " << std::numeric_limits<unsigned int>::min() << "/" << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "Unsigned Long Long int max value: " << std::numeric_limits<unsigned long long>::max() << std::endl;
    
    std::cout << "#=====================================================#" << std::endl;
    std::cout << "#==             FIXED WIDTH INT TYPES               ==#" << std::endl;
    std::cout << "#=====================================================#" << std::endl;
    /*
    Non sono tipi primitivi nativi.
    Tipi ad ampiezza fissa, utili per l'adattamento cross-platform.
    Sarà il compilatore ad adattare il tipo in base all'architettura corrente.
    */
    int16_t n;

    std::cout << "Fixed width int length: " << sizeof(n) << " Byte / " << sizeof(n)*8 << " bit" << std::endl;
    switch(sizeof(n)) {
        case 2:
            std::cout << "It's a short int!" << std::endl; 
            break;
        case 4:
            std::cout << "It's a int or a long int!" << std::endl;
            break;
        case 8:
            std::cout << "It's a long long int!" << std::endl;
            break;
        default:
            std::cout << "Not a matching case!" << std::endl;
            break;
    }

    return 0;
}