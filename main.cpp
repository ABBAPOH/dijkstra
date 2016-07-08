#include <iostream>
#include <fstream>
#include <QString>

#include "graph.h"

int main(int argc, char *argv[])
{
    try {

        std::string s = argv[0];
        QString str = QString::fromStdString(s);

        Graph g;
        if (argc == 1) {
            g.read(std::cin);
        } else if (argc == 2) {
            std::ifstream file;
            file.exceptions(file.exceptions() | std::ifstream::badbit);
            file.open(argv[1]);
            g.read(file);
        }

        g.dump();

    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return -1;
    } catch (...) {
        std::cerr << "Caught unknown exception" << std::endl;
        return -1;
    }

    return 0;
}
