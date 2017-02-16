objects = {}
objects[0] = creategameobject("GameObject", false, -1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,-1.00000,0.00000,-1.12000,0.00000,3.82000,1.00000, "KeyPadLock.obj", "KeyPad")

objects[1] = creategameobject("Cockpit", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,21.30000,41.47000,1.00000, "Cockpit.obj", "lit")
addbehaviour(objects[1], "meshcollider", false)
addbehaviour(objects[1], "rigidbody", 0, false, false, false, false, false, false, false)
objects[2] = creategameobject("Windows", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000, "Glass.obj", "litWindows")
addchild(objects[1], objects[2], false)

objects[3] = creategameobject("BGM", false, 0.50000,0.85355,0.14645,0.00000,-0.50000,0.14645,0.85355,0.00000,0.70711,-0.50000,0.50000,0.00000,1.62132,-0.35355,3.35355,1.00000, "", "")
addbehaviour(objects[3], "audiosource", "test.wav", true, true, true, true, 1, 1, true)

objects[4] = creategameobject("Player", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,9.70000,-1.90000,1.00000, "", "")
addbehaviour(objects[4], "player")
objects[5] = creategameobject("Main Camera", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.70000,0.10000,1.00000, "", "")
addbehaviour(objects[5], "camera", 60, 0.3, 1000)
addchild(objects[4], objects[5], false)

objects[6] = creategameobject("Directional Light", false, 0.86603,-0.38302,0.32139,0.00000,0.00000,0.64279,0.76604,0.00000,-0.50000,-0.66341,0.55667,0.00000,0.00000,1.92836,2.29813,1.00000, "", "")
addbehaviour(objects[6], "light", "directional", 1, 0.9568627, 0.8392157, 1, 1, 30)

objects[7] = creategameobject("Door", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,13.77000,1.00000, "door.obj", "lit")
addbehaviour(objects[7], "meshcollider", true)
addbehaviour(objects[7], "rigidbody", 0, false, false, false, false, false, false, false)

objects[8] = creategameobject("Point light", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,-0.53543,-4.09778,43.14000,1.00000, "", "")
addbehaviour(objects[8], "light", "point", 0.2797576, 0.1695502, 0.7205882, 1, 1, 30)

objects[9] = creategameobject("Sphere", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.63000,-0.52744,7.39000,1.00000, "Shape.obj", "lit")
addbehaviour(objects[9], "spherecollider", 1)
addbehaviour(objects[9], "npc", 0, true, false)
addbehaviour(objects[9], "rigidbody", 1, false, false, false, false, false, false, false)

