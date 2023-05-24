#include "Contact.h"

int main()
{
	Agenda agenda;

	Contact* contact1 = new Prieten("Ion", "01/01/1990", "Adresa 1", 123456789);
	Contact* contact2 = new Cunoscut("Vasile", 97812345);
	Contact* contact3 = new Coleg("Ana", 182930456, "Adresa 2", "Lancome");

	agenda.adauga_contact(contact1);
	agenda.adauga_contact(contact2);
	agenda.adauga_contact(contact3);

	// Cutare contact
	std::string NumeDeCautat = "Ion";
	bool rezultat = agenda.cautare_contact(NumeDeCautat);
	if (rezultat == true)
		std::cout << "Contactul " << NumeDeCautat << " a fost gasit." << std::endl;
	else
		std::cout << "Contactl " << NumeDeCautat << " nu a fost gasit." << std::endl;


	// Stergere contact
	std::string NumeDeSters = "Ana";
	agenda.sterge_contact(NumeDeSters);
	std::cout << "Contactul " << NumeDeSters << " a fost sters." << std::endl;

	// Lista de prieteni
	std::list<Prieten*> prieteni = agenda.lista_prieteni();
	std::cout << "Lista de prieteni: " << std::endl;
	for (auto prieten : prieteni)
	{
		std::cout << prieten->getName() << std::endl;
	}
}