# IntentRecognizer
The idea is to be able to ask a set of predefined questions and accurately recognize the intent of the user. The predefined intents are the following:

* What is the weather like today? => Prints (Intent: Get Weather)
* What is the weather like in Paris today? => Prints (Intent: Get Weather City)
* What is the weather like in New York today? => Prints (Intent: Get Weather City)
* Am I free at 13:00 PM tomorrow? ==> Prints (Intent: Check calendar)
* Tell me an interesting fact. => Prints (Intent: Get Fact)

Requirements:
CMake : https://cmake.org/

Prerequisites:
1. Minimum CMake Version 3.10
2. Googletest should be cloned using git clone https://github.com/google/googletest/
3. copy googletest cloned in Step 2. to directory to /IntentRecognizer (parent directory)

#### Steps to build the project:

1. Install **cmake ** (details on the website mentioned above)
2. mkdir build
3. cd build
4. cmake ..
5. make

#### Steps to run the unit test:
1. cd build/test
2. ./intent_test

#### Steps to run the code:
1. cd build
2. ./IntentRecognizer 

