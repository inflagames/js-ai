#ifndef JS_AI_PARSER_H
#define JS_AI_PARSER_H

#include "scanner.h"
#include "ast_tree.h"
#include "exceptions.h"
#include "lsp_protocol.h"
#include "goto.h"
#include <memory>

#define MATERIAL_BLOCK 1
#define PROGRAM_VERTEX_BLOCK 2
#define PROGRAM_FRAGMENT_BLOCK 3
#define TECHNIQUE_BLOCK 4
#define PASS_BLOCK 5
#define TEXTURE_UNIT_BLOCK 6
#define RTSHADER_BLOCK 7

namespace OgreScriptLSP {
    class Parser {
    private:
        std::unique_ptr<Scanner> scanner;

        std::vector<TokenValue> tokens;
        int currentToken = 0;

        std::unique_ptr<MaterialScriptAst> script;
        std::map<std::pair<int, std::string>, TokenValue> declarations;

        std::vector<BaseException> exceptions;

    public:
        std::string uri;

        Parser();

        ~Parser() = default;

        MaterialScriptAst *getScript() { return script.get(); }

        [[nodiscard]] const Scanner *getScanner() const;

        [[nodiscard]] std::unique_ptr<std::map<std::pair<int, std::string>, TokenValue>> getDeclarations() const {
            auto decl = std::make_unique<std::map<std::pair<int, std::string>, TokenValue>>(declarations);
            return decl;
        }

        std::vector<BaseException> getExceptions() {
            return exceptions;
        }

        void loadScript(const std::string &fileUri, const std::string &code = "");

        static std::string uriToPath(const std::string &uri);

        void parse(const std::string &fileUri);

        void parse();

        // IMPORT STATEMENT
        void importBlock(MaterialScriptAst *scriptAst);

        // ABSTRACT STATEMENT
        void abstract(MaterialScriptAst *scriptAst);

        // PROGRAM STATEMENT
        void program(MaterialScriptAst *scriptAst);

        void programOpt(ProgramAst *program);

        void programBody(ProgramAst *program);

        void programDefaults(ProgramAst *program);

        // MATERIAL STATEMENT
        void material(MaterialScriptAst *scriptAst);

        void materialBody(MaterialAst *material);

        void materialTechnique(MaterialAst *material);

        void materialTechniqueBody(TechniqueAst *technique);

        void materialPass(TechniqueAst *technique);

        void materialPassBody(PassAst *pass);

        void materialTexture(PassAst *pass);

        void materialTextureBody(TextureUnitAst *texture);

        void materialRtShader(OgreScriptLSP::PassAst *pass);

        void materialRtShaderBody(OgreScriptLSP::RtShaderAst *shader);

        void materialProgramRef(PassAst *pass);

        void materialProgramRefBody(MaterialProgramAst *programRef);

        // THIS IS COMMON SECTION
        void paramsLine(ParamAst *params);

        /**
         * current token
         */
        TokenValue getToken();

        void recuperateLine();

        void nextTokenAndConsumeEndLines();

        void consumeOpenCurlyBracket();

        void consumeCloseCurlyBracket();

        void consumeToken(Token token, std::string errorMessage, bool consumeEndLines = false);

        void nextToken();

        void consumeEndLines();

        bool isEof();

        void initSwap();

        void registerDeclaration(AstObject *object, int type);

        bool isMainStructure();

        void
        objectDefinition(AstObject *astObject, std::string error1, std::string error2, bool notTopLevelObject = false);
    };
}


#endif //JS_AI_PARSER_H
