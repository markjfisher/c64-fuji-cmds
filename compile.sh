#!/bin/env bash

# CMDS="fcd fconfig fcopy feject fhost finfo fld flh flobby fls fmall fmount fnet fnew freset fscan"
CMDS="fconfig freset fmall"

for cmd in $CMDS; do
  sed "s#__FUJI_PRG__#${cmd}#" < Makefile.template > Makefile
  rm -rf dist/* obj/* build/* bin/${cmd}.*.prg
  make all release
  mkdir bin > /dev/null 2>&1
  echo "Moving dist/${cmd}.*.prg to bin/"
  mv dist/${cmd}.*.prg bin/
done

echo -e "\nbin dir:"
ls -l bin/*.prg