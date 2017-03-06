objects = {}
objects[112] = creategameobject("PostProcessors", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[112], "fog")
addbehaviour(objects[112], "vignette")
addbehaviour(objects[112], "contrast", 0.08)

objects[113] = creategameobject("Spotlight", false, -79.495, 27.249, -53.194, 0.7071068, 0, 0, 0.7071068, 1, 1, 1, "", "")
addbehaviour(objects[113], "light", "spot", 1, 0.2279412, 0.2279412, 1, 0, 70)
addbehaviour(objects[113], "lightidentifier", 0)

objects[114] = creategameobject("BrokenCableTrigger", true, -83.281, 23.136, -34.943, 0.689055, -0.1587554, 0.1587553, 0.689055, 0.5409834, 0.8087289, 0.5409834, "", "")
addbehaviour(objects[114], "capsulecollider", 0.5, 2)
addbehaviour(objects[114], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[114], "npc", 0, true, false)

objects[115] = creategameobject("Keycard", false, -80.198, 24.502, -53.155, 0.3524841, -0.3524841, -0.6129886, 0.6129886, 0.2039833, 0.2071294, 0.2071294, "KeycardFrame.obj", "KeycardFrame")
addbehaviour(objects[115], "rigidbody", 1, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[115], "meshcollider", true)
addbehaviour(objects[115], "npc", 25, true, false)
objects[116] = creategameobject("glass", false, 0, 0, 0, 0, 0, -2.235174E-08, 1, 1, 1, 1, "KeycardGlass.obj", "KeycardGlass")
addchild(objects[115], objects[116], false)

objects[117] = creategameobject("Drawer (1)", true, -58.423, 27.92, -44.18154, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer")
addbehaviour(objects[117], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[117], "meshcollider", true)

objects[118] = creategameobject("Wall (9)", true, -57.81, 22.9, -45, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[118], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[118], "meshcollider", true)

objects[119] = creategameobject("Wall (31)", true, -89.44, 29.95, -39.16, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1.01196, 1.01196, "Walls/Wall.obj", "Wall")
addbehaviour(objects[119], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[119], "meshcollider", true)

objects[120] = creategameobject("Drawer (8)", true, -90.03609, 27.92, -36.50562, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[120], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[120], "meshcollider", true)

objects[121] = creategameobject("Wall (51)", true, -90.7, 29.11, -25.62, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[121], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[121], "meshcollider", true)

objects[122] = creategameobject("Drawer (5)", true, -58.423, 27.92, -28.84269, 0, 1, 0, 0, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[122], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[122], "meshcollider", true)

objects[123] = creategameobject("Wall (38)", true, -69.249, 28.96, -52.69, 0, 0.7071068, 0, 0.7071068, 1, 1, -1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[123], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[123], "meshcollider", true)

objects[124] = creategameobject("quad:Wall_Corner", true, -89.05101, 22.9, -63.956, 0, 1, 0, 0, 1, 1, 1, "Walls/Corner.obj", "corner")
addbehaviour(objects[124], "meshcollider", true)
addbehaviour(objects[124], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[125] = creategameobject("Drawer (10)", true, -90.03609, 27.92, -44.18154, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[125], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[125], "meshcollider", true)

objects[126] = creategameobject("Wall (15)", true, -58.68, 29.7666, -51.97, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[126], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[126], "meshcollider", true)

objects[127] = creategameobject("Drawer (14)", true, -90.03609, 27.92, -55.67919, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[127], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[127], "meshcollider", true)

objects[128] = creategameobject("Wall (47)", true, -59.48, 22.9, -54.01, 0, 0.7071068, 0, -0.7071068, 1, 1, -1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[128], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[128], "meshcollider", true)

objects[129] = creategameobject("wallnopillar_Walls (3)", true, -58.76, 32.14, -50.97, 0, -0.7071068, 0, 0.7071068, -1, 1, 1, "Walls/WallNoPillar.obj", "Wall")
addbehaviour(objects[129], "meshcollider", true)
addbehaviour(objects[129], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[130] = creategameobject("DoorFrame", true, -64.95, 22.77, -50.39, 0, -1, 0, 0, 1, 1, 1, "Walls/DoorWall.obj", "doorframe")
addbehaviour(objects[130], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[130], "meshcollider", false)

objects[131] = creategameobject("Wall (5)", true, -63.07, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[131], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[131], "meshcollider", true)

objects[132] = creategameobject("Wall (41)", true, -70.06, 28.96, -66.55, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[132], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[132], "meshcollider", true)

objects[133] = creategameobject("Wall (46)", true, -64.98, 29.02, -50.52, 0, -1, 0, 0, -1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[133], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[133], "meshcollider", true)

objects[134] = creategameobject("Player", false, -86.59, 23.99, -34.97, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[134], "player", 8)
addbehaviour(objects[134], "charactercontroller", 45, 0.3, 0.5, 2)
objects[135] = creategameobject("Camera", false, 0, 1.41, 0, 0, -1, 0, -4.371139E-08, 1, 1, 1, "", "")
addbehaviour(objects[135], "camera", 60, 0.3, 1000)
addbehaviour(objects[135], "audiolistener")
addchild(objects[134], objects[135], false)

objects[136] = creategameobject("Wall (2)", true, -63.07, 22.9, -25.69, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[136], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[136], "meshcollider", true)

objects[137] = creategameobject("quad:Wall_Corner", true, -58.157, 22.9, -49.917, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Corner.obj", "corner")
addbehaviour(objects[137], "meshcollider", true)
addbehaviour(objects[137], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[138] = creategameobject("Wall (4)", true, -84.018, 29.11, -25.62, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[138], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[138], "meshcollider", true)

objects[139] = creategameobject("Wall (1)", true, -70.09, 22.9, -25.69, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[139], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[139], "meshcollider", true)

objects[140] = creategameobject("Wall (19)", true, -69.25, 22.9, -66.83, 0, 0.7071068, 0, 0.7071068, 1, 1, -1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[140], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[140], "meshcollider", true)

objects[141] = creategameobject("Wall (48)", true, -59.67, 22.9, -61.06, 0, 0.7071068, 0, -0.7071068, 1, 1, -1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[141], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[141], "meshcollider", true)

objects[142] = creategameobject("Wall (37)", true, -72.84, 28.96, -64.55, 0, -1, 0, 0, -1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[142], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[142], "meshcollider", true)

objects[143] = creategameobject("pasted__pCube85_group", true, -59.972, 22.9, -51.19, 0, 0.05096556, 0, 0.9987005, 1.000837, 1, 1.000837, "pillar.obj", "pillar")
addbehaviour(objects[143], "meshcollider", true)
addbehaviour(objects[143], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[144] = creategameobject("Wall (17)", true, -69.25, 22.9, -52.69, 0, 0.7071068, 0, 0.7071068, 1, 1, -1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[144], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[144], "meshcollider", true)

objects[145] = creategameobject("Wall (29)", true, -89.44, 29.95, -25.04, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1.01196, 1.01196, "Walls/Wall.obj", "Wall")
addbehaviour(objects[145], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[145], "meshcollider", true)

objects[146] = creategameobject("Wall (50)", true, -64.98, 29.02, -51.01, 0, -1, 0, 0, -1, 1, -1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[146], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[146], "meshcollider", true)

objects[147] = creategameobject("Wall (43)", true, -69.25, 28.97, -59.78, 0, 0.7071068, 0, 0.7071068, 1, 1, -1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[147], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[147], "meshcollider", true)

objects[148] = creategameobject("Wall (8)", true, -57.81, 22.9, -37.98, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[148], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[148], "meshcollider", true)

objects[149] = creategameobject("pasted__pCube85_group", true, -59.972, 22.9, -50.184, 0, 0.05096556, 0, 0.9987004, 1.000837, 1, 1.000837, "pillar.obj", "pillar")
addbehaviour(objects[149], "meshcollider", true)
addbehaviour(objects[149], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[150] = creategameobject("crate (7)", true, -87.05388, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[150], "meshcollider", true)
addbehaviour(objects[150], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[151] = creategameobject("quad:Wall_Corner", true, -58.157, 22.899, -26.041, 0, 0, 0, 1, 1, 1, 1, "Walls/Corner.obj", "corner")
addbehaviour(objects[151], "meshcollider", true)
addbehaviour(objects[151], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[152] = creategameobject("Drawer", true, -58.423, 27.92, -40.34682, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer")
addbehaviour(objects[152], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[152], "meshcollider", true)

objects[153] = creategameobject("Wall (35)", true, -79.85, 28.96, -64.55, 0, -1, 0, 0, -1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[153], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[153], "meshcollider", true)

objects[154] = creategameobject("Wall (20)", true, -75.32, 22.9, -64.3, 0, -1, 0, 0, -1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[154], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[154], "meshcollider", true)

objects[155] = creategameobject("crate (1)", true, -83.96, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[155], "meshcollider", true)
addbehaviour(objects[155], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[156] = creategameobject("Drawer (15)", true, -90.03609, 27.92, -59.50741, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[156], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[156], "meshcollider", true)

objects[157] = creategameobject("pasted__pCube85_group", true, -69.04, 22.9, -50.184, 0, 0.05096556, 0, 0.9987004, 1.000837, 1, 1.000837, "pillar.obj", "pillar")
addbehaviour(objects[157], "meshcollider", true)
addbehaviour(objects[157], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[158] = creategameobject("Wall (45)", true, -58.68, 29.7666, -66.15, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[158], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[158], "meshcollider", true)

objects[159] = creategameobject("Wall (30)", true, -89.44, 29.95, -32.04, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1.01196, 1.01196, "Walls/Wall.obj", "Wall")
addbehaviour(objects[159], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[159], "meshcollider", true)

objects[160] = creategameobject("Wall (34)", true, -89.44, 29.95, -60.15, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1.01196, 1.01196, "Walls/Wall.obj", "Wall")
addbehaviour(objects[160], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[160], "meshcollider", true)

objects[161] = creategameobject("Wall (7)", true, -77.11, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[161], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[161], "meshcollider", true)

objects[162] = creategameobject("crate (3)", true, -77.58985, 22.77, -27.45414, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[162], "meshcollider", true)
addbehaviour(objects[162], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[163] = creategameobject("crate (6)", true, -71.77184, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[163], "meshcollider", true)
addbehaviour(objects[163], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[164] = creategameobject("Wall (44)", true, -58.68, 29.7666, -59.14, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[164], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[164], "meshcollider", true)

objects[165] = creategameobject("Drawer (3)", true, -58.423, 27.92, -36.50562, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer")
addbehaviour(objects[165], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[165], "meshcollider", true)

objects[166] = creategameobject("Drawer (7)", true, -90.03609, 27.92, -32.66442, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[166], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[166], "meshcollider", true)

objects[167] = creategameobject("rounddoor", false, -64.81427, 22.77, -49.42999, 0, 0, 0, 1, 1, 1, 1, "rounddoor.obj", "door")
addbehaviour(objects[167], "meshcollider", true)
addbehaviour(objects[167], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[167], "npc", 4, false, false)

objects[168] = creategameobject("quad:Wall_Corner", true, -70.4099, 22.8974, -63.953, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Corner.obj", "corner")
addbehaviour(objects[168], "meshcollider", true)
addbehaviour(objects[168], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[169] = creategameobject("pasted__pCube85_group", true, -73.98, 22.9, -40.76, 0, -0.4153649, 0, 0.9096549, 1.01999, 1, 1.01999, "pillar.obj", "pillar")
addbehaviour(objects[169], "meshcollider", true)
addbehaviour(objects[169], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[170] = creategameobject("crate (4)", true, -67.74512, 22.77, -27.45414, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[170], "meshcollider", true)
addbehaviour(objects[170], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[171] = creategameobject("Wall (12)", true, -58.68, 29.7666, -30.77, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[171], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[171], "meshcollider", true)

objects[172] = creategameobject("crate (2)", true, -86.85376, 26.47, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[172], "meshcollider", true)
addbehaviour(objects[172], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[173] = creategameobject("FingerPrintScanner", true, -58.088, 24.661, -34.498, 0, 0.7071068, 0, 0.7071068, 0.848711, 0.84871, 0.848711, "fingerprintscanner.obj", "fingerprintscanner")
addbehaviour(objects[173], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[173], "boxcollider", 0.6365318, 0.4243546, 1.273067)
addbehaviour(objects[173], "npc", 1, false, false)

objects[174] = creategameobject("Wall (28)", true, -90.41, 22.9, -25.694, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[174], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[174], "meshcollider", true)

objects[175] = creategameobject("Wall (16)", true, -70.06, 22.9, -52.69, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[175], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[175], "meshcollider", true)

objects[176] = creategameobject("Wall (11)", true, -58.68, 29.7666, -37.98, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[176], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[176], "meshcollider", true)

objects[177] = creategameobject("Wall (36)", true, -86.7, 28.96, -64.55, 0, -1, 0, 0, -1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[177], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[177], "meshcollider", true)

objects[178] = creategameobject("capsule (5)", true, -83.82, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule")
addbehaviour(objects[178], "meshcollider", true)
addbehaviour(objects[178], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[179] = creategameobject("Drawer (9)", true, -90.03609, 27.92, -48.00976, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[179], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[179], "meshcollider", true)

objects[180] = creategameobject("wallnopillar_Walls (2)", true, -58.76, 32.14, -50.48, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/WallNoPillar.obj", "Wall")
addbehaviour(objects[180], "meshcollider", true)
addbehaviour(objects[180], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[181] = creategameobject("Wall (13)", true, -58.68, 29.7666, -23.67, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[181], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[181], "meshcollider", true)

objects[182] = creategameobject("Plane", true, -72.83281, 22.77, -49.217, 0, 0, 0, 1, 50, 1, 50, "plane.obj", "ground")
addbehaviour(objects[182], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[182], "boxcollider", 250, 0, 250)

objects[183] = creategameobject("Wall (24)", true, -88.61, 22.92918, -46.18, 0.1359903, -0.6939068, 0.1359903, 0.6939068, 1, 1.009971, 1.009971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[183], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[183], "meshcollider", true)

objects[184] = creategameobject("Wall (40)", true, -70.06, 28.96, -59.66, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[184], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[184], "meshcollider", true)

objects[185] = creategameobject("capsule (1)", true, -64.86, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule")
addbehaviour(objects[185], "meshcollider", true)
addbehaviour(objects[185], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[186] = creategameobject("wallnopillartri", true, -72.93267, 26.01245, -51.04012, 0, 0, 0, 1, 1, 1, 1, "Walls/WallNoPillar.obj", "Wall")
addbehaviour(objects[186], "meshcollider", true)
addbehaviour(objects[186], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[187] = creategameobject("capsule (2)", true, -74.39, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule")
addbehaviour(objects[187], "meshcollider", true)
addbehaviour(objects[187], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[188] = creategameobject("Wall (22)", true, -88.61, 22.92918, -60.15, 0.1359903, -0.6939068, 0.1359903, 0.6939068, 1, 1.009971, 1.009971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[188], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[188], "meshcollider", true)

objects[189] = creategameobject("Wall", true, -77.11, 22.9, -25.69, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[189], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[189], "meshcollider", true)

objects[190] = creategameobject("Wall (32)", true, -89.44, 29.95, -46.18, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1.01196, 1.01196, "Walls/Wall.obj", "Wall")
addbehaviour(objects[190], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[190], "meshcollider", true)

objects[191] = creategameobject("Wall (10)", true, -58.68, 29.7666, -45, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1.01197, 1.011971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[191], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[191], "meshcollider", true)

objects[192] = creategameobject("Drawer (6)", true, -90.03609, 27.92, -28.84269, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[192], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[192], "meshcollider", true)

objects[193] = creategameobject("Drawer (4)", true, -58.423, 27.92, -32.66442, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer")
addbehaviour(objects[193], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[193], "meshcollider", true)

objects[194] = creategameobject("Wall (27)", true, -88.61, 22.92918, -25.04, 0.1359903, -0.6939068, 0.1359903, 0.6939068, 1, 1.009971, 1.009971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[194], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[194], "meshcollider", true)

objects[195] = creategameobject("Wall (6)", true, -70.09, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[195], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[195], "meshcollider", true)

objects[196] = creategameobject("tv_set:polySurface5", true, -73.99264, 31.72438, -40.98919, 0, 0, 0, 1, 0.5695158, 0.5695158, 0.5695158, "Tv's.obj", "tv's")

objects[197] = creategameobject("Drawer (2)", true, -58.423, 27.92, -48.00976, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer")
addbehaviour(objects[197], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[197], "meshcollider", true)

objects[198] = creategameobject("Keypad", true, -69.666, 24.89, -48.7, 0, -1, 0, 0, 1, 1, 1, "keypad.obj", "keypad")
addbehaviour(objects[198], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[198], "boxcollider", 0.5, 0.5, 0.5)
addbehaviour(objects[198], "npc", 2, false, false)

objects[199] = creategameobject("capsule (3)", true, -71.38, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule")
addbehaviour(objects[199], "meshcollider", true)
addbehaviour(objects[199], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[200] = creategameobject("wallnopillar_Walls (1)", true, -70.06, 26.01, -59.02, 0, -1, 0, 0, 1, 1, 1, "Walls/WallNoPillar.obj", "Wall")
addbehaviour(objects[200], "meshcollider", true)
addbehaviour(objects[200], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[201] = creategameobject("table", true, -79.11, 22.884, -53.33, 0, 0, 0, 1, 0.4131236, 0.4131236, 0.4131236, "table.obj", "table")
addbehaviour(objects[201], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[201], "meshcollider", true)

objects[202] = creategameobject("Wall (39)", true, -70.06, 28.96, -52.69, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[202], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[202], "meshcollider", true)

objects[203] = creategameobject("Generator", true, -85.939, 22.901, -41.491, 0, -0.7071068, 0, -0.7071068, 0.7960583, 0.7960575, 0.7960584, "generator.obj", "generator")
addbehaviour(objects[203], "meshcollider", true)
addbehaviour(objects[203], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[204] = creategameobject("Wall (23)", true, -88.61, 22.92918, -53.16, 0.1359903, -0.6939068, 0.1359903, 0.6939068, 1, 1.009971, 1.009971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[204], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[204], "meshcollider", true)

objects[205] = creategameobject("capsule", true, -61.85, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule")
addbehaviour(objects[205], "meshcollider", true)
addbehaviour(objects[205], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[206] = creategameobject("Wall (42)", true, -69.25, 28.97, -66.83, 0, 0.7071068, 0, 0.7071068, 1, 1, -1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[206], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[206], "meshcollider", true)

objects[207] = creategameobject("Drawer (12)", true, -90.03609, 27.92, -51.85096, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[207], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[207], "meshcollider", true)

objects[208] = creategameobject("CeilingLamp_Tri", true, -79.39, 31.5, -56.52, 0, 0, 0, 1, 1, 1, 1, "ceilinglamp.obj", "ceilinglamp")
addbehaviour(objects[208], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[208], "meshcollider", true)

objects[209] = creategameobject("Wall (14)", true, -56.38, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[209], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[209], "meshcollider", true)

objects[210] = creategameobject("wallnopillar_Walls", true, -57.807, 26.012, -30.943, 0, -1, 0, 0, 1, 1, 1, "Walls/WallNoPillar.obj", "Wall")
addbehaviour(objects[210], "meshcollider", true)
addbehaviour(objects[210], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[211] = creategameobject("Wall (26)", true, -88.61, 22.92918, -32.04, 0.1359903, -0.6939068, 0.1359903, 0.6939068, 1, 1.009971, 1.009971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[211], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[211], "meshcollider", true)

objects[212] = creategameobject("capsule (4)", true, -80.81, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule")
addbehaviour(objects[212], "meshcollider", true)
addbehaviour(objects[212], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[213] = creategameobject("BrokenCableBroken", true, -63.1, 22.9, -45.743, 0, 0, 0, 1, 1, 1, 1, "brokencablebroken.obj", "brokencable")
addbehaviour(objects[213], "npc", 99, false, false)

objects[214] = creategameobject("Wall (33)", true, -89.44, 29.95, -53.16, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1.01196, 1.01196, "Walls/Wall.obj", "Wall")
addbehaviour(objects[214], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[214], "meshcollider", true)

objects[215] = creategameobject("Wall (25)", true, -88.61, 22.92918, -39.16, 0.1359903, -0.6939068, 0.1359903, 0.6939068, 1, 1.009971, 1.009971, "Walls/Wall.obj", "Wall")
addbehaviour(objects[215], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[215], "meshcollider", true)

objects[216] = creategameobject("Wall (3)", true, -84.018, 22.9, -25.694, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[216], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[216], "meshcollider", true)

objects[217] = creategameobject("Wall (21)", true, -82.35, 22.9, -64.3, 0, -1, 0, 0, -1, 1, 1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[217], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[217], "meshcollider", true)

objects[218] = creategameobject("Wall (18)", true, -69.25, 22.9, -59.78, 0, 0.7071068, 0, 0.7071068, 1, 1, -1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[218], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[218], "meshcollider", true)

objects[219] = creategameobject("Directional Light", false, 11.46, 22.87, -37, 0.6831398, -0.05744888, -0.3307006, 0.6485807, 1, 1, 1, "", "")
addbehaviour(objects[219], "light", "directional", 1, 0.9568627, 0.8392157, 1, 0.5, 30)

objects[220] = creategameobject("Drawer (11)", true, -90.03609, 27.92, -40.34682, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer")
addbehaviour(objects[220], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[220], "meshcollider", true)

objects[221] = creategameobject("Wall (49)", true, -59.87, 22.9, -68.15, 0, 0.7071068, 0, -0.7071068, 1, 1, -1, "Walls/Wall.obj", "Wall")
addbehaviour(objects[221], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[221], "meshcollider", true)

objects[222] = creategameobject("crate (5)", true, -71.64982, 26.47, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[222], "meshcollider", true)
addbehaviour(objects[222], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[223] = creategameobject("pasted__pCube85_group", true, -69.04, 22.9, -51.19, 0, 0.05096556, 0, 0.9987004, 1.000837, 1, 1.000837, "pillar.obj", "pillar")
addbehaviour(objects[223], "meshcollider", true)
addbehaviour(objects[223], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

