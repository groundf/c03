#!/bin/sh
# Auto-formats all C/C++ code with Artistic Style (http://astyle.sourceforge.net/)
# to adhere to a consistent coding style.  Should be run before committing.
astyle \
    --options=none \
    --indent=spaces \
    --suffix=".orig~" \
    --pad-header \
    --delete-empty-lines \
    --style=allman \
    --indent-switches \
    --indent-modifiers  \
    --indent-namespaces \
    --indent-preproc-block \
    --align-pointer=name \
    --formatted \
    --recursive 