#include <array>
#include <string>
#include <vector>
#include <cmath>

std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> roundedScores;

    for (int i : student_scores) {
        roundedScores.push_back(static_cast<int>(i));
    }
    return roundedScores;
}


int count_failed_students(std::vector<int> student_scores) {
    std::vector<int> failed;
    for (int i : student_scores) {
        if (i <= 40) {
            failed.push_back(i);
        }
    }
    return failed.size();
}

std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
    std::vector<int>the_best{};
    for(int i: student_scores) {
        if (i >= threshold) {
            the_best.push_back(i);
        }
    }
    return the_best;
}

std::array<int, 4> letter_grades(int highest_score) {
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 41;

    num2 += ceil((highest_score + 41.0) / 2.0);
    num1 += ceil((highest_score + num2) / 2.0);
    num3 += (num2 + num4) / 2.0;
    std::array<int, 4> arr_scores{num4, num3, num2, num1};

    return arr_scores;
}

std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> tierList{};

    for(int i = 0; i < student_names.size(); i++) {

        int num = 1;
        num += i;
        std::string rank1 = std::to_string(num) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]);
        tierList.emplace_back(rank1);
    }
    return tierList;
}

std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::string valedictorian = "";
    for(int i = 0; i < student_scores.size(); i++) {
        if(student_scores[i] == 100) {
            return valedictorian = student_names[i];

        }
    }
    return valedictorian;
}
