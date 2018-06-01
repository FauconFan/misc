all:
	echo "voila"

image:
	docker build -t own_ts .

run: image
	docker run --rm -it own_ts

run_cheating:
	docker run -p 9987:9987/udp -p 10011:10011 -p 30033:30033 -e TS3SERVER_LICENSE=accept teamspeak
