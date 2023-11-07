# cub3d

A C project using minilibX for the graphical interface. The goal is to create a program allowing you to take a configuration file as a parameter which allows
to generate a 3D map assigning each face of walls (North, South, East and West) its own texture. The player must be able to move and collision against walls.
The challenge of the project was to manage raycasting using algorithms so that the display of wall faces appeared correctly.

<img width="1857" alt="Screen Shot 2023-11-07 at 10 11 56 AM" src="https://github.com/PaoloYam/cub3d/assets/89736891/a381a023-d6b5-412a-86d8-91fa9db6891c">
<br />
<br />
<br />

You can launch the programm this way:
```bash
make
./cub3d maps/map.cub
 ```
