#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class CsvIterator {
    std::vector<std::vector<std::string>>& vec;
    int index;

public:

    CsvIterator(std::vector<std::vector<std::string>>& vec, int index) : vec(vec), index(index) {
    }

    bool operator!=(const CsvIterator& other) {
        return index != other.index;
    }

    CsvIterator& operator++() {
        index++;
        return *this;
    }

    std::vector<std::string> operator*() {
        return vec[index];
    }
};

class CsvReader {

    std::ifstream& file;
    std::vector<std::vector<std::string>> vec;

public:
    CsvReader(std::ifstream& file) : file(file) {
        read();
    }

    std::vector<std::string> split(std::string secventa) {

        std::vector<std::string> v;
        std::string secventa2;

        for (int i = 0; i <= secventa.size(); i++) {

            if (secventa[i] == '"') {
                i++;
                while (secventa[i] != '"') {
                    secventa2 += secventa[i];
                    i++;
                }
                v.push_back(secventa2);
                secventa2.resize(0);
            }

            else {
                if (secventa[i] == ',' || i == secventa.size()) {
                    v.push_back(secventa2);
                    secventa2.resize(0);
                }
                else {
                    secventa2 += secventa[i];
                }
            }
        }
        return v;
    }

    void read() {
        std::string line;
        while (std::getline(file, line)) {
            vec.push_back(split(line));
        }
    }

    CsvIterator begin() {
        return { vec, 0 };
    }

    CsvIterator end() {
        return { vec,(int)vec.size() };
    }
};


struct Episode {
    std::string title;
    std::string date;
    std::string length;
    std::string viewersmm;
    std::string score;
};