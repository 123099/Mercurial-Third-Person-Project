objects = {}
objects[0] = creategameobject("BGM", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000, "", "")
addbehaviour(objects[0], "audiosource", "test.wav", true, true, true, true, 1, 1, true)

objects[1] = creategameobject("Point light", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,-0.53543,-4.09778,-43.14000,1.00000, "", "")
addbehaviour(objects[1], "light", "point", 0.2797576, 0.1695502, 0.7205882, 1, 1, 30)

--objects[2] = creategameobject("Cockpit", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,21.30000,-41.47000,1.00000, "Cockpit.obj", "lit")
--objects[3] = creategameobject("Windows", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000, "Glass.obj", "litWindows")
--addchild(objects[2], objects[3], false)

objects[4] = creategameobject("Sphere", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,-1.92159,-0.52744,-7.39000,1.00000, "Shape.obj", "lit")
addbehaviour(objects[4], "spherecollider", 1)
addbehaviour(objects[4], "npc", 0)

objects[5] = creategameobject("Directional Light", false, 0.86603,0.00000,0.50000,0.00000,-0.38302,0.64279,0.66341,0.00000,-0.32139,-0.76604,0.55667,0.00000,0.00000,3.00000,0.00000,1.00000, "", "")
addbehaviour(objects[5], "light", "directional", 1, 0.9568627, 0.8392157, 1, 1, 30)

objects[6] = creategameobject("Player", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000, "", "")
addbehaviour(objects[6], "player")
objects[7] = creategameobject("Main Camera", false, 1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.00000,0.00000,1.00000,0.00000,0.00000,0.70000,-0.10000,1.00000, "", "")
addbehaviour(objects[7], "camera", 60, 0.3, 1000)
addchild(objects[6], objects[7], false)

