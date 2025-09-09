#include "Poly.hpp"

Poly::Poly(std::string _equation) : _equation(equation){
	_ax2 = 0;
	_bx1 = 0;
	_cx0 = 0;
	_d = 0;
}

Poly::~Poly(){

}

void    Poly::parseEquation(){
	size_t	countlen = -1;
	size_t	it;
	for (it = 0; it != NULL; it++){
		if (_equation[it] == '+' || _equation[it] == '-'){
			checkBetweenOperator(_equation.substr(it - countlen, countlen));
			countlen = -1;
		}
		if (_equation[it] == '='){
			checkBetweenOperator(_equation.substr(it));
			break;
		}
		countlen++;
	}
}

void	Poly::checkBetweenOperator(std::string str){
	float					value;
	std::string::iterartor	it;
	value = strtof()
	for (it = str.begin(); (*it != ',' || (*it < 58 && *it > 47)) && it != str.end() ; it++){}
	std::string temp = str.substr(it, 5)
	if (temp != " * X^"){
		//err syntax
	}
	it += 5;
	if (it >= str.end()){
		//err syntax
	}
	fillValues(*it, value)
}

void	Poly::fillValues(char degree, float value){
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
			//err syntax
	}
}

void    Poly::checkSyntax(){
	
}