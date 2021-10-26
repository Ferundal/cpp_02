#include <iostream>

int	main()
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR;
	stringPTR = &brain;
	std::string	&stringREF = brain;
	std::cout << "\"Hi brain\" adress by string: " << &brain << std::endl;
	std::cout << "\"Hi brain\" adress by stringPTR: " << stringPTR << std::endl;
	std::cout << "\"Hi brain\" adress by stringREF: " << &stringREF << std::endl;
	std::cout << "\"Hi brain\" string by stringPTR: " << *stringPTR << std::endl;
	std::cout << "\"Hi brain\" string by stringREF: " << stringREF << std::endl;
}
