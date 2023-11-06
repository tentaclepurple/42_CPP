/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:16:30 by imontero          #+#    #+#             */
/*   Updated: 2023/11/04 20:23:16 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i = 1;
	int j = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j] == ' ')
				j++;
			while (argv[i][j])
			{	
				if (argv[i][j] == ' ' && (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0'))
					j++;
				else
				{
					std::cout << (char)(std::toupper(argv[i][j]));
					j++;
				}
			} 
			if (i != argc - 1)
				std::cout<< " ";
			i++;
		}
		std::cout << std::endl;			
	}
	return (0);
}
