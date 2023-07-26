# Spell Checker
### The Spell Checker is a simple C++ program that allows you to check the spelling of words and find the closest matching word in a given dictionary. It utilizes the Damerau-Levenshtein distance algorithm to compute the similarity between words.

## How it Works
### Dictionary Initialization: The spell checker reads a dictionary file containing a list of valid words. Each word in the dictionary is converted to lowercase to enable case-insensitive spell checking. The words are stored in a set data structure for efficient lookup.

### Spell Checking: Given a word, the spell checker checks if it is present in the dictionary. It first converts the input word to lowercase to ensure a case-insensitive match. If the word is present in the dictionary, it is considered valid. Otherwise, the spell checker proceeds to find the closest matching word.

### Finding Closest Match: To find the closest match, the spell checker uses the Damerau-Levenshtein distance algorithm. This algorithm calculates the minimum number of insertions, deletions, substitutions, and transpositions required to transform one word into another. The algorithm iterates through the dictionary and computes the Damerau-Levenshtein distance for each word, identifying the word with the smallest distance as the closest match.

## Usage
### Compile the program: Use a C++ compiler to compile the SpellChecker.cpp source file along with any necessary headers.

### Run the program: Execute the compiled binary and provide the path to the dictionary file as a command-line argument.

### Spell Checking: Enter a word you wish to spell-check. The program will inform you whether the word is valid (present in the dictionary) or provide the closest match if the word is misspelled.

## Dictionary File Format
The dictionary file should contain one word per line. All words should be in lowercase for accurate spell checking. Any non-alphabetic characters or uppercase letters in the dictionary file may lead to unexpected results.

