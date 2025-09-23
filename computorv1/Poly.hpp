#ifndef POLY_HPP
# define POLY_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <map>
#include <stdlib.h>
#include <cstdio>

class	Poly {

	public:

		Poly(std::string equation);
		~Poly();

		void	parseEquation();
		void	displayReducedForm();
		void	displayPolynomialDegree();
		void	displaySolution();

	private:

		void	calculateDiscriminant();
		void	checkBetweenOperator(std::string str, int minus);
		void	fillValues();
		void	oneSolution();
		void	twoRealSolution();
		void	twoNotRealSolution();
		void	firstDegreeSolution();

		std::string	_strequation;
		std::map<int, float> _floatequation;
		float		_ax2;
		float		_bx1;
		float		_cx0;
		float		_d;
		int			_degree;
		float		_discriminant;
};

class	SyntaxException: public std::exception{
	virtual const char* what() const throw(){
		return "Wrong Syntax";
	}
};

class	DegreeException: public std::exception{
	virtual const char* what() const throw(){
		return "Wrong Degree";
	}
};


#endif