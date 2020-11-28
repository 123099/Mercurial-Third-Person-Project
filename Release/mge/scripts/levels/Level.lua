objects = {}
objects[0] = creategameobject("straightwall (4)", false, -7.959999, 0.72, 22.82, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[0], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[0], "boxcollider", 3.5, 6, 0.5)

objects[1] = creategameobject("straightwall (17)", false, -9.3, 0.72, 14.3, 0, -0.3826834, 0, 0.9238796, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[1], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[1], "boxcollider", 2.828428, 6, 2.828427)

objects[2] = creategameobject("Directional Light", false, 0, 3, 0, 0.4082179, 0.2345697, -0.1093816, 0.8754261, 1, 1, 1, "", "")
addbehaviour(objects[2], "light", "directional", 1, 0.9568627, 0.8392157, 1, 1, 30)

objects[3] = creategameobject("Player", false, -7.817, 2.125, 6.166, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[3], "player")
objects[4] = creategameobject("Camera", false, 0, 0.56, -0.11, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[4], "camera", 60, 0.3, 1000)
addchild(objects[3], objects[4], false)

objects[5] = creategameobject("pillar (3)", false, -11.01, 0.680001, 22.01, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[5], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[5], "boxcollider", 0.5, 0.5, 0.5)

objects[6] = creategameobject("pillar", false, -17.42, 0.680001, 3.07, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[6], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[6], "boxcollider", 0.5, 0.5, 0.5)

objects[7] = creategameobject("pillar (2)", false, -5.38, 0.680001, 22.01, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[7], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[7], "boxcollider", 0.5, 0.5, 0.5)

objects[8] = creategameobject("pillar (1)", false, -5.49, 0.680001, 3.07, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[8], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[8], "boxcollider", 0.5, 0.5, 0.5)

objects[9] = creategameobject("fingerprintscanner", false, -18.05, 1.16, 8.1, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "", "")
addbehaviour(objects[9], "npc", 1, true, false)
addbehaviour(objects[9], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[9], "boxcollider", 0.5, 0.5, 0.5)

objects[10] = creategameobject("Table", false, -11.91571, 2.090361, 9.417349, 0, 0, 0, 1, 4, 0.2, 3, "", "")
addbehaviour(objects[10], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[10], "boxcollider", 2, 0.0999999, 1.5)

objects[11] = creategameobject("Tablet", false, -11.67571, 2.26736, 9.78735, 0, 0, 0, 1, 0.7, 0.1, 1, "plane.obj", "lit")
addbehaviour(objects[11], "npc", 3, true, false)
addbehaviour(objects[11], "boxcollider", 0.3500004, 0.04999995, 0.5)
addbehaviour(objects[11], "rigidbody", 1, false, false, false, false, false, false, false)

objects[12] = creategameobject("Generator", false, -5.16, 1.89036, 10.17735, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[12], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[12], "boxcollider", 0.5, 1, 0.5)

objects[13] = creategameobject("Cable (5)", false, -17.93125, 1.403914, 10.78869, 0.7071068, 0, 0, 0.7071068, 0.09999999, 2.429113, 0.1000001, "", "")

objects[14] = creategameobject("Cable (2)", false, -15.32, 1.293914, 4.87869, 0.5, -0.5, 0.5, 0.5, 0.1, 1.657918, 0.1, "", "")

objects[15] = creategameobject("Cable", false, -5.701252, 1.093914, 14.46869, 0.7053843, -0.04932528, 0.04932528, 0.7053843, 0.1, 4.038383, 0.1, "", "")

objects[16] = creategameobject("Cable (1)", false, -8.03, 1.093914, 19.77869, 0.5, -0.5, 0.5, 0.5, 0.1, 1.657918, 0.1, "", "")

objects[17] = creategameobject("Cable (4)", false, -17.93125, 2.693913, 13.17869, 0, 0, 0, 1, 0.1, 1.317898, 0.1, "", "")

objects[18] = creategameobject("Broken cable", false, -7.559999, 1.093914, 7.53869, 0.2705981, -0.6532815, 0.6532815, 0.2705981, 0.1000001, 3.500002, 0.1000001, "", "")
addbehaviour(objects[18], "npc", 0, true, false)

objects[19] = creategameobject("Cable (3)", false, -11.38, 1.293914, 4.87869, 0.5, -0.5, 0.5, 0.5, 0.1, 1.657918, 0.1, "", "")

objects[20] = creategameobject("hibernatecapsule (4)", false, -9.830002, 0.72, 19.07, 0, -1, 0, 0, 1, 1, 1, "hibernatecapsule.obj", "hibernatecapsule")
addbehaviour(objects[20], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[20], "boxcollider", 0.5, 0.5, 0.5)

objects[21] = creategameobject("hibernatecapsule (2)", false, -16.58, 0.72, 5.14, 0, 0, 0, 1, 1, 1, 1, "hibernatecapsule.obj", "hibernatecapsule")
addbehaviour(objects[21], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[21], "boxcollider", 0.5, 0.5, 0.5)

objects[22] = creategameobject("hibernatecapsule", false, -9.950001, 0.72, 5.14, 0, 0, 0, 1, 1, 1, 1, "hibernatecapsule.obj", "hibernatecapsule")
addbehaviour(objects[22], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[22], "boxcollider", 0.5, 0.5, 0.5)

objects[23] = creategameobject("straightwall (5)", false, -18.26, 0.72, 5.69, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[23], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[23], "boxcollider", 0.5, 6, 3.500001)

objects[24] = creategameobject("straightwall (7)", false, -18.26, 0.72, 12.66, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[24], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[24], "boxcollider", 0.5, 6, 3.500002)

objects[25] = creategameobject("straightwall (2)", false, -4.450001, 0.72, 5.4, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[25], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[25], "boxcollider", 0.5000005, 6, 3.500001)

objects[26] = creategameobject("straightwall (8)", false, -11.93, 0.72, 20.04, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[26], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[26], "boxcollider", 0.500001, 6, 3.500002)

objects[27] = creategameobject("rounddoor", false, -15.01, 0.7200003, 17.13, 0, 0, 0, 1, 1, 1, 1, "rounddoor.obj", "rounddoor")
addbehaviour(objects[27], "npc", 4, true, true)
addbehaviour(objects[27], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[27], "boxcollider", 0.5, 0.5, 0.5)

objects[28] = creategameobject("straightwall", false, -15.02, 0.72, 2.1, 0, -1, 0, 0, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[28], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[28], "boxcollider", 3.5, 6, 0.5)

objects[29] = creategameobject("Keypad", false, -18.14171, 3.741, 13.61935, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Keypad.obj", "Keypad")
addbehaviour(objects[29], "npc", 2, true, false)

objects[30] = creategameobject("straightwall (1)", false, -7.959999, 0.72, 2.1, 0, -1, 0, 0, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[30], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[30], "boxcollider", 3.5, 6, 0.5)

objects[31] = creategameobject("hibernatecapsule (3)", false, -6.43, 0.72, 19.17, 0, -1, 0, 0, 1, 1, 1, "hibernatecapsule.obj", "hibernatecapsule")
addbehaviour(objects[31], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[31], "boxcollider", 0.5, 0.5, 0.5)

objects[32] = creategameobject("Floor", false, -6.88, 0.18, 25.83, 0, 0, 0, 1, 25, 1, 60, "plane.obj", "lit")
addbehaviour(objects[32], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[32], "boxcollider", 312.5, 0.5, 1800)

objects[33] = creategameobject("straightwall (9)", false, -12.36, 0.72, 19.41, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[33], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[33], "boxcollider", 0.500001, 6, 3.500002)

objects[34] = creategameobject("straightwall (13)", false, -18.26, 0.72, 19.94, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[34], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[34], "boxcollider", 0.5, 6, 3.500002)

objects[35] = creategameobject("straightwall (3)", false, -4.48, 0.72, 12.39, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[35], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[35], "boxcollider", 0.5000005, 6, 3.500002)

objects[36] = creategameobject("straightwall (6)", false, -4.48, 0.72, 19.41, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[36], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[36], "boxcollider", 0.5000005, 6, 3.500002)

objects[37] = creategameobject("hibernatecapsule (1)", false, -13.07, 0.72, 5.14, 0, 0, 0, 1, 1, 1, 1, "hibernatecapsule.obj", "hibernatecapsule")
addbehaviour(objects[37], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[37], "boxcollider", 0.5, 0.5, 0.5)

