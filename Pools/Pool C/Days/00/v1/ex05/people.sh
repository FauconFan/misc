ldapsearch -LLL "(uid=z*)" cn | grep cn | sort -r | sed -e "s/cn: //g"
