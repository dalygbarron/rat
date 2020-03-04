#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "main/Options.hh"

Options getOptions(int argc, char **argv) {
    Options options;
    int opt;
    while ((opt = getopt(argc, argv, "hvi:o:s:d:f:")) != -1) {
        switch (opt) {
            case 'h':
                options.help = true;
                break;
            case 'v':
                options.version = true;
                break;
            case 'i':
                options.image = optarg;
                break;
            case 'o':
                options.output = optarg;
                break;
            case 's':
                options.style = optarg;
                break;
            case 'd':
                // TODO: parse dimensions into vector.
                break;
            case 'f':
                options.fonts.emplace(options.fonts.end(), optarg);
                break;
        }
    }
    for (int i = optind; i < argc; i++) {
        options.pics.emplace(options.pics.end(), argv[i]);
    }
    return options;
}

int main(int argc, char **argv) {
    Options options = getOptions(argc, argv);
    std::sort(options.pics.begin(), options.pics.end());
    return 0;
}
