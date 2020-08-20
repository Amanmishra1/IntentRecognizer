#ifndef INCLUDE_RECOGNIZER_FACTORY_H
#define INCLUDE_RECOGNIZER_FACTORY_H

#include <IRecognizer.h>
#include <memory>

/*****************************************************
Factory has been added to add future libraries easily
In future, to add AdvanceRecognizer do the following
1. Create a new function here, say, createAdvamceIntent
2. Add implementation in RecognizerAppFactory.cppp file 
3. Create a new library containing with 2 files, say,
   AdvanceRecognizer.h and AdvanceRecognizer.cpp
******************************************************/

class RecognizerFactory {
public:
    static std::unique_ptr<IRecognizer> createBasicIntent();
};

#endif // INCLUDE_RECOGNIZER_FACTORY_H
