#ifndef POLY_HPP
# define POLY_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>

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
		void	checkBetweenOperator();
		void	fillValues();
		void	oneSolution();
		void	twoRealSolution();
		void	twoNotRealSolution();
		void	firstDegreeSolution();

		std::string	_equation;
		float		_ax2;
		float		_bx1;
		float		_cx0;
		float		_d;
		int			_degree;
		float		_discriminant;
}

class	ErrSyntax {
	virtual const char* what const throw(){
		return "Wrong Syntax"
	}
}

class	ErrDegree {
	virtual const char* what const throw(){
		return "Wrong Degree"
	}
}


#endif