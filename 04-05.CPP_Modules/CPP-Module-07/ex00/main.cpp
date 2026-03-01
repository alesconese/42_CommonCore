/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:34:56 by ade-tole          #+#    #+#             */
/*   Updated: 2025/02/26 17:34:58 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Foo.hpp"

class A
{
private:
	int	_n;
public:
	A(int n): _n(n) {}
	~A() {}

	bool operator>(A const &rhs) const {return _n > rhs._n;}
	bool operator<(A const &rhs) const {return _n < rhs._n;}


	int get_n() const{return _n;}
};

std::ostream &operator<<(std::ostream &o, const A &a) {o << a.get_n(); return o;}

int	main()
{
	{
		std::cout << "* * * * * TEST 1: Simple data type (int) * * * * *" << std::endl;
		int	a = 2;
		int	b = 3;

		::swap(a,b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	{
		std::cout << "\n\n* * * * * TEST 2: Simple data type (str) * * * * *" << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << "\n\n* * * * * TEST 3: Complex data (class) * * * * *" << std::endl;

		A	x(2), y(4);

		::swap(x, y);
		std::cout << x << " " << y << std::endl;
		std::cout << ::max(x, y) << std::endl;
		std::cout << ::min(x, y) << std::endl;
	}	
	return 0;
}
