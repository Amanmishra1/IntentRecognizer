#include <RecognizerAppFactory.h>
#include "BasicRecognizer.h"

std::unique_ptr<IRecognizer> RecognizerFactory::createBasicIntent()
{
    return std::make_unique<BasicRecognizer>();
}

