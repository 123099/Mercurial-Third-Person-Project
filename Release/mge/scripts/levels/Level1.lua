objects = {}
objects[0] = creategameobject("Point Light", 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,7.00000,0.00000,1.00000, "cube_flat.obj", "color")
addbehaviour(objects[0], "light", "point", 0.1431775, 0.09758868, 0.6985294, 1, 3, 30)

objects[1] = creategameobject("Spot Light", 1.00000,0.00000,0.00000,0.00000,0.00000,0.00000,-1.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,2.00000,0.00000,1.00000, "cube_flat.obj", "color")
addbehaviour(objects[1], "light", "spot", 0.9485294, 0.6834992, 0.6834992, 1, 4, 45)

objects[2] = creategameobject("Directional Light", 0.86603,0.00000,0.50000,0.00000,-0.38302,0.64279,0.66341,0.00000,-0.32139,-0.76604,0.55667,0.00000,0.00000,0.00000,0.00000,1.00000, "cube_flat.obj", "color")
addbehaviour(objects[2], "light", "directional", 0.08088234, 0.326572, 0.625, 1, 0.3, 30)

objects[3] = creategameobject("Terrain", 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000, "", "terrain")
addbehaviour(objects[3], "terrain", 512, 512.5, 512)
addbehaviour(objects[3], "wobblebehaviour")

objects[4] = creategameobject("Main Sphere", 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,10.00000,-2.40000,1.00000, "Shape.obj", "lit")
addbehaviour(objects[4], "rotatingbehaviour", 40)
objects[5] = creategameobject("Dragon", 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,10.00000,6.10000,1.00000, "dragon.obj", "litDragon")
objects[6] = creategameobject("Sub Sphere", 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,13.93000,-1.03000,1.00000, "Shape.obj", "lit")
addbehaviour(objects[6], "rotatingbehaviour", 40)
addchild(objects[5], objects[6])
addchild(objects[4], objects[5])

