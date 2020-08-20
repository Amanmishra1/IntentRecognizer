#include<RecognizerAppFactory.h>
#include<BasicRecognizer.h>

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    //Current implementation only inmplements "BASIC" intent
    std::unique_ptr<IRecognizer> r;
    std::string sentence;
    r = RecognizerFactory::createBasicIntent();

    std::cout<<"Enter your sentence" << std::endl;
    std::getline(std::cin, sentence);

    std::cout << "Your input is" << std::endl;
    std::cout << sentence;

    std::cout << "Intent: " << r->getIntent(sentence) << "\n";
    return EXIT_SUCCESS;
}
