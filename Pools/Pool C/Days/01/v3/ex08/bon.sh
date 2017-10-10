ldapsearch -QLLL '(sn=*BON*)' | grep cn: | cut -d ' ' -f 3 | wc -l | tr -d ' '
