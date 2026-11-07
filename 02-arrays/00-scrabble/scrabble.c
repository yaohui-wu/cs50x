#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet.
const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void) {
    // Get words from both players.
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words.
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner.
    if (score1 == score2) {
        printf("Tie!\n");
    } else if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}

int compute_score(string word) {
    int score = 0;
    int length = strlen(word);

    // Compute score for letters only.
    for (int i = 0; i < length; i++) {
        char letter = word[i];

        // Use ASCII to map letters to indices 0-25.
        if (isupper(letter)) {
            score += POINTS[letter - 'A'];
        } else if (islower(word[i])) {
            score += POINTS[letter - 'a'];
        }
    }

    return score;
}
