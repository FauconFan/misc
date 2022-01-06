/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:51:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 16:27:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CLASS_HPP
#define CLASS_CLASS_HPP

#include "Lexer.class.hpp"
#include "Parser.class.hpp"
#include "ProgEnv.class.hpp"

class Main {
    public:
        Main (int ac, char ** ag);
        virtual ~Main ();

        int run();

    private:
        std::vector<void (Main::*)()> list_function;

        int argc;
        char ** argv;
        bool doPrintUsage;
        bool is_running;

        std::string content;
        Lexer *lexer;
        Parser *parser;

        Main (const Main &);

        Main &operator=(Main const &);

        void usage();

        void loadEntry();
        void loadCin();
        void loadFile(char *path);
        void lex();
        void parse();
        void progRun();
};

#endif
