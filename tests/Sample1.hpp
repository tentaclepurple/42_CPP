#ifndef SAMPLE_HPP
# define SAMPLE_HPP

# include <iostream> 

class Test 
{
	public:

		int		i1;
		float 	f1;
		char	c1;
		std::string 	s1;

		Test(int num, float flo, char letr, std::string palabro);
		~Test(void);

		void	funsion(int cosica);
};

#endif
