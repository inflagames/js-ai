//
// Created by guille on 21.01.24.
//

#ifndef JS_AI_PARSER_H
#define JS_AI_PARSER_H

#include "scanner.h"

namespace OgreScriptLSP {
    class Parser {
    private:
        Scanner *scanner;

    public:
        Parser();

        void loadScript(const std::string &scriptFile);

        void parse();
    };
}


#endif //JS_AI_PARSER_H
