#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

double coleman_liau(int letters, int words, int sentences);
void count_text(string text, int counts[]);

int main(void) {
    string text = get_string("Text: ");

    // counts stores letters, words, and sentences at indices 0, 1, and 2.
    int counts[3] = {0};
    count_text(text, counts);
    // Number of letters, words, and sentences in the text.
    int letters = counts[0];
    int words = counts[1];
    int sentences = counts[2];

    // Coleman-Liau index
    double index = coleman_liau(letters, words, sentences);
    // Grade level of the text.
    int grade = (int)round(index);

    if (grade > 16) {
        printf("Grade 16+");
    } else if (grade < 1) {
        printf("Before Grade 1");
    } else {
        printf("Grade %d", grade);
    }
    printf("\n");

    return 0;
}

void count_text(string text, int counts[]) {
    int i = 0;
    bool inside_word = false;

    // Count letters, words, and sentences in one pass through the text.
    while (text[i] != '\0') {
        char character = text[i];

        if (isalpha(character)) {
            counts[0] += 1;
        }

        if (isspace(character)) {
            inside_word = false;
        } else if (!inside_word) {
            // First non-whitespace character starts a word.
            counts[1] += 1;
            inside_word = true;
        }

        if (character == '.' || character == '!' || character == '?') {
            counts[2] += 1;
        }

        i += 1;
    }
}

double coleman_liau(int letters, int words, int sentences) {
    // Avoid division by zero for empty or whitespace-only text.
    if (words == 0) {
        return 0.0;
    }

    // Average number of letters per 100 words.
    double average_letters = letters * 100.0 / words;
    // Average number of sentences per 100 words.
    double average_sentences = sentences * 100.0 / words;

    // Calculate Coleman-Liau index
    return 0.0588 * average_letters - 0.296 * average_sentences - 15.8;
}
