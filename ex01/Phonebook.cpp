#include "Phonebook.hpp"

int searchOldestContact(Contact contacts[MAX_CONTACTS], int contactsCount) 
{
    if (!contactsCount) 
      return -1;
    std::time_t oldest = contacts[0].getCreationDate();
    int oldestIndex = 0;

    for (int i = 1; i < contactsCount; i++)
    {
        if (contacts[i].getCreationDate() < oldest)
        {
            oldest = contacts[i].getCreationDate();
            oldestIndex = i;
        }
    }

    return oldestIndex;
}

std::string formatField(const std::string& field) 
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void Phonebook::displayContact(int index) const 
{
    if (index < 0 || index >= _contactsCount) 
    {
        std::cout << "\033[1;31m" <<"Invalid index" << "\033[0m" << std::endl;
        return;
    }
    std::cout << "\033[1;32m" << index << std::endl;
    std::cout << "\033[1;32mName: \033[0m" << _contacts[index].getFirstName() << std::endl;
    std::cout << "\033[1;32mLastname: \033[0m" << _contacts[index].getLastName() << std::endl;
    std::cout << "\033[1;32mNickname: \033[0m" << _contacts[index].getNickname() << std::endl;
    std::cout << "\033[1;32mPhone Number: \033[0m" << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "\033[1;32mDarkest Secret: \033[0m" << _contacts[index].getDarkestSecret() << std::endl;
    
}

Phonebook::Phonebook() 
{
    _contactsCount = 0;
}

Phonebook::~Phonebook() 
{

}

int Phonebook::getNumContacts() const 
{
    return _contactsCount;
}

void Phonebook::addContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) 
{
    if (_contactsCount < MAX_CONTACTS) 
    {
      _contacts[_contactsCount] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        _contactsCount++;
    } 
    else 
    {
        int oldestIndex = searchOldestContact(_contacts, _contactsCount);
        _contacts[oldestIndex] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    }
}

void Phonebook::displayContacts() const 
{
    if (_contactsCount == 0) 
    {
        std::cout << "Phonebook is empty" << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < _contactsCount; i++) 
    {
      std::cout << "\033[1;32m" << std::setw(10) << i << "|";
      std::cout << "\033[1;32m" << std::setw(10) << formatField(_contacts[i].getFirstName()) << "\033[0m|";
      std::cout << "\033[1;32m" << std::setw(10) << formatField(_contacts[i].getLastName()) << "\033[0m|";
      std::cout << "\033[1;32m" << std::setw(10) << formatField(_contacts[i].getNickname()) << "\033[0m" << std::endl;
    }
}
