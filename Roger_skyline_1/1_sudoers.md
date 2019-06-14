#1 sudoers

Install sudo and put user in sudoers

Connect as root

```sh
su
```

Install sudo
```
apt update
apt install -y sudo
```

put this line in the /etc/sudoers file (you can use nano)

pepe	ALL=(ALL:ALL)	ALL
pepe	ALL=(ALL) NOPASSWD:ALL

You can logout as superuser

```sh
exit
```