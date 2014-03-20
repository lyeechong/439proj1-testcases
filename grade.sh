#!/bin/bash

testdir=439proj2-testcases;

mkdir -p workdir

cd $testdir

for i in {1..11}; do
   if [ ! -e $testdir/test${i}.o ]; then
      gcc -I. -c -o test${i}.o test${i}.c
   fi
done

cd ..

submissions=`ls | grep -v 439proj2-testcases | grep -v workdir`;

cd workdir;

for submission in $submissions; do
   echo "================================="
   echo "$submission"
   echo "================================="

   for i in {1..11}; do
        echo ""
        echo "TEST $i for $submission"
        #echo ""

        gcc -w -I ../$testdir -c -o threads.o ../$submission/threads.c ||
        continue;
        gcc -w threads.o ../$testdir/test${i}.o -o test${i}
        ./test${i} > test${i}.out
        if ! diff --ignore-all-space -q test${i}.out ../$testdir/test${i}_expected_out > /dev/null; then
           diff --ignore-all-space test${i}.out ../$testdir/test${i}_expected_out
        else
           echo "PASSED"
        fi

   done

done;
