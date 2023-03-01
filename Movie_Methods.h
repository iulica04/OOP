#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

class Movie
{
private:

	char name[257];
	int year;
	double score;
	int length;
	int passedYears;  

public:

	void set_name(const char* Name);
	void set_score(const double number);
	void set_year(const int number);
	void set_length(const int number);
	void set_passed_years();

	const char* get_name();
	const double get_score();
	const int get_year();
	const int get_length();
    int get_passed_years();

};

class MovieSeries
{
private:
	Movie* serie[16];
	int count = 0;
public:
	void init();
	void add(Movie* M);
	void print();
	void sort();

};