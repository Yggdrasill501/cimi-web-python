//
// Created by Filip Žitný on 02/02/2024.
//
#ifndef CIMISERVER_HTML_HANDLER_H
#define CIMISERVER_HTML_HANDLER_H
#include <string>

class HtmlLHandler{
public:
    static std::string readHtmlFile(const std::string& filepath);
};

#endif //CIMISERVER_HTML_HANDLER_H
