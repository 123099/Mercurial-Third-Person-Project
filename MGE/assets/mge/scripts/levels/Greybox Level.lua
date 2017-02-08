objects = {}
objects[0] = creategameobject("Cockpit", False, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,21.30000,-41.47000,1.00000, "Cockpit.obj", "lit")
objects[1] = creategameobject("Windows", False, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000, "Glass.obj", "litWindows")
addchild(objects[0], objects[1], False)

objects[2] = creategameobject("Sphere", False, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,-1.92159,-0.52744,-7.39000,1.00000, "Shape.obj", "lit")

objects[3] = creategameobject("Directional Light", False, 0.86603,0.00000,0.50000,0.00000,-0.38302,0.64279,0.66341,0.00000,-0.32139,-0.76604,0.55667,0.00000,0.00000,3.00000,0.00000,1.00000, "", "")
addbehaviour(objects[3], "light", "directional", 1, 0.9568627, 0.8392157, 1, 1, 30)

objects[4] = creategameobject("Player", False, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000, "", "")
addbehaviour(objects[4], "player")
objects[5] = creategameobject("Main Camera", False, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.70000,-0.10000,1.00000, "", "")
addbehaviour(objects[5], "camera", 60, 0.3, 1000)
addchild(objects[4], objects[5], False)
