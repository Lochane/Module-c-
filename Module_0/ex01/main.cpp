#include "Phonebook.class.hpp"

int main()
{
	PhoneBook book;

	book.index = 0;
	while(book.input.compare("EXIT") && std::cin.eof() == 0)
	{
		if (book.input.compare("ADD") == 0)
			book.add_contact(&book);
		// else if (book.input.compare("SEARCH") == 0)
		// 	book.search_contact(&book);
		std::cout << "✿ Please enter a command ~> ";
		std::cin >> book.input;
	}
}