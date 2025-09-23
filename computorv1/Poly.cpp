#include "Poly.hpp"

Poly::Poly(std::string equation) : _strequation(equation){
	_ax2 = 0;
	_bx1 = 0;
	_cx0 = 0;
	_d = 0;
}

Poly::~Poly(){

}

void    Poly::parseEquation(){
	size_t	countlen = 0;
	float	minus = 1;
	size_t	it;
	for (it = 0; it <= _strequation.size() ; it++){
		if (_strequation[it] == '+'){
			//printf("%f / %s\n", minus, _strequation.substr(it - countlen, countlen).c_str());
			checkBetweenOperator(_strequation.substr(it - countlen, countlen), minus);
			countlen = -1;
			minus = 1;
		}
		if (_strequation[it] == '-'){
			//printf("%f / %s\n", minus, _strequation.substr(it - countlen, countlen).c_str());
			checkBetweenOperator(_strequation.substr(it - countlen, countlen), minus);
			countlen = -1;
			minus = -1;
		}
		if (_strequation[it] == '='){
			//printf("%f / %s\n", minus, _strequation.substr(it - countlen, countlen).c_str());
			checkBetweenOperator(_strequation.substr(it - countlen, countlen), minus);
			minus = -1;
			//printf("%f / %s\n", minus, _strequation.substr(it + 1).c_str());
			checkBetweenOperator(_strequation.substr(it), minus);
			break;
		}
		countlen++;
	}
}

void	Poly::checkBetweenOperator(std::string str, int minus){
	float	value;
	size_t	it;
	value = strtof(str.c_str(), NULL) * minus;
	for (it = 0; it < str.size() && str[it] != ',' && (str[it] > 57 || str[it] < 48); it++){}
	if (it + 5 < str.size()){
		throw SyntaxException();
	}
	std::string temp = str.substr(it, 5);
	if (temp != " * X^"){
		throw SyntaxException();
	}
	it += 5;
	if (it > str.size()){
		throw SyntaxException();
	}
	printf("%f * X^%c", value, str[it]);
	//fillValues(*it, value)
	it++;
}
/*
void	Poly::fillValues(char degree, float value){
	//if (this->_floatequation.find(degree) == this->_floatequation.end())
	//	this->_floatequation.insert (std::pair<int,float>(degree,value));
	//else
	//	this->_floatequation[degree] += value;
	switch (degree){
		case '0':
			this._cx0 += value
			break;
		case '1':
			this._bx1 += value
			break;
		case '2':
			this._ax2 += value
			break;
		default:
			throw ErrDegree;
	}
}

void    Poly::calculateDiscriminant(){
	this->_discriminant = this->_bx1 * this->_bx1 - 4 * this->_ax2 * this->_cx0
}

void	Poly::displayReducedForm(){
	std::cout << _cx0 << " * X^0 ";
	if (_bx1 > 0){
		std::cout << "+ " << _bx1 << " * X^1 ";
	}
	else if (_bx1 < 0){
		std::cout << "- " << _bx1 * -1 << " * X^1 ";
	}
	if (_ax2 > 0){
		std::cout << "+ " << _ax2 << " * X^2 ";
	}
	if (_ax2 < 0){
		std::cout << "- " << _ax2 * -1 << " * X^2 ";
	}
	std::cout << "= 0" << std::endl;
}

void	Poly::displayPolynomialDegree(){
	std::cout << "Polynomial degree: " << _degree << std::endl;
}

void	Poly::displaySolution(){
	if (_degree == 1){
		return (firstDegreeSolution());
	}
	calculateDiscriminant();
	if (_discriminant = 0){
		return(oneSolution());
	}

}

void	Poly::firstDegreeSolution(){
	std::cout << "The solution is:" << std::endl;
	std::cout << -1 * _cx0 / _bx1 << std::endl;
}

void	Poly::oneSolution(){
	std::cout << "The solution is:" << std::endl;
	std::cout << -1 * _bx1 / (2 * _ax2) << std::endl;
}

void	Poly::twoRealSolution(){
	std::cout << 
}
	*/
