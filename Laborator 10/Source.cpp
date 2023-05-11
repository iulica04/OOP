#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <fstream>

using namespace std;

class CommandManager {
private:
    map<string, function<void(vector<string>)>> commands;

public:
    void add(string name, function<void(vector<string>)> fn) {
        commands[name] = fn;
    }

    void run() {
        string tmp;
        vector<string> args;

        while (true) {
            printf("\n");

            getline(cin, tmp);
            args.clear();

            auto ptr = strtok(&tmp[0], " ");
            while (ptr) {
                args.push_back(ptr);
                ptr = strtok(nullptr, " ");
            }

            if (args.empty()) {
                // empty command, doing nothing
                continue;
            }

            auto command = args[0];
            if (command == "stop") {
                return;
            }
            auto it = commands.find(command);
            if (it == commands.end()) {
                printf("no command with that name: %s\n", command.c_str());
                continue;
            }

            // remove the command name
            args.erase(args.begin());

            try {
                it->second(args);
            }
            catch (std::exception& e) {
                fprintf(stderr, "command `%s` failed: %s\n", command.c_str(), e.what());
            }
        }
    }
};


class FileException : public std::exception {
private:
    std::string message;
public:
    explicit FileException(const std::string& fileName, const std::string& errorMessage) {
        message = "Exception occurred while working with file '" + fileName + "': " + errorMessage;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};


int main() {
    CommandManager manager;

    auto ping = [](const std::vector<std::string>& args) { std::cout << "pong!" << std::endl; };
    manager.add("ping", ping);

    auto count = [](const std::vector<std::string>& args) {
        std::cout << "counted " << args.size() << " args" << std::endl;
    };
    manager.add("count", count);

    auto times = [](const std::vector<std::string>& args) {
        static int callCount = 0;
        callCount++;
        std::cout << "times called: " << callCount << std::endl;
    };
    manager.add("times", times);

    auto copy = [](const std::vector<std::string>& args) {
        if (args.size() != 2) {
            throw FileException("copy", "Invalid number of arguments. Expected source and destination.");
        }

        const std::string& source = args[0];
        const std::string& destination = args[1];

        std::ifstream inputFile(source, std::ios::binary);
        if (!inputFile) {
            throw FileException("copy", "Failed to open source file.");
        }

        std::ofstream outputFile(destination, std::ios::binary);
        if (!outputFile) {
            throw FileException("copy", "Failed to open destination file.");
        }

        outputFile << inputFile.rdbuf();

        if (!outputFile) {
            throw FileException("copy", "Failed to write to destination file.");
        }

        std::cout << "File copied successfully from '" << source << "' to '" << destination << "'" << std::endl;
    };
    manager.add("copy", copy);
    manager.run();

    std::cout << "goodbye." << std::endl;
    return 0;
}