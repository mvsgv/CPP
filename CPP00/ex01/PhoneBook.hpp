#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cctype>

/*
Keeping member variables private in a class is a core principle of **encapsulation** in object-oriented programming. Here’s why it’s important:
- **Control Access:** You control how data is read or modified, preventing accidental or unauthorized changes.
- **Data Integrity:** You can validate or restrict values before setting them, ensuring the object always stays in a valid state.
- **Implementation Hiding:** The internal representation can change without affecting code that uses the class, making maintenance easier.
- **Security:** Sensitive information (like a contact’s secret) is protected from direct access.
Setters and getters allow controlled, safe access to these private members.
*/
class Contact{
	private: 
		int index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		void	clear();
		/*setters*/
		int 	setIndex(int id);
		void	setFirstName(const std::string &str);
		void	setLastName(const std::string &str);
		void	setNickname(const std::string &str);
		void	setPhoneNumber(const std::string &str);
		void	setDarkestSecret(const std::string &str);
		/*getters*/
		int		getIndex() const ;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
};

class PhoneBook{
	private:
		Contact contacts[8];
		int		nextIndex;
	public:
		void ShowContacts();
		void Search();
		void Welcome(void);
		void add();
};

#endif
