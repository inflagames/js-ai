#ifndef OGRE_SCRIPTS_LSP_LIB_SEMANTIC_TOKENS_H
#define OGRE_SCRIPTS_LSP_LIB_SEMANTIC_TOKENS_H


#include "lsp_protocol.h"
#include "parser.h"

namespace OgreScriptLSP {
    class SemanticTokens {
    public:
        static ResultArray *getSemanticTokens(Parser *parser);
    };
}


#endif //OGRE_SCRIPTS_LSP_LIB_SEMANTIC_TOKENS_H
