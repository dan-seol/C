#!/bin/bash
contents=0
multiple=0

usage() {
 echo "Usage ./seeker.sh [-c] [-a] pattern [path]"
 exit 0
}

while getopts "ca" opt; do
  case "$opt" in
    c) contents=1;;
    a) multiple=1;;
  esac
done
shift $(( OPTIND - 1 ))

if [[ "$#" -gt 0 ]]; then

pattern=${1?$( usage )}
path=${2:-"$PWD"}

if ! [[  -d "$path" ]]; then
  echo "Error $path is not a valid directory"
  exit 0
fi

if [[ "$multiple" -gt 0 ]]; then
  readarray -t arr <<< `find "$path" -name "*$pattern*" -print`
else
  readarray -t arr <<< `find "$path" -name "*$pattern*" -print -quit`
fi
for filename in "${arr[@]}"
do
  if [[ "$contents" -gt 0 ]]; then
    echo "==== Contents of: $filename ===="
    cat "$filename"
  else
    echo "$filename"
  fi
done
exit 0
else
  echo "Error missing the pattern argument"
  usage
fi
exit 0


