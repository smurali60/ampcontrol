#!/bin/sh

make clean

for AUDIOPROC in TDA7313 TDA7318 TDA7439
do
	for DISPLAY in KS0066 PCF8574
	do
		for TUNER in LM7001 TEA5767 TUX032
		do
			make AUDIOPROC=${AUDIOPROC} DISPLAY=${DISPLAY} TUNER=${TUNER}
			make AUDIOPROC=${AUDIOPROC} DISPLAY=${DISPLAY} TUNER=${TUNER} clean_var
		done
	done
done

make clean_const
