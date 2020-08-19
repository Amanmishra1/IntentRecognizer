#include "BasicRecognizer.h"

BasicRecognizer::BasicRecognizer()
    : basic_intent_{
          {std::regex(R"(What('s| is) the weather like( today| tomorrow| in (two|three|four|five|six) days)?\?)"), Intent::kGet_Weather},
          {std::regex(R"(What('s| is) the weather like in (Paris|London|Berlin|Stuttgart)( today| tomorrow| in (two|three|four|five|six) days)?\?)"), Intent::kGet_Weather_City},
          {std::regex(R"(Am I free at .*)?( today| tomorrow| in (two|three|four|five|six) days)?\?)"), Intent::kCheck_Calender},
          {std::regex(R"(.*fact.*)"), Intent::kGet_Fact},
          {std::regex(R"(.*)"), Intent::kUnknown},
      }
{
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
