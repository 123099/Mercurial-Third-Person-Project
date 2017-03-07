objects = {}
objects[0] = creategameobject("Spotlight (2)", false, -19.041, 2.626, 6.5, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "", "")
addbehaviour(objects[0], "light", "spot", 0.137327, 0.8349481, 0.9338235, 1, 0.9, 60)

objects[1] = creategameobject("Spotlight (1)", false, -23.76, 3.28, 11.02, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[1], "light", "spot", 0.137327, 0.8349481, 0.9338235, 1, 0.9, 60)

objects[2] = creategameobject("tris", true, -17.87, 0.65, 15.64, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "doorframe")
addbehaviour(objects[2], "meshcollider", false)
addbehaviour(objects[2], "rigidbody", 0, false, false, false, false, false, false, false)

objects[3] = creategameobject("Tv's", false, -11.1787, 4.1, 8.19, 0, 0, 0, 1, 1, 1, 1, "Tv's.obj", "tv's")

objects[4] = creategameobject("Spotlight", false, -4.27, 10.44, 6.52, 0.7071068, 0, 0, 0.7071068, 1, 1, 1, "", "")
addbehaviour(objects[4], "light", "spot", 1, 0, 0, 1, 0, 60)
addbehaviour(objects[4], "lightidentifier", 0)

objects[5] = creategameobject("BrokenCableBroken", false, -14.97, 0.5, 10.66, 0, -1, 0, 0, 0.7, 0.7, 0.7, "brokencablebroken.obj", "brokencable")
addbehaviour(objects[5], "npc", 99, false, false)

objects[6] = creategameobject("pillar (4)", true, -22.46, 0, 15.72, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "pillar.obj", "pillar")
addbehaviour(objects[6], "rigidbody", 0, false, true, true, true, true, true, true)
addbehaviour(objects[6], "meshcollider", true)

objects[7] = creategameobject("generator", false, -0.03, 1.89, 7.04, 0, 0, 0, 1, 0.5, 0.5, 0.5, "generator.obj", "generator")
addbehaviour(objects[7], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[7], "meshcollider", true)

objects[8] = creategameobject("capsule (3)", true, -18.52, 0.503, 2.14, 0, 0, 0, 1, 2.2, 2.2, 2.2, "capsule.obj", "capsule")
addbehaviour(objects[8], "meshcollider", true)
addbehaviour(objects[8], "rigidbody", 0, false, false, false, false, false, false, false)

objects[9] = creategameobject("crate (1)", true, -8.77, 0.63, 20.28, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[9], "meshcollider", true)
addbehaviour(objects[9], "rigidbody", 0, false, true, true, true, true, true, true)

objects[10] = creategameobject("pillar (2)", true, -10.83, 0, 7.94, 0, 0, 0, 1, 1, 1, 1, "pillar.obj", "pillar")
addbehaviour(objects[10], "rigidbody", 0, false, true, true, true, true, true, true)
addbehaviour(objects[10], "meshcollider", true)

objects[11] = creategameobject("Broken cable", true, -0.58, 1.139, 3.59, 0.2705981, -0.6532815, 0.6532815, 0.2705981, 0.1000001, 0.573524, 0.1000002, "shape.obj", "color")
addbehaviour(objects[11], "npc", 0, true, false)
addbehaviour(objects[11], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[11], "capsulecollider", 0.5, 2)

objects[12] = creategameobject("rounddoor", true, -17.78, 0.49, 16.89, 0, 0, 0, 1, 1, 1, 1, "rounddoor.obj", "rounddoor")
addbehaviour(objects[12], "meshcollider", true)
addbehaviour(objects[12], "npc", 4, false, false)
addbehaviour(objects[12], "rigidbody", 0, true, false, false, false, false, false, false)

objects[13] = creategameobject("pillar (3)", true, -11.96, 0, 16.26, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "pillar.obj", "pillar")
addbehaviour(objects[13], "rigidbody", 0, false, true, true, true, true, true, true)
addbehaviour(objects[13], "meshcollider", true)

