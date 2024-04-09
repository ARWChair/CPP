/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:00:47 by yatabay           #+#    #+#             */
/*   Updated: 2023/09/19 22:39:59 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contacts::Contacts() {}

Contacts::Contacts(std::string firstName, std::string lastName, std::string nickName, std::string secret, std::string number) {
	setFirstName(firstName);
	setLastName(lastName);
	setNickName(nickName);
	setSecret(secret);
	setPhoneNumber(number);
}

void	Contacts::setFirstName(std::string name){
	this->firstName = name;
}

void	Contacts::setLastName(std::string name){
	this->lastName = name;
}

void	Contacts::setNickName(std::string name){
	this->nickName = name;
}

void	Contacts::setSecret(std::string secret){
	this->secret = secret;
}

void	Contacts::setPhoneNumber(std::string number){
	this->phoneNumber = number;
}

std::string	Contacts::getFirstName(){
	return firstName;
}

std::string	Contacts::getLastName(){
	return lastName;
}

std::string	Contacts::getNickName(){
	return nickName;
}

std::string	Contacts::getSecret(){
	return secret;
}

std::string	Contacts::getPhoneNumber(){
	return phoneNumber;
}
