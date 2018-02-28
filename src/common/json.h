#ifndef JSONPARSER_LIBRARY_H
#define JSONPARSER_LIBRARY_H


#include <cstdio>
#include <fstream>
#include <sstream>
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

namespace MyJson{
    class Input {
        std::unique_ptr<std::istream> stream;
    public:
        int c;
    public:

        void loadString(std::string str) {
            this->stream = std::make_unique<std::stringstream>(str);
        }

        void loadFile(std::string filePath) {
            this->stream = std::make_unique<std::ifstream>(filePath);
        }

        int nextChara() {
            c = this->stream->get();
            return c;
        }

        bool eof() {
            return this->stream->eof();
        }
    };

    enum class CharaType {
        Digital,
        Alphabet,
        Quote,
        WhiteSpace,
        Symbol,
        CharaError,
    };

    struct Token {
    public:
        enum class Type {
            Number,
            String,
            Bool,
            Null,
            LeftSquareBracket,
            RightSquareBracket,
            LeftCurlyBracket,
            RightCurlyBracket,
            Colon,
            Conma,
            None,
        };
        Token::Type type;
        std::string str;
        int num;
        bool b;

        Token(const std::string &str) : type(Type::String) {
            new(&this->str) std::string(str);
        }

        Token(int num) : type(Type::Number), num(num) {}

        Token(bool b) : type(Type::Bool), b(b) {}

        Token(Type type) : type(type) {}

        ~Token() {
            if (this->type == Type::String) {
                this->str.~basic_string();
            }
        }
    };

    class ParseToken {
    private:
        Input input;
        CharaType charType[256];
    public:
        std::vector<Token> tokenList{};

        void parseFile(std::string filePath) {
            input.loadFile(filePath);
            this->parse();
        }

        void parseStr(std::string str) {
            input.loadString(str);
            this->parse();
        }

        void debugView() {
            for (auto &token: tokenList) {
                switch (token.type) {
                    case Token::Type::Number:
                        std::cout << token.num << std::endl;
                        break;
                    case Token::Type::String:
                        std::cout << token.str << std::endl;
                        break;
                    case Token::Type::Bool:
                        std::cout << token.b << std::endl;
                        break;
                    case Token::Type::Null:
                        std::cout << "null" << std::endl;
                        break;
                    case Token::Type::LeftSquareBracket:
                        std::cout << "[" << std::endl;
                        break;
                    case Token::Type::RightSquareBracket:
                        std::cout << "]" << std::endl;
                        break;
                    case Token::Type::LeftCurlyBracket:
                        std::cout << "{" << std::endl;
                        break;
                    case Token::Type::RightCurlyBracket:
                        std::cout << "}" << std::endl;
                        break;
                    case Token::Type::Colon:
                        std::cout << ":" << std::endl;
                        break;
                    case Token::Type::Conma:
                        std::cout << "," << std::endl;
                        break;
                }
            }
        }

    private:
        void parse() {
            this->charTypeInit();
            this->input.nextChara();
            while (!this->input.eof()) {
                this->readToken();
            }
        }

        void charTypeInit() {
            for (int i = 0; i < 256; i++) {
                charType[i] = CharaType::CharaError;
            }
            for (char i = '0'; i <= '9'; i++) {
                charType[i] = CharaType::Digital;
            }
            for (char i = 'a'; i <= 'z'; i++) {
                charType[i] = CharaType::Alphabet;
            }
            for (char i = 'A'; i <= 'Z'; i++) {
                charType[i] = CharaType::Alphabet;
            }
            charType[' '] = CharaType::WhiteSpace;
            charType['\t'] = CharaType::WhiteSpace;
            charType['\r'] = CharaType::WhiteSpace;
            charType['\n'] = CharaType::WhiteSpace;
            charType['"'] = CharaType::Quote;
            charType['['] = CharaType::Symbol;
            charType[']'] = CharaType::Symbol;
            charType['{'] = CharaType::Symbol;
            charType['}'] = CharaType::Symbol;
            charType[':'] = CharaType::Symbol;
            charType[','] = CharaType::Symbol;
        }

