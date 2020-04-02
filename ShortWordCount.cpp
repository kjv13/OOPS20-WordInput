/*
    ShortWordCount.cpp

    Summarize usage frequencey of English language short words(less than 4 characters)
*/

#include <iostream>
#include <fstream>
#include <string>
#include "WordReader.hpp"

int main(int argc, char *argv[])
{

    // require filename
    if (argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    // number of each English language short words
    int ShortWordCount = 0;

    // count the short words from the input file
    WordReader reader(
        [&](const std::string &word) -> void {
            if (word.length() < 4)
                ++ShortWordCount;
        });
    std::ifstream in(argv[1]);
    reader.run(in);

    // output report on English-language short words
    std::cout << "  Number of short words "
              << ": " << ShortWordCount << '\n';

    return 0;
}
