#include "imcomposer/application/imcomposer.h"
#include "imcomposer/application/imcomposer_environment.h"

#include <iostream>

int main(int argc, char** argv)
{
    ImComposer::Environment::applicationPath = argv[0];
    ImComposer::ImComposerUi imcomposer;
    imcomposer.render();
}
