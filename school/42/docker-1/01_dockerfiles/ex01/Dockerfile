FROM debian

RUN apt-get update -y &&\
        apt-get install -y wget bzip2 &&\
        rm -rf /var/lib/apt/lists/*

# CONFIG TEAMSPEAK

ENV TS3SERVER_LICENSE accept

RUN useradd ts3

EXPOSE 9987/udp
EXPOSE 30033
EXPOSE 10011

WORKDIR /home/ts3
RUN wget http://dl.4players.de/ts/releases/3.2.0/teamspeak3-server_linux_amd64-3.2.0.tar.bz2
RUN bzip2 -d teamspeak3-server_linux_amd64-3.2.0.tar.bz2 &&\
        tar -xvf teamspeak3-server_linux_amd64-3.2.0.tar &&\
        rm -f teamspeak3-server_linux_amd64-3.2.0.tar.bz2 teamspeak3-server_linux_amd64-3.2.0.tar

WORKDIR /home/ts3/teamspeak3-server_linux_amd64
COPY ts3server.ini /home/ts3/teamspeak3-server_linux_amd64/ts3server.ini

CMD ["sh", "ts3server_startscript.sh", "start"]

#PORT
# EXPOSE 9987/udp
# EXPOSE 30033
# EXPOSE 10011
#
# RUN useradd ts3
# WORKDIR /home/t3
#
# RUN curl http://dl.4players.de/ts/releases/3.0.13.6/teamspeak3-server_linux_amd64-3.0.13.6.tar.bz2 > teamspeak-server.tar.bz2
# RUN tar -xjvf teamspeak-server.tar.bz2
# WORKDIR teamspeak3-server_linux_amd64
# COPY ts3server.ini /home/t3/teamspeak3-server_linux_amd64/ts3server.ini
# USER ts3
# ENTRYPOINT ["sh","ts3server_minimal_runscript.sh", "inifile=ts3server.ini"]
# CMD ["sh", "ts3server_startscript.sh", "start"]
