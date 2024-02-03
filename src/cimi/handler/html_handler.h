//
// Created by Filip Žitný on 02/02/2024.
//
#ifndef CIMIWEB_HTML_HANDLER_H
#define CIMIWEB_HTML_HANDLER_H
#include <string>

class HtmlLHandler{
public:
    static std::string readHtmlFile(const std::string& filepath);
};

#endif //CIMIWEB_HTML_HANDLER_H
