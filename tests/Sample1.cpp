#include "Sample1.hpp"

Test::Test(int num, float flo, char letr, std::string palabro) : i1(num), f1(flo), c1(letr), s1(palabro)
{
	//cosica = 2;

	std::cout << "llamo a la funsion en el constructor: " << std::endl;
	
	
	std::cout << "el a1: " << this->i1 << std::endl;
	std::cout << "el f1: " << this->f1 << std::endl;
	std::cout << "el c1: " << this->c1 << std::endl;
	std::cout << "el strin: " << this->s1 << std::endl;

	



	return ;
}

Test::~Test(void)
{
	std::cout << "Destructor fucked up everything" << std::endl;
	return ;
}

void	Test::funsion(int cosica)
{

		std::cout << "te printeo esta movida: " << std::endl;

}