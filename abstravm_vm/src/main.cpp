/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:51:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/24 18:57:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>
#include "main.hpp"
#include "LexerError.class.hpp"
#include "ParserError.class.hpp"
#include "InvalidEntryException.class.hpp"
#include "SuperException.class.hpp"

Main::Main(int ac, char ** av)
    : argc(ac), argv(av), doPrintUsage(false), is_running(true),
    content(std::string()), lexer(NULL), parser(NULL)
{
    this->list_function = std::vector<void (Main::*)()>();
    this->list_function.push_back(&Main::loadEntry);
    this->list_function.push_back(&Main::lex);
    this->list_function.push_back(&Main::parse);
    this->list_function.push_back(&Main::progRun);
}

Main::~Main() {
    if (this->lexer)
        delete this->lexer;
    if (this->parser)
        delete this->parser;
}

int Main::run() {
    std::vector<void (Main::*)()>::iterator it;
    for (it = this->list_function.begin(); it != this->list_function.end(); it++) {
        if (this->is_running == false)
            break;
        (this->**it)();
    }

    if (this->doPrintUsage)
        this->usage();
    return (this->is_running ? 0 : 1);
}

void Main::loadEntry() {
    if (this->argc == 0 || this->argc >= 3) {
        this->doPrintUsage = true;
        this->is_running = false;
    }
    else {
        try {
            if (this->argc == 1) {
                this->loadCin();
            }
            else if (this->argc == 2) {
                this->loadFile(this->argv[1]);
            }
        }
        catch (InvalidEntryException const & iee)
        {
            std::cout << iee.what() << '\n';
            this->is_running = false;
        }
    }
}

void Main::usage() {
    std::cout << "Use this program properly..." << '\n';
    std::cout << "./abstractVM [file]" << '\n';
    std::cout << "./abstractVM" << '\n';
}

void Main::loadCin() {
    std::string line;

    while (std::cin.good()) {
		std::getline(std::cin, line);
        if (line == ";;") {
            break;
        }
        this->content += line + "\n";
    }
    if (std::cin.bad()) {
        throw InvalidEntryException(STDIN_BAD);
    }
}

void Main::loadFile(char * path) {
    std::ifstream input_file(path, std::ios::in);

    if (input_file.is_open()) {
        std::string line;
        while (std::getline(input_file, line)) {
            this->content += line + "\n";
        }
        input_file.close();
    }
    else {
        throw InvalidEntryException(FILE_BAD);
    }
}

void Main::lex() {
    this->lexer = new Lexer(content);
    bool lexing;

    try {
        lexing = this->lexer->run();
    }
    catch (SuperException const & se) {
        std::cout << se.what() << '\n';
        this->is_running = false;
    }
    if (this->is_running && lexing == false) {
        this->is_running = false;
        std::vector<LexerError> errors = this->lexer->getErrors();

        std::cout << "Error(s) occured, when lexing :" << '\n';
        for (const LexerError & le : errors) {
            std::cout << le;
        }
    }
}

void Main::parse() {
    this->parser = new Parser(this->lexer->getTokens());
    bool parsing;

    try {
        parsing = this->parser->run();
    }
    catch (SuperException const & se) {
        std::cout << se.what() << '\n';
        this->is_running = false;
    }
    if (this->is_running && parsing == false) {
        this->is_running = false;
        std::vector<ParserError> errors = this->parser->getErrors();

        std::cout << "Error(s) occured, when parsing :" << '\n';
        for (const ParserError & pe : errors) {
            std::cout << pe;
        }
    }
}

void Main::progRun() {
    try {
        ProgEnv progEnv(this->parser->getInstructions());
        progEnv.run();
    }
    catch (SuperException const & se)
    {
        this->is_running = false;
        std::cout << se.what() << '\n';
    }
}

int main(int argc, char * argv []) {
    Main main(argc, argv);

    return (main.run());
}
