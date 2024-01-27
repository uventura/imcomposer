#include "imcomposer/application/imcomposer.hpp"

int main(int argc, char** argv)
{
    std::string applicationPath = argv[0];
    ImComposer::ImComposerUi imcomposer(applicationPath);
    imcomposer.render();
}
