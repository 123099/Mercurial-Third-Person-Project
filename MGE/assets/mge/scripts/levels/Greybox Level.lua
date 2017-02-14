objects = {}
objects[0] = creategameobject("Cockpit", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,21.30000,41.47000,1.00000, "Cockpit.obj", "lit")
addbehaviour(objects[0], "meshcollider", false)
addbehaviour(objects[0], "rigidbody", 0, false, false, false, false, false, false, false)
objects[1] = creategameobject("Windows", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000, "Glass.obj", "litWindows")
addchild(objects[0], objects[1], false)

objects[2] = creategameobject("BGM", false, 0.50000,0.85355,0.14645,0.00000,-0.50000,0.14645,0.85355,0.00000,0.70711,-0.50000,0.50000,0.00000,1.62132,-0.35355,3.35355,1.00000, "", "")
addbehaviour(objects[2], "audiosource", "test.wav", true, true, true, true, 1, 1, true)

objects[3] = creategameobject("Player", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,1.19000,69.04000,1.00000, "", "")
addbehaviour(objects[3], "player")
objects[4] = creategameobject("Main Camera", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.70000,0.10000,1.00000, "", "")
addbehaviour(objects[4], "camera", 60, 0.3, 1000)
addchild(objects[3], objects[4], false)

objects[5] = creategameobject("Directional Light", false, 0.86603,-0.38302,0.32139,0.00000,0.00000,0.64279,0.76604,0.00000,-0.50000,-0.66341,0.55667,0.00000,0.00000,1.92836,2.29813,1.00000, "", "")
addbehaviour(objects[5], "light", "directional", 1, 0.9568627, 0.8392157, 1, 1, 30)

objects[6] = creategameobject("Door", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,13.77000,1.00000, "door.obj", "lit")
addbehaviour(objects[6], "meshcollider", true)
addbehaviour(objects[6], "rigidbody", 0, false, false, false, false, false, false, false)

objects[7] = creategameobject("Point light", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,-0.53543,-4.09778,43.14000,1.00000, "", "")
addbehaviour(objects[7], "light", "point", 0.2797576, 0.1695502, 0.7205882, 1, 1, 30)

objects[8] = creategameobject("Sphere", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.63000,-0.52744,7.39000,1.00000, "Shape.obj", "lit")
addbehaviour(objects[8], "spherecollider", 1)
addbehaviour(objects[8], "npc", 0)
addbehaviour(objects[8], "rigidbody", 0, false, false, false, false, false, false, false)

