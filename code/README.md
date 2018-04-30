
# Code for review and usage

## Install clang-format 

    sudo apt update
    sudo apt-cache search clang-format
    sudo apt-get install clang-format-3.9

    To add path, 
    c9 open ~/.bashrc
    # add the following to the last line
    export PATH="$PATH:/usr/lib/llvm-3.9/bin/" 

### Usage of clang-format

    // echo to display
    clang-format -style=LLVM <filename.c>

    // to perform in-place edit,
    clang-format -i -style=LLVM <filename.c> 