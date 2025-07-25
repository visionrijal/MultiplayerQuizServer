#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

struct Question {
    int questionId;
    std::string questionText;
    std::vector<std::string> options;  // 4 options
    int correctAnswerIndex;  // 0-3

    Question() : questionId(-1), correctAnswerIndex(-1) {}
    Question(int id, const std::string& text, const std::vector<std::string>& opts, int correct)
        : questionId(id), questionText(text), options(opts), correctAnswerIndex(correct) {}

    // Basic getters
    int getQuestionId() const { return questionId; }
    std::string getQuestionText() const { return questionText; }
    std::vector<std::string> getOptions() const { return options; }
    int getCorrectAnswerIndex() const { return correctAnswerIndex; }
    std::string getCorrectAnswer() const { 
        return (correctAnswerIndex >= 0 && correctAnswerIndex < static_cast<int>(options.size())) 
               ? options[correctAnswerIndex] : ""; 
    }

    // Check if answer is correct
    bool isCorrectAnswer(int answerIndex) const { 
        return answerIndex == correctAnswerIndex; 
    }

    // Get number of options
    int getOptionCount() const { return static_cast<int>(options.size()); }
};

#endif // QUESTION_H 