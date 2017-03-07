objects = {}
objects[0] = creategameobject("big_pipes_Tri", true, -89.01, 29.87, -45.37, 0, 0, 0, 1, 1, 1, 1, "bigpipe.obj", "bigpipe", true)

objects[1] = creategameobject("big_pipes_Tri (1)", true, -59.29, 29.55, -45.37, 0, 0, 0, 1, 1, 1, 1, "bigpipe.obj", "bigpipe", true)
objects[2] = creategameobject("Drawer (13)", true, 0.8670006, -1.92, -12.31, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true)
addchild(objects[1], objects[2], false)

objects[3] = creategameobject("Drawer (19)", true, -58.423, 27.92, -65.55, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true)

objects[4] = creategameobject("Drawer (18)", true, -58.423, 27.92, -69.37, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true)

objects[5] = creategameobject("Drawer (17)", true, -58.423, 27.92, -61.5, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true)

objects[6] = creategameobject("Drawer (16)", true, -58.423, 27.92, -53.84, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true)

objects[7] = creategameobject("rounddoor (5)", false, -82.8, 23.28, -109.97, 0, 0, 0, 1, 1, 1, 1, "door.obj", "door", true)
addbehaviour(objects[7], "meshcollider", true)
addbehaviour(objects[7], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[7], "npc", 23, false, true)

