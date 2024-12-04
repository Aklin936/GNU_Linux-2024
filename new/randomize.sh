
#!/bin/bash

raw=`hexdump -e '16/1 "%02x\n" "\n"'`

col=0
row=0

tput cup $LINES 0