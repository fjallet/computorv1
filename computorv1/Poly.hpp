#ifndef POLY_HPP
# define POLY_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <map>
#include <stdlib.h>
#include <tgmath.h>
//#include <cstdio>

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
		void	fillValues(int degree, float value);
		void	oneSolution();
		void	twoRealSolution();
		void	twoNotRealSolution();
		void	firstDegreeSolution();
		int		getPGCD(int a, int b);
		bool	isInteger(float x);
		void	printIrreductibleFraction(float a, std::string link, float b);
		float	myABS(float a);
		float	mySQRT(float a);

		std::string	_strequation;
		std::map<int, float> _degreemap;
		int			_degree;
		float		_discriminant;
		float		_ax2;
		float		_bx1;
		float		_cx0;
};

class	SyntaxException: public std::exception{
	virtual const char* what() const throw();
};


#endif