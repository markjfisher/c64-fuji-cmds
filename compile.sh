#!/bin/env bash

# CMDS="fcd fconfig fcopy feject fhost finfo fld flh flobby fls fmall fmount fnet fnew freset fscan"
CMDS="fconfig"

for cmd in $CMDS; do
  sed "s#__FUJI_PRG__#${cmd}#" < Makefile.template > Makefile
  make clean all release
  mv dist/${cmd}.*.prg bin/
done
