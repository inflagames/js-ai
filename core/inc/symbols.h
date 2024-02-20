#ifndef OGRE_SCRIPTS_LSP_LIB_SYMBOLS_H
#define OGRE_SCRIPTS_LSP_LIB_SYMBOLS_H


#include "lsp_protocol.h"
#include "parser.h"

namespace OgreScriptLSP {
    class Symbols {
        static ResultArray *getSymbols(Parser* parser);
    };
}


#endif //OGRE_SCRIPTS_LSP_LIB_SYMBOLS_H
