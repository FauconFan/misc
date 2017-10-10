touch -ar bomb.txt -A -'000001' bomb.txt && stat -s bomb.txt | tr ' ' '\n' | grep st_atime | sed 's/st_atime=//'
