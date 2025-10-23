#include "Poly.hpp"

Poly::Poly(std::string equation) : _strequation(equation){
	_degree = 0;
	_ax2 = 0;
	_bx1 = 0;
	_cx0 = 0;
}

Poly::~Poly(){

}

void    Poly::parseEquation(){
	size_t	countlen = 0;
	float	minus = 1;
	size_t	it;
	for (it = 0; it <= _strequation.size() ; it++){
		if (_strequation[it] == '+' && countlen > 2){
			checkBetweenOperator(_strequation.substr(it - countlen, countlen), minus);
			countlen = -1;
			minus = 1;
		}
		if (_strequation[it] == '-' && countlen > 2){
			checkBetweenOperator(_strequation.substr(it - countlen, countlen), minus);
			countlen = -1;
			minus = -1;
		}
		if (_strequation[it] == '=' && countlen > 2){
			checkBetweenOperator(_strequation.substr(it - countlen, countlen), minus);
			countlen = -1;
			minus = -1;
		}
		countlen++;
	}
	checkBetweenOperator(_strequation.substr(it - countlen, countlen), minus);
}

void	Poly::checkBetweenOperator(std::string str, int minus){
	float	value;
	size_t	it = 0;
	value = strtof(str.c_str(), NULL) * minus;
	if (str == " 0")
		return;
	if (str[it] == ' ')
		it++;
	while (it < str.size() && (str[it] == '.' || str[it] == '-' || (str[it] <= 57 && str[it] >= 48)))
		it++;
	if (it + 5 > str.size()){
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
	fillValues(str[it] - 48, value);
	it++;
}

void	Poly::fillValues(int degree, float value){
	if (degree > _degree)
		_degree = degree;
	if (_degreemap.find(degree) == _degreemap.end())
		_degreemap.insert (std::pair<int,float>(degree,value));
	else
		_degreemap[degree] += value;
	if (degree == 0)
		_cx0 += value;
	if (degree == 1)
		_bx1 += value;
	if (degree == 2)
		_ax2 += value;
}

void	Poly::displayReducedForm(){
	int degree = 0;
	std::cout << "reduced form : ";
	if (!_degreemap.empty())
		std::cout << _degreemap[0] << " * X^0 ";
	else if (_degreemap.empty()){
		std::cout << "0 * X^0 ";
	}
	degree++;
	while (degree <= _degree){
		if (_degreemap.find(degree) != _degreemap.end()){
			if (_degreemap[degree] > 0)
				std::cout << "+ " << _degreemap[degree] << " * X^" << degree << " ";
			else if (_degreemap[degree] < 0)
				std::cout << "- " << _degreemap[degree] * -1 << " * X^" << degree << " ";
			else if (_degreemap[degree] == 0)
				std::cout << "+ 0 * X^" << degree << " ";
		}
		degree++;
	}
	std::cout << "= 0" << std::endl;
}

void	Poly::displayPolynomialDegree(){
	if (_degree == 0)
		return;
	std::cout << "Polynomial degree: " << _degree << std::endl;
}

void	Poly::displaySolution(){
	if (_degree > 2)
		std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
	if (_degree == 0 && _cx0 == 0)
		std::cout << "Any real number is a solution." << std::endl;
	else if (_degree == 0 && _cx0 != 0)
		std::cout << "No solution." << std::endl;
	if (_degree == 1){
		return (firstDegreeSolution());
	}
	if (_degree == 2){
		calculateDiscriminant();
		if (_discriminant == 0)
			return(oneSolution());
		if (_discriminant > 0)
			return(twoRealSolution());
		if (_discriminant < 0)
			return(twoNotRealSolution());
	}
}

void	Poly::firstDegreeSolution(){
	std::cout << "The solution is:" << std::endl;
	std::cout << -1 * _cx0 / _bx1 << std::endl;
}

void    Poly::calculateDiscriminant(){
	_discriminant = _bx1 * _bx1 - 4 * _ax2 * _cx0;
}

void	Poly::oneSolution(){
	std::cout << "The solution is:" << std::endl;
	std::cout << -1 * _bx1 / (2 * _ax2) << std::endl;
}

void	Poly::twoRealSolution(){
	std::cout << "Discriminant is strictly positive, the two solutions are:" << std::endl;
	std::cout << (-1 * _bx1 + mySQRT(_discriminant)) / (2 * _ax2) << std::endl;
	std::cout << (-1 * _bx1 - mySQRT(_discriminant)) / (2 * _ax2) << std::endl;
}

int		Poly::getPGCD(int a, int b){
	int	pgcd = 0;
	a = myABS(a);
	b = myABS(b);
	while (b != 0){
		pgcd = a % b;
        a = b;
        b = pgcd;
	}
	return (a);
}

float	Poly::mySQRT(float a){
	float	x;
	if (a < 0)
		throw SQRTException();
	if (a == 0)
		return (0);
	if (a > 0 && a < 1)
		x = 1;
	if (a == 1)
		return (1);
	if (a > 1)
		x = a / 2;
	for (int i = 0; i < 10; ++i){
		x = (x + a / x) / 2;
	}
	return (x);
}

float	Poly::myABS(float a){
	if (a > 0)
		return (a);
	else
		return (a * -1);
}

bool	Poly::isInteger(float x){
	return (x == static_cast<int>(x));
}

void	Poly::printIrreductibleFraction(float a, std::string link, float b){
	int pgcd;
	if (!isInteger(a) || !isInteger(b))
		std::cout << a << link << b;
	else {
		pgcd = getPGCD(static_cast<int>(a), static_cast<int>(b));
		std::cout << a / static_cast<float>(pgcd) << link << b / static_cast<float>(pgcd);
	}
}

void	Poly::twoNotRealSolution(){
	std::cout << "Discriminant is strictly negative, the two complex solutions are:" << std::endl;
	printIrreductibleFraction(_bx1 * - 1, "/", 2 * _ax2);
	std::cout << " + "; 
	printIrreductibleFraction(mySQRT(myABS(_discriminant)), "i/", 2 * _ax2);
	std::cout << std::endl;
	printIrreductibleFraction(_bx1 * - 1, "/", 2 * _ax2);
	std::cout << " - "; 
	printIrreductibleFraction(mySQRT(myABS(_discriminant)), "i/", 2 * _ax2);
	std::cout << std::endl;
}


const char*	SyntaxException::what() const throw(){
		return "Wrong Syntax";
}

const char*	SQRTException::what() const throw(){
		return "negative number in mySQRT";
}