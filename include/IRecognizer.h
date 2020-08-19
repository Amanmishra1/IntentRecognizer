#ifndef INCLUDE_RECOGNIZER_H
#define INCLUDE_RECOGNIZER_H

#include <ostream>
#include <string>

enum class Intent {
    kUnknown = 0,
    kGet_Weather = 1,
    kGet_Weather_City = 2,
    kCheck_Calender = 3,
    kGet_Fact = 4,
};

class IRecognizer {
public:
    virtual const Intent getIntent(const std::string& input) const = 0;

    virtual ~IRecognizer() {};
};

#endif // INCLUDE_RECOGNIZER_H

