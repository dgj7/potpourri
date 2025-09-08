#!/bin/bash

# build the app (maybe)
if [ ! -f chess-ui/target/chess-ui-jar-with-dependencies.jar ]; then
    ./silent.sh
else
    printf "no build needed, skipping.\n"
fi

# run the app
printf "launching..."
(cd ui/target ; java -jar chess-ui-jar-with-dependencies.jar &)
printf "done.\n"
