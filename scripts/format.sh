find . -regex 'imcomposer/**/.*\.\(cpp\|h\|cc\|cxx\)' -exec clang-format -style=file -i {} \;
find . -regex 'data/**/.*\.\(cpp\|h\|cc\|cxx\)' -exec clang-format -style=file -i {} \;