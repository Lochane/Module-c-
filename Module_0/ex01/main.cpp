#include "Phonebook.class.hpp"

// TODO modif file name

int main() {
    PhoneBook book;
    book.index = 0;

    while (true) {     
        if (std::cin.eof())
			break ;
        std::cout << "✿ Enter a command ~> ";
        std::getline(std::cin, book.input);

        if (book.input.compare("EXIT") == 0 || std::cin.eof()) {
            break;
        } else if (book.input.compare("ADD") == 0) {
            book.add_contact(&book);
        } else if (book.input.compare("SEARCH") == 0) {
            book.search_contact(&book);
        } else {
            std::cout << "Unknown command. Please enter 'ADD', 'SEARCH', or 'EXIT'.\n";
        }
    }

    return 0;
}
