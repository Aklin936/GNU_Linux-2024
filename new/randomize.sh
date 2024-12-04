
#!/bin/bash

raw=`hexdump -e '16/1 "%02x\n" "\n"'`

col=0
row=0

while IFS= read -r line
do
    # echo $line
    case "$line" in
        "0a")
            row=$((++row))
            col=0
            ;;
        "20")
            col=$((++col))
            ;;
        "  ")
            ;;
        *)
            data+="$row $col $line"$'\n'
            col=$((++col))
            ;;
    esac
done < <(printf  "%s\n" "$raw")



tput cup $LINES 0