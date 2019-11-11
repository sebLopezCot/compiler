#!/bin/bash

if [ $# -eq 0 ]
  then
    echo "No test directory specified."
    echo "Usage: ./run_tests.sh [TEST DIR]"
    exit
fi

GIT_ROOT_DIR=$(git rev-parse --show-toplevel)
INPUT_DIR=$1
TEST_RESULTS_FILE=$GIT_ROOT_DIR/"test_results.txt"

ORIG_IFS=$IFS

echo "" > $TEST_RESULTS_FILE

for f in $(ls $INPUT_DIR | grep ".zsl");
do
    # Keep newlines in test output
    #https://unix.stackexchange.com/questions/164508/why-do-newline-characters-get-lost-when-using-command-substitution
    IFS=

    echo "TEST " $f >> $TEST_RESULTS_FILE
    echo $($GIT_ROOT_DIR/compiler $INPUT_DIR/$f --debug) >> $TEST_RESULTS_FILE
    echo "" >> $TEST_RESULTS_FILE
    echo "" >> $TEST_RESULTS_FILE

    # Switch back for input filenames
    IFS=$ORIG_IFS
done

cat $TEST_RESULTS_FILE

