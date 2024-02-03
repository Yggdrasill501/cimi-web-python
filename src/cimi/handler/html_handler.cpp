//
// Created by Filip Žitný on 02/02/2024.
//
#include "html_handler.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string HtmlLHandler::readHtmlFile(const std::string& filepath){
    std::ifstream fileStream(filepath);
    if(!fileStream.is_open()){
        std::cerr << "Failed to open " << filepath << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << fileStream.rdbuf();
    return buffer.str();
}