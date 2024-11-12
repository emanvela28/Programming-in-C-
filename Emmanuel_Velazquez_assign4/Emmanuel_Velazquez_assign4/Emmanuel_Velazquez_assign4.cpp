#include <iostream>
using namespace std;

int main() {
    // Comment 1: Make an array where we can store the correct answers.
    char correctAnswers[] = { 'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B' };

    // Comment 2: Make an array of size 20 so we can input the students answers.
    char studentAnswers[20];
    int incorrectQuestions[20];
    int numIncorrect = 0;
    cout << "Please enter the student's answers for each of the questions." << endl;
    cout << "Please Enter after typing each answer." << endl;
    cout << "Please enter only an A, B, C, or D for each question." << endl;

    // Comment 3: Ask the user to enter the student's answers for each question.
    for (int i = 0; i < 20; i++) {
        cout << "Question " << (i + 1) << ": ";
        cin >> studentAnswers[i];

        // Comment 4: Only accept 'A', 'B', 'C', or 'D' as answers.
        while (studentAnswers[i] != 'A' && studentAnswers[i] != 'B' && studentAnswers[i] != 'C' && studentAnswers[i] != 'D') {
            cout << "Invalid input. Please enter 'A', 'B', 'C', or 'D' for question " << (i + 1) << ": ";
            cin >> studentAnswers[i];
        }

        // Comment 5: Compare the student's answers to the answer key and store the wrong ones.
        if (studentAnswers[i] != correctAnswers[i]) {
            incorrectQuestions[numIncorrect] = i + 1;

            // Comment 6: Count the number of incorrect answers.
            numIncorrect++;
        }
    }

    // Comment 7: Total number of correct answers.
    int numCorrect = 20 - numIncorrect;

    // Comment 8: Display whether the student passed or failed the exam.
    if (numCorrect >= 15) {
        cout << "\nThe student passed the exam!" << endl;
    }
    else {
        cout << "\nThe student failed the exam." << endl;
    }

    // Comment 9: Display the total number of correct and incorrect answers.
    cout << "\nCorrect Answers: " << numCorrect << endl;
    cout << "Incorrect Answers: " << numIncorrect << endl;

    // Comment 10: Display the list of incorrectly answered questions.
    if (numIncorrect > 0) {
        cout << "\nQuestions that were answered incorrectly:";
        for (int i = 0; i < numIncorrect; i++) {
            cout << "\n " << incorrectQuestions[i];
        }
        cout << endl;
    }

    return 0;
}

