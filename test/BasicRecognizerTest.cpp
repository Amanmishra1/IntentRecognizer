#include <gtest/gtest.h>
#include<RecognizerAppFactory.h>
#include <memory>
#include <tuple>

class IntentRecognizerFixtureTests : public ::testing::TestWithParam<std::tuple<std::string, Intent>> {
};

//Get Weather Positive test cases
INSTANTIATE_TEST_CASE_P(
        GetWeatherTests,
        IntentRecognizerFixtureTests,
        ::testing::Values(
                //Positive tests for Get Weather
                std::make_tuple("What is the weather like today?", Intent::kGet_Weather),
                std::make_tuple("WHAT IS THE WEATHER LIKE TODAY?", Intent::kGet_Weather),
                std::make_tuple("WHAT IS THE WEATHER LIKE TomoRRow?", Intent::kGet_Weather),
                std::make_tuple("WHAT's the Weather like in two days?", Intent::kGet_Weather),

                //Positive tests for Get Weather City
                std::make_tuple("What is the weather like in Paris today?", Intent::kGet_Weather_City),
                std::make_tuple("What's the weather like in Munich tomorrow?", Intent::kGet_Weather_City),
                std::make_tuple("What's THE weather LIKE in Stuttgart tomorrow?", Intent::kGet_Weather_City),
                std::make_tuple("What's THE weather LIKE in Berlin in four days?", Intent::kGet_Weather_City),

                //Positive tests for Check Calender
                std::make_tuple("Am I free at 13:00 PM tomorrow?", Intent::kCheck_Calender),
                std::make_tuple("Am I free at 14:00 PM today?", Intent::kCheck_Calender),
                std::make_tuple("Am I free at 17 PM tomorrow?", Intent::kCheck_Calender),
                std::make_tuple("AM I FREE at 02:00 AM tomorrow?", Intent::kCheck_Calender),

                //Positive tests for Get Fact
                std::make_tuple("fact", Intent::kGet_Fact),
                std::make_tuple("Tell me an interesting fact.", Intent::kGet_Fact),
                std::make_tuple("tell me one interesting fact about berlin?", Intent::kGet_Fact)
        ));

TEST_P(IntentRecognizerFixtureTests, GetWeatherTests) {
    std::unique_ptr<IRecognizer> r;
    r = RecognizerFactory::createBasicIntent();
    auto input = std::get<0>(GetParam());
    auto expected = std::get<1>(GetParam());
    EXPECT_EQ(r->getIntent(input), expected);
}
