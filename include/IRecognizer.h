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

inline std::ostream& operator<<(std::ostream& s, const Intent& i) {
    switch (i) {
        case Intent::kUnknown:
            return s << "Unknown";
        case Intent::kGet_Weather:
            return s << "Get Weather";
        case Intent::kGet_Weather_City:
            return s << "Get Weather City";
        case Intent::kCheck_Calender:
            return s << "Check Calendar";
        case Intent::kGet_Fact:
            return s << "Get Fact";
    }
}
#endif // INCLUDE_RECOGNIZER_H

