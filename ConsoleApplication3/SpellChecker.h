#include <string>
#include <unordered_set>

class SpellChecker {
public:
    SpellChecker(const std::string& dictionary_file);

    bool isWordValid(const std::string& word) const;
    std::string findClosestMatch(const std::string& word) const;

private:
    int damerauLevenshteinDistance(const std::string& word1, const std::string& word2) const;
    std::unordered_set<std::string> dictionary;
};