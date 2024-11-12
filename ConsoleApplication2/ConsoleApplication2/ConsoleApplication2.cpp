#include <iostream>
#include <iomanip>
using namespace std;

// Comment 1: Provided function that will get the score from 0.0 to 10.0 and display error message if the
//            score is not within bounds.
void getJudgeData(double& score) {
    do {
        cout << "Enter a judge's score: ";
        cin >> score;
        // Comment 2: If the score is not within the range, display the error message and take in another input.
        if (score < 0.0 || score > 10.0) {
            cout << "The score bust be between 0.0 and 10.0" << endl;
        }
    } while (score < 0.0 || score > 10.0);
}

// Comment 3: Provided function finding the lowest score, using the 5 inputes from the user
double findLowest(double score1, double score2, double score3, double score4, double score5) {
    double lowest = score1;
    // Comment 4: Setting score 1 to be the lowest by default, then comparing other scores and updating if necessary.
    if (score2 < lowest) lowest = score2;
    if (score3 < lowest) lowest = score3;
    if (score4 < lowest) lowest = score4;
    if (score5 < lowest) lowest = score5;
    return lowest;
}

// Comment 5: Provided function finding the highest score, using the 5 inputes from the user
double findHighest(double score1, double score2, double score3, double score4, double score5) {
    double highest = score1;
    // Comment 6: Setting score 1 to be the highest by default, then comparing other scores and updating if necessary.
    if (score3 > highest) highest = score3;
    if (score4 > highest) highest = score4;
    if (score5 > highest) highest = score5;
    return highest;
}

// Comment 7: Provided function to calculate and display the student's average score.
void calcScore(double score1, double score2, double score3, double score4, double score5) {
    double lowest = findLowest(score1, score2, score3, score4, score5);
    double highest = findHighest(score1, score2, score3, score4, score5);
    double total = score1 + score2 + score3 + score4 + score5 - lowest - highest;
    double average = total / 3.0;

    // Comment 8: Display the calculated average score with one decimal place.
    cout << "\nAfter dropping the lowest and highest scores, the average score was " << fixed << setprecision(1) << average << endl;
}

int main() {
    double score1;
    double score2;
    double score3;
    double score4;
    double score5;

    // Comment 9: Get scores for all five judges using the getJudgeData function.
    getJudgeData(score1);
    getJudgeData(score2);
    getJudgeData(score3);
    getJudgeData(score4);
    getJudgeData(score5);

    // Comment 10: Calculate and display the average score using the calcScore function.
    calcScore(score1, score2, score3, score4, score5);

    return 0;
}
