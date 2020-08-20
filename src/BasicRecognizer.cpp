#include "BasicRecognizer.h"

BasicRecognizer::BasicRecognizer()
{  
    basic_intent_.push_back(std::make_pair(std::regex(R"(What('s| is) the weather like( today| tomorrow| in (two|three|four|five|six) days)?\?)",std::regex::icase), Intent::kGet_Weather));
    basic_intent_.push_back(std::make_pair(std::regex(R"(What('s| is) the weather like in (Munich|Berlin|Stuttgart|Paris)( today| tomorrow| in (two|three|four|five|six) days)?\?)",std::regex::icase), Intent::kGet_Weather_City));
    basic_intent_.push_back(std::make_pair(std::regex(R"(Am I free at .* (AM|PM)( today| tomorrow)?\?)",std::regex::icase), Intent::kCheck_Calender));
    basic_intent_.push_back(std::make_pair(std::regex("(.*fact.*)",std::regex::icase), Intent::kGet_Fact));
    basic_intent_.push_back(std::make_pair(std::regex("(.*)",std::regex::icase), Intent::kUnknown));
}

const Intent BasicRecognizer::getIntent(const std::string &input_sentence) const
{
    const auto isFound = std::find_if(basic_intent_.cbegin(), basic_intent_.cend(), [&input_sentence](const auto &entry) -> bool 
                         { return std::regex_match(input_sentence, entry.first); });

    // If sentence matches regex return enum class value
    if (isFound == basic_intent_.cend())
    {
        return  Intent::kUnknown; 
    }

    return isFound->second;
}
