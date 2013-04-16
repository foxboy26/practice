#! /bin/sh

#if [ -z "$st" ]; then
#  echo "Need to set st"
#  exit 1
#fi
st=PtQf882IWXv
filename=`basename $1`
filename=${filename%.*}
curl --form filename=@$PWD/$1 --form a=$st --form S=$filename  http://ace.delos.com/upload3
