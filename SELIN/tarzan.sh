#!/bin/bash

if [ "$#" -eq 2 ]; then
  fullpath=`readlink -f "$2"`
  if test -f "$fullpath"; then
    tarlist=`tar -tvf "$fullpath"`
    if [[ "$tarlist" == *"$1"* ]]; then
      echo "$1 exists in $2"
    else
      echo "$1 does not exist in $2"
    fi
  else
    echo "Error cannot find tarfile $2"
  fi
else
  echo "Usage ./tarzan.sh filename tarfile"
fi
