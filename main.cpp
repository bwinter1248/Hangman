#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "statesQueue.h"


using namespace std;

vector<string> words = { "computer", "science", "test" };

class RandomNumberGenerator {
public:
    RandomNumberGenerator(const vector<string>& vec) : distribution(0, words.size() - 1), generator(rd()) {}

    int generateRandomIndex() {
        return distribution(generator);
    }

private:
    random_device rd;
    mt19937 generator;
    uniform_int_distribution<> distribution;
};

class RandomWordChooser {
private:
    vector<string> words;

public:
    // Constructor
    RandomWordChooser(const vector<string>& wordVector) : words(wordVector) {}

    // Method to choose a random word
    string chooseRandomWord() {
        if (words.empty())
            return "";

        RandomNumberGenerator rng(words);


        int randomIndex = rng.generateRandomIndex();
        return words[randomIndex];
    }
};

char make_guess()
{
    char c;
    cout << "\nEnter your guess:\n";
    cin >> c;

    // todo check if c is a valid letter!
    return c;
};

void AddQueue(const string hangmanPic1[], int size) {
    StateQueue<std::string> q;
    for (int i = 0; i < size; i++) {
        q.enqueue(hangmanPic1[i]);
    }
}
// Art Credit - https://gist.github.com/chrishorton/8510732aa9a80a03c829b09f12e20d9c
const string hangmanPic[7] = {
        " +---+\n"
        " |   |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        " |   |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|   |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "/    |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "/ \\  |\n"
        "     |\n"
        "=========="
};


int main() {
    string randomWord = RandomWordChooser(words).chooseRandomWord();
    AddQueue(hangmanPic, 7);

    cout << "Random word: " << randomWord << endl;
    return 0;
}
