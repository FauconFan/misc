/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:51:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/09 17:34:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Lexer.class.hpp"
#include "Parser.class.hpp"

static void usage() {
    std::cout << "Use this program properly..." << '\n';
    std::cout << "./abstractVM [file]" << '\n';
    std::cout << "./abstractVM" << '\n';
}

static std::string load_cin() {
    std::string content;
    std::string line;

    while (true) {
        std::cin >> line;
        if (line == ";;") {
            break;
        }
        content += line + "\n";
    }
    return content;
}

static std::string load_file(char * path) {
    std::string content;
    std::ifstream input_file(path, std::ios::in);

    if (input_file.is_open()) {
        std::string line;
        while (std::getline(input_file, line)) {
            content += line + "\n";
        }
        input_file.close();
    }
    else {
        std::cerr << "Unable to open file\n";
    }
    return content;
}

int main(int argc, char * argv []) {
    int ret = 0;
    std::string content;

    if (argc == 0 || argc >= 3) {
        usage();
        ret = 1;
    }
    else {
        if (argc == 1) {
            content = load_cin();
        }
        else if (argc == 2) {
            content = load_file(argv[1]);
        }
        Lexer lex(content);
        if (lex.run() == false) {
            std::vector<Lexer::LexerError> errors = lex.getErrors();

            ret = 1;
            for (Lexer::LexerError le : errors) {
                std::cout << le;
            }
        }
        else {
            std::vector<IToken *> tokens = lex.getTokens();
            Parser par(tokens);

            par.run();
        }
    }

    return ret;
}