objects[14] = creategameobject("Walls", true, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")
objects[15] = creategameobject("Wall", true, -5.28, 0.72, 22.7, 0, 0, 0, 1, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[15], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[15], "meshcollider", true)
addchild(objects[14], objects[15], false)
objects[16] = creategameobject("Wall (1)", true, 1.85, 0.72, 22.81, 0, 0, 0, 1, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[16], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[16], "meshcollider", true)
addchild(objects[14], objects[16], false)
objects[17] = creategameobject("wall2corner", true, 2.96, 0.69, 22.75, 0, 0, 0, 1, 1, 1, 1, "corner.obj", "corner")
addbehaviour(objects[17], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[17], "meshcollider", true)
addchild(objects[14], objects[17], false)
objects[18] = creategameobject("Wall (2)", true, 3.25, 0.72, 14.01, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[18], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[18], "meshcollider", true)
addchild(objects[14], objects[18], false)
objects[19] = creategameobject("Wall (3)", true, 3.34, 0.72, 6.99, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[19], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[19], "meshcollider", true)
addchild(objects[14], objects[19], false)
objects[20] = creategameobject("Wall (4)", true, 3.41, 0.72, -0.08, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[20], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[20], "meshcollider", true)
addchild(objects[14], objects[20], false)
objects[21] = creategameobject("wall2corner (1)", true, 3.37, 0.691, -1.824, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "corner.obj", "corner")
addbehaviour(objects[21], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[21], "meshcollider", true)
addchild(objects[14], objects[21], false)
objects[22] = creategameobject("Wall (5)", true, -4.8, 0.72, -1.97, 0, -1, 0, 0, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[22], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[22], "meshcollider", true)
addchild(objects[14], objects[22], false)
objects[23] = creategameobject("Wall (7)", true, -19.67, 0.72, -2.16, 0, -1, 0, 0, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[23], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[23], "meshcollider", true)
addchild(objects[14], objects[23], false)
objects[24] = creategameobject("wall2corner (2)", true, -27.4, 0.69, -2.12, 0, -1, 0, 0, 1, 1, 1, "corner.obj", "corner")
addbehaviour(objects[24], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[24], "meshcollider", true)
addchild(objects[14], objects[24], false)
objects[25] = creategameobject("Wall (8)", true, -27.5, 0.72, 6.64, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[25], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[25], "meshcollider", true)
addchild(objects[14], objects[25], false)
objects[26] = creategameobject("Wall (9)", true, -27.47, 0.72, 13.68, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[26], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[26], "meshcollider", true)
addchild(objects[14], objects[26], false)
objects[27] = creategameobject("Wall (10)", true, -27.42, 0.72, 20.68, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[27], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[27], "meshcollider", true)
addchild(objects[14], objects[27], false)
objects[28] = creategameobject("Wall (11)", true, -14.09, 0.72, 20.83, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[28], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[28], "meshcollider", true)
addchild(objects[14], objects[28], false)
objects[29] = creategameobject("wall2corner (3)", true, -14.045, 0.691, 22.571, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corner.obj", "corner")
addbehaviour(objects[29], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[29], "meshcollider", true)
addchild(objects[14], objects[29], false)
objects[30] = creategameobject("Wall (12)", true, -14.96, 0.72, 16.04, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[30], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[30], "meshcollider", true)
addchild(objects[14], objects[30], false)
objects[31] = creategameobject("Wall (13)", true, -26.57, 0.72, -2.16, 0, -1, 0, 0, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[31], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[31], "meshcollider", true)
addchild(objects[14], objects[31], false)
objects[32] = creategameobject("Wall (14)", true, -20.99, 0.72, 15.58, 0, 0, 0, 1, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[32], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[32], "meshcollider", true)
addchild(objects[14], objects[32], false)
objects[33] = creategameobject("Wall (15)", true, -12.57, 0.72, -2.16, 0, -1, 0, 0, 1, 1, 1, "wall2.obj", "wall2")
addbehaviour(objects[33], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[33], "meshcollider", true)
addchild(objects[14], objects[33], false)

objects[34] = creategameobject("Keypad", false, -23.456, 2.924, 15.33, 0, 0, 0, 1, 1.358284, 1.358284, 1.358284, "Keypad.obj", "Keypad")
addbehaviour(objects[34], "npc", 2, false, false)
addbehaviour(objects[34], "rigidbody", 0, true, false, false, false, false, false, false)
addbehaviour(objects[34], "boxcollider", 1.358284, 0.6791422, 0.679142)

objects[35] = creategameobject("table", true, -4.62, 0.57, 14.33, 0, -0.3826835, 0, 0.9238795, 1, 1, 1, "table.obj", "table")
addbehaviour(objects[35], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[35], "meshcollider", true)

objects[36] = creategameobject("Keycard", false, -5.93, 2.549, 12.72, 0, 0, 0, 1, 0.2, 0.2, 0.2, "keycard.obj", "keycard")
addbehaviour(objects[36], "npc", 25, true, false)
addbehaviour(objects[36], "rigidbody", 1, false, false, false, false, false, false, false)
addbehaviour(objects[36], "meshcollider", true)

objects[37] = creategameobject("Floor", true, 0, 0, 25.83, 0, 0, 0, 1, 60, 1, 60, "plane.obj", "lit")
addbehaviour(objects[37], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[37], "boxcollider", 30, 0.5, 30)

objects[38] = creategameobject("capsule (2)", true, -6.05, 0.503, 2.14, 0, 0, 0, 1, 2.2, 2.2, 2.2, "capsule.obj", "capsule")
addbehaviour(objects[38], "meshcollider", true)
addbehaviour(objects[38], "rigidbody", 0, false, false, false, false, false, false, false)

objects[39] = creategameobject("pillar (1)", true, -22.26, 0, 6.41, 0, 0, 0, 1, 1, 1, 1, "pillar.obj", "pillar")
addbehaviour(objects[39], "rigidbody", 0, false, true, true, true, true, true, true)
addbehaviour(objects[39], "meshcollider", true)

objects[40] = creategameobject("fingerprintscanner", true, -21.77, 2.619, 6.447, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "fingerprintscanner.obj", "fingerprintscanner")
addbehaviour(objects[40], "rigidbody", 0, true, true, true, true, true, true, true)
addbehaviour(objects[40], "meshcollider", true)
addbehaviour(objects[40], "npc", 1, false, false)

objects[41] = creategameobject("crate", true, -5.89, 0.63, 20.28, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[41], "rigidbody", 0, false, true, true, true, true, true, true)
addbehaviour(objects[41], "meshcollider", true)

objects[42] = creategameobject("BGM", false, -14.16089, 5.704401, 5.262645, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[42], "audiosource", "bgm.wav", true, true, true, true, 1, 0.3, true)

objects[43] = creategameobject("Directional Light", true, 3.4, 6.97, -7.03, 0.3535534, -0.3535534, 0.1464466, 0.8535535, 1, 1, 1, "", "")
addbehaviour(objects[43], "light", "directional", 0.5519031, 0.6910034, 0.8529412, 1, 0.1, 30)

objects[44] = creategameobject("capsule (1)", true, -12.52, 0.503, 2.14, 0, 0, 0, 1, 2.2, 2.2, 2.2, "capsule.obj", "capsule")
addbehaviour(objects[44], "meshcollider", true)
addbehaviour(objects[44], "rigidbody", 0, false, false, false, false, false, false, false)

objects[45] = creategameobject("Player", false, -1.18, 2.125, 2.43, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[45], "player", 8)
addbehaviour(objects[45], "charactercontroller", 45, 0.3, 0.5, 2)
objects[46] = creategameobject("Camera", false, 0, 1.281, -0.013, 0, -1, 0, -4.371139E-08, 1, 1, 1, "", "")
addbehaviour(objects[46], "camera", 60, 0.3, 1000)
addbehaviour(objects[46], "audiolistener")
addchild(objects[45], objects[46], false)
