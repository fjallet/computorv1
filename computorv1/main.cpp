#include "Poly.hpp"

int main(int argc, char** argv){
    if (argc != 2){
        std::cout << "error arguments" << std::endl;
        return (1);
    }
    try{
        Poly    equation(argv[1]);
        equation.parseEquation();
    }
    catch (std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}