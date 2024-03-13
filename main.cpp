#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <cstdlib>


using namespace std;

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

        int randomIndex = rand() % words.size();
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
    srand((unsigned) time(NULL));
    const vector<string> words = { "computer", "science", "test" };
    string randomWord = RandomWordChooser(words).chooseRandomWord();

    cout << "Random word: " << randomWord << endl;
    return 0;
}
