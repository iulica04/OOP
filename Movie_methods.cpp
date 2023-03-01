#include "Movie_Methods.h"

void Movie::set_name(const char* Name)
{
	strcpy(name, Name);
}

void Movie:: set_score(const double number)
{
	if(number>=1.0 && number<=10.0)
		score = number;
}

void Movie::set_passed_years()
{
	passedYears = 2023 - year;
}

void Movie::set_year(const int number)
{
	year = number;
	set_passed_years();
}

void Movie::set_length(const int number)
{
	length = number;
}

 const char* Movie::get_name()
{
	return name;
}

 const double Movie::get_score()
 {
	 return score;
 }

 const int Movie::get_year()
 {
	 return year;
 }

 const int Movie::get_length()
 {
	 return length;
 }

 int Movie::get_passed_years()
 {
	 return passedYears;
 }

 void MovieSeries::init()
 {
	 count = 0;
 }

 void MovieSeries::add(Movie* M)
 {
	 serie[count++] = M;

 }

 void MovieSeries::print()
 {
	 for (int i = 0; i < count; i++)
		 printf(
			 R"(
name        : %s
year        : %d
score       : %f
length      : %d
passed years: % d
count: %d
)",
serie[i]->get_name(),
serie[i]->get_year(),
serie[i]->get_score(),
serie[i]->get_length(),
serie[i]->get_passed_years(),
count);
 }

 void MovieSeries::sort()
 {
	 for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
			 if (serie[i]->get_passed_years() < serie[j]->get_passed_years())
			 {
				 Movie* aux = serie[i];
				 serie[i] = serie[j];
				 serie[j] = aux;
			 }
 }