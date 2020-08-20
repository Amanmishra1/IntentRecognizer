#include "BasicRecognizer.h"

BasicRecognizer::BasicRecognizer()
{  
    basic_intent_.emplace_back(std::make_pair(std::regex(R"(What('s| is) the weather like( today| tomorrow| in (two|three|four|five|six) days)?\?)",std::regex::icase), Intent::kGet_Weather));
    basic_intent_.emplace_back(std::make_pair(std::regex(R"(What('s| is) the weather like in (Munich|Berlin|Stuttgart|Paris)( today| tomorrow| in (two|three|four|five|six) days)?\?)",std::regex::icase), Intent::kGet_Weather_City));
    basic_intent_.emplace_back(std::make_pair(std::regex(R"(Am I free at .* (AM|PM)( today| tomorrow)?\?)",std::regex::icase), Intent::kCheck_Calender));
    basic_intent_.emplace_back(std::make_pair(std::regex("(.*interesting fact.*)",std::regex::icase), Intent::kGet_Fact));
    basic_intent_.emplace_back(std::make_pair(std::regex("(.*)",std::regex::icase), Intent::kUnknown));
}

const Intent BasicRecognizer::getIntent(const std::string &input_sentence) const
{
    const auto isFound = std::find_if(basic_intent_.cbegin(), basic_intent_.cend(), [&input_sentence](const auto &entry) -> bool 
                         { return std::regex_match(input_sentence, entry.first); });

    // If sentence does not match, return Unknown
    if (isFound == basic_intent_.cend())
    {
        return  Intent::kUnknown; 
    }

    return isFound->second;
}
