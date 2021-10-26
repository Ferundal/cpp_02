#ifndef _Fixed_hpp_
#define _Fixed_hpp_

# include <string>
# include <iostream>

class Fixed {
private:
	int					value;
	static const int	point_bits = 8;
public:
	Fixed( void );
	Fixed( const Fixed& origin);
	Fixed& operator =(const Fixed& origin);
	~Fixed( void );

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};
#endif