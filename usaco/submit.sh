#! /bin/sh

#if [ -z "$st" ]; then
#  echo "Need to set st"
#  exit 1
#fi
st=iwfakjOLsbW
filename=`basename $1`
filename=${filename%.*}
curl --form filename=@$PWD/$1 --form a=$st --form S=$filename  http://train.usaco.org/upload3
