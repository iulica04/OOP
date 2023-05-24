#pragma once
#include <iostream>
#include <string>
#include <list>

enum class Type
{
	Prieten,
	Cunoscut,
	Coleg
};

class Contact
{
private:
	std::string nume;
public:
	Contact(const std::string& nume) : nume(nume) {};

	
	std::string getName() const
	{
		return nume;
	}

	virtual Type getType() const = 0;
};

class Prieten : public Contact
{
private:
	std::string DataNastere;
	std::string Adresa;
	long int NumarTelefon;
public:
	Prieten(const std::string& nume, const std::string& DataNastere, const std::string& Adresa, const long int NumarTelefon) :
		Contact(nume),
		DataNastere(DataNastere),
		Adresa(Adresa),
		NumarTelefon(NumarTelefon) {};

	std::string getDataNastere() const
	{
		return DataNastere;
	}
	std::string getAdresa() const
	{
		return Adresa;
	}
	long int getNumarTelefon() const
	{
		return NumarTelefon;
	}

	Type getType() const override
	{
		return Type::Prieten;
	}
};

class Cunoscut : public Contact
{
private:
	long int NumarTelefon;
public:
	Cunoscut(const std::string& nume, const long int NumarTelefon) : 
		Contact(nume), 
		NumarTelefon(NumarTelefon) {};

	long int getNumarTelefon() const
	{
		return NumarTelefon;
	}

	Type getType() const override
	{
		return Type::Cunoscut;
	}
};

class Coleg : public Contact
{
private:
	long int NumarTelefon;
	std::string Adresa;
	std::string Firma;
public:
	Coleg(const std::string& nume, const long int NumarTelefon, const std::string& Adresa, const std::string& Firma) :
		Contact(nume),
		NumarTelefon(NumarTelefon),
		Adresa(Adresa),
		Firma(Firma) {};

	long int getNumarTelefon() const
	{
		return NumarTelefon;
	}
	std::string getAdresa() const
	{
		return Adresa;
	}
	std::string getFirma() const
	{
		return Firma;
	}

	Type getType() const override
	{
		return Type::Coleg;
	}
};

class Agenda
{
private:
	std::list<Contact*> contacte;
public:
	bool cautare_contact(const std::string& nume)
	{
		for (auto contact : contacte)
		{
			if (contact->getName() == nume)
				return true;
		}
		return false;
	}

	void sterge_contact(const std::string& nume)
	{
		for (auto it = contacte.begin(); it != contacte.end(); it++)
		{
			if ((*it)->getName() == nume)
			{
				delete* it;
				contacte.erase(it);
				break;
			}
		}
	}

	void adauga_contact(Contact* contact)
	{
		contacte.push_back(contact);
	}

	std::list<Prieten*> lista_prieteni()
	{
		std::list<Prieten*> prieteni;
		for (auto contact : contacte)
		{
			if (contact->getType() == Type::Prieten)
				prieteni.push_back(static_cast<Prieten*>(contact));
		}
		return prieteni;
	}

	~Agenda()
	{
		for (auto contact : contacte)
			delete contact;
	}
};

