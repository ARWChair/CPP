/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:59:53 by yatabay           #+#    #+#             */
/*   Updated: 2023/09/20 13:48:31 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Contacts {
	public:
		Contacts();
		Contacts(std::string firstName, std::string lastName, std::string nickName, std::string secret, std::string number);
		void	setFirstName(std::string name);
		void	setLastName(std::string name);
		void	setNickName(std::string name);
		void	setSecret(std::string secret);
		void	setPhoneNumber(std::string number);
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getSecret();
		std::string	getPhoneNumber();
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	secret;
		std::string	phoneNumber;
};

