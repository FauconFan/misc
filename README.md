# fdf

This project is finished, the goal was to build a 3d representation of a specific map given as argument.

usage ./fdf file_name [0xRRGGBB 0xRRGGBB] [-iso]

by default, fdf launch the map without any rotation
you may have to change it manually or give the option -iso
you can specify two colors starting with the prefix "0x"

if you run this program under a linux machine, you may have to change the default keyboard shortcuts
how to use it :

	 Q => Increase elevation
	 W => Decrease elevation

	 T => ROTATE X +
	 Y => ROTATE X -
	 G => ROTATE Y +
	 H => ROTATE Y -
	 B => ROTATE Z +
	 N => ROTATE Z -

	 + => ZOOM +
	 - => ZOOM -

	 UP => TRANSLATE UP
	 DOWN => TRANSLATE DOWN
	 LEFT => TRANSLATE LEFT
	 RIGHT => TRANSLATE RIGHT

	 MOUSE CLICK => orient the shape in the dir. of the mouse

# Some images because we like that

![img01](https://github.com/FauconFan/fdf/blob/master/assets/img01.png)
