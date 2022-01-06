#0 Setup vm

- cd in your sgoinfre
- download a debian iso file

```sh
curl -C - -L -O https://saimei.ftp.acc.umu.se/debian-cd/current/amd64/iso-cd/debian-9.9.0-amd64-netinst.iso
```

- open virtual box
- create a new vm with 8Go of space with extra RAM if you want
- launch the vm, it will ask you for the path. And then proces to installation
- Choose Intall (not Graphical Install)
- choose everything in french, but keyboard for united states
- choose root passwor, new user name and password
- Manual partition
	- select the default partition (usually sda) and free it
	- select free space and create a primarily 4.21 Go partition on ext4 format
	- select free space and create a logical 1Go partition for swap
	- select the remaining free space and create partition on ext4 format
- Don't scan new disk
- Select a french mirror for apt
- Dont agree for debian surveillance
- Install just ssh server and common software
- Install the GRUB
- Do the reboot
- Be happy