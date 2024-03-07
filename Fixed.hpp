/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rr <rr@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:24:31 by rr                #+#    #+#             */
/*   Updated: 2024/03/06 21:50:22 by rr               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed
{
    private:
        int nbr;
        static const int bits = 8;
    public:
    	Fixed();
    	Fixed(const Fixed &var);
		Fixed(const int nb);
		Fixed(const float nb);
    	~Fixed();
		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		int		toInt(void) const;
		float 	toFloat(void) const;
		Fixed &operator=(Fixed const &obj);//Surcharge de l'opérateur =   
};

std::ostream &operator<<(std::ostream &out, Fixed const &obj);

#endif