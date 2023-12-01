#include "Sample.hpp"

Test::Test(void)
{
	//cosica = 2;

	this->cosica = 5;
	
	std::cout << "Calling constructor, zokete" << std::endl;
	std::cout << "la movida" << cosica << std::endl;

	std::cout << "llamo a la funsion en el constructor: ";
	this->funsion(this->cosica);
	return ;
}

Test::~Test(void)
{
	std::cout << "Destructor fucked up everything" << std::endl;
	return ;
}

void	Test::funsion(int cosica)
{
		this->cosica = cosica;
		std::cout << "te printeo esta movida: " << this->cosica << std::endl;

}