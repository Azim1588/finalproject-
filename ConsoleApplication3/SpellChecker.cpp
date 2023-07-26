#include "SpellChecker.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

// Constructor: Reads the dictionary file and populates the dictionary set.
SpellChecker::SpellChecker(const std::string& dictionary_file) {
    std::ifstream file(dictionary_file);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the dictionary file.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Convert each word in the dictionary to lowercase to make the spell-checking case-insensitive.
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        dictionary.insert(line); // Insert the word into the dictionary set.
    }

    file.close(); // Close the file after reading all words.
}

// Check if a given word is valid (present in the dictionary).
bool SpellChecker::isWordValid(const std::string& word) const {
    std::string lowerWord = word;
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
    return dictionary.find(lowerWord) != dictionary.end(); // Check if the word is in the dictionary set.
}

// Find the closest match to a given misspelled word.
std::string SpellChecker::findClosestMatch(const std::string& word) const {
    std::string lowerWord = word;
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

    int minDistance = INT_MAX; // Initialize the minimum distance to a large value.
    std::string closestMatch;

    // Iterate over each word in the dictionary to find the closest match using Damerau-Levenshtein distance.
    for (const auto& validWord : dictionary) {
        int distance = damerauLevenshteinDistance(lowerWord, validWord);
        if (distance < minDistance) {
            minDistance = distance; // Update the minimum distance.
            closestMatch = validWord; // Update the closest match word.
        }
    }

    return closestMatch; // Return the word that has the smallest Damerau-Levenshtein distance.
}

// Compute the Damerau-Levenshtein distance between two strings.
int SpellChecker::damerauLevenshteinDistance(const std::string& word1, const std::string& word2) const {
    int n = word1.size();
    int m = word2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    // Fill in the DP table using dynamic programming to compute the distance.
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0) {
                dp[i][j] = j; // Base case: If the first word is empty, we need j insertions to make it equal to the second word.
            }
            else if (j == 0) {
                dp[i][j] = i; // Base case: If the second word is empty, we need i deletions to make it equal to the first word.
            }
            else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // If the characters match, no additional operation is needed.
            }
            else {
                // If characters don't match, find the minimum of insertion, deletion, and substitution operations.
                dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });

                // Check for the transposition operation (Damerau-Levenshtein extension).
                if (i > 1 && j > 1 && word1[i - 1] == word2[j - 2] && word1[i - 2] == word2[j - 1]) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 2][j - 2] + 1);
                }
            }
        }
    }

    return dp[n][m]; // The final cell of the DP table contains the minimum distance.
}
