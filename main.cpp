/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:24:33 by rr                #+#    #+#             */
/*   Updated: 2024/03/07 14:52:36 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    // Fixed 		a;
    // Fixed const b(10);
    //Fixed const c(42.42f);// sans f par default c'est un double 
	// Fixed const d(b);

	// a = Fixed(1234.4321f);
    //std::cout << "c is " << c.toFloat() << " as integer" << std::endl;// 42.42 = 42.42 * 256 avc la formule nbr(roundf(nb * (1 << bits))) ou nb = 42.42 est nbr stockera 10859.52 arrondis donne (10860) (binary = 10101001101100) appel a to int pour redécaller les bits de 8 position vers la droite est obtenir la partie entiere qui est 00000000101010
    Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << a.getRawBits()<< std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}