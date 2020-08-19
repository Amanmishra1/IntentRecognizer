#ifndef BASIC_RECOGNIZER_H
#define BASIC_RECOGNIZER_H

#include <IRecognizer.h>
#include <regex>
#include <vector>

class BasicRecognizer : public IRecognizer {
public:
    const Intent getIntent(const std::string& input) const override;

    BasicRecognizer();

    BasicRecognizer(BasicRecognizer const& other) = default;
    BasicRecognizer& operator=(BasicRecognizer const& other) = default;

    BasicRecognizer(BasicRecognizer&& other) = default;
    BasicRecognizer& operator=(BasicRecognizer&& other) = default;

    ~BasicRecognizer() = default;

private:
    std::vector<std::pair<std::regex, Intent>> basic_intent_; 
};

#endif // BASIC_RECOGNIZER_H