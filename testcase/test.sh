#!/bin/bash

tot=0
suc=0

for i in $(ls $3/in)
do
  tot=$(($tot+1))
  if [[ $(diff -b <( cat $3/out/${i%%/} ) <( cat $3/in/${i%%/} | $2 $1 )) = "" ]]
  then
    suc=$(($suc+1))
  fi
done

echo "$suc/$tot"