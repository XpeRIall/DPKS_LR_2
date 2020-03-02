#include <cstdio>
#include <iostream>
#include <getopt.h>

void help() {
    std::cout << "Commands: -l --list, -v --version, -h --help." << std::endl;
}

void version() {
    std::cout << "0.0.1" << std::endl;
}

void list(char *ch) {
    std::cout << "Listing...." << std::endl;
    printf("%s", ch);
    std::cout << "\nEnd." << std::endl;
}

void value(char *opts) {
    std::cout << "Value: ";
    printf("%s", opts);
    printf("\n");
}

static struct option ops[] = {
        {"help",    no_argument,       nullptr, 'h'},
        {"list",    no_argument,       nullptr, 'l'},
        {"version", optional_argument, nullptr, 'v'},
        {"value",   required_argument, nullptr, 'V'}
};

int main(int argc, char *argv[]) {

    int param, paramI;

    bool l, ver, h, val = false;

    while ((param = getopt_long(argc, argv, "hvl::V:", ops, &paramI)) != 1) {
        switch (param) {
            case 'h' :
                if (!h) {
                    help();
                    h = true;
                }
                break;
            case 'v':
                if (!ver) {
                    version();
                    ver = true;
                }
                break;
            case 'l' :
                if (!l) {
                    list(optarg);
                    l = true;
                }
                break;
            case 'V':
                if (!val) {
                    value(optarg);
                    val = true;
                }

        }
    }

    return 0;
}
