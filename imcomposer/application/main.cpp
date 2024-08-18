#include <iostream>

#include "imcomposer/application/imcomposer.h"
#include "imcomposer/application/imcomposer_environment.h"

int main(int argc, char** argv) {
  ImComposer::Environment::applicationPath = argv[0];
  ImComposer::ImComposerUi imcomposer;
  imcomposer.render();
}
