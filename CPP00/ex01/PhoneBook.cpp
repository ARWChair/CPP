/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:00:38 by yatabay           #+#    #+#             */
/*   Updated: 2023/09/22 18:59:56 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"


Contacts	create() {
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	secret;
	std::string	phoneNumber;

	std::cout << std::endl << "Firstname: ";
	std::cin >> firstName;
	std::cout << "Lastname: ";
	std::cin >> lastName;
	std::cout << "Nickname: ";
	std::cin >> nickName;
	std::cout << "Secret: ";
	std::cin >> secret;
	std::cout << "Phone: ";
	std::cin >> phoneNumber;
	std::cout << std::endl;
	Contacts contact(firstName, lastName, nickName, secret, phoneNumber);
	return contact;
}

void	add(Contacts *contacts, int *amount) {
	static int index;

	if (index < 9)
		index++;
	if (index == 9) {
		for (int i = 0; i < 7; i++)
			contacts[i] = contacts[i + 1];
		index--;
	}
	*amount = index;
	contacts[index - 1] = create();
}

std::string	display(std::string str) {
	int len = str.size();

	if (len > 10) {
		str.resize(10);
		str[9] = '.';
	} else {
		while (len++ < 10)
			str = " " + str;
	}
	return str;
}

void	search(Contacts contacts[], int amount) {
	std::cout << "╔═══════════ Phonebook Contacts ═══════════╗" << std::endl;
	for(int i = 0; i < amount; i++) {
		std::cout << "╠ " << "       " << i + 1 << "" << "|" << display(contacts[i].getFirstName()) << "|" << display(contacts[i].getLastName()) << "|" << display(contacts[i].getNickName()) << "╣" << std::endl;
	}
	std::cout << "╚══════════════════════════════════════════╝" << std::endl;
}

int	main() {
	Contacts contacts[8];
	std::string word;
	int	amount = 0;

	while (!std::cin.eof()) {
		std::cin >> word;
		if (word == "ADD")
			add(contacts, &amount);
		else if (word == "SEARCH")
			search(contacts, amount);
		else if (word == "EXIT")
			break;
		else
			std::cout << "Wrong input" << std::endl << std::endl;
	}
	return 0;
}

