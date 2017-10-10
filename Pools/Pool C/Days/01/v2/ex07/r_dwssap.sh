cat /etc/passwd | grep -v '#' | sed -n 'n;p' | cut -d : -f 1 | rev | sort -r | awk -v LINE1=$FT_LINE1 -v LINE2=$FT_LINE2 '{if ((NR + 1) >= LINE1 && (NR + 1) <= LINE2) print $0}' | tr '
' ' ' | sed 's/ /, /g' | rev | sed 's/ ,/./' | rev | tr -d '
'

