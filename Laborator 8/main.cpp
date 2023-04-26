#include<string>
#include<fstream>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<utility>

//I bought an apple. Then I eat an apple. Apple is my favorite.
//012345678911111111122
//          02345678901

int main()
{
	std::string sir;
	std::ifstream file;

	file.open("date.txt");
	if (!file.is_open()) {
		return 1;
	}

	std::getline(file, sir);

	std::vector<std::string> words;
	std::string separator = ".,!? ";

	std::string::size_type poz1 = 0;
	std::string::size_type poz2 = 0;

	while ((poz1 = sir.find_first_of(separator, poz2)) != std::string::npos)
	{
		if (poz1 != poz2)
		{
			std::string word = sir.substr(poz2, poz1 - poz2);
			std::string::iterator ch;
			for (ch = word.begin(); ch < word.end(); ch++)
			{
				*ch = std::tolower(*ch);
			}
			words.push_back(word);
		}
		poz2 = poz1 + 1;
	}

	std::map<std::string, int> Words;

	std::vector<std::string>::iterator it;
	for (it = words.begin(); it < words.end(); it++)
		Words[*it]++;

	auto compare = [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
	{
		if (a.second != b.second)
			return a.second < b.second;
		else
			return a.first > b.first;
	};

	std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(compare)> WORDS(compare);


	for (const auto& IT : Words)
		WORDS.push(IT);

	while (!WORDS.empty())
	{
		auto p = WORDS.top();
		std::cout << p.first << " => " << p.second << std::endl;
		WORDS.pop();
	}

	file.close();
	return 0;
}