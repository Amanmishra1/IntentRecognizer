#include<RecognizerAppFactory.h>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    //Current implementation only inmplements "BASIC" intent
    std::unique_ptr<IRecognizer> r;
    std::string sentence;
    r = RecognizerFactory::createBasicIntent();

    std::cout<<"Enter a sentence" << std::endl;
    std::getline(std::cin, sentence);

    std::cout << "Intent: " << r->getIntent(sentence) << "\n";
    return EXIT_SUCCESS;
}
