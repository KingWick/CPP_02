/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rr <rr@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:24:28 by rr                #+#    #+#             */
/*   Updated: 2024/03/06 22:49:55 by rr               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : nbr(0)
{
    std::cout << "Default constructor called " << std::endl;
}

Fixed::Fixed(const Fixed &var)//évite la copie inutile de l'objet original (a) et garanti que je modifie pas (var) le but ici est juste de la copier 
{
    std::cout << "Copy constructor called " << std::endl;
    *this = var;// Copie les données de l'instance A dans l'instance B (deux objets distincts)
                // *this ici représente l'objet B tandis que this sans (*) aurait représenté l'adresse de l'objet B
}

Fixed::~Fixed()
{
    std::cout << "Destructor called " << std::endl;
}

//Recupere mon nombre a point fixe (ex : 10 en binaire = 1010 application de la formule = nb<<bits = (10 << 8) = 0000101000000000(2560) = 00001010.00000000) jai ici mon nombre a point fixe 
Fixed::Fixed(const int nb) : nbr(nb << bits)//nb << bits équivaut à déplacer les bits de nb vers la gauche de bits(8 dans notre cas) positions.
											// Equivaux a 10 * 256 dans le cas ou nb est 10 --- nb<<bits = (10 << 8) nbr vaudras le resultat de 10*256
{
	std::cout << "Int Constructor called " << std::endl;
}

Fixed::Fixed(const float nb) : nbr(roundf(nb * (1 << bits)))// pas possible de réutiliser la formule de int car ici on manipule un float(nb)   1 << bits reviens a mettre 1 ala 8eme position (0000000100000000) Qui est = a 256 donc nb * (1 << bits) reviens a ecrire (nb * 256) roundf arrondis au plus proche
{
	std::cout << "Float Constructor called " << std::endl;
}

int Fixed::getRawBits(void) const 
{
	return (nbr);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawbits member function called " << std::endl;
	nbr = raw;
}

Fixed &Fixed::operator=(Fixed const &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)//evite l'auto-affectation en comparant que les adresse sont differente 
        this->nbr = obj.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &out, Fixed const &obj)
{
	out << obj.toFloat();
	return (out);
}
int	Fixed::toInt(void) const
{
    return (nbr >> bits);	
}

float Fixed::toFloat(void) const 
{
    float value = static_cast<float>(nbr) / (1 << bits);
    return value;
}

//Nombre a virgule fixe : 
//representation avec 4 bits pour la partie entiere est 4 bits pour la partie fractionnaire 
//                   1101       .    1011 = (13.6875)
//                   4bits 			 4bits 
//                    13        .    6875
//Les 4 premiers bits ici represente l'entier 13 et ce qui est apres le point represente les 4 derniers bits qui
//sont la partie fractionnaire 6875

// 4bits = 16 valeur car 2puissance4 = 16 donc 16 combinaison possible 
// 1 Octet = 8 bits 
// nbr(nb << Bits) reviens a multiplier le nombre par 256 (2puissance8) 2 pour le systeme binaire (0-1) et 8 car on a init bits a 8
// Ici, nbr(nb << Bits)' effectue un décalage à gauche de 'nb' par 8 bits.
// Cela revient à multiplier 'nb' par 2^8 (ou 256), car dans le système binaire, décaler un nombre à gauche de n bits le multiplie par 2^n.
// '2' vient de la base du système de numération binaire (0 et 1), et '8' est la valeur que nous avons attribuée à 'Bits'.
