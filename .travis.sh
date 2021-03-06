#!/bin/bash
case "$KEY" in
    linter)
        which clang-format-7.0 > /dev/null \
        && find . -regex '.*\.\(h\|cpp\)' \
                  -exec clang-format-7.0 -i -style=file {} \; \
        || { return 0; } \
        && git diff-files --quiet \
        || {
          for i in {{1..80}}; do echo -n = ; done
          echo
          echo "The following files don't meet the style guidelines:"
          git diff --name-only | sed "s/^/ - /"
          for i in {{1..80}}; do echo -n = ; done
          echo
          echo "Detailed style violations are as below:"
          git diff --color=always -U0 \
            | sed "/^\x1b\[32m+/d;s/^\x1b\[36m/\n\0/;s/^\x1b\[1mdiff/\n\0/"
          echo
          return 1
        }
        ;;

    clang++-7)
        cd bin && cmake .. && make && echo "Executing Clang compiled binaries:" \
        && { ./testing; }
        ;;

    g++-8)
        cd bin && cmake .. && make && echo "Executing GCC compiled binaries:" \
        && { ./testing; }
        ;;

    *)
        echo "KEY must be one of linter|clang++-7|g++-8; aborting." && exit 1
esac