objects[8] = creategameobject("Double_Door_Wall_Tri (5)", true, -82.9, 23.24, -110.81, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "wall", true)
addbehaviour(objects[8], "meshcollider", false)
addbehaviour(objects[8], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[9] = creategameobject("Double_Door_Wall_Tri (4)", true, -87.33, 23.24, -106.48, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "doorframe.obj", "wall", true)
addbehaviour(objects[9], "meshcollider", false)
addbehaviour(objects[9], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[10] = creategameobject("rounddoor (4)", false, -87.23, 23.28, -106.26, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "door.obj", "door", true)
addbehaviour(objects[10], "meshcollider", true)
addbehaviour(objects[10], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[10], "npc", 16, false, true)

objects[11] = creategameobject("rounddoor (3)", false, -78.62, 23.28, -106.26, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "door.obj", "door", true)
addbehaviour(objects[11], "meshcollider", true)
addbehaviour(objects[11], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[11], "npc", 66, false, true)

objects[12] = creategameobject("Double_Door_Wall_Tri (3)", true, -78.72, 23.24, -106.48, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "doorframe.obj", "wall", true)
addbehaviour(objects[12], "meshcollider", false)
addbehaviour(objects[12], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[13] = creategameobject("Double_Door_Wall_Tri (2)", true, -82.9, 23.24, -102.09, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "wall", true)
addbehaviour(objects[13], "meshcollider", false)
addbehaviour(objects[13], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[14] = creategameobject("rounddoor (2)", false, -82.8, 23.28, -101.25, 0, 0, 0, 1, 1, 1, 1, "door.obj", "door", true)
addbehaviour(objects[14], "meshcollider", true)
addbehaviour(objects[14], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[14], "npc", 17, false, true)

objects[15] = creategameobject("Corridor_Reinfocement_Tri (6)", true, -82.985, 25.96, -101.33, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false)
addbehaviour(objects[15], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[15], "meshcollider", false)

objects[16] = creategameobject("Corridor_Straight_Tri (3)", true, -83.005, 25.83, -98.04, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/straightcorridor.obj", "straightcorridor", false)
addbehaviour(objects[16], "meshcollider", false)
addbehaviour(objects[16], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)

objects[17] = creategameobject("Corridor_Straight_Tri (2)", true, -83.005, 25.83, -91.3, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/straightcorridor.obj", "straightcorridor", false)
addbehaviour(objects[17], "meshcollider", false)
addbehaviour(objects[17], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)

objects[18] = creategameobject("Corridor_Reinfocement_Tri (5)", true, -82.985, 25.96, -94.59, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false)
addbehaviour(objects[18], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[18], "meshcollider", false)

objects[19] = creategameobject("Corridor_Reinfocement_Tri (4)", true, -82.985, 25.96, -87.965, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false)
addbehaviour(objects[19], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[19], "meshcollider", false)

objects[20] = creategameobject("Corridor_Straight_Tri (1)", true, -83.005, 25.83, -84.67, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/straightcorridor.obj", "straightcorridor", false)
addbehaviour(objects[20], "meshcollider", false)
addbehaviour(objects[20], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)

objects[21] = creategameobject("Corridor_Reinfocement_Tri (3)", true, -82.985, 25.96, -81.365, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false)
addbehaviour(objects[21], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[21], "meshcollider", false)

objects[22] = creategameobject("Corridor_L_Turn_Quad (1)", true, -82.56, 25.87, -76.02, 0, -1, 0, 0, 1, 1, 1, "corridors/leftcorridor.obj", "leftcorridor", false)
addbehaviour(objects[22], "meshcollider", false)
addbehaviour(objects[22], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)

objects[23] = creategameobject("Corridor_Reinfocement_Tri (2)", true, -77.18, 25.96, -75.656, 0, 0, 0, 1, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false)
addbehaviour(objects[23], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[23], "meshcollider", false)

objects[24] = creategameobject("Corridor_Straight_Tri", true, -73.94, 25.83, -75.645, 0, 0, 0, 1, 1, 1, 1, "corridors/straightcorridor.obj", "straightcorridor", false)
addbehaviour(objects[24], "meshcollider", false)
addbehaviour(objects[24], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)

objects[25] = creategameobject("Corridor_L_Turn_Quad", true, -65.129, 25.87, -75.3, 0, 0, 0, 1, 1, 1, 1, "corridors/leftcorridor.obj", "leftcorridor", false)
addbehaviour(objects[25], "meshcollider", false)
addbehaviour(objects[25], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)

objects[26] = creategameobject("Corridor_Reinfocement_Tri (1)", true, -70.57, 25.96, -75.62, 0, 0, 0, 1, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false)
addbehaviour(objects[26], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[26], "meshcollider", false)

objects[27] = creategameobject("Corridor_Reinfocement_Tri", true, -64.77, 25.36, -70.23, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false)
addbehaviour(objects[27], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[27], "meshcollider", false)

objects[28] = creategameobject("rounddoor (1)", false, -64.75, 22.92, -68.46, 0, 0, 0, 1, 1, 1, 1, "door.obj", "door", true)
addbehaviour(objects[28], "meshcollider", true)
addbehaviour(objects[28], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[28], "npc", 15, false, true)

objects[29] = creategameobject("Double_Door_Wall_Tri (1)", true, -64.77, 22.88, -69.3, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "wall", true)
addbehaviour(objects[29], "meshcollider", false)
addbehaviour(objects[29], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[30] = creategameobject("crate (11)", true, -75.97, 22.77, -41.39, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate", true)
addbehaviour(objects[30], "meshcollider", true)
addbehaviour(objects[30], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[31] = creategameobject("crate (10)", true, -71.56, 22.77, -41.06, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "crate.obj", "crate", true)
addbehaviour(objects[31], "meshcollider", true)
addbehaviour(objects[31], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[32] = creategameobject("Spotlight (6)", false, -75.44, 30.91, -41.63, 0.06526307, -0.8586165, 0.113039, 0.4957224, 1, 1, 1, "", "", true)
addbehaviour(objects[32], "light", "spot", 0.5893166, 0.7232133, 0.7352941, 1, 0.8, 139)

objects[33] = creategameobject("Spotlight (5)", false, -72.9, 30.91, -41.39, 0.06526307, 0.8586165, -0.113039, 0.4957224, 1, 1, 1, "", "", true)
addbehaviour(objects[33], "light", "spot", 0.5893166, 0.7232133, 0.7352941, 1, 0.8, 139)

objects[34] = creategameobject("Spotlight (4)", false, -74.28, 30.91, -39.89, 0.1305262, 0, 0, 0.9914449, 1, 1, 1, "", "", true)
addbehaviour(objects[34], "light", "spot", 0.5893166, 0.7232133, 0.7352941, 1, 0.8, 139)

objects[35] = creategameobject("Spotlight (3)", false, -65.26, 30.1, -43.27, 0.7071068, 0, 0, 0.7071068, 1, 1, 1, "", "", true)
addbehaviour(objects[35], "light", "spot", 0.5893166, 0.7232133, 0.7352941, 1, 0, 112)
addbehaviour(objects[35], "lightidentifier", 1)

objects[36] = creategameobject("CeilingLamp_Tri (1)", true, -61.17, 34.31, -43.43, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "ceilinglamp.obj", "ceilinglamp", true)

objects[37] = creategameobject("Wall (25)", true, -89.52, 22.92918, -39.13, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[37], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[37], "meshcollider", true)

objects[38] = creategameobject("Wall (24)", true, -89.52, 22.92918, -46.12, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false)
addbehaviour(objects[38], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[38], "meshcollider", true)

objects[39] = creategameobject("Plane (1)", true, -72.83281, 35, -49.217, 1, 0, 0, 0, 50, 1, 50, "plane.obj", "ground", false)
addbehaviour(objects[39], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[39], "meshcollider", true)

objects[40] = creategameobject("Double_Door_Wall_Tri", true, -64.77, 22.75, -50.69, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "wall", true)
addbehaviour(objects[40], "meshcollider", false)
addbehaviour(objects[40], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[41] = creategameobject("DoubleSidedWall (3)", true, -70.04, 22.95, -59.64, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true)
addbehaviour(objects[41], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[41], "meshcollider", true)

objects[42] = creategameobject("DoubleSidedWall (2)", true, -70.04, 22.95, -52.79, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true)
addbehaviour(objects[42], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[42], "meshcollider", true)

objects[43] = creategameobject("DoubleSidedWall (1)", true, -59.7, 29, -50.57, 0, -1, 0, 0, 1, 1, 1, "Walls/walldoublesided.obj", "wall", false)

objects[44] = creategameobject("DoubleSidedWall", true, -66.54, 29, -50.57, 0, -1, 0, 0, 1, 1, 1, "Walls/walldoublesided.obj", "wall", false)

objects[45] = creategameobject("crate (9)", true, -84.09, 26.47, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true)
addbehaviour(objects[45], "meshcollider", true)
addbehaviour(objects[45], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[46] = creategameobject("crate (8)", true, -81.2, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true)
addbehaviour(objects[46], "meshcollider", true)
addbehaviour(objects[46], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[47] = creategameobject("Tablet", false, -78.01, 24.646, -53.35, 0, -0.3007058, 0, 0.953717, 0.18, 0.18, 0.18, "tablet.obj", "tablet", true)
addbehaviour(objects[47], "rigidbody", 1, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[47], "meshcollider", true)
addbehaviour(objects[47], "npc", 12, true, false)
objects[48] = creategameobject("TabletScreen", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "tabletscreen.obj", "tabletscreen", true)
addchild(objects[47], objects[48], false)

objects[49] = creategameobject("GameObject", false, -70.18, 25.18, -39.84, 0, 0, 0, 1, 1, 1, 1, "", "", true)
addbehaviour(objects[49], "audiosource", "bgm.wav", true, true, true, false, 1, 1, true)

objects[50] = creategameobject("WallDoubleSided", true, -69.91, 22.856, -52.61, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true)
addbehaviour(objects[50], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[50], "meshcollider", true)

objects[51] = creategameobject("Drawer (1)", true, -58.423, 27.92, -44.18154, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true)

objects[52] = creategameobject("Wall (9)", true, -57.81, 22.9, -45, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[52], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[52], "meshcollider", true)

objects[53] = creategameobject("Wall (31)", true, -89.44, 29.95, -39.16, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[54] = creategameobject("Drawer (8)", true, -89.76, 28.27, -36.50562, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true)

objects[55] = creategameobject("Wall (51)", true, -90.7, 29.11, -25.62, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[56] = creategameobject("Drawer (5)", true, -58.423, 27.92, -28.84269, 0, 1, 0, 0, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true)

objects[57] = creategameobject("Wall (38)", true, -69.249, 28.96, -52.69, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true)

objects[58] = creategameobject("quad:Wall_Corner", true, -89.05101, 22.9, -63.956, 0, 1, 0, 0, 1, 1, 1, "Walls/Corner.obj", "corner", true)
addbehaviour(objects[58], "meshcollider", true)
addbehaviour(objects[58], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[59] = creategameobject("Drawer (10)", true, -89.76, 28.27, -44.18154, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true)

objects[60] = creategameobject("Wall (15)", true, -58.68, 29.7666, -51.97, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[61] = creategameobject("Drawer (14)", true, -89.76, 28.27, -55.67919, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true)

objects[62] = creategameobject("Wall (47)", true, -59.48, 22.9, -54.01, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[62], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[62], "meshcollider", true)

objects[63] = creategameobject("Wall (5)", true, -63.07, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[64] = creategameobject("Wall (41)", true, -70.06, 28.96, -66.55, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[65] = creategameobject("Player", false, -86.89, 23.99, -31.8, 0, 0, 0, 1, 1, 1, 1, "", "", true)
addbehaviour(objects[65], "player", 8)
addbehaviour(objects[65], "charactercontroller", 45, 0.3, 0.5, 2)
objects[66] = creategameobject("Camera", false, 0, 1.41, 0, 0, 0.5849578, 0, -0.8110638, 1, 1, 1, "", "", true)
addbehaviour(objects[66], "camera", 60, 0.3, 1000)
addbehaviour(objects[66], "audiolistener")
addchild(objects[65], objects[66], false)

objects[67] = creategameobject("Wall (2)", true, -63.07, 22.9, -25.69, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[67], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[67], "meshcollider", true)

objects[68] = creategameobject("quad:Wall_Corner", true, -58.157, 22.9, -49.917, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Corner.obj", "corner", true)
addbehaviour(objects[68], "meshcollider", true)
addbehaviour(objects[68], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[69] = creategameobject("Wall (4)", true, -84.018, 29.11, -25.62, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[70] = creategameobject("Wall (1)", true, -70.09, 22.9, -25.69, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[70], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[70], "meshcollider", true)

objects[71] = creategameobject("Wall (48)", true, -59.67, 22.9, -61.06, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[71], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[71], "meshcollider", true)

objects[72] = creategameobject("Wall (37)", true, -72.84, 28.96, -64.55, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[73] = creategameobject("pasted__pCube85_group", true, -59.972, 22.9, -51.19, 0, 0.05096556, 0, 0.9987005, 1.000837, 1, 1.000837, "pillar.obj", "pillar", true)
addbehaviour(objects[73], "meshcollider", true)
addbehaviour(objects[73], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[74] = creategameobject("Wall (29)", true, -89.44, 29.95, -25.04, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[75] = creategameobject("Wall (43)", true, -69.25, 28.97, -59.78, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true)

objects[76] = creategameobject("Wall (8)", true, -57.81, 22.9, -37.98, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[76], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[76], "meshcollider", true)

objects[77] = creategameobject("pasted__pCube85_group", true, -59.972, 22.9, -50.184, 0, 0.05096556, 0, 0.9987004, 1.000837, 1, 1.000837, "pillar.obj", "pillar", true)
addbehaviour(objects[77], "meshcollider", true)
addbehaviour(objects[77], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[78] = creategameobject("crate (7)", true, -87.05388, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true)
addbehaviour(objects[78], "meshcollider", true)
addbehaviour(objects[78], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[79] = creategameobject("quad:Wall_Corner", true, -58.157, 22.899, -26.041, 0, 0, 0, 1, 1, 1, 1, "Walls/Corner.obj", "corner", true)
addbehaviour(objects[79], "meshcollider", true)
addbehaviour(objects[79], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[80] = creategameobject("Drawer", true, -58.423, 27.92, -40.34682, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true)

objects[81] = creategameobject("Wall (35)", true, -79.85, 28.96, -64.55, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[82] = creategameobject("Wall (20)", true, -75.32, 22.9, -64.3, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[82], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[82], "meshcollider", true)

objects[83] = creategameobject("crate (1)", true, -83.96, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true)
addbehaviour(objects[83], "meshcollider", true)
addbehaviour(objects[83], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[84] = creategameobject("Drawer (15)", true, -89.76, 28.27, -59.50741, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true)

objects[85] = creategameobject("pasted__pCube85_group", true, -69.04, 22.9, -50.184, 0, 0.05096556, 0, 0.9987004, 1.000837, 1, 1.000837, "pillar.obj", "pillar", true)
addbehaviour(objects[85], "meshcollider", true)
addbehaviour(objects[85], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[86] = creategameobject("Wall (45)", true, -58.68, 29.7666, -66.15, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", true)

objects[87] = creategameobject("Wall (30)", true, -89.44, 29.95, -32.04, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[88] = creategameobject("Wall (34)", true, -89.44, 29.95, -60.15, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[89] = creategameobject("Wall (7)", true, -77.11, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[90] = creategameobject("crate (3)", true, -77.58985, 22.77, -27.45414, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate", true)
addbehaviour(objects[90], "meshcollider", true)
addbehaviour(objects[90], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[91] = creategameobject("crate (6)", true, -71.77184, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true)
addbehaviour(objects[91], "meshcollider", true)
addbehaviour(objects[91], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[92] = creategameobject("Wall (44)", true, -58.68, 29.7666, -59.14, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", true)

objects[93] = creategameobject("Drawer (3)", true, -58.423, 27.92, -36.50562, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true)

objects[94] = creategameobject("Drawer (7)", true, -89.76, 28.27, -32.66442, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true)

objects[95] = creategameobject("rounddoor", false, -64.75, 22.82, -49.85, 0, 0, 0, 1, 1, 1, 1, "door.obj", "door", true)
addbehaviour(objects[95], "meshcollider", true)
addbehaviour(objects[95], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[95], "npc", 4, false, false)

objects[96] = creategameobject("quad:Wall_Corner", true, -70.4099, 22.8974, -63.953, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Corner.obj", "corner", true)
addbehaviour(objects[96], "meshcollider", true)
addbehaviour(objects[96], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[97] = creategameobject("pasted__pCube85_group", true, -73.98, 22.9, -40.76, 0, -0.4153649, 0, 0.9096549, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true)
addbehaviour(objects[97], "meshcollider", true)
addbehaviour(objects[97], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[98] = creategameobject("crate (4)", true, -67.74512, 22.77, -27.45414, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate", true)
addbehaviour(objects[98], "meshcollider", true)
addbehaviour(objects[98], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[99] = creategameobject("Wall (12)", true, -58.68, 29.7666, -30.77, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[100] = creategameobject("crate (2)", true, -86.85376, 26.47, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true)
addbehaviour(objects[100], "meshcollider", true)
addbehaviour(objects[100], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[101] = creategameobject("FingerPrintScanner", true, -58.088, 24.661, -34.498, 0, 0.7071068, 0, 0.7071068, 0.848711, 0.84871, 0.848711, "fingerprintscanner.obj", "fingerprintscanner", true)
addbehaviour(objects[101], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[101], "npc", 1, false, false)
addbehaviour(objects[101], "boxcollider", 0.6365318, 0.4243546, 1.273067)

objects[102] = creategameobject("Wall (28)", true, -90.41, 22.9, -25.694, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[102], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[102], "meshcollider", true)

objects[103] = creategameobject("Wall (11)", true, -58.68, 29.7666, -37.98, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[104] = creategameobject("Wall (36)", true, -86.7, 28.96, -64.55, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[105] = creategameobject("capsule (5)", true, -83.82, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true)
addbehaviour(objects[105], "meshcollider", true)
addbehaviour(objects[105], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[106] = creategameobject("Drawer (9)", true, -89.76, 28.27, -48.00976, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true)

objects[107] = creategameobject("Wall (13)", true, -58.68, 29.7666, -23.67, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[107], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[107], "meshcollider", true)

objects[108] = creategameobject("Plane", true, -72.83281, 22.93, -49.217, 0, 0, 0, 1, 50, 1, 50, "plane.obj", "ground", true)
addbehaviour(objects[108], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[108], "meshcollider", true)

objects[109] = creategameobject("Wall (40)", true, -70.06, 28.96, -59.66, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false)
addbehaviour(objects[109], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[109], "meshcollider", true)

objects[110] = creategameobject("capsule (1)", true, -64.86, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true)
addbehaviour(objects[110], "meshcollider", true)
addbehaviour(objects[110], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[111] = creategameobject("capsule (2)", true, -74.39, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true)
addbehaviour(objects[111], "meshcollider", true)
addbehaviour(objects[111], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[112] = creategameobject("Wall (22)", true, -89.52, 22.92918, -60.15, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[112], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[112], "meshcollider", true)

objects[113] = creategameobject("Wall", true, -77.11, 22.9, -25.69, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[113], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[113], "meshcollider", true)

objects[114] = creategameobject("Wall (32)", true, -89.44, 29.95, -46.18, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[115] = creategameobject("Wall (10)", true, -58.68, 29.7666, -45, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[116] = creategameobject("Drawer (6)", true, -89.76, 28.27, -28.84269, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true)

objects[117] = creategameobject("Drawer (4)", true, -58.423, 27.92, -32.66442, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true)

objects[118] = creategameobject("Wall (27)", true, -89.52, 22.92918, -25.04, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[118], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[118], "meshcollider", true)

objects[119] = creategameobject("Wall (6)", true, -70.09, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[120] = creategameobject("tv_set:polySurface5", true, -73.99264, 31.72438, -40.98919, 0, 0, 0, 1, 0.5695158, 0.5695158, 0.5695158, "Tv's.obj", "tv's", true)

objects[121] = creategameobject("Keycard", false, -80.198, 24.54, -53.155, 0.3524841, -0.3524841, -0.6129886, 0.6129886, 0.2039833, 0.2071294, 0.2071294, "KeycardFrame.obj", "KeycardFrame", true)
addbehaviour(objects[121], "rigidbody", 1, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[121], "meshcollider", true)
addbehaviour(objects[121], "npc", 25, true, false)
objects[122] = creategameobject("glass", false, 0, 0, 0, 0, 0, -2.235174E-08, 1, 1, 1, 1, "KeycardGlass.obj", "KeycardGlass", true)
addchild(objects[121], objects[122], false)

objects[123] = creategameobject("Drawer (2)", true, -58.423, 27.92, -48.00976, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true)

objects[124] = creategameobject("Keypad", true, -69.666, 24.89, -49.013, 0, -1, 0, 0, 1, 1, 1, "keypad.obj", "keypad", true)
addbehaviour(objects[124], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[124], "boxcollider", 0.5, 0.5, 0.5)
addbehaviour(objects[124], "npc", 2, false, false)

objects[125] = creategameobject("capsule (3)", true, -71.38, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true)
addbehaviour(objects[125], "meshcollider", true)
addbehaviour(objects[125], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[126] = creategameobject("table", true, -79.11, 22.94, -53.33, 0, 0, 0, 1, 0.4131236, 0.4131236, 0.4131236, "table.obj", "table", true)
addbehaviour(objects[126], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[126], "meshcollider", true)

objects[127] = creategameobject("Wall (39)", true, -70.06, 28.96, -52.69, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false)
addbehaviour(objects[127], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[127], "meshcollider", true)

objects[128] = creategameobject("Generator", true, -85.7, 22.901, -41.491, 0, -0.7071068, 0, -0.7071068, 0.8, 0.8, 0.8, "generator.obj", "generator", true)
addbehaviour(objects[128], "meshcollider", true)
addbehaviour(objects[128], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[129] = creategameobject("Wall (23)", true, -89.52, 22.92918, -53.16, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false)
addbehaviour(objects[129], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[129], "meshcollider", true)

objects[130] = creategameobject("capsule", true, -61.85, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true)
addbehaviour(objects[130], "meshcollider", true)
addbehaviour(objects[130], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[131] = creategameobject("Wall (42)", true, -69.25, 28.97, -66.83, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true)

objects[132] = creategameobject("Drawer (12)", true, -89.76, 28.27, -51.85096, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true)

objects[133] = creategameobject("CeilingLamp_Tri", true, -79.39, 32.82, -56.52, 0, 0, 0, 1, 1, 1, 1, "ceilinglamp.obj", "ceilinglamp", true)

objects[134] = creategameobject("Wall (14)", true, -56.38, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[135] = creategameobject("PostProcessors", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "", true)
addbehaviour(objects[135], "fog")
addbehaviour(objects[135], "vignette")
addbehaviour(objects[135], "contrast", 0.08)

objects[136] = creategameobject("wallnopillar_Walls", true, -57.807, 26.012, -30.943, 0, -1, 0, 0, 1, 1, 1, "Walls/WallNoPillar.obj", "Wall", true)
addbehaviour(objects[136], "meshcollider", true)
addbehaviour(objects[136], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[137] = creategameobject("Wall (26)", true, -89.52, 22.92918, -32.04, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[137], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[137], "meshcollider", true)

objects[138] = creategameobject("capsule (4)", true, -80.81, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true)
addbehaviour(objects[138], "meshcollider", true)
addbehaviour(objects[138], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[139] = creategameobject("BrokenCableBroken", true, -63.1, 22.9, -45.743, 0, 0, 0, 1, 1, 1, 1, "brokencablebroken.obj", "brokencable", true)
addbehaviour(objects[139], "npc", 99, true, true)

objects[140] = creategameobject("Wall (33)", true, -89.44, 29.95, -53.16, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false)

objects[141] = creategameobject("BrokenCableTrigger", true, -83.281, 23.136, -34.943, 0.689055, -0.1587554, 0.1587553, 0.689055, 0.5409834, 0.8087289, 0.5409834, "", "", true)
addbehaviour(objects[141], "capsulecollider", 0.5, 2)
addbehaviour(objects[141], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[141], "npc", 0, true, false)

objects[142] = creategameobject("Wall (3)", true, -84.018, 22.9, -25.694, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[142], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[142], "meshcollider", true)

objects[143] = creategameobject("Wall (21)", true, -82.35, 22.9, -64.3, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[143], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[143], "meshcollider", true)

objects[144] = creategameobject("Directional Light", false, -56.94, 42.9, -24.46, 0.1255607, -0.731492, 0.6023041, 0.2939114, 1, 1, 1, "", "", true)
addbehaviour(objects[144], "light", "directional", 1, 0.9568627, 0.8392157, 1, 0.5, 30)

objects[145] = creategameobject("Drawer (11)", true, -89.76, 28.27, -40.34682, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true)

objects[146] = creategameobject("Wall (49)", true, -59.87, 22.9, -68.15, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true)
addbehaviour(objects[146], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[146], "meshcollider", true)

objects[147] = creategameobject("crate (5)", true, -71.64982, 26.47, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true)
addbehaviour(objects[147], "meshcollider", true)
addbehaviour(objects[147], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[148] = creategameobject("pasted__pCube85_group", true, -69.04, 22.9, -51.19, 0, 0.05096556, 0, 0.9987004, 1.000837, 1, 1.000837, "pillar.obj", "pillar", true)
addbehaviour(objects[148], "meshcollider", true)
addbehaviour(objects[148], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[149] = creategameobject("Spotlight", false, -79.495, 28.44, -52.9, 0.7071068, 0, 0, 0.7071068, 1, 1, 1, "", "", true)
addbehaviour(objects[149], "light", "spot", 0.5893166, 0.7232133, 0.7352941, 1, 0, 112)
addbehaviour(objects[149], "lightidentifier", 0)