        void skipWhiteSpace() {
            auto c = ' ';
            while (charType[c] == CharaType::WhiteSpace) {
                c = input.nextChara();
            }
        }

        void readDigital() {
            int num = 0;
            for (; charType[input.c] == CharaType::Digital; input.nextChara()) {
                num = num * 10 + (input.c - '0');
            }
            tokenList.emplace_back(num);
        }

        // エスケープは無視
        // TODO エスケープ対応
        void readString() {
            std::string str;
            input.nextChara();
            for (int i = 0; input.c != '"'; input.nextChara(), i++) {
                if (
                        input.c < 0x20 ||
                        input.c == '"' ||
                        input.c == '\\') {
                    abort();
                }
                if (i >= 100) {
                    abort();
                }
                str.push_back(input.c);
            }
            input.nextChara();
            tokenList.emplace_back(str);
        }

        void readIdentifier() {
            std::string str;
            for (; charType[input.c] == CharaType::Alphabet; input.nextChara()) {
                str.push_back(input.c);
            }
            if (str == "true") {
                tokenList.emplace_back(true);
            } else if (str == "false") {
                tokenList.emplace_back(false);
            } else if (str == "null") {
                tokenList.emplace_back(Token::Type::Null);
            }
        }

        void readSymbol() {
            switch (input.c) {
                case '[':
                    tokenList.emplace_back(Token::Type::LeftSquareBracket);
                    break;
                case ']':
                    tokenList.emplace_back(Token::Type::RightSquareBracket);
                    break;
                case '{':
                    tokenList.emplace_back(Token::Type::LeftCurlyBracket);
                    break;
                case '}':
                    tokenList.emplace_back(Token::Type::RightCurlyBracket);
                    break;
                case ':':
                    tokenList.emplace_back(Token::Type::Colon);
                    break;
                case ',':
                    tokenList.emplace_back(Token::Type::Conma);
                    break;
                default:
                    break;
            }
            input.nextChara();
        }

        void readToken() {
            switch (charType[input.c]) {
                case CharaType::Digital:
                    readDigital();
                    break;
                case CharaType::Quote:
                    readString();
                    break;
                case CharaType::Alphabet:
                    readIdentifier();
                    break;
                case CharaType::Symbol:
                    readSymbol();
                    break;
                case CharaType::WhiteSpace:
                    skipWhiteSpace();
                    break;
                case CharaType::CharaError:
                    break;
            }
        }
    };

    enum class JsonType {
        Number,
        Bool,
        String,
        Null,
        Object,
        Array,
    };

    class JsonInterFace {
    public:
        JsonType type;

        JsonInterFace(JsonType type) : type(type) {}

        //オーバーロードしてる
        virtual std::shared_ptr<JsonInterFace> operator()(int i) {
            abort();
            //return std::shared_ptr<JsonInterFace>();
        }

        virtual std::shared_ptr<JsonInterFace> operator()(std::string key) {
            abort();
            //return std::shared_ptr<JsonInterFace>();
        }

        template<typename... T>
        std::shared_ptr<JsonInterFace> operator()(int i, T... args) {
            std::shared_ptr<JsonInterFace> temp = (*this)(i);
            return (*temp)(args...);
        }

        template<typename... T>
        std::shared_ptr<JsonInterFace> operator()(std::string key, T... args) {
            std::shared_ptr<JsonInterFace> temp = (*this)(key);
            return (*temp)(args...);
        }

        virtual int getInt() { abort(); }

        virtual double getDouble() { abort(); }

        virtual std::string getString() { abort(); }

        virtual bool getBool() { abort(); }
        //template <> int get<int>(){
        //    return getInt();
        //}
        //template <> double get<double>(){
        //    return getDouble();
        //}
        //template <> std::string get<std::string>(){
        //    return getString();
        //}
        //template <> bool get<bool>(){
        //    return getBool();
        //}
    };

    class JsonObject : public JsonInterFace {
    public:
        std::unordered_map<std::string, std::shared_ptr<JsonInterFace>> objectList;

        JsonObject() : JsonInterFace(JsonType::Object) {
        }

        std::shared_ptr<JsonInterFace> operator()(std::string key) override {
            return objectList[key];
        }
    };

    class JsonArray : public JsonInterFace {
    public:
        std::vector<std::shared_ptr<JsonInterFace>> objectList;

        JsonArray() : JsonInterFace(JsonType::Array) {
        }

        std::shared_ptr<JsonInterFace> operator()(int i) override {
            return objectList[i];
        }
        int size(){
            return objectList.size();
        }
    };

    class JsonNumber : public JsonInterFace {
    public:
        double number;

        JsonNumber(double number) : JsonInterFace(JsonType::Number), number(number) {
        }

        int getInt() override {
            return static_cast<int>(this->number);
        }

        double getDouble() override {
            return this->number;
        }
    };

    class JsonBool : public JsonInterFace {
    public:
        bool b;

        JsonBool(bool b) : JsonInterFace(JsonType::Bool), b(b) {
        }

        bool getBool() override {
            return b;
        }
    };

    class JsonString : public JsonInterFace {
    public:
        std::string str;

        JsonString(std::string str) : JsonInterFace(JsonType::String), str(str) {
        }

        std::string getString() override {
            return str;
        }
    };

    class JsonNull : public JsonInterFace {
    public:
        JsonNull() : JsonInterFace(JsonType::Null) {
        }
    };

    class Json {
    public:
        std::shared_ptr<JsonInterFace> root;

        template<typename... T>
        std::shared_ptr<JsonInterFace> operator()(T... args) {
            return (*root)(args...);
        }

        void parseFile(std::string filePath) {
            ParseToken parseToken;
            parseToken.parseFile(filePath);
            this->tokenList = tokenList;
            this->root = read();
        }

        void parseStr(std::string str) {
            ParseToken parseToken;
            parseToken.parseStr(str);
            this->tokenList = parseToken.tokenList;
            this->root = read();
        }

    private:
        std::vector<Token> tokenList;
        int index = 0;

        std::shared_ptr<JsonInterFace> read() {
            switch (tokenList[index].type) {
                case Token::Type::Number:
                    return readNumber();
                    break;
                case Token::Type::String:
                    return readString();
                    break;
                case Token::Type::Bool:
                    return readBool();
                    break;
                case Token::Type::Null:
                    return readNull();
                    break;
                case Token::Type::LeftSquareBracket:
                    return readArray();
                    break;
                case Token::Type::LeftCurlyBracket:
                    return readObject();
                    break;
            }
        }

        std::shared_ptr<JsonObject> readObject() {
            std::shared_ptr<JsonObject> object = std::make_shared<JsonObject>();
            index++;
            if (tokenList[index].type == Token::Type::RightSquareBracket) {
                index++;
                return object;
            }
            bool isNext = true;
            while (isNext) {
                std::string key = tokenList[index].str;
                index++;
                index++;
                object->objectList[key] = read();
                isNext = tokenList[index].type == Token::Type::Conma;
                index++;
            }
            index++;
            return object;
        }

        std::shared_ptr<JsonInterFace> readArray() {
            std::shared_ptr<JsonArray> array = std::make_shared<JsonArray>();
            index++;
            bool isNext = true;
            while (isNext) {
                array->objectList.push_back(read());
                isNext = tokenList[index].type == Token::Type::Conma;
                index++;
            }
            index++;
            return array;
        }

        std::shared_ptr<JsonInterFace> readNumber() {
            auto obj = std::make_shared<JsonNumber>(tokenList[index].num);
            index++;
            return obj;
        }

        std::shared_ptr<JsonInterFace> readBool() {
            auto obj = std::make_shared<JsonBool>(tokenList[index].b);
            index++;
            return obj;
        }

        std::shared_ptr<JsonInterFace> readString() {
            auto obj = std::make_shared<JsonString>(tokenList[index].str);
            index++;
            return obj;
        }

        std::shared_ptr<JsonInterFace> readNull() {
            index++;
        }
    };
}

#endif
