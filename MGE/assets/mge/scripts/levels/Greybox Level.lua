objects = {}
objects[0] = creategameobject("GameObject", false, -1.12, 0, -3.82, 0, -1, 0, 0, 1, 1, 1, "KeyPadLock.obj", "KeyPad")

objects[1] = creategameobject("Cockpit", false, 0, 21.3, 41.47, 0, 0, 0, 1, 1, 1, 1, "Cockpit.obj", "lit")
addbehaviour(objects[1], "meshcollider", false)
addbehaviour(objects[1], "rigidbody", 0, false, false, false, false, false, false, false)
objects[2] = creategameobject("Windows", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "Glass.obj", "litWindows")
addchild(objects[1], objects[2], false)

objects[3] = creategameobject("BGM", false, -1, 2, 3, 0.4619398, -0.1913417, -0.1913417, 0.8446233, 1, 1, 1, "", "")
addbehaviour(objects[3], "audiosource", "test.wav", true, true, true, true, 1, 1, true)

objects[4] = creategameobject("Player", false, 0, 9.7, -1.9, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[4], "player")
objects[5] = creategameobject("Main Camera", false, 0, 0.7, 0.1, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[5], "camera", 60, 0.3, 1000)
addchild(objects[4], objects[5], false)

objects[6] = creategameobject("Directional Light", false, 0, 3, 0, 0.4082179, 0.2345697, -0.1093816, 0.8754261, 1, 1, 1, "", "")
addbehaviour(objects[6], "light", "directional", 1, 0.9568627, 0.8392157, 1, 1, 30)

objects[7] = creategameobject("Door", false, 0, 0, 13.77, 0, 0, 0, 1, 1, 1, 1, "door.obj", "lit")
addbehaviour(objects[7], "meshcollider", true)
addbehaviour(objects[7], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[7], "npc", 1, false, false)

objects[8] = creategameobject("Point light", false, 0.5354313, -4.097783, 43.14, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[8], "light", "point", 0.2797576, 0.1695502, 0.7205882, 1, 1, 30)

objects[9] = creategameobject("Sphere", false, -0.63, -0.5274407, 7.39, 0, 0, 0, 1, 1, 1, 1, "Shape.obj", "lit")
addbehaviour(objects[9], "spherecollider", 1)
addbehaviour(objects[9], "npc", 0, true, false)
addbehaviour(objects[9], "rigidbody", 1, false, false, false, false, false, false, false)
addbehaviour(objects[9], "translationanimation")

