//
// Created by a_mod on 25.07.2018.
//

#include "../header/Line.h"
#include "../header/InputFile.h"
#include "../header/utils.h"
#include "../header/error.h"

compiler::data::Line::Line(std::string str, bool hasSym, size_t fileNum) {
    auto splitStr = utils::splitStr(str, ' ');
    for(int64_t i = splitStr.size() - 1; i >= 0; i--){
        if(splitStr.at(i) == "")
            splitStr.erase(splitStr.begin() + i);
    }

    this->hasSymbol = hasSym;
    if(hasSym){
        this->symbol = splitStr[0];
        this->symbol.erase(this->symbol.begin());
        if(this->symbol[0] == '\'')
            this->symbol.erase(this->symbol.begin());
        splitStr.erase(splitStr.begin());
    }

    if(splitStr.size() == 0 || splitStr[0] == "")
        throw error::syntax_error("Symbol defined without instructions following it.");

    this->instructionName = splitStr[0];
    splitStr.erase(splitStr.begin());

    for(auto arg : splitStr){
        this->args.push_back(arg);
    }

}
