#ifndef POLY_HPP
# define POLY_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class	Poly {

	public:

		Poly(std::string equation);
		~Poly();

		void	parseEquation();

	private:

		void	calculateDiscriminant();
		void	checkBetweenOperator();
		void	fillValues();

		std::string	_equation;
		float		_ax2;
		float		_bx1;
		float		_cx0;
		float		_d;
		int			_degree;
		float		_discriminant;
}