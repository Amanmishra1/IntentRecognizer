#ifndef INCLUDE_RECOGNIZER_FACTORY_H
#define INCLUDE_RECOGNIZER_FACTORY_H

#include <IRecognizer.h>
#include <memory>

class RecognizerFactory {
public:
    static std::unique_ptr<IRecognizer> createBasicIntent();
};

#endif // INCLUDE_RECOGNIZER_FACTORY_H
