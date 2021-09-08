// Andrew Player, Robert Lawton, Gannon Higgins
// Project 8
// 11/30/2020
// Source for Project 8, Part A

#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

// Adds up the number of distince words in a string
// and returns the total count and individual counts
// in a formatted string.
// Preconditions:
//  None
// Guarantee:
//  No-Throw Guarantee
std::string count_words(const std::string& str) {

    std::map<std::string, int> m = {};

    std::istringstream is(str);
    std::string word;
    while (is >> word) {
        auto f = m.find(word);
        // If its in the map, increment its value
        // If not, insert the word and 1
        if (f != m.end()) {
            f->second += 1;
        }
        else {
            m.insert(std::pair<std::string, int>({ word, 1 }));
        }
    }

    std::ostringstream counts;
    int distinct = 0;
    for (auto p : m) {
        distinct++;
        counts << p.first << ": " << p.second << "\n";
    }

    std::string final_count = "Number of distinct words: " // Number of distince words: x
        + std::to_string(distinct)    // 
        + "\n\n"                      // word1: 1
        + counts.str();               // ...

    return final_count;
}

int main() {

    std::string filename;
    std::cout << "Enter a Filname: ";
    std::getline(std::cin, filename);

    std::ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        std::cout << "Error opening: \"" << filename << "\"" << std::endl;
    }
    else {
        std::ostringstream os;
        std::string line;
        while (std::getline(file, line)) {
            os << line;
        }
        std::cout << count_words(os.str()) << std::endl;
    }

    return 0;
}