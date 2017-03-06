objects = {}
objects[0] = creategameobject("Directional Light (1)", false, 8.98, 24.5, -35.79, 0.5782874, -0.2183753, -0.4915552, 0.6134081, 1, 1, 1, "", "")
addbehaviour(objects[0], "light", "directional", 1, 0.9568627, 0.8392157, 1, 0.35, 30)

objects[1] = creategameobject("Directional Light", false, 11.46, 22.87, -37, 0.6831398, -0.05744888, -0.3307006, 0.6485807, 1, 1, 1, "", "")
addbehaviour(objects[1], "light", "directional", 1, 0.9568627, 0.8392157, 1, 1, 30)

objects[2] = creategameobject("Player", false, -86.59, 23.99, -34.97, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[2], "player", 8)
addbehaviour(objects[2], "charactercontroller", 45, 0.3, 0.5, 2)
objects[3] = creategameobject("Camera", false, 0, 1.41, 0, 0, -1, 0, -4.371139E-08, 1, 1, 1, "", "")
addbehaviour(objects[3], "camera", 60, 0.3, 1000)
addbehaviour(objects[3], "audiolistener")
addchild(objects[2], objects[3], false)

objects[4] = creategameobject("tris", true, -64.95, 22.77, -50.39, 0, -1, 0, 0, 1, 1, 1, "doorframe.obj", "doorframe")
addbehaviour(objects[4], "meshcollider", false)
addbehaviour(objects[4], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[5] = creategameobject("rounddoor", false, -64.81427, 22.77, -49.42999, 0, 0, 0, 1, 1, 1, 1, "rounddoor.obj", "rounddoor")
addbehaviour(objects[5], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[5], "meshcollider", true)

objects[6] = creategameobject("CeilingLamp_Tri", true, -79.39, 31.5, -56.52, 0, 0, 0, 1, 1, 1, 1, "ceilinglamp.obj", "ceilinglamp")
addbehaviour(objects[6], "meshcollider", true)
addbehaviour(objects[6], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[7] = creategameobject("crate (7)", true, -87.05388, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[7], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[7], "meshcollider", true)

objects[8] = creategameobject("crate (5)", true, -71.64982, 26.47, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[8], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[8], "meshcollider", true)

objects[9] = creategameobject("crate (6)", true, -71.77184, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[9], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[9], "meshcollider", true)

objects[10] = creategameobject("crate (4)", true, -67.74512, 22.77, -27.45414, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[10], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[10], "meshcollider", true)

objects[11] = creategameobject("crate (3)", true, -77.58985, 22.77, -27.45414, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[11], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[11], "meshcollider", true)

objects[12] = creategameobject("pasted__pCube85_group", true, -69.04, 22.9, -51.19, 0, 0.05096556, 0, 0.9987004, 1.000837, 1, 1.000837, "pillar.obj", "pillar")
addbehaviour(objects[12], "meshcollider", true)
addbehaviour(objects[12], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[13] = creategameobject("Wall (49)", true, -59.87, 22.9, -68.15, 0, 0.7071068, 0, -0.7071068, 1, 1, -1, "straightwall.obj", "straightwall")
addbehaviour(objects[13], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[13], "meshcollider", true)

objects[14] = creategameobject("Drawer (11)", true, -90.03609, 27.92, -40.34682, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[14], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[14], "meshcollider", true)

objects[15] = creategameobject("Wall (18)", true, -69.25, 22.9, -59.78, 0, 0.7071068, 0, 0.7071068, 1, 1, -1, "straightwall.obj", "straightwall")
addbehaviour(objects[15], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[15], "meshcollider", true)

objects[16] = creategameobject("Wall (21)", true, -82.35, 22.9, -64.3, 0, -1, 0, 0, -1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[16], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[16], "meshcollider", true)

objects[17] = creategameobject("Wall (3)", true, -84.018, 22.9, -25.694, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[17], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[17], "meshcollider", true)

objects[18] = creategameobject("Wall (25)", true, -88.61, 22.92918, -39.16, 0.1359903, -0.6939068, 0.1359903, 0.6939068, 1, 1.009971, 1.009971, "straightwall.obj", "straightwall")
addbehaviour(objects[18], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[18], "meshcollider", true)

objects[19] = creategameobject("Wall (33)", true, -89.44, 29.95, -53.16, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1.01196, 1.01196, "straightwall.obj", "straightwall")
addbehaviour(objects[19], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[19], "meshcollider", true)

objects[20] = creategameobject("Wall (26)", true, -88.61, 22.92918, -32.04, 0.1359903, -0.6939068, 0.1359903, 0.6939068, 1, 1.009971, 1.009971, "straightwall.obj", "straightwall")
addbehaviour(objects[20], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[20], "meshcollider", true)

objects[21] = creategameobject("wallnopillar_Walls", true, -57.807, 26.012, -30.943, 0, -1, 0, 0, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[21], "meshcollider", true)
addbehaviour(objects[21], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[22] = creategameobject("Wall (14)", true, -56.38, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[22], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[22], "meshcollider", true)

objects[23] = creategameobject("Drawer (12)", true, -90.03609, 27.92, -51.85096, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[23], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[23], "meshcollider", true)

objects[24] = creategameobject("Wall (42)", true, -69.25, 28.97, -66.83, 0, 0.7071068, 0, 0.7071068, 1, 1, -1, "straightwall.obj", "straightwall")
addbehaviour(objects[24], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[24], "meshcollider", true)

objects[25] = creategameobject("Wall (23)", true, -88.61, 22.92918, -53.16, 0.1359903, -0.6939068, 0.1359903, 0.6939068, 1, 1.009971, 1.009971, "straightwall.obj", "straightwall")
addbehaviour(objects[25], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[25], "meshcollider", true)

objects[26] = creategameobject("Wall (39)", true, -70.06, 28.96, -52.69, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[26], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[26], "meshcollider", true)

objects[27] = creategameobject("wallnopillar_Walls (1)", true, -70.06, 26.01, -59.02, 0, -1, 0, 0, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[27], "meshcollider", true)
addbehaviour(objects[27], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[28] = creategameobject("Drawer (2)", true, -58.423, 27.92, -48.00976, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer")
addbehaviour(objects[28], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[28], "meshcollider", true)

objects[29] = creategameobject("tv_set:polySurface5", true, -73.99264, 31.72438, -40.98919, 0, 0, 0, 1, 0.5695158, 0.5695158, 0.5695158, "Tv's.obj", "tv's")

objects[30] = creategameobject("Wall (6)", true, -70.09, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[30], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[30], "meshcollider", true)

objects[31] = creategameobject("Wall (27)", true, -88.61, 22.92918, -25.04, 0.1359903, -0.6939068, 0.1359903, 0.6939068, 1, 1.009971, 1.009971, "straightwall.obj", "straightwall")
addbehaviour(objects[31], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[31], "meshcollider", true)

objects[32] = creategameobject("Drawer (4)", true, -58.423, 27.92, -32.66442, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer")
addbehaviour(objects[32], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[32], "meshcollider", true)

objects[33] = creategameobject("Drawer (6)", true, -90.03609, 27.92, -28.84269, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[33], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[33], "meshcollider", true)

objects[34] = creategameobject("Wall (10)", true, -58.68, 29.7666, -45, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "straightwall.obj", "straightwall")
addbehaviour(objects[34], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[34], "meshcollider", true)

objects[35] = creategameobject("Wall (32)", true, -89.44, 29.95, -46.18, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1.01196, 1.01196, "straightwall.obj", "straightwall")
addbehaviour(objects[35], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[35], "meshcollider", true)

objects[36] = creategameobject("Wall", true, -77.11, 22.9, -25.69, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[36], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[36], "meshcollider", true)

objects[37] = creategameobject("Wall (22)", true, -88.61, 22.92918, -60.15, 0.1359903, -0.6939068, 0.1359903, 0.6939068, 1, 1.009971, 1.009971, "straightwall.obj", "straightwall")
addbehaviour(objects[37], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[37], "meshcollider", true)

objects[38] = creategameobject("wallnopillartri", true, -72.93267, 26.01245, -51.04012, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[38], "meshcollider", true)
addbehaviour(objects[38], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[39] = creategameobject("Wall (40)", true, -70.06, 28.96, -59.66, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[39], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[39], "meshcollider", true)

objects[40] = creategameobject("Wall (24)", true, -88.61, 22.92918, -46.18, 0.1359903, -0.6939068, 0.1359903, 0.6939068, 1, 1.009971, 1.009971, "straightwall.obj", "straightwall")
addbehaviour(objects[40], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[40], "meshcollider", true)

objects[41] = creategameobject("Wall (13)", true, -58.68, 29.7666, -23.67, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "straightwall.obj", "straightwall")
addbehaviour(objects[41], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[41], "meshcollider", true)

objects[42] = creategameobject("wallnopillar_Walls (2)", true, -58.76, 32.14, -50.48, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[42], "meshcollider", true)
addbehaviour(objects[42], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[43] = creategameobject("Drawer (9)", true, -90.03609, 27.92, -48.00976, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[43], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[43], "meshcollider", true)

objects[44] = creategameobject("Wall (36)", true, -86.7, 28.96, -64.55, 0, -1, 0, 0, -1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[44], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[44], "meshcollider", true)

objects[45] = creategameobject("Wall (11)", true, -58.68, 29.7666, -37.98, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "straightwall.obj", "straightwall")
addbehaviour(objects[45], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[45], "meshcollider", true)

objects[46] = creategameobject("Wall (16)", true, -70.06, 22.9, -52.69, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[46], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[46], "meshcollider", true)

objects[47] = creategameobject("Wall (28)", true, -90.41, 22.9, -25.694, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[47], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[47], "meshcollider", true)

objects[48] = creategameobject("Wall (12)", true, -58.68, 29.7666, -30.77, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "straightwall.obj", "straightwall")
addbehaviour(objects[48], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[48], "meshcollider", true)

objects[49] = creategameobject("pasted__pCube85_group", true, -73.98, 22.9, -40.76, 0, -0.4153649, 0, 0.9096549, 1.01999, 1, 1.01999, "pillar.obj", "pillar")
addbehaviour(objects[49], "meshcollider", true)
addbehaviour(objects[49], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[50] = creategameobject("quad:Wall_Corner", true, -70.4099, 22.8974, -63.953, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "corner.obj", "corner")
addbehaviour(objects[50], "meshcollider", true)
addbehaviour(objects[50], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[51] = creategameobject("Drawer (7)", true, -90.03609, 27.92, -32.66442, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[51], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[51], "meshcollider", true)

objects[52] = creategameobject("Drawer (3)", true, -58.423, 27.92, -36.50562, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer")
addbehaviour(objects[52], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[52], "meshcollider", true)

objects[53] = creategameobject("Wall (44)", true, -58.68, 29.7666, -59.14, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "straightwall.obj", "straightwall")
addbehaviour(objects[53], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[53], "meshcollider", true)

objects[54] = creategameobject("Wall (7)", true, -77.11, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[54], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[54], "meshcollider", true)

objects[55] = creategameobject("Wall (34)", true, -89.44, 29.95, -60.15, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1.01196, 1.01196, "straightwall.obj", "straightwall")
addbehaviour(objects[55], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[55], "meshcollider", true)

objects[56] = creategameobject("Wall (30)", true, -89.44, 29.95, -32.04, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1.01196, 1.01196, "straightwall.obj", "straightwall")
addbehaviour(objects[56], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[56], "meshcollider", true)

objects[57] = creategameobject("Wall (45)", true, -58.68, 29.7666, -66.15, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "straightwall.obj", "straightwall")
addbehaviour(objects[57], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[57], "meshcollider", true)

objects[58] = creategameobject("pasted__pCube85_group", true, -69.04, 22.9, -50.184, 0, 0.05096556, 0, 0.9987004, 1.000837, 1, 1.000837, "pillar.obj", "pillar")
addbehaviour(objects[58], "meshcollider", true)
addbehaviour(objects[58], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[59] = creategameobject("Drawer (15)", true, -90.03609, 27.92, -59.50741, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[59], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[59], "meshcollider", true)

objects[60] = creategameobject("Wall (20)", true, -75.32, 22.9, -64.3, 0, -1, 0, 0, -1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[60], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[60], "meshcollider", true)

objects[61] = creategameobject("Wall (35)", true, -79.85, 28.96, -64.55, 0, -1, 0, 0, -1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[61], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[61], "meshcollider", true)

objects[62] = creategameobject("Drawer", true, -58.423, 27.92, -40.34682, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer")
addbehaviour(objects[62], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[62], "meshcollider", true)

objects[63] = creategameobject("quad:Wall_Corner", true, -58.157, 22.899, -26.041, 0, 0, 0, 1, 1, 1, 1, "corner.obj", "corner")
addbehaviour(objects[63], "meshcollider", true)
addbehaviour(objects[63], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[64] = creategameobject("pasted__pCube85_group", true, -59.972, 22.9, -50.184, 0, 0.05096556, 0, 0.9987004, 1.000837, 1, 1.000837, "pillar.obj", "pillar")
addbehaviour(objects[64], "meshcollider", true)
addbehaviour(objects[64], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[65] = creategameobject("Wall (8)", true, -57.81, 22.9, -37.98, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[65], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[65], "meshcollider", true)

objects[66] = creategameobject("Wall (43)", true, -69.25, 28.97, -59.78, 0, 0.7071068, 0, 0.7071068, 1, 1, -1, "straightwall.obj", "straightwall")
addbehaviour(objects[66], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[66], "meshcollider", true)

objects[67] = creategameobject("Wall (50)", true, -64.98, 29.02, -51.01, 0, -1, 0, 0, -1, 1, -1, "straightwall.obj", "straightwall")
addbehaviour(objects[67], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[67], "meshcollider", true)

objects[68] = creategameobject("Wall (29)", true, -89.44, 29.95, -25.04, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1.01196, 1.01196, "straightwall.obj", "straightwall")
addbehaviour(objects[68], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[68], "meshcollider", true)

objects[69] = creategameobject("Wall (17)", true, -69.25, 22.9, -52.69, 0, 0.7071068, 0, 0.7071068, 1, 1, -1, "straightwall.obj", "straightwall")
addbehaviour(objects[69], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[69], "meshcollider", true)

objects[70] = creategameobject("pasted__pCube85_group", true, -59.972, 22.9, -51.19, 0, 0.05096556, 0, 0.9987005, 1.000837, 1, 1.000837, "pillar.obj", "pillar")
addbehaviour(objects[70], "meshcollider", true)
addbehaviour(objects[70], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[71] = creategameobject("Wall (37)", true, -72.84, 28.96, -64.55, 0, -1, 0, 0, -1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[71], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[71], "meshcollider", true)

objects[72] = creategameobject("Wall (48)", true, -59.67, 22.9, -61.06, 0, 0.7071068, 0, -0.7071068, 1, 1, -1, "straightwall.obj", "straightwall")
addbehaviour(objects[72], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[72], "meshcollider", true)

objects[73] = creategameobject("Wall (19)", true, -69.25, 22.9, -66.83, 0, 0.7071068, 0, 0.7071068, 1, 1, -1, "straightwall.obj", "straightwall")
addbehaviour(objects[73], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[73], "meshcollider", true)

objects[74] = creategameobject("Wall (1)", true, -70.09, 22.9, -25.69, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[74], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[74], "meshcollider", true)

objects[75] = creategameobject("Wall (4)", true, -84.018, 29.11, -25.62, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[75], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[75], "meshcollider", true)

objects[76] = creategameobject("quad:Wall_Corner", true, -58.157, 22.9, -49.917, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "corner.obj", "corner")
addbehaviour(objects[76], "meshcollider", true)
addbehaviour(objects[76], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[77] = creategameobject("Wall (2)", true, -63.07, 22.9, -25.69, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[77], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[77], "meshcollider", true)

objects[78] = creategameobject("Wall (46)", true, -64.98, 29.02, -50.52, 0, -1, 0, 0, -1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[78], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[78], "meshcollider", true)

objects[79] = creategameobject("Wall (41)", true, -70.06, 28.96, -66.55, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[79], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[79], "meshcollider", true)

objects[80] = creategameobject("Wall (5)", true, -63.07, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[80], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[80], "meshcollider", true)

objects[81] = creategameobject("wallnopillar_Walls (3)", true, -58.76, 32.14, -50.97, 0, -0.7071068, 0, 0.7071068, -1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[81], "meshcollider", true)
addbehaviour(objects[81], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[82] = creategameobject("Wall (47)", true, -59.48, 22.9, -54.01, 0, 0.7071068, 0, -0.7071068, 1, 1, -1, "straightwall.obj", "straightwall")
addbehaviour(objects[82], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[82], "meshcollider", true)

objects[83] = creategameobject("Drawer (14)", true, -90.03609, 27.92, -55.67919, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[83], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[83], "meshcollider", true)

objects[84] = creategameobject("Wall (15)", true, -58.68, 29.7666, -51.97, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "straightwall.obj", "straightwall")
addbehaviour(objects[84], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[84], "meshcollider", true)

objects[85] = creategameobject("Drawer (10)", true, -90.03609, 27.92, -44.18154, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[85], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[85], "meshcollider", true)

objects[86] = creategameobject("quad:Wall_Corner", true, -89.05101, 22.9, -63.956, 0, 1, 0, 0, 1, 1, 1, "corner.obj", "corner")
addbehaviour(objects[86], "meshcollider", true)
addbehaviour(objects[86], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[87] = creategameobject("Wall (38)", true, -69.249, 28.96, -52.69, 0, 0.7071068, 0, 0.7071068, 1, 1, -1, "straightwall.obj", "straightwall")
addbehaviour(objects[87], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[87], "meshcollider", true)

objects[88] = creategameobject("Drawer (5)", true, -58.423, 27.92, -28.84269, 0, 1, 0, 0, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[88], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[88], "meshcollider", true)

objects[89] = creategameobject("Wall (51)", true, -90.7, 29.11, -25.62, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[89], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[89], "meshcollider", true)

objects[90] = creategameobject("Drawer (8)", true, -90.03609, 27.92, -36.50562, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[90], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[90], "meshcollider", true)

objects[91] = creategameobject("Wall (31)", true, -89.44, 29.95, -39.16, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1.01196, 1.01196, "straightwall.obj", "straightwall")
addbehaviour(objects[91], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[91], "meshcollider", true)

objects[92] = creategameobject("Keycard", false, -81.159, 24.4444, -52.877, 0.3524841, -0.3524841, -0.6129886, 0.6129886, 0.2039832, 0.2071294, 0.2071293, "keycard.obj", "keycard")
addbehaviour(objects[92], "rigidbody", 1, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[92], "meshcollider", true)

objects[93] = creategameobject("Wall (9)", true, -57.81, 22.9, -45, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[93], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[93], "meshcollider", true)

objects[94] = creategameobject("Drawer (1)", true, -58.423, 27.92, -44.18154, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer")
addbehaviour(objects[94], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[94], "meshcollider", true)

objects[95] = creategameobject("crate (1)", true, -83.96, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[95], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[95], "meshcollider", true)

objects[96] = creategameobject("crate (2)", true, -86.85376, 26.47, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[96], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[96], "meshcollider", true)

objects[97] = creategameobject("BrokenCableBroken", false, -63.1, 22.9, -45.743, 0, 0, 0, 1, 1, 1, 1, "brokencablebroken.obj", "brokencable")

objects[98] = creategameobject("capsule (4)", true, -80.81, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule")
addbehaviour(objects[98], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[98], "meshcollider", true)

objects[99] = creategameobject("capsule", true, -61.85, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule")
addbehaviour(objects[99], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[99], "meshcollider", true)

objects[100] = creategameobject("Generator", true, -85.939, 22.901, -41.491, 0, -0.7071068, 0, -0.7071068, 0.7960583, 0.7960575, 0.7960584, "generator.obj", "generator")
addbehaviour(objects[100], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[100], "meshcollider", true)

objects[101] = creategameobject("table", true, -79.11, 22.884, -53.33, 0, 0, 0, 1, 0.4131236, 0.4131236, 0.4131236, "table.obj", "table")
addbehaviour(objects[101], "meshcollider", true)
addbehaviour(objects[101], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[102] = creategameobject("capsule (3)", true, -71.38, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule")
addbehaviour(objects[102], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[102], "meshcollider", true)

objects[103] = creategameobject("Keypad", true, -69.666, 24.89, -48.7, 0, -1, 0, 0, 1, 1, 1, "keypad.obj", "keypad")
addbehaviour(objects[103], "meshcollider", true)
addbehaviour(objects[103], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[104] = creategameobject("capsule (2)", true, -74.39, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule")
addbehaviour(objects[104], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[104], "meshcollider", true)

objects[105] = creategameobject("capsule (1)", true, -64.86, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule")
addbehaviour(objects[105], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[105], "meshcollider", true)

objects[106] = creategameobject("capsule (5)", true, -83.82, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule")
addbehaviour(objects[106], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[106], "meshcollider", true)

objects[107] = creategameobject("FingerPrintScanner", true, -58.108, 24.661, -34.498, 0, 0.7071068, 0, 0.7071068, 0.848711, 0.84871, 0.848711, "fingerprintscanner.obj", "fingerprintscanner")
addbehaviour(objects[107], "meshcollider", true)
addbehaviour(objects[107], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[108] = creategameobject("Plane", true, -72.83281, 22.77, -49.217, 0, 0, 0, 1, 10, 1, 10, "plane.obj", "ground")
addbehaviour(objects[108], "rigidbody", 1, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[108], "boxcollider", 50, 0, 50)

