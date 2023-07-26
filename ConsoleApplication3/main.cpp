#include <iostream>
#include "SpellChecker.h"
#include <fstream>

bool fileExists(const std::string& filename);

int main() {
    std::string dictionary_file = "dictionary.txt";

    if (!fileExists(dictionary_file)) {
        std::cerr << "Error: Dictionary file not found or could not be opened.\n";
        return 1;
    }

    SpellChecker spellChecker(dictionary_file);

    if (!spellChecker.isWordValid("academig")) {
        std::cout << "The word 'academi' is misspelled. Did you mean: " << spellChecker.findClosestMatch("academig") << "?\n";
    }
    else {
        std::cout << "The word 'academig' is spelled correctly.\n";
    }

    if (!spellChecker.isWordValid("budget")) {
        std::cout << "The word 'budget' is misspelled. Did you mean: " << spellChecker.findClosestMatch("budget") << "?\n";
    }
    else {
        std::cout << "The word 'budget' is spelled correctly.\n";
    }
    if (!spellChecker.isWordValid("budgit")) {
        std::cout << "The word 'budgit' is misspelled. Did you mean: " << spellChecker.findClosestMatch("budgit") << "?\n";
    }
    else {
        std::cout << "The word 'budgit' is spelled correctly.\n";
    }

    return 0;
}


bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}