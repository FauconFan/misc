cat /etc/passwd | grep -v '#' | awk '{if((NR + 1) % 2) print $0}' | cut -d : -f 1 | rev | sort -r | awk -v LINE1=$FT_LINE1 -v LINE2=$FT_LINE2 '{if (NR > LINE1 && NR <= LINE2) print $0}' | tr '\n' ' ' | sed 's/ /, /g' | rev | sed 's/ ,/./' | rev
