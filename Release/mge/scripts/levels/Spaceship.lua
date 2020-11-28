objects = {}

objects[371] = creategameobject("Tablet (1)", false, -70.927, 24.498, -36.4, 0, -0.3007058, 0, 0.953717, 0.18, 0.18, 0.18, "tablet.obj", "tablet", true, true)
addbehaviour(objects[371], "npc", 12, true, false)
addbehaviour(objects[371], "rigidbody", 2, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[371], "meshcollider", true)
objects[372] = creategameobject("TabletScreen", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "tabletscreen.obj", "tabletscreen", false, false)
addchild(objects[371], objects[372], false)

objects[16] = creategameobject("Tablet (2)", false, -12.466, 25.29, -42.808, 0, -0.3007058, 0, 0.953717, 0.18, 0.18, 0.18, "tablet.obj", "tablet", false, false)
addbehaviour(objects[16], "npc", 12, true, false)
addbehaviour(objects[16], "rigidbody", 2, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[16], "meshcollider", true)
objects[17] = creategameobject("TabletScreen", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "tabletscreen.obj", "tabletscreenwin", false, false)
addchild(objects[16], objects[17], false)

objects[392] = creategameobject("Sun_Tri", false, -93.95, 26.55, -186.21, 0, 0, 0, 1, 1, 1, 1, "sun.obj", "sun", false, false)
addbehaviour(objects[392], "sun")

objects[0] = creategameobject("whiteboard", true, -23.11, 23.08, -54.43, 0, -0.7071068, 0, 0.7071068, 0.04, 0.035, 0.05, "whiteboard.obj", "whiteboard", true, true)
addbehaviour(objects[0], "meshcollider", false)
addbehaviour(objects[0], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[1] = creategameobject("Plane (16)", true, -21.39, 35.34, -56.33, 0.7071068, 0, 0.7071068, 0, 4, 1, 22.17339, "plane.obj", "ceiling", false, false)
addbehaviour(objects[1], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[1], "meshcollider", true)

objects[2] = creategameobject("Plane (15)", true, -2.39, 35.27, -80.39, 1, 0, 0, 0, 2, 1, 20, "plane.obj", "ceiling", false, false)
addbehaviour(objects[2], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[2], "meshcollider", true)

objects[3] = creategameobject("Plane (14)", true, -29.09, 35.36, -96.78, 0.7071068, 0, 0.7071068, 0, 1.561553, 1, 20, "plane.obj", "ceiling", false, false)
addbehaviour(objects[3], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[3], "meshcollider", true)

objects[4] = creategameobject("Button_Frame (5)", false, -23.59, 25.88, -55.04, 0, -1, 0, 0, 0.2, 0.2, 0.2, "ButtonFrame.obj", "Button", false, false)

objects[5] = creategameobject("Button_Tri", false, -23.59, 25.88, -55.04, 0, -1, 0, 0, 0.2, 0.2, 0.2, "Button.obj", "Button", false, false)
addbehaviour(objects[5], "npc", 43, false, false)
addbehaviour(objects[5], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[5], "meshcollider", true)

objects[6] = creategameobject("Button_Tri", false, -24.6, 25.88, -55.04, 0, -1, 0, 0, 0.2, 0.2, 0.2, "Button.obj", "Button", false, false)
addbehaviour(objects[6], "npc", 44, false, false)
addbehaviour(objects[6], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[6], "meshcollider", true)

objects[7] = creategameobject("Button_Frame (4)", false, -24.6, 25.88, -55.04, 0, -1, 0, 0, 0.2, 0.2, 0.2, "ButtonFrame.obj", "Button", false, false)

objects[8] = creategameobject("Button_Frame (3)", false, -25.6, 25.88, -55.04, 0, -1, 0, 0, 0.2, 0.2, 0.2, "ButtonFrame.obj", "Button", false, false)

objects[9] = creategameobject("Button_Tri", false, -25.6, 25.88, -55.04, 0, -1, 0, 0, 0.2, 0.2, 0.2, "Button.obj", "Button", false, false)
addbehaviour(objects[9], "npc", 45, false, false)
addbehaviour(objects[9], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[9], "meshcollider", true)

objects[10] = creategameobject("Button_Tri", false, -22.59, 25.88, -55.04, 0, -1, 0, 0, 0.2, 0.2, 0.2, "Button.obj", "Button", false, false)
addbehaviour(objects[10], "npc", 42, false, false)
addbehaviour(objects[10], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[10], "meshcollider", true)

objects[11] = creategameobject("Button_Frame (2)", false, -22.59, 25.88, -55.04, 0, -1, 0, 0, 0.2, 0.2, 0.2, "ButtonFrame.obj", "Button", false, false)

objects[12] = creategameobject("Button_Frame (1)", false, -21.56, 25.88, -55.04, 0, -1, 0, 0, 0.2, 0.2, 0.2, "ButtonFrame.obj", "Button", false, false)

objects[13] = creategameobject("Button_Tri", false, -21.56, 25.88, -55.04, 0, -1, 0, 0, 0.2, 0.2, 0.2, "Button.obj", "Button", false, false)
addbehaviour(objects[13], "npc", 41, false, false)
addbehaviour(objects[13], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[13], "meshcollider", true)

objects[14] = creategameobject("Button_Tri", false, -20.5, 25.88, -55.04, 0, -1, 0, 0, 0.2, 0.2, 0.2, "Button.obj", "Button", false, false)
addbehaviour(objects[14], "npc", 40, false, false)
addbehaviour(objects[14], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[14], "meshcollider", true)

objects[15] = creategameobject("Button_Frame", false, -20.5, 25.88, -55.04, 0, -1, 0, 0, 0.2, 0.2, 0.2, "ButtonFrame.obj", "Button", false, false)

objects[18] = creategameobject("table (5)", true, -12.53, 23.53, -42.35, 0, 0, 0, 1, 0.4131236, 0.4131236, 0.4131236, "table.obj", "table", true, true)
addbehaviour(objects[18], "meshcollider", true)
addbehaviour(objects[18], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[19] = creategameobject("Plane (13)", true, -12.96, 29.67, -43.97, 1, 0, 0, 0, 5.006196, 5.006199, 7.463857, "plane.obj", "ground", false, false)
addbehaviour(objects[19], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[19], "meshcollider", true)

objects[20] = creategameobject("Wall (142)", true, -8.7, 23.54, -38.64, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[20], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[20], "meshcollider", true)

objects[21] = creategameobject("Wall (141)", true, -15.19, 23.54, -38.64, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[21], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[21], "meshcollider", true)

objects[22] = creategameobject("Wall (140)", true, -8.33, 23.54, -48.3, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[22], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[22], "meshcollider", true)

objects[23] = creategameobject("Wall (139)", true, -8.33, 23.54, -41.68, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[23], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[23], "meshcollider", true)

objects[24] = creategameobject("Wall (94)", true, -17.39, 23.54, -41.32, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[24], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[24], "meshcollider", true)

objects[25] = creategameobject("Wall (60)", true, -17.39, 23.54, -47.94, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[25], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[25], "meshcollider", true)

objects[26] = creategameobject("Double_Door_Wall_Tri (7)", true, -12.63, 23.46, -51.25, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "doorframe", true, true)
addbehaviour(objects[26], "meshcollider", false)
addbehaviour(objects[26], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[27] = creategameobject("DoorPrefab (7)", false, -12.47, 23.48, -51.27, 0, 0, 0, 1, 1, 1, 0.5, "", "", true, true)
addbehaviour(objects[27], "npc", 24, false, true)
addbehaviour(objects[27], "door")
objects[28] = creategameobject("DoorLeft", false, 0.15, 0, 0, 0, 0, 0, 1, 1, 1, 1, "DoorLeft.obj", "Door", true, true)
addbehaviour(objects[28], "meshcollider", true)
addbehaviour(objects[28], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[28], "translationanimation")
addchild(objects[27], objects[28], false)
objects[29] = creategameobject("DoorRight", false, -0.15, 0, 0, 0, 0, 0, 1, 1, 1, 1, "DoorRight.obj", "Door", true, true)
addbehaviour(objects[29], "meshcollider", true)
addbehaviour(objects[29], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[29], "translationanimation")
addchild(objects[27], objects[29], false)

objects[30] = creategameobject("Plane (12)", true, -43.16, 35.27, -84.42, 1, 0, 0, 0, 2.217881, 1, 3.447347, "plane.obj", "ceiling", false, false)
addbehaviour(objects[30], "meshcollider", true)
addbehaviour(objects[30], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[31] = creategameobject("Plane (11)", true, -43.967, 35.38, -84.42, 0, 0, 0, 1, 1.767549, 1, 3.447347, "plane.obj", "ground", false, false)
addbehaviour(objects[31], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[31], "meshcollider", true)

objects[32] = creategameobject("DoubleSidedWall (14)", true, -41.29, 35.1, -55.37, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true, true)
addbehaviour(objects[32], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[32], "meshcollider", true)

objects[33] = creategameobject("Wall (138)", true, -50.34, 29.2, -50.08, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[33], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[33], "meshcollider", true)

objects[34] = creategameobject("Wall (137)", true, -50.34, 35.09, -50.08, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[34], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[34], "meshcollider", true)

objects[35] = creategameobject("Wall (136)", true, -50.34, 23.54, -50.08, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[35], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[35], "meshcollider", true)

objects[36] = creategameobject("Wall (135)", true, -47.19, 35.09, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[36], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[36], "meshcollider", true)

objects[37] = creategameobject("Wall (134)", true, -50.34, 23.54, -57.21, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[37], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[37], "meshcollider", true)

objects[38] = creategameobject("Wall (133)", true, -50.34, 35.09, -57.21, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[38], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[38], "meshcollider", true)

objects[39] = creategameobject("Wall (132)", true, -50.34, 29.2, -57.21, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[39], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[39], "meshcollider", true)

objects[40] = creategameobject("Wall (131)", true, -0.381, 23.54, -52.87, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[40], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[40], "meshcollider", true)

objects[41] = creategameobject("Wall (130)", true, -0.381, 35.09, -52.87, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[41], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[41], "meshcollider", true)

objects[42] = creategameobject("Wall (120)", true, -0.381, 29.2, -52.87, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[42], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[42], "meshcollider", true)

objects[43] = creategameobject("Audio Source", false, -83.001, 25.97, -87.939, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "", "", false, false)
addbehaviour(objects[43], "audiosource", "SparksReverb.wav", true, true, true, true, 1, 1, false)

objects[44] = creategameobject("Small Box", false, -44.47, 23.4, -57.33, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[44], "meshcollider", true)
addbehaviour(objects[44], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[44], "npc", 50, true, false)

objects[45] = creategameobject("RenderTV", false, -29.49, 31.94, -50.95, 0, -1, 0, 0, 1, 1, 1, "TVFrame.obj", "TV's", false, false)
objects[46] = creategameobject("TVScreen", false, 0, -0.03, 0.05, 0, 0, 0, 1, 1, 1, 1, "TVScreen.obj", "TVScreen", false, false)
addbehaviour(objects[46], "tv")
objects[47] = creategameobject("Camera", false, 3.55, 12.9, 33.98, 0.6087614, 1.832368E-07, 8.738289E-08, -0.7933534, 1, 1, 1, "", "", false, false)
addbehaviour(objects[47], "camera", 70, 0.3, 1000, false)
addchild(objects[46], objects[47], false)
addchild(objects[45], objects[46], false)

objects[48] = creategameobject("Plane (3)", true, -29.09, 35.4, -96.78, 0, -0.7071068, 0, 0.7071068, 1.561553, 1, 20, "plane.obj", "ground", false, false)
addbehaviour(objects[48], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[48], "meshcollider", true)

objects[49] = creategameobject("DoorPrefab (1)", false, -64.547, 22.85, -69.568, 0, 0, 0, 1, 1, 1, 0.5, "", "", true, true)
addbehaviour(objects[49], "npc", 15, false, true)
addbehaviour(objects[49], "door")
objects[50] = creategameobject("DoorLeft", false, 0.15, 0, 0, 0, 0, 0, 1, 1, 1, 1, "DoorLeft.obj", "Door", true, true)
addbehaviour(objects[50], "meshcollider", true)
addbehaviour(objects[50], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[50], "translationanimation")
addchild(objects[49], objects[50], false)
objects[51] = creategameobject("DoorRight", false, -0.15, 0, 0, 0, 0, 0, 1, 1, 1, 1, "DoorRight.obj", "Door", true, true)
addbehaviour(objects[51], "meshcollider", true)
addbehaviour(objects[51], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[51], "translationanimation")
addchild(objects[49], objects[51], false)

objects[52] = creategameobject("Plane (9)", true, -46, 35.4, -93.61, 0, 0, 0, 1, 5, 1, 6, "plane.obj", "ground", false, false)
addbehaviour(objects[52], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[52], "meshcollider", true)

objects[53] = creategameobject("DoorPrefab (6)", false, -46.07, 35.19, -79.32, 0, 0, 0, 1, 1, 1, 0.5, "", "", true, true)
addbehaviour(objects[53], "npc", 17, false, true)
addbehaviour(objects[53], "door")
objects[54] = creategameobject("DoorLeft", false, 0.15, 0, 0, 0, 0, 0, 1, 1, 1, 1, "DoorLeft.obj", "Door", true, true)
addbehaviour(objects[54], "meshcollider", true)
addbehaviour(objects[54], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[54], "translationanimation")
addchild(objects[53], objects[54], false)
objects[55] = creategameobject("DoorRight", false, -0.15, 0, 0, 0, 0, 0, 1, 1, 1, 1, "DoorRight.obj", "Door", true, true)
addbehaviour(objects[55], "meshcollider", true)
addbehaviour(objects[55], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[55], "translationanimation")
addchild(objects[53], objects[55], false)

objects[56] = creategameobject("Plane (4)", true, -2.39, 35.4, -80.39, 0, 0, 0, 1, 2, 1, 20, "plane.obj", "ground", false, false)
addbehaviour(objects[56], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[56], "meshcollider", true)

objects[57] = creategameobject("DoorPrefab (5)", false, -46.75, 23.39, -99.04, 0, 0, 0, 1, 1, 1, 0.5, "", "", true, true)
addbehaviour(objects[57], "npc", 16, false, true)
addbehaviour(objects[57], "door")
objects[58] = creategameobject("DoorLeft", false, 0.15, 0, 0, 0, 0, 0, 1, 1, 1, 1, "DoorLeft.obj", "Door", true, true)
addbehaviour(objects[58], "meshcollider", true)
addbehaviour(objects[58], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[58], "translationanimation")
addchild(objects[57], objects[58], false)
objects[59] = creategameobject("DoorRight", false, -0.15, 0, 0, 0, 0, 0, 1, 1, 1, 1, "DoorRight.obj", "Door", true, true)
addbehaviour(objects[59], "meshcollider", true)
addbehaviour(objects[59], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[59], "translationanimation")
addchild(objects[57], objects[59], false)

objects[60] = creategameobject("Plane (5)", true, -21.39, 35.38, -56.33, 0, -0.7071068, 0, 0.7071068, 4, 1, 22.17339, "plane.obj", "ground", false, false)
addbehaviour(objects[60], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[60], "meshcollider", true)

objects[61] = creategameobject("DoorPrefab", false, -64.657, 22.85, -50.635, 0, 0, 0, 1, 1, 1, 0.5, "", "", true, true)
addbehaviour(objects[61], "npc", 4, false, true)
addbehaviour(objects[61], "door")
objects[62] = creategameobject("DoorLeft", false, 0.15, 0, 0, 0, 0, 0, 1, 1, 1, 1, "DoorLeft.obj", "Door", true, true)
addbehaviour(objects[62], "meshcollider", true)
addbehaviour(objects[62], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[62], "translationanimation")
addchild(objects[61], objects[62], false)
objects[63] = creategameobject("DoorRight", false, -0.15, 0, 0, 0, 0, 0, 1, 1, 1, 1, "DoorRight.obj", "Door", true, true)
addbehaviour(objects[63], "meshcollider", true)
addbehaviour(objects[63], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[63], "translationanimation")
addchild(objects[61], objects[63], false)

objects[64] = creategameobject("Plane (2)", true, -46.35, 35.4, -66.71, 0, 0, 0, 1, 5.191815, 1, 15.67551, "plane.obj", "ground", false, false)
addbehaviour(objects[64], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[64], "meshcollider", true)

objects[65] = creategameobject("Corridor_L_Turn_Quad", true, -65.129, 25.87, -75.3, 0, 0, 0, 1, 1, 1, 1, "corridors/leftcorridor.obj", "leftcorridor", false, true)
addbehaviour(objects[65], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[65], "meshcollider", false)

objects[66] = creategameobject("Drawer (19)", true, -58.423, 27.92, -65.55, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true, true)

objects[67] = creategameobject("Wall (107)", true, -0.3, 35.09, -73.87, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[67], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[67], "meshcollider", true)

objects[68] = creategameobject("battery_Tri", false, -48.271, 24.21617, -54.75, 0, 0, 0, 1, 1, 1, 1, "battery.obj", "greenbattery", true, true)
addbehaviour(objects[68], "npc", 10, true, false)
addbehaviour(objects[68], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[68], "meshcollider", true)
addbehaviour(objects[68], "audiosource", "sparks.wav", true, true, true, false, 1, 0.5, false)

objects[69] = creategameobject("Elevator_Cockpit_Platform_tri", false, -109.39, 16.59, -114.27, 0, -1, 0, 0, 1, 1, 1, "elevator.obj", "elevator", true, true)
addbehaviour(objects[69], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[69], "meshcollider", true)
addbehaviour(objects[69], "elevator", -109.39, 23.514, -114.27, 3.5)
addbehaviour(objects[69], "npc", 68, false, false)
objects[70] = creategameobject("Elevator_Cockpit_Gears_tri", false, 1.220001, -0.2299995, 0.01000214, 0, 1, 0, 0, 1, 1, 1, "elevatorgears.obj", "elevatorgears", true, true)
addbehaviour(objects[70], "rotationanimation", 0, 0, -100)
addchild(objects[69], objects[70], false)

objects[71] = creategameobject("Elevator_Cockpit_Beams_tri (1)", true, -79.7, 21.22, -114.241, 0, 0, 0, 1, 1, 1, 1, "elevatorbeam.obj", "elevatorbeam", true, true)

objects[72] = creategameobject("Corridor_L_Turn_Quad (3)", true, -58.775, 25.87, -94.188, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/leftcorridor.obj", "leftcorridor", false, true)
addbehaviour(objects[72], "meshcollider", false)
addbehaviour(objects[72], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[73] = creategameobject("crate (10)", true, -71.56, 22.77, -41.06, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[73], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[73], "meshcollider", true)

objects[74] = creategameobject("Drawer (1)", true, -58.423, 27.92, -44.18154, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true, true)

objects[75] = creategameobject("small_box (16)", true, -35.9, 23.4, -68.06, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[75], "meshcollider", true)
addbehaviour(objects[75], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[76] = creategameobject("Wall (114)", true, -4.81, 23.54, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[76], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[76], "meshcollider", true)

objects[77] = creategameobject("Wall (9)", true, -57.81, 22.9, -45, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[77], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[77], "meshcollider", true)

objects[78] = creategameobject("Wall (126)", true, -4.96, 35.09, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[78], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[78], "meshcollider", true)

objects[79] = creategameobject("Wall (31)", true, -89.44, 29.95, -39.16, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[80] = creategameobject("Drawer (8)", true, -89.76, 28.27, -36.50562, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true, true)

objects[81] = creategameobject("Small Box", false, -47.11, 25.27, -56.75, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[81], "meshcollider", true)
addbehaviour(objects[81], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[81], "npc", 50, true, false)

objects[82] = creategameobject("Wall (106)", true, -0.3, 35.09, -87.97, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[82], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[82], "meshcollider", true)

objects[83] = creategameobject("Wall (18)", true, -33.11, 23.54, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[83], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[83], "meshcollider", true)

objects[84] = creategameobject("Wall (51)", true, -90.7, 29.11, -25.62, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[85] = creategameobject("Small Box", false, -7.46, 23.4, -78.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[85], "meshcollider", true)
addbehaviour(objects[85], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[85], "npc", 50, true, false)

objects[86] = creategameobject("Spotlight (8)", false, -82.43, 28.6, -89.11, 0.7071068, 0, 0, 0.7071068, 1, 1, 1, "", "", false, false)
addbehaviour(objects[86], "light", "spot", 0.5893166, 0.7232133, 0.7352941, 1, 0.8, 80)

objects[87] = creategameobject("Drawer (5)", true, -58.423, 27.92, -28.84269, 0, 1, 0, 0, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true, true)

objects[88] = creategameobject("Wall (129)", true, 2.13, 29.2, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[88], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[88], "meshcollider", true)

objects[89] = creategameobject("Wall (38)", true, -69.249, 28.96, -52.69, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)

objects[90] = creategameobject("Small Box", false, -46.49, 29.27, -54.61, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[90], "meshcollider", true)
addbehaviour(objects[90], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[90], "npc", 50, true, false)

objects[91] = creategameobject("Wall (92)", true, -50.34, 35.09, -71.26, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[91], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[91], "meshcollider", true)

objects[92] = creategameobject("quad:Wall_Corner", true, -89.05101, 22.9, -63.956, 0, 1, 0, 0, 1, 1, 1, "Walls/Corner.obj", "corner", true, true)
addbehaviour(objects[92], "meshcollider", true)
addbehaviour(objects[92], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[93] = creategameobject("Wall (61)", true, -47.31, 29.2, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[93], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[93], "meshcollider", true)

objects[94] = creategameobject("Small Box", false, -10.46, 23.4, -72.19, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[94], "meshcollider", true)
addbehaviour(objects[94], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[94], "npc", 50, true, false)

objects[95] = creategameobject("FingerPrintScanner (2)", true, -107.374, 18.193, -116.4, 0, -1, 0, 0, 1, 1, 1, "fingerprintscanner.obj", "fingerprintscanner", true, true)
addbehaviour(objects[95], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[95], "meshcollider", true)
addbehaviour(objects[95], "npc", 72, true, false)

objects[96] = creategameobject("pasted__pCube85_group (4)", true, -82.408, 16.257, -118.258, 0, -0.7071068, 0, 0.7071068, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[96], "meshcollider", true)
addbehaviour(objects[96], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[97] = creategameobject("recharger_Tri (4)", true, -15.5, 25.94, -96.74, 0, 0, 0, 1, 1, 1, 1, "batteryslot.obj", "greenbattery", true, true)
addbehaviour(objects[97], "npc", 21, false, true)
addbehaviour(objects[97], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[97], "meshcollider", false)

objects[98] = creategameobject("Drawer (10)", true, -89.76, 28.27, -44.18154, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true, true)

objects[99] = creategameobject("Wall (15)", true, -58.68, 29.7666, -51.97, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[100] = creategameobject("the_thing_orb_tri", false, -94.88, 16.37, -122.3, 0, 0, 0, 1, 1, 1, 1, "roundthingorb.obj", "roundthing", true, true)
addbehaviour(objects[100], "rotationanimation", 0, 50, 0)
addbehaviour(objects[100], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[100], "meshcollider", true)

objects[101] = creategameobject("small_box (54)", true, -41.78, 23.4, -86.71, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[101], "meshcollider", true)
addbehaviour(objects[101], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[102] = creategameobject("Wall (58)", true, -33.23, 23.54, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[102], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[102], "meshcollider", true)

objects[103] = creategameobject("small_box (45)", true, -29.76, 23.4, -83.71, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[103], "meshcollider", true)
addbehaviour(objects[103], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[104] = creategameobject("Spotlight (9)", false, -93.7, 28.6, -103.68, 0.7071068, 0, 0, 0.7071068, 1, 1, 1, "", "", false, false)
addbehaviour(objects[104], "light", "spot", 0.5893166, 0.7232133, 0.7352941, 1, 0.8, 80)

objects[105] = creategameobject("FingerPrintScanner (3)", true, -81.912, 18.23, -116.383, 0, -1, 0, 0, 1, 1, 1, "fingerprintscanner.obj", "fingerprintscanner", true, true)
addbehaviour(objects[105], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[105], "meshcollider", true)
addbehaviour(objects[105], "npc", 71, true, false)

objects[106] = creategameobject("Drawer (14)", true, -89.76, 28.27, -55.67919, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true, true)

objects[107] = creategameobject("Wall (99)", true, -19.11, 35.09, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[107], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[107], "meshcollider", true)

objects[108] = creategameobject("Wall (47)", true, -59.48, 22.9, -54.01, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[108], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[108], "meshcollider", true)

objects[109] = creategameobject("Double_Door_Wall_Tri (1)", true, -64.77, 22.88, -69.3, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "doorframe", true, true)
addbehaviour(objects[109], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[109], "meshcollider", false)

objects[110] = creategameobject("small_box (48)", true, -23.76, 23.4, -86.71, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[110], "meshcollider", true)
addbehaviour(objects[110], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[111] = creategameobject("small_box (31)", true, -38.32, 23.4, -70.01, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[111], "meshcollider", true)
addbehaviour(objects[111], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[112] = creategameobject("WallDoubleSided", true, -70.014, 22.777, -52.799, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/WallDoubleSided.obj", "Wall", true, true)
addbehaviour(objects[112], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[112], "meshcollider", true)

objects[113] = creategameobject("Wall (56)", true, -19.11, 23.54, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[113], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[113], "meshcollider", true)

objects[114] = creategameobject("Wall (5)", true, -63.07, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[115] = creategameobject("Wall (41)", true, -70.06, 28.96, -66.55, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[116] = creategameobject("Plane (7)", true, -25.1, 40.98, -79.7, 0, 0, -1, 0, 30, 1, 30, "plane.obj", "ceiling", false, false)
addbehaviour(objects[116], "meshcollider", true)
addbehaviour(objects[116], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[117] = creategameobject("player", false, -86.36, 25.03, -33.04, 0, 0, 0, 1, 1, 1, 1, "", "", true, true)
addbehaviour(objects[117], "player", 8)
addbehaviour(objects[117], "charactercontroller", 45, 0.3, 0.5, 2)
objects[118] = creategameobject("Camera", false, 0, 0.967, 0, 0.02475809, 0.5846852, 0.01785609, -0.8106858, 1, 1, 1, "", "", true, true)
addbehaviour(objects[118], "camera", 60, 0.3, 1000, true)
addbehaviour(objects[118], "audiolistener")
addchild(objects[117], objects[118], false)

objects[119] = creategameobject("Bottom_Tri", true, -94.738, 16.9, -129.168, 0, 0, 0, 1, 1, 1, 1, "cockpit/cockpitfloor.obj", "cockpitfloor", true, true)
addbehaviour(objects[119], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[119], "meshcollider", false)

objects[120] = creategameobject("Wall (2)", true, -63.07, 22.9, -25.69, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[120], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[120], "meshcollider", true)

objects[121] = creategameobject("quad:Wall_Corner", true, -58.157, 22.9, -49.917, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Corner.obj", "corner", true, true)
addbehaviour(objects[121], "meshcollider", true)
addbehaviour(objects[121], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[122] = creategameobject("small_box (47)", true, -23.76, 23.4, -83.71, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[122], "meshcollider", true)
addbehaviour(objects[122], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[123] = creategameobject("crane_Tri", true, -24.49, 39.82, -79.42, 0, 0, 0, 1, 1, 1, 1, "cranesupport.obj", "crane", true, true)

objects[124] = creategameobject("Double_Door_Wall_Tri (4)", true, -94.48, 23.53, -106.62, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "doorframe", true, true)
addbehaviour(objects[124], "meshcollider", false)
addbehaviour(objects[124], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[125] = creategameobject("Corridor_Straight_Tri (5)", true, -58.42, 25.87, -102.91, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/straightcorridor.obj", "straightcorridor", false, true)
addbehaviour(objects[125], "meshcollider", false)
addbehaviour(objects[125], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[126] = creategameobject("Plane (10)", true, -46, 35.27, -93.61, 1, 0, 0, 0, 5, 1, 6, "plane.obj", "ceiling", false, false)
addbehaviour(objects[126], "meshcollider", true)
addbehaviour(objects[126], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[127] = creategameobject("Wall (64)", true, -0.3, 23.54, -87.97, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[127], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[127], "meshcollider", true)

objects[128] = creategameobject("Small Box", false, -48.53, 28.59, -54.61, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[128], "meshcollider", true)
addbehaviour(objects[128], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[128], "npc", 50, true, false)

objects[129] = creategameobject("Corridor_Reinfocement_Tri (6)", true, -94.49, 25.97, -99.428, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[129], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[129], "meshcollider", false)

objects[130] = creategameobject("Corridor_L_Turn_Quad (4)", true, -58.08, 25.88, -111.58, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "corridors/leftcorridor.obj", "leftcorridor", false, true)
addbehaviour(objects[130], "meshcollider", false)
addbehaviour(objects[130], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[131] = creategameobject("Wall (75)", true, -33.23, 29.2, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[131], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[131], "meshcollider", true)

objects[132] = creategameobject("Wall (4)", true, -84.018, 29.11, -25.62, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[133] = creategameobject("FingerPrintScanner (1)", true, -107.325, 25.34, -116.379, 0, -1, 0, 0, 1, 1, 1, "fingerprintscanner.obj", "fingerprintscanner", true, true)
addbehaviour(objects[133], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[133], "meshcollider", true)
addbehaviour(objects[133], "npc", 69, true, false)

objects[134] = creategameobject("small_box (58)", true, -23.76, 23.4, -89.96, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[134], "meshcollider", true)
addbehaviour(objects[134], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[135] = creategameobject("rails (4)", true, -89.738, 23.227, -111.598, 0, 0.3173046, 0, 0.9483237, 1, 1, 1, "rails.obj", "rails", true, true)
addbehaviour(objects[135], "meshcollider", true)
addbehaviour(objects[135], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[136] = creategameobject("Corridor_Reinfocement_Tri (5)", true, -88.673, 25.97, -93.756, 0, 0, 0, 1, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[136], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[136], "meshcollider", false)

objects[137] = creategameobject("Wall (73)", true, -0.3, 29.2, -95.08, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[137], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[137], "meshcollider", true)

objects[138] = creategameobject("Wall (128)", true, -4.96, 29.2, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[138], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[138], "meshcollider", true)

objects[139] = creategameobject("crate (8)", true, -81.2, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[139], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[139], "meshcollider", true)

objects[140] = creategameobject("control_panel (1)", true, -100.98, 16.477, -141.718, 0, -0.7071068, 0, -0.7071068, 1.2, 1.2, 1.2, "computer.obj", "computer", true, true)
addbehaviour(objects[140], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[140], "meshcollider", true)

objects[141] = creategameobject("Wall (84)", true, -50.34, 29.2, -78.36, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[141], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[141], "meshcollider", true)

objects[142] = creategameobject("Spotlight (4)", false, -65.64, 26.68, -40.67, 1, 0, 0, 0, 1, 1, 1, "", "", false, false)
addbehaviour(objects[142], "light", "spot", 0.5893166, 0.7232133, 0.7352941, 1, 0, 65)
addbehaviour(objects[142], "lightidentifier", 2)

objects[143] = creategameobject("DoubleSidedWall (1)", true, -59.7, 29, -50.57, 0, -1, 0, 0, 1, 1, 1, "Walls/walldoublesided.obj", "wall", false, true)

objects[144] = creategameobject("Wall (53)", true, -25.89, 29.2, -52.25, 0, 0, 0, 1, 1.062688, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[144], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[144], "meshcollider", true)

objects[145] = creategameobject("Wall (1)", true, -70.09, 22.9, -25.69, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[145], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[145], "meshcollider", true)

objects[146] = creategameobject("Double_Door_Wall_Tri", true, -64.77, 22.75, -50.69, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "doorframe", true, true)
addbehaviour(objects[146], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[146], "meshcollider", false)

objects[147] = creategameobject("big_pipes_Tri (1)", true, -59.29, 29.55, -45.37, 0, 0, 0, 1, 1, 1, 1, "bigpipe.obj", "bigpipe", true, true)
objects[148] = creategameobject("Drawer (13)", true, 0.8670006, -1.92, -12.31, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true, true)
addchild(objects[147], objects[148], false)

objects[149] = creategameobject("pasted__pCube85_group (3)", true, -82.408, 16.307, -118.998, 0, -0.7071068, 0, 0.7071068, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[149], "meshcollider", true)
addbehaviour(objects[149], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[150] = creategameobject("Wall (48)", true, -59.74, 22.9, -61.06, 0, -0.7191516, 0, -0.6948533, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[150], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[150], "meshcollider", true)

objects[151] = creategameobject("control_panel", true, -46.5, 35.36, -55.4, 0, -0.9238796, 0, 0.3826834, 1, 1, 1, "computer.obj", "computer", false, false)
addbehaviour(objects[151], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[151], "meshcollider", false)
addbehaviour(objects[151], "npc", 18, false, false)
objects[152] = creategameobject("CraneTV", true, -0.746, 2.031, -1.471, 0.7723781, 0.03304067, -0.0328606, 0.6334513, 0.6723396, 0.6633902, 0.3919748, "plane.obj", "TVScreen", false, false)
addbehaviour(objects[152], "tv")
objects[153] = creategameobject("Camera (1)", false, -40.94, 9.17, 3.31, -0.7476079, 0.2257863, -0.2606802, 0.5675816, 1.514349, 2.482132, 1.549458, "", "", false, false)
addbehaviour(objects[153], "camera", 60, 0.3, 1000, false)
addchild(objects[152], objects[153], false)
addchild(objects[151], objects[152], false)

objects[154] = creategameobject("small_box (13)", true, -29.97, 23.4, -67.23, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[154], "meshcollider", true)
addbehaviour(objects[154], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[155] = creategameobject("Wall (90)", true, -50.34, 35.09, -85.26, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)
addbehaviour(objects[155], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[155], "meshcollider", false)

objects[156] = creategameobject("DoubleSidedWall (4)", true, -70.04, 22.95, -66.74, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true, true)
addbehaviour(objects[156], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[156], "meshcollider", true)

objects[157] = creategameobject("Wall (37)", true, -72.84, 28.96, -64.55, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[158] = creategameobject("pasted__pCube85_group", true, -59.972, 22.9, -51.19, 0, 0.05096556, 0, 0.9987005, 1.000837, 1, 1.000837, "pillar.obj", "pillar", true, true)
addbehaviour(objects[158], "meshcollider", true)
addbehaviour(objects[158], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[159] = creategameobject("Back_Tri", true, -94.648, 24.987, -112.108, 0, 0, 0, 1, 1, 1, 1, "cockpit/cockpitentrance.obj", "cockpitentrance", true, true)
addbehaviour(objects[159], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[159], "meshcollider", false)

objects[160] = creategameobject("Wall (29)", true, -89.44, 29.95, -25.04, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[161] = creategameobject("Spotlight", false, -82.4, 36, -106.4, 0.7071068, 0, 0, 0.7071068, 1, 1, 1, "", "", false, false)
addbehaviour(objects[161], "light", "spot", 1, 1, 1, 1, 1, 70)

objects[162] = creategameobject("Wall (82)", true, -50.34, 29.2, -64.19, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[162], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[162], "meshcollider", true)

objects[163] = creategameobject("Corridor_Reinfocement_Tri (7)", true, -94.49, 25.97, -106.047, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[163], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[163], "meshcollider", false)

objects[164] = creategameobject("Wall (101)", true, -33.23, 35.09, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[164], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[164], "meshcollider", true)

objects[165] = creategameobject("Wall (87)", true, -50.34, 29.2, -92.28, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[165], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[165], "meshcollider", true)

objects[166] = creategameobject("Wall (105)", true, -0.3, 35.09, -80.96, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[166], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[166], "meshcollider", true)

objects[167] = creategameobject("DoubleSidedWall (3)", true, -70.04, 22.95, -59.64, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true, true)
addbehaviour(objects[167], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[167], "meshcollider", true)

objects[168] = creategameobject("Double_Door_Wall_Tri (5)", true, -46.91, 23.37, -99.02, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "doorframe", true, true)
addbehaviour(objects[168], "meshcollider", false)
addbehaviour(objects[168], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[169] = creategameobject("pasted__pCube85_group (5)", true, -103.268, 16.307, -117.958, 0, -0.7071068, 0, 0.7071068, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[169], "meshcollider", true)
addbehaviour(objects[169], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[170] = creategameobject("Wall (43)", true, -69.25, 28.97, -59.78, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)

objects[171] = creategameobject("Corridor_Straight_Tri (3)", true, -94.49, 25.865, -102.766, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/straightcorridor.obj", "straightcorridor", false, true)
addbehaviour(objects[171], "meshcollider", false)
addbehaviour(objects[171], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[172] = creategameobject("Wall (116)", true, -11.84, 35.09, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[172], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[172], "meshcollider", true)

objects[173] = creategameobject("the_thing", true, -95.25, 16.24, -122.31, 0, 0, 0, 1, 1, 1, 1, "roundthing.obj", "roundthing", true, true)
addbehaviour(objects[173], "meshcollider", true)
addbehaviour(objects[173], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[174] = creategameobject("Plane (8)", true, -46, 35, -66.71, 1, 0, 0, 0, 5.191815, 1, 14.55824, "plane.obj", "ceiling", false, false)
addbehaviour(objects[174], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[174], "meshcollider", true)

objects[175] = creategameobject("Wall (71)", true, -0.3, 29.2, -87.97, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[175], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[175], "meshcollider", true)

objects[176] = creategameobject("elevator_outside", true, -6.09, 24.32, -95.55, 0, 0, 0, 1, 1, 1, 1, "adielevatorbottom.obj", "adielevatoroutside", false, false)
addbehaviour(objects[176], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[176], "meshcollider", false)

objects[177] = creategameobject("Spotlight (7)", false, -73.859, 28.6, -76.03, 0.7071068, 0, 0, 0.7071068, 1, 1, 1, "", "", false, false)
addbehaviour(objects[177], "light", "spot", 0.5893166, 0.7232133, 0.7352941, 1, 0.8, 80)

objects[178] = creategameobject("small_box (53)", true, -39.15, 23.4, -87.62, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[178], "meshcollider", true)
addbehaviour(objects[178], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[179] = creategameobject("Corridor_Reinfocement_Tri (16)", true, -46.946, 25.985, -99.717, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[179], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[179], "meshcollider", false)

objects[180] = creategameobject("small_box (57)", true, -26.76, 23.4, -89.96, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[180], "meshcollider", true)
addbehaviour(objects[180], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[181] = creategameobject("roof_cables (1)", true, -100.118, 29.517, -123.798, 0, -1, 0, 0, 1, 1, 1, "roofcable.obj", "roofcable", true, true)

objects[182] = creategameobject("Wall (8)", true, -57.81, 22.9, -37.98, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[182], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[182], "meshcollider", false)

objects[183] = creategameobject("Corridor_L_Turn_Quad (2)", true, -94.062, 25.865, -94.111, 0, -1, 0, 0, 1, 1, 1, "corridors/leftcorridor.obj", "leftcorridor", false, true)
addbehaviour(objects[183], "meshcollider", false)
addbehaviour(objects[183], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[184] = creategameobject("pasted__pCube85_group", true, -59.972, 22.9, -50.184, 0, 0.05096556, 0, 0.9987004, 1.000837, 1, 1.000837, "pillar.obj", "pillar", true, true)
addbehaviour(objects[184], "meshcollider", true)
addbehaviour(objects[184], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[185] = creategameobject("Wall (93)", true, -50.34, 35.09, -64.19, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[185], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[185], "meshcollider", true)

objects[186] = creategameobject("DoubleSidedWall (10)", true, -41.29, 35.1, -69.35, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true, true)
addbehaviour(objects[186], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[186], "meshcollider", true)

objects[187] = creategameobject("roof_cables", true, -89.458, 29.517, -123.798, 0, 0, 0, 1, 1, 1, 1, "roofcable.obj", "roofcable", true, true)

objects[188] = creategameobject("control_panel (2)", true, -88.53, 16.477, -141.78, 0, 0, 0, 1, 1.2, 1.2, 1.2, "computer.obj", "computer", true, true)
addbehaviour(objects[188], "meshcollider", true)
addbehaviour(objects[188], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[189] = creategameobject("Wall (79)", true, -33.11, 29.2, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[189], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[189], "meshcollider", true)

objects[190] = creategameobject("crate (7)", true, -87.05388, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[190], "meshcollider", true)
addbehaviour(objects[190], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[191] = creategameobject("Wall (95)", true, -40.2, 35.09, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[191], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[191], "meshcollider", true)

objects[192] = creategameobject("quad:Wall_Corner", true, -58.157, 22.899, -26.041, 0, 0, 0, 1, 1, 1, 1, "Walls/Corner.obj", "corner", true, true)
addbehaviour(objects[192], "meshcollider", true)
addbehaviour(objects[192], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[193] = creategameobject("Wall (69)", true, -0.3, 29.2, -66.79, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[193], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[193], "meshcollider", true)

objects[194] = creategameobject("small_box (27)", true, -34.79, 23.4, -74.55, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[194], "meshcollider", true)
addbehaviour(objects[194], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[195] = creategameobject("Wall (62)", true, -0.3, 23.54, -95.08, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[195], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[195], "meshcollider", false)

objects[196] = creategameobject("Wall (104)", true, -0.3, 35.09, -95.08, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[196], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[196], "meshcollider", false)

objects[197] = creategameobject("Corridor_L_Turn_Quad (5)", true, -47.374, 25.88, -111.653, 0, 0, 0, 1, 1, 1, 1, "corridors/leftcorridor.obj", "leftcorridor", false, true)
addbehaviour(objects[197], "meshcollider", false)
addbehaviour(objects[197], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[198] = creategameobject("Wall (100)", true, -26.2, 35.09, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[198], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[198], "meshcollider", true)

objects[199] = creategameobject("Wall (52)", true, -50.45, 23.54, -71.26, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[199], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[199], "meshcollider", true)

objects[200] = creategameobject("DoubleSidedWall (12)", true, -41.29, 35.1, -82.65, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true, true)
addbehaviour(objects[200], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[200], "meshcollider", true)

objects[201] = creategameobject("Wall (74)", true, -40.2, 29.2, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[201], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[201], "meshcollider", true)

objects[202] = creategameobject("Corridor_Y_Turn_Tri", true, -83.001, 25.865, -93.328, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "corridors/ycorridor.obj", "ycorridor", false, true)
addbehaviour(objects[202], "meshcollider", false)
addbehaviour(objects[202], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[203] = creategameobject("table (3)", true, -100.04, 16.83, -133.9, 0, -0.7071068, 0, -0.7071068, 0.42, 0.42, 0.42, "table.obj", "table", true, true)
addbehaviour(objects[203], "meshcollider", true)
addbehaviour(objects[203], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[204] = creategameobject("battery_Tri (1)", false, -24.53, 33.564, -79.84, 0, 0, 0, 1, 1, 1, 1, "battery.obj", "redbattery", true, true)
addbehaviour(objects[204], "npc", 11, true, false)
addbehaviour(objects[204], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, true)
addbehaviour(objects[204], "meshcollider", true)
addbehaviour(objects[204], "audiosource", "sparks.wav", true, true, true, false, 1, 0.5, false)

objects[205] = creategameobject("Small Box", false, -10.46, 23.4, -75.19, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[205], "meshcollider", true)
addbehaviour(objects[205], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[205], "npc", 50, true, false)

objects[206] = creategameobject("Drawer", true, -58.423, 27.92, -40.34682, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true, true)

objects[207] = creategameobject("Wall (102)", true, -40.2, 35.09, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[207], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[207], "meshcollider", true)

objects[208] = creategameobject("Wall (35)", true, -79.85, 28.96, -64.55, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[209] = creategameobject("Wall (20)", true, -75.32, 22.9, -64.3, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[209], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[209], "meshcollider", true)

objects[210] = creategameobject("crate (1)", true, -83.96, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[210], "meshcollider", true)
addbehaviour(objects[210], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[211] = creategameobject("pasted__pCube85_group (1)", true, -107.038, 16.257, -118.258, 0, -0.7071068, 0, 0.7071068, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[211], "meshcollider", true)
addbehaviour(objects[211], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[212] = creategameobject("Wall (65)", true, -0.3, 23.54, -73.87, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[212], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[212], "meshcollider", true)

objects[213] = creategameobject("pasted__pCube85_group (7)", true, -87.618, 16.307, -113.008, 0, -0.7071068, 0, 0.7071068, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[213], "meshcollider", true)
addbehaviour(objects[213], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[214] = creategameobject("Wall (81)", true, -47.23, 29.2, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[214], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[214], "meshcollider", true)

objects[215] = creategameobject("Wall (125)", true, -11.99, 35.09, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[215], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[215], "meshcollider", true)

objects[216] = creategameobject("cockpit_curved_wall_bottom_tri", true, -95.038, 15.967, -103.608, 0, 0, 0, 1, 1, 1, 1, "cockpit/bottomwall.obj", "bottomwall", true, true)
addbehaviour(objects[216], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[216], "meshcollider", false)

objects[217] = creategameobject("Wall (68)", true, -0.3, 29.2, -59.86, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[217], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[217], "meshcollider", true)

objects[218] = creategameobject("Drawer (15)", true, -89.76, 28.27, -59.50741, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true, true)

objects[219] = creategameobject("recharger_Tri (2)", true, -30.49, 26.08, -56.03, 0, -1, 0, 0, 1, 1, 1, "batteryslot.obj", "greenbattery", true, true)
addbehaviour(objects[219], "npc", 28, false, true)
addbehaviour(objects[219], "meshcollider", false)
addbehaviour(objects[219], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[220] = creategameobject("Wall (70)", true, -0.3, 29.2, -73.87, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[220], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[220], "meshcollider", true)

objects[221] = creategameobject("pasted__pCube85_group", true, -69.04, 22.9, -50.184, 0, 0.05096556, 0, 0.9987004, 1.000837, 1, 1.000837, "pillar.obj", "pillar", true, true)
addbehaviour(objects[221], "meshcollider", true)
addbehaviour(objects[221], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[222] = creategameobject("Corridor_Straight_Tri", true, -73.855, 25.87, -75.655, 0, 0, 0, 1, 1, 1, 1, "corridors/straightcorridor.obj", "straightcorridor", false, true)
addbehaviour(objects[222], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[222], "meshcollider", false)

objects[223] = creategameobject("Wall (86)", true, -50.34, 29.2, -99.18, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)
addbehaviour(objects[223], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[223], "meshcollider", true)

objects[224] = creategameobject("Wall (115)", true, 2.28, 23.54, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[224], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[224], "meshcollider", true)

objects[225] = creategameobject("rails (6)", true, -94.858, 23.227, -109.658, 0, 0, 0, 1, 1, 1, 1, "rails.obj", "rails", true, true)
addbehaviour(objects[225], "meshcollider", true)
addbehaviour(objects[225], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[226] = creategameobject("Wall (119)", true, 2.28, 35.09, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[226], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[226], "meshcollider", true)

objects[227] = creategameobject("Small Box", false, -7.46, 23.4, -75.19, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[227], "meshcollider", true)
addbehaviour(objects[227], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[227], "npc", 50, true, false)

objects[228] = creategameobject("Wall (103)", true, -47.31, 35.09, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[228], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[228], "meshcollider", true)

objects[229] = creategameobject("Wall (45)", true, -58.68, 29.7666, -66.15, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)

objects[230] = creategameobject("Small Box", false, -44.93, 23.4, -54.78, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[230], "meshcollider", true)
addbehaviour(objects[230], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[230], "npc", 50, true, false)

objects[231] = creategameobject("Wall (30)", true, -89.44, 29.95, -32.04, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[232] = creategameobject("Wall (63)", true, -0.3, 23.54, -80.96, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[232], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[232], "meshcollider", true)

objects[233] = creategameobject("DoubleSidedWall", true, -66.54, 29, -50.57, 0, -1, 0, 0, 1, 1, 1, "Walls/walldoublesided.obj", "wall", false, true)

objects[234] = creategameobject("Plane", true, -72.5, 22.94, -50.3, 0, 0, 0, 1, 20, 1, 25, "plane.obj", "ground", false, false)
addbehaviour(objects[234], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[234], "meshcollider", true)

objects[235] = creategameobject("polySurface12", false, -6.09, 24.27, -95.58, 0, 0, 0, 1, 1, 1, 1, "adielevatorpad.obj", "adielevatorinside", true, true)
addbehaviour(objects[235], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[235], "meshcollider", false)
addbehaviour(objects[235], "elevator", -6.09, 35.79, -95.58, 3.5)
addbehaviour(objects[235], "npc", 20, true, false)
objects[236] = creategameobject("elevator_stuffontop", false, 0.25, 0.03999901, -0.04000092, 0, 0, 0, 1, 1, 1, 1, "adielevatorjunk.obj", "adielevatorinside", true, true)
addchild(objects[235], objects[236], false)

objects[237] = creategameobject("small_box (50)", true, -29.76, 23.4, -86.71, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[237], "meshcollider", true)
addbehaviour(objects[237], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[238] = creategameobject("Wall (34)", true, -89.44, 29.95, -60.15, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[239] = creategameobject("Corridor_Reinfocement_Tri (12)", true, -58.42, 25.975, -106.191, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[239], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[239], "meshcollider", false)

objects[240] = creategameobject("Wall (50)", true, -50.42, 23.54, -78.36, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[240], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[240], "meshcollider", false)

objects[241] = creategameobject("Wall (112)", true, -4.81, 29.2, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[241], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[241], "meshcollider", true)

objects[242] = creategameobject("Wall (121)", true, -11.99, 23.54, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[242], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[242], "meshcollider", true)

objects[243] = creategameobject("Wall (7)", true, -77.11, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[244] = creategameobject("Crane", false, -24.54, 33.03, -79.88, 0, 0, 0, 1, 1, 1, 1, "", "", false, false)
addbehaviour(objects[244], "elevator", -24.54, 25.4, -79.88, 2)
addbehaviour(objects[244], "npc", 19, true, false)
objects[245] = creategameobject("crane_bottom", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "cranebottom.obj", "crane", false, false)
addchild(objects[244], objects[245], false)
objects[246] = creategameobject("crane_top", false, 0, 3.450001, 0, 0, 0, 0, 1, 1, 1, 1, "cranetop.obj", "crane", false, false)
addchild(objects[244], objects[246], false)
objects[247] = creategameobject("CraneFloorCollider", false, 0, 0.185, 0, 0, 0, 0, 1, 1.704787, 1, 3.461635, "plane.obj", "", false, false)
addbehaviour(objects[247], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[247], "meshcollider", true)
addchild(objects[244], objects[247], false)
objects[248] = creategameobject("CraneFloorCollider (1)", false, 0, -0.16, 0, 0, 0, 0, 1, 1.70479, 1, 3.46163, "plane.obj", "", false, false)
addbehaviour(objects[248], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[248], "meshcollider", true)
addchild(objects[244], objects[248], false)
objects[249] = creategameobject("CraneCeilingCollider", false, 0, 5.64, 0, 0, 0, 0, 1, 1.70479, 1, 3.46163, "plane.obj", "", false, false)
addbehaviour(objects[249], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[249], "meshcollider", true)
addchild(objects[244], objects[249], false)
objects[250] = creategameobject("CraneCeilingCollider (1)", false, 2.08, 3.867, 0, 0, 0, -0.7071068, 0.7071068, 1.70479, 1, 3.46163, "plane.obj", "", false, false)
addbehaviour(objects[250], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[250], "meshcollider", true)
addchild(objects[244], objects[250], false)
objects[251] = creategameobject("CraneCeilingCollider (2)", false, -2.09, 3.867001, 0, 0, 0, -0.7071068, 0.7071068, 1.704791, 1, 3.46163, "plane.obj", "", false, false)
addbehaviour(objects[251], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[251], "meshcollider", true)
addchild(objects[244], objects[251], false)

objects[252] = creategameobject("crate (3)", true, -77.58985, 22.77, -27.45414, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[252], "meshcollider", true)
addbehaviour(objects[252], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[253] = creategameobject("crate (6)", true, -71.77184, 22.77, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[253], "meshcollider", true)
addbehaviour(objects[253], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[254] = creategameobject("small_box (44)", true, -34.56, 23.4, -83.71, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[254], "meshcollider", true)
addbehaviour(objects[254], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[255] = creategameobject("Small Box", false, -47.69, 27.16, -56.43, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[255], "meshcollider", true)
addbehaviour(objects[255], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[255], "npc", 50, true, false)

objects[256] = creategameobject("Wall (19)", true, -26.08, 23.54, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[256], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[256], "meshcollider", true)

objects[257] = creategameobject("pasted__pCube85_group (9)", true, -91.928, 16.307, -109.828, 0, -0.7071068, 0, 0.7071068, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[257], "meshcollider", true)
addbehaviour(objects[257], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[258] = creategameobject("tv_set:polySurface5 (1)", true, -94.508, 31.727, -126.078, 0, 0, 0, 1, 0.5695158, 0.5695158, 0.5695158, "Tv's.obj", "tv's", true, true)

objects[259] = creategameobject("BGM", false, -70.18, 25.18, -39.84, 0, 0, 0, 1, 1, 1, 1, "", "", true, true)
addbehaviour(objects[259], "audiosource", "bgm.wav", true, true, true, false, 1, 1, true)

objects[260] = creategameobject("Wall (44)", true, -58.68, 29.7666, -59.14, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)

objects[261] = creategameobject("Drawer (3)", true, -58.423, 27.92, -36.50562, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true, true)

objects[262] = creategameobject("Drawer (7)", true, -89.76, 28.27, -32.66442, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true, true)

objects[263] = creategameobject("small_box (1)", true, -29.97, 23.4, -62.9, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[263], "meshcollider", true)
addbehaviour(objects[263], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[264] = creategameobject("small_box (30)", true, -39.79, 23.4, -72.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[264], "meshcollider", true)
addbehaviour(objects[264], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[265] = creategameobject("DoubleSidedWall (6)", true, -68.25, 29, -69.05, 0, -1, 0, 0, 1, 1, 1, "Walls/walldoublesided.obj", "wall", false, true)

objects[266] = creategameobject("Small Box", false, -46.15, 31.43, -53.89, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[266], "meshcollider", true)
addbehaviour(objects[266], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[266], "npc", 50, true, false)

objects[267] = creategameobject("Plane (1)", true, -81.7, 35.3, -61.2, 0, 0, -1, 0, 25, 1, 45, "plane.obj", "ceiling", false, false)
addbehaviour(objects[267], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[267], "meshcollider", true)

objects[268] = creategameobject("pasted__pCube85_group (10)", true, -97.638, 16.307, -109.828, 0, -0.7071068, 0, 0.7071068, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[268], "meshcollider", true)
addbehaviour(objects[268], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[269] = creategameobject("quad:Wall_Corner", true, -70.4099, 22.8974, -63.953, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Corner.obj", "corner", true, true)
addbehaviour(objects[269], "meshcollider", true)
addbehaviour(objects[269], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[270] = creategameobject("Corridor_L_Turn_Quad (1)", true, -82.529, 25.865, -76.005, 0, -1, 0, 0, 1, 1, 1, "corridors/leftcorridor.obj", "leftcorridor", false, true)
addbehaviour(objects[270], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[270], "meshcollider", false)

objects[271] = creategameobject("Spotlight (3)", false, -64.48, 30.1, -35.79, 0.7071068, 0, 0, 0.7071068, 1, 1, 1, "", "", false, false)
addbehaviour(objects[271], "light", "spot", 0.5893166, 0.7232133, 0.7352941, 1, 0, 100)
addbehaviour(objects[271], "lightidentifier", 1)

objects[272] = creategameobject("Wall (122)", true, 2.13, 35.09, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[272], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[272], "meshcollider", true)

objects[273] = creategameobject("pasted__pCube85_group", true, -73.98, 22.9, -40.76, 0, -0.4153649, 0, 0.9096549, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[273], "meshcollider", true)
addbehaviour(objects[273], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[273], "npc", 900, false, true)

objects[274] = creategameobject("Small Box", true, -13.36, 23.4, -84.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[274], "meshcollider", true)
addbehaviour(objects[274], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[275] = creategameobject("crate (4)", true, -67.74512, 22.77, -27.45414, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[275], "meshcollider", true)
addbehaviour(objects[275], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[276] = creategameobject("Wall (12)", true, -58.68, 29.7666, -30.77, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[277] = creategameobject("Wall (59)", true, -40.2, 23.54, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[277], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[277], "meshcollider", true)

objects[278] = creategameobject("Small Box", true, -16.46, 23.4, -75.19, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[278], "meshcollider", true)
addbehaviour(objects[278], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[279] = creategameobject("rails (1)", true, -105.208, 23.227, -118.368, 0, 0, 0, 1, 1, 1, 1, "rails.obj", "rails", true, true)
addbehaviour(objects[279], "meshcollider", true)
addbehaviour(objects[279], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[280] = creategameobject("crate (2)", true, -86.85376, 26.47, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[280], "meshcollider", true)
addbehaviour(objects[280], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[281] = creategameobject("FingerPrintScanner", true, -58.088, 24.661, -34.498, 0, 0.7071068, 0, 0.7071068, 0.848711, 0.84871, 0.848711, "fingerprintscanner.obj", "fingerprintscanner", false, false)
addbehaviour(objects[281], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[281], "npc", 1, false, false)
addbehaviour(objects[281], "meshcollider", true)

objects[282] = creategameobject("Wall (28)", true, -90.41, 22.9, -25.694, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[282], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[282], "meshcollider", true)

objects[283] = creategameobject("Small Box", false, -13.46, 23.4, -75.19, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[283], "meshcollider", true)
addbehaviour(objects[283], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[283], "npc", 50, true, false)

objects[284] = creategameobject("recharger_Tri (5)", true, -37.72, 26.1, -55.73, 0, -1, 0, 0, 1, 1, 1, "batteryslot.obj", "blackbattery", true, true)
addbehaviour(objects[284], "npc", 30, false, true)
addbehaviour(objects[284], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[284], "meshcollider", false)

objects[285] = creategameobject("Wall (66)", true, -0.3, 23.54, -66.79, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[285], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[285], "meshcollider", true)

objects[286] = creategameobject("Small Box", false, -46.5, 23.4, -57.05, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[286], "meshcollider", true)
addbehaviour(objects[286], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[286], "npc", 50, true, false)

objects[287] = creategameobject("recharger_Tri (3)", true, -34.09, 26.05, -55.73, 0, -1, 0, 0, 1, 1, 1, "batteryslot.obj", "redbattery", true, true)
addbehaviour(objects[287], "npc", 29, false, true)
addbehaviour(objects[287], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[287], "meshcollider", false)

objects[288] = creategameobject("Small Box", true, -7.36, 23.4, -84.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[288], "meshcollider", true)
addbehaviour(objects[288], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[289] = creategameobject("Small Box", false, -7.46, 23.4, -69.19, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[289], "meshcollider", true)
addbehaviour(objects[289], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[289], "npc", 50, true, false)

objects[290] = creategameobject("Wall (11)", true, -58.68, 29.7666, -37.98, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[291] = creategameobject("Wall (88)", true, -50.34, 35.09, -92.28, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[291], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[291], "meshcollider", true)

objects[292] = creategameobject("Wall (36)", true, -86.7, 28.96, -64.55, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[293] = creategameobject("Wall (55)", true, -18.99, 23.54, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[293], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[293], "meshcollider", true)

objects[294] = creategameobject("Double_Door_Wall_Tri (6)", true, -46.23, 35.17, -79.3, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "wall", true, true)
addbehaviour(objects[294], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[294], "meshcollider", false)

objects[295] = creategameobject("Corridor_Reinfocement_Tri (3)", true, -82.98, 25.97, -81.32, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[295], "meshcollider", false)
addbehaviour(objects[295], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[296] = creategameobject("small_box (22)", true, -29.97, 23.4, -76.3, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[296], "meshcollider", true)
addbehaviour(objects[296], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[297] = creategameobject("Small Box", true, -13.46, 23.4, -78.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[297], "meshcollider", true)
addbehaviour(objects[297], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[298] = creategameobject("battery_Tri (2)", false, -33.84, 36.02, -96.2, 0, 0, 0, 1, 1, 1, 1, "battery.obj", "blackbattery", true, true)
addbehaviour(objects[298], "npc", 26, true, false)
addbehaviour(objects[298], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[298], "meshcollider", true)
addbehaviour(objects[298], "audiosource", "sparks.wav", true, true, true, false, 1, 0.5, false)

objects[299] = creategameobject("Wall (91)", true, -50.34, 35.09, -78.36, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[299], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[299], "meshcollider", true)

objects[300] = creategameobject("Drawer (18)", true, -58.423, 27.92, -69.37, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true, true)

objects[301] = creategameobject("capsule (5)", true, -83.82, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true, true)
addbehaviour(objects[301], "meshcollider", true)
addbehaviour(objects[301], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[302] = creategameobject("small_box (56)", true, -29.76, 23.4, -89.96, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[302], "meshcollider", true)
addbehaviour(objects[302], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[303] = creategameobject("Drawer (9)", true, -89.76, 28.27, -48.00976, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true, true)

objects[304] = creategameobject("FingerPrintScanner (4)", true, -81.923, 24.84, -116.394, 0, -1, 0, 0, 1, 1, 1, "fingerprintscanner.obj", "fingerprintscanner", true, true)
addbehaviour(objects[304], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[304], "meshcollider", true)
addbehaviour(objects[304], "npc", 70, true, false)

objects[305] = creategameobject("Wall (54)", true, -50.34, 23.54, -64.19, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[305], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[305], "meshcollider", true)

objects[306] = creategameobject("Wall (13)", true, -58.68, 29.7666, -23.67, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[306], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[306], "meshcollider", true)

objects[307] = creategameobject("big_pipes_Tri", true, -89.01, 29.87, -45.37, 0, 0, 0, 1, 1, 1, 1, "bigpipe.obj", "bigpipe", true, true)

objects[308] = creategameobject("small_box (8)", true, -34.79, 23.4, -65.48, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[308], "meshcollider", true)
addbehaviour(objects[308], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[309] = creategameobject("WallDoubleSided", true, -69.91, 22.856, -52.61, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true, true)
addbehaviour(objects[309], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[309], "meshcollider", true)

objects[310] = creategameobject("small_box (25)", true, -29.97, 23.4, -73.3, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[310], "meshcollider", true)
addbehaviour(objects[310], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[311] = creategameobject("DoubleSidedWall (13)", true, -41.29, 35.1, -89.2, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true, true)
addbehaviour(objects[311], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[311], "meshcollider", true)

objects[312] = creategameobject("FingerPrintScanner (5)", true, -0.53, 25, -92.61, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "fingerprintscanner.obj", "fingerprintscanner", true, true)
addbehaviour(objects[312], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[312], "meshcollider", true)
addbehaviour(objects[312], "npc", 27, true, false)

objects[313] = creategameobject("DoubleSidedWall (5)", true, -61.41, 29, -69.05, 0, -1, 0, 0, 1, 1, 1, "Walls/walldoublesided.obj", "wall", false, true)

objects[314] = creategameobject("Small Box", true, -7.46, 23.4, -72.19, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[314], "meshcollider", true)
addbehaviour(objects[314], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[315] = creategameobject("Corridor_Straight_Tri (2)", true, -74.048, 25.865, -93.756, 0, 0, 0, 1, 1, 1, 1, "corridors/straightcorridor.obj", "straightcorridor", false, true)
addbehaviour(objects[315], "meshcollider", false)
addbehaviour(objects[315], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[316] = creategameobject("small_box (18)", true, -39.49, 23.4, -76.54, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[316], "meshcollider", true)
addbehaviour(objects[316], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[317] = creategameobject("Wall (85)", true, -50.34, 29.2, -85.26, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)
addbehaviour(objects[317], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[317], "meshcollider", true)

objects[318] = creategameobject("Corridor_Straight_Tri (6)", true, -46.946, 25.88, -103.055, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/straightcorridor.obj", "straightcorridor", false, true)
addbehaviour(objects[318], "meshcollider", false)
addbehaviour(objects[318], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[319] = creategameobject("Wall (57)", true, -26.2, 23.54, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[319], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[319], "meshcollider", true)

objects[320] = creategameobject("Corridor_Reinfocement_Tri (2)", true, -77.14, 25.97, -75.65, 0, 0, 0, 1, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[320], "meshcollider", false)
addbehaviour(objects[320], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[321] = creategameobject("Top_Wall_Tri", true, -94.48, 26.69, -108.95, 0, 0, 0, 1, 1, 1, 1, "cockpit/topwall.obj", "topwall", true, true)
addbehaviour(objects[321], "meshcollider", false)
addbehaviour(objects[321], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[322] = creategameobject("pasted__pCube85_group (12)", true, -84.08, 16.307, -111.83, 0, -0.7071068, 0, 0.7071068, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[322], "meshcollider", true)
addbehaviour(objects[322], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[323] = creategameobject("polySurface12", false, -47.23, 24.24, -85.37, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "adielevatorpad.obj", "adielevatorinside", true, true)
addbehaviour(objects[323], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[323], "meshcollider", false)
addbehaviour(objects[323], "elevator", -47.23, 35.92, -85.37, 3.5)
addbehaviour(objects[323], "npc", 13, true, false)
objects[324] = creategameobject("elevator_stuffontop", false, 0.25, 0.03999901, -0.04000089, 0, 0, 0, 1, 1, 1, 1, "adielevatorjunk.obj", "adielevatorinside", true, true)
addchild(objects[323], objects[324], false)

objects[325] = creategameobject("Wall (124)", true, -11.99, 29.2, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[325], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[325], "meshcollider", true)

objects[326] = creategameobject("Wall (24)", true, -89.52, 22.92918, -46.12, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)
addbehaviour(objects[326], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[326], "meshcollider", true)

objects[327] = creategameobject("rails (2)", true, -102.478, 23.227, -115.588, 0, -0.5877852, 0, 0.809017, 1, 1, 1, "rails.obj", "rails", true, true)
addbehaviour(objects[327], "meshcollider", true)
addbehaviour(objects[327], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[328] = creategameobject("Small Box", false, -13.46, 23.4, -81.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[328], "meshcollider", true)
addbehaviour(objects[328], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[328], "npc", 50, true, false)

objects[329] = creategameobject("Wall (76)", true, -26.2, 29.2, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[329], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[329], "meshcollider", true)

objects[330] = creategameobject("Wall (40)", true, -70.06, 28.96, -59.66, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)
addbehaviour(objects[330], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[330], "meshcollider", true)

objects[331] = creategameobject("Small Box", true, -10.46, 23.4, -69.19, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[331], "meshcollider", true)
addbehaviour(objects[331], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[332] = creategameobject("crate (9)", true, -84.09, 26.47, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[332], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[332], "meshcollider", true)

objects[333] = creategameobject("small_box (101)", true, -41.78, 23.4, -89.96, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[333], "meshcollider", true)
addbehaviour(objects[333], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[334] = creategameobject("Small Box", false, -7.46, 23.4, -81.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[334], "meshcollider", true)
addbehaviour(objects[334], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[334], "npc", 50, true, false)

objects[335] = creategameobject("capsule (1)", true, -64.86, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true, true)
addbehaviour(objects[335], "meshcollider", true)
addbehaviour(objects[335], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[336] = creategameobject("Corridor_Reinfocement_Tri (4)", true, -83.001, 25.97, -87.939, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[336], "meshcollider", false)
addbehaviour(objects[336], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[337] = creategameobject("capsule (2)", true, -74.39, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true, true)
addbehaviour(objects[337], "meshcollider", true)
addbehaviour(objects[337], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[338] = creategameobject("Wall (22)", true, -89.52, 22.92918, -60.15, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[338], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[338], "meshcollider", true)

objects[339] = creategameobject("Wall (111)", true, -50.34, 23.54, -99.18, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)
addbehaviour(objects[339], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[339], "meshcollider", true)

objects[340] = creategameobject("Wall", true, -77.11, 22.9, -25.69, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[340], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[340], "meshcollider", true)

objects[341] = creategameobject("Wall (32)", true, -89.44, 29.95, -46.18, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[342] = creategameobject("Small Box", true, -10.46, 23.4, -81.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[342], "meshcollider", true)
addbehaviour(objects[342], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[343] = creategameobject("small_box (19)", true, -36.49, 23.4, -76.54, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[343], "meshcollider", true)
addbehaviour(objects[343], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[344] = creategameobject("Small Box", false, -44.98, 27.16, -54.61, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[344], "meshcollider", true)
addbehaviour(objects[344], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[344], "npc", 50, true, false)

objects[345] = creategameobject("Corridor_Reinfocement_Tri (11)", true, -58.42, 25.975, -99.577, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[345], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[345], "meshcollider", false)

objects[346] = creategameobject("Wall (10)", true, -58.68, 29.7666, -45, -0.1530254, 0.6903501, 0.1530254, 0.6903501, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[347] = creategameobject("small_box (34)", true, -29.97, 23.4, -70.3, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[347], "meshcollider", true)
addbehaviour(objects[347], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[347], "npc", 901, false, true)

objects[348] = creategameobject("small_box (42)", true, -41.83, 23.4, -83.71, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[348], "meshcollider", true)
addbehaviour(objects[348], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[349] = creategameobject("Drawer (6)", true, -89.76, 28.27, -28.84269, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true, true)

objects[350] = creategameobject("Wall (123)", true, 2.13, 23.54, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[350], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[350], "meshcollider", true)

objects[351] = creategameobject("Drawer (4)", true, -58.423, 27.92, -32.66442, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true, true)

objects[352] = creategameobject("Wall (27)", true, -89.52, 22.92918, -25.04, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[352], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[352], "meshcollider", true)

objects[353] = creategameobject("Wall (6)", true, -70.09, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[354] = creategameobject("Point light (1)", false, -31.6, 38.75, -76.2, 0, 0, 0, 1, 0.5695158, 0.5695158, 0.5695158, "", "", false, false)
addbehaviour(objects[354], "light", "point", 1, 1, 1, 1, 4, 30)

objects[355] = creategameobject("Small Box", false, -48.48, 23.4, -57.66, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[355], "meshcollider", true)
addbehaviour(objects[355], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[355], "npc", 50, true, false)

objects[356] = creategameobject("Small Box", false, -10.46, 23.4, -78.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[356], "meshcollider", true)
addbehaviour(objects[356], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[356], "npc", 50, true, false)

objects[357] = creategameobject("Wall (117)", true, -4.81, 35.09, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[357], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[357], "meshcollider", true)

objects[358] = creategameobject("Wall (25)", true, -89.52, 22.92918, -39.13, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[358], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[358], "meshcollider", true)

objects[359] = creategameobject("small_box (51)", true, -34.56, 23.4, -86.71, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[359], "meshcollider", true)
addbehaviour(objects[359], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[360] = creategameobject("tv_set:polySurface5", true, -73.99264, 31.72438, -40.98919, 0, 0, 0, 1, 0.5695158, 0.5695158, 0.5695158, "Tv's.obj", "tv's", true, true)

objects[361] = creategameobject("Corridor_Reinfocement_Tri (1)", true, -70.518, 25.975, -75.655, 0, 0, 0, 1, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[361], "meshcollider", false)
addbehaviour(objects[361], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[362] = creategameobject("Wall (77)", true, -19.11, 29.2, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[362], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[362], "meshcollider", true)

objects[363] = creategameobject("Wall (109)", true, -0.3, 35.09, -59.86, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[363], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[363], "meshcollider", true)

objects[364] = creategameobject("Small Box", false, -16.46, 23.4, -69.19, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[364], "meshcollider", true)
addbehaviour(objects[364], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[364], "npc", 50, true, false)

objects[365] = creategameobject("small_box (5)", true, -39.49, 23.4, -63.33, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[365], "meshcollider", true)
addbehaviour(objects[365], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[366] = creategameobject("Wall (110)", true, -50.34, 23.54, -92.28, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[366], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[366], "meshcollider", true)

objects[367] = creategameobject("pasted__pCube85_group (2)", true, -107.038, 16.307, -118.998, 0, -0.7071068, 0, 0.7071068, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[367], "meshcollider", true)
addbehaviour(objects[367], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[368] = creategameobject("Wall (67)", true, -0.3, 23.54, -59.86, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[368], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[368], "meshcollider", true)

objects[369] = creategameobject("pasted__pCube85_group (11)", true, -105.29, 16.307, -111.83, 0, -0.7071068, 0, 0.7071068, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[369], "meshcollider", true)
addbehaviour(objects[369], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[370] = creategameobject("Corridor_Reinfocement_Tri (13)", true, -52.763, 25.985, -112.008, 0, -1, 0, 0, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[370], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[370], "meshcollider", false)

objects[373] = creategameobject("pasted__pCube85_group (8)", true, -101.668, 16.307, -113.008, 0, -0.7071068, 0, 0.7071068, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[373], "meshcollider", true)
addbehaviour(objects[373], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[374] = creategameobject("Windows_Tri", true, -94.738, 24.937, -131.858, 0, 0, 0, 1, 1, 1, 1, "cockpit/windows.obj", "windows", false, false)
addbehaviour(objects[374], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[374], "meshcollider", false)

objects[375] = creategameobject("Corridor_Straight_Tri (4)", true, -67.43, 25.87, -93.76, 0, 0, 0, 1, 1, 1, 1, "corridors/straightcorridor.obj", "straightcorridor", false, true)
addbehaviour(objects[375], "meshcollider", false)
addbehaviour(objects[375], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[376] = creategameobject("FingerPrintScanner (7)", true, -50.116, 36.517, -82.828, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "fingerprintscanner.obj", "fingerprintscanner", true, true)
addbehaviour(objects[376], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[376], "meshcollider", true)
addbehaviour(objects[376], "npc", 101, true, false)

objects[377] = creategameobject("Elevator_Cockpit_Beams_tri", true, -109.6, 21.22, -114.24, 0, -1, 0, 0, 1, 1, 1, "elevatorbeam.obj", "elevatorbeam", true, true)

objects[378] = creategameobject("Wall (118)", true, 2.28, 29.2, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[378], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[378], "meshcollider", true)

objects[379] = creategameobject("rails", true, -84.688, 23.227, -118.368, 0, 0, 0, 1, 1, 1, 1, "rails.obj", "rails", true, true)
addbehaviour(objects[379], "meshcollider", true)
addbehaviour(objects[379], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[380] = creategameobject("DoubleSidedWall (11)", true, -41.29, 35.1, -75.95, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true, true)
addbehaviour(objects[380], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[380], "meshcollider", true)

objects[381] = creategameobject("Wall (96)", true, -33.11, 35.09, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[381], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[381], "meshcollider", true)

objects[382] = creategameobject("Corridor_Reinfocement_Tri (10)", true, -64.092, 25.975, -93.76, 0, 0, 0, 1, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[382], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[382], "meshcollider", false)

objects[383] = creategameobject("Small Box", false, -16.46, 23.4, -81.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[383], "meshcollider", true)
addbehaviour(objects[383], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[383], "npc", 50, true, false)

objects[384] = creategameobject("DoubleSidedWall (9)", true, -41.29, 35.1, -62.26, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true, true)
addbehaviour(objects[384], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[384], "meshcollider", true)

objects[385] = creategameobject("Wall (89)", true, -50.34, 35.09, -99.18, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)
addbehaviour(objects[385], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[385], "meshcollider", true)

objects[386] = creategameobject("Keycard", false, -80.198, 24.54, -53.155, 0.3524841, -0.3524841, -0.6129886, 0.6129886, 0.2039833, 0.2071294, 0.2071294, "KeycardFrame.obj", "KeycardFrame", true, true)
addbehaviour(objects[386], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[386], "meshcollider", true)
addbehaviour(objects[386], "npc", 25, true, false)
objects[387] = creategameobject("glass", false, 0, 0, 0, 0, 0, -2.235174E-08, 1, 1, 1, 1, "KeycardGlass.obj", "KeycardGlass", true, true)
addchild(objects[386], objects[387], false)

objects[388] = creategameobject("Drawer (2)", true, -58.423, 27.92, -48.00976, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true, true)

objects[389] = creategameobject("Wall (80)", true, -40.2, 29.2, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[389], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[389], "meshcollider", true)

objects[390] = creategameobject("Keypad", true, -69.754, 25.161, -48.967, 0, -1, 0, 0, 1, 1, 1, "keypad.obj", "keypad", true, true)
addbehaviour(objects[390], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[390], "boxcollider", 0.5, 0.5, 0.5)
addbehaviour(objects[390], "npc", 2, false, false)
objects[391] = creategameobject("KeypadSlider", true, -0.22, 0, 0.0125, 0, 0, 0, 1, 1, 1, 1, "keypadslider.obj", "keypadslider", false, true)
addchild(objects[390], objects[391], false)

objects[393] = creategameobject("capsule (3)", true, -71.38, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true, true)
addbehaviour(objects[393], "meshcollider", true)
addbehaviour(objects[393], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[394] = creategameobject("elevator_outside (1)", true, -47.23, 24.32, -85.34, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "adielevatorbottom.obj", "adielevatoroutside", true, true)
addbehaviour(objects[394], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[394], "meshcollider", false)

objects[395] = creategameobject("Plane (6)", true, -23.39, 23.5, -67.01, 0, 0, 0, 1, 30, 1, 32.60102, "plane.obj", "ground", false, false)
addbehaviour(objects[395], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[395], "meshcollider", true)

objects[396] = creategameobject("table", true, -79.11, 22.94, -53.33, 0, 0, 0, 1, 0.4131236, 0.4131236, 0.4131236, "table.obj", "table", true, true)
addbehaviour(objects[396], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[396], "meshcollider", true)

objects[397] = creategameobject("Wall (39)", true, -70.06, 28.96, -52.69, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)
addbehaviour(objects[397], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[397], "meshcollider", true)

objects[398] = creategameobject("Generator", true, -85.7, 22.901, -41.491, 0, -0.7071068, 0, -0.7071068, 0.8, 0.8, 0.8, "generator.obj", "generator", true, true)
addbehaviour(objects[398], "meshcollider", true)
addbehaviour(objects[398], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[398], "npc", 98, false, false)

objects[399] = creategameobject("crate (11)", true, -75.97, 22.77, -41.39, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[399], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[399], "meshcollider", true)

objects[400] = creategameobject("Small Box", true, -16.36, 23.4, -84.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[400], "meshcollider", true)
addbehaviour(objects[400], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[401] = creategameobject("Small Box", true, -13.46, 23.4, -69.19, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[401], "meshcollider", true)
addbehaviour(objects[401], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[402] = creategameobject("Wall (17)", true, -40.2, 23.54, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[402], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[402], "meshcollider", true)

objects[403] = creategameobject("Wall (23)", true, -89.52, 22.92918, -53.16, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)
addbehaviour(objects[403], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[403], "meshcollider", true)

objects[404] = creategameobject("Wall (113)", true, -11.84, 29.2, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[404], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[404], "meshcollider", true)

objects[405] = creategameobject("capsule", true, -61.85, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true, true)
addbehaviour(objects[405], "meshcollider", true)
addbehaviour(objects[405], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[406] = creategameobject("Small Box", true, -10.36, 23.4, -84.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[406], "meshcollider", true)
addbehaviour(objects[406], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[407] = creategameobject("FingerPrintScanner (8)", true, -50.118, 24.98, -80.77, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "fingerprintscanner.obj", "fingerprintscanner", true, true)
addbehaviour(objects[407], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[407], "meshcollider", true)
addbehaviour(objects[407], "npc", 100, true, false)

objects[408] = creategameobject("Wall (42)", true, -69.25, 28.97, -66.83, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)

objects[409] = creategameobject("Drawer (12)", true, -89.76, 28.27, -51.85096, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true, true)

objects[410] = creategameobject("small_box (46)", true, -26.76, 23.4, -83.71, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[410], "meshcollider", true)
addbehaviour(objects[410], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[411] = creategameobject("CeilingLamp_Tri", true, -79.39, 32.82, -56.52, 0, 0, 0, 1, 1, 1, 1, "ceilinglamp.obj", "ceilinglamp", true, true)

objects[412] = creategameobject("Wall (97)", true, -26.08, 35.09, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[412], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[412], "meshcollider", true)

objects[413] = creategameobject("Wall (14)", true, -56.38, 29.11, -25.61, -0.07009556, 0, 0, 0.9975403, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[414] = creategameobject("PostProcessors", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "", true, true)
addbehaviour(objects[414], "fog")
addbehaviour(objects[414], "vignette")
addbehaviour(objects[414], "contrast", 0.08)

objects[415] = creategameobject("Small Box", false, -13.46, 23.4, -72.19, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[415], "meshcollider", true)
addbehaviour(objects[415], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[415], "npc", 50, true, false)

objects[416] = creategameobject("table (1)", true, -94.74, 16.82, -143.38, 0, 0, 0, 1, 0.42, 0.42, 0.42, "table.obj", "table", true, true)
addbehaviour(objects[416], "meshcollider", true)
addbehaviour(objects[416], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[417] = creategameobject("wallnopillar_Walls", true, -57.807, 26.012, -30.943, 0, -1, 0, 0, 1, 1, 1, "Walls/WallNoPillar.obj", "Wall", true, true)
addbehaviour(objects[417], "meshcollider", false)
addbehaviour(objects[417], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[418] = creategameobject("Small Box", false, -16.46, 23.4, -78.26, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[418], "meshcollider", true)
addbehaviour(objects[418], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[418], "npc", 50, true, false)

objects[419] = creategameobject("small_box (6)", true, -41.28, 23.4, -65.48, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[419], "meshcollider", true)
addbehaviour(objects[419], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[420] = creategameobject("small_box (52)", true, -36.81, 23.4, -85.64, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[420], "meshcollider", true)
addbehaviour(objects[420], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[421] = creategameobject("Wall (16)", true, -47.23, 23.54, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[421], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[421], "meshcollider", true)

objects[422] = creategameobject("Corridor_Reinfocement_Tri (8)", true, -77.329, 25.97, -93.756, 0, 0, 0, 1, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[422], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[422], "meshcollider", false)

objects[423] = creategameobject("Wall (127)", true, -4.96, 23.54, -98.38, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[423], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[423], "meshcollider", true)

objects[424] = creategameobject("Small Box", true, -16.46, 23.4, -72.19, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[424], "meshcollider", true)
addbehaviour(objects[424], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[425] = creategameobject("Drawer (17)", true, -58.423, 27.92, -61.5, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true, true)

objects[426] = creategameobject("Corridor_Reinfocement_Tri (9)", true, -70.71, 25.97, -93.76, 0, 0, 0, 1, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[426], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[426], "meshcollider", false)

objects[427] = creategameobject("pasted__pCube85_group (6)", true, -86.188, 16.307, -117.958, 0, -0.7071068, 0, 0.7071068, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[427], "meshcollider", true)
addbehaviour(objects[427], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[428] = creategameobject("Wall (26)", true, -89.52, 22.92918, -32.04, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[428], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[428], "meshcollider", true)

objects[429] = creategameobject("capsule (4)", true, -80.81, 22.9, -31.31, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true, true)
addbehaviour(objects[429], "meshcollider", true)
addbehaviour(objects[429], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[430] = creategameobject("Floor_Grate_Tri", true, -94.83, 15.05, -133.24, 0, 0, 0, 1, 1, 1, 1, "cockpit/floorgrate.obj", "floorgrate", true, true)
addbehaviour(objects[430], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[430], "meshcollider", true)

objects[431] = creategameobject("BrokenCableBroken", true, -63.1, 22.9, -45.743, 0, 0, 0, 1, 1, 1, 1, "brokencablebroken.obj", "brokencable", true, true)
addbehaviour(objects[431], "npc", 99, false, true)

objects[432] = creategameobject("CeilingLamp_Tri (1)", true, -61.17, 34.31, -35.95, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "ceilinglamp.obj", "ceilinglamp", true, true)

objects[433] = creategameobject("Wall (33)", true, -89.44, 29.95, -53.16, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[434] = creategameobject("recharger_Tri", true, -48.43, 25.98, -77.96, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "batteryslot.obj", "greenbattery", true, true)
addbehaviour(objects[434], "npc", 14, false, true)
addbehaviour(objects[434], "meshcollider", false)
addbehaviour(objects[434], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[435] = creategameobject("Wall (78)", true, -18.86, 29.2, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[435], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[435], "meshcollider", true)

objects[436] = creategameobject("table (2)", true, -89.32, 16.69, -134.14, 0, -0.7071068, 0, 0.7071068, 0.42, 0.42, 0.42, "table.obj", "table", true, true)
addbehaviour(objects[436], "meshcollider", true)
addbehaviour(objects[436], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[437] = creategameobject("Wall (98)", true, -18.99, 35.09, -52.25, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[437], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[437], "meshcollider", true)

objects[438] = creategameobject("rails (5)", true, -99.758, 23.227, -111.748, 0, -0.3173046, 0, 0.9483237, 1, 1, 1, "rails.obj", "rails", true, true)
addbehaviour(objects[438], "meshcollider", true)
addbehaviour(objects[438], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[439] = creategameobject("Wall (46)", true, -50.32, 23.54, -85.26, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)
addbehaviour(objects[439], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[439], "meshcollider", true)

objects[440] = creategameobject("Wall (72)", true, -0.3, 29.2, -80.96, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[440], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[440], "meshcollider", true)

objects[441] = creategameobject("Small Box", false, -44.12, 25.27, -55.41, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[441], "meshcollider", true)
addbehaviour(objects[441], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[441], "npc", 50, true, false)

objects[442] = creategameobject("small_box (29)", true, -41.28, 23.4, -74.55, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[442], "meshcollider", true)
addbehaviour(objects[442], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[443] = creategameobject("BrokenCableTrigger", true, -83.281, 23.136, -34.943, 0.689055, -0.1587554, 0.1587553, 0.689055, 0.5409834, 0.8087289, 0.5409834, "", "", true, true)
addbehaviour(objects[443], "capsulecollider", 0.5, 2)
addbehaviour(objects[443], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[443], "npc", 0, true, false)

objects[444] = creategameobject("Wall (3)", true, -84.018, 22.9, -25.694, 0, 0, 0, 1, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[444], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[444], "meshcollider", true)

objects[445] = creategameobject("Wall (21)", true, -82.35, 22.9, -64.3, 0, -1, 0, 0, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[445], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[445], "meshcollider", true)

objects[446] = creategameobject("Elevator_Cockpit_Platform_tri (1)", false, -80.2, 16.59, -114.27, 0, 0, 0, 1, 1, 1, 1, "elevator.obj", "elevator", true, true)
addbehaviour(objects[446], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[446], "meshcollider", true)
addbehaviour(objects[446], "elevator", -80.2, 23.514, -114.27, 3.5)
addbehaviour(objects[446], "npc", 67, false, false)
objects[447] = creategameobject("Elevator_Cockpit_Gears_tri (1)", false, 1.199997, -0.441, -0.04000092, 0, 0, 0, 1, 1, 1, 1, "elevatorgears.obj", "elevatorgears", true, true)
addbehaviour(objects[447], "rotationanimation", 0, 0, -100)
addchild(objects[446], objects[447], false)

objects[448] = creategameobject("FingerPrintScanner (6)", true, -0.497, 36.38, -92.719, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "fingerprintscanner.obj", "fingerprintscanner", true, true)
addbehaviour(objects[448], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[448], "meshcollider", true)
addbehaviour(objects[448], "npc", 102, true, false)

objects[449] = creategameobject("recharger_Tri (1)", true, -11.61, 25.93, -96.89, 0, 0, 0, 1, 1, 1, 1, "batteryslot.obj", "redbattery", true, true)
addbehaviour(objects[449], "npc", 22, false, true)
addbehaviour(objects[449], "meshcollider", false)
addbehaviour(objects[449], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[450] = creategameobject("Corridor_Straight_Tri (1)", true, -82.98, 25.865, -84.658, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/straightcorridor.obj", "straightcorridor", false, true)
addbehaviour(objects[450], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[450], "meshcollider", false)

objects[451] = creategameobject("Corridor_Reinfocement_Tri (15)", true, -46.946, 25.985, -106.336, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[451], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[451], "meshcollider", false)

objects[452] = creategameobject("small_box (4)", true, -36.49, 23.4, -63.33, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[452], "meshcollider", true)
addbehaviour(objects[452], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[453] = creategameobject("Wall (108)", true, -0.3, 35.09, -66.79, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[453], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[453], "meshcollider", true)

objects[454] = creategameobject("Small Box", false, -42.49, 23.4, -55.76, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[454], "meshcollider", true)
addbehaviour(objects[454], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[454], "npc", 50, true, false)

objects[455] = creategameobject("Small Box", false, -42.38, 23.4, -53.63, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[455], "meshcollider", true)
addbehaviour(objects[455], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[455], "npc", 50, true, false)

objects[456] = creategameobject("Corridor_Reinfocement_Tri", true, -64.77, 25.36, -70.23, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[456], "meshcollider", false)
addbehaviour(objects[456], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)

objects[457] = creategameobject("Wall (83)", true, -50.34, 29.2, -71.26, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[457], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[457], "meshcollider", true)

objects[458] = creategameobject("Directional Light", false, -94.68, 31.26, -164.48, 0.1736482, 0, 0, 0.9848078, 1, 1, 1, "", "", false, false)
addbehaviour(objects[458], "light", "directional", 1, 0.9568627, 0.8392157, 1, 0.3, 30)

objects[459] = creategameobject("Drawer (11)", true, -89.76, 28.27, -40.34682, 0, 0, 0, 1, 0.8074501, 0.80745, 0.80745, "drawer.obj", "drawer", true, true)

objects[460] = creategameobject("rails (3)", true, -86.848, 23.227, -115.588, 0, 0.5877852, 0, 0.809017, 1, 1, 1, "rails.obj", "rails", true, true)
addbehaviour(objects[460], "meshcollider", true)
addbehaviour(objects[460], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[461] = creategameobject("DoubleSidedWall (15)", true, -41.29, 35.1, -95.79, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true, true)
addbehaviour(objects[461], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[461], "meshcollider", true)

objects[462] = creategameobject("Canopy_Tri", true, -94.738, 24.937, -131.858, 0, 0, 0, 1, 1, 1, 1, "cockpit/canopy.obj", "canopy", true, false)
addbehaviour(objects[462], "rigidbody", 0, true, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[462], "meshcollider", false)

objects[463] = creategameobject("Wall (49)", true, -59.87, 22.9, -68.15, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/Wall.obj", "Wall", true, true)
addbehaviour(objects[463], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[463], "meshcollider", true)

objects[464] = creategameobject("table (4)", true, -69.48, 22.94, -36.23, 0, 0, 0, 1, 0.4131236, 0.4131236, 0.4131236, "table.obj", "table", true, true)
addbehaviour(objects[464], "meshcollider", true)
addbehaviour(objects[464], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[465] = creategameobject("small_box (55)", true, -34.56, 23.4, -89.96, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[465], "meshcollider", true)
addbehaviour(objects[465], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[466] = creategameobject("crate (5)", true, -71.64982, 26.47, -62.34, 0, -1, 0, 0, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[466], "meshcollider", true)
addbehaviour(objects[466], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[467] = creategameobject("Drawer (16)", true, -58.423, 27.92, -53.84, 0, 1, 0, 0, 0.8074467, 0.807447, 0.807447, "drawer.obj", "drawer", true, true)

objects[468] = creategameobject("Small Box", false, -48.61, 31.43, -54.61, 0, 0, 0, 1, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[468], "meshcollider", true)
addbehaviour(objects[468], "rigidbody", 1, false, false, false, false, false, false, false, 0.5, false)
addbehaviour(objects[468], "npc", 50, true, false)

objects[469] = creategameobject("pasted__pCube85_group", true, -69.04, 22.9, -51.19, 0, 0.05096556, 0, 0.9987004, 1.000837, 1, 1.000837, "pillar.obj", "pillar", true, true)
addbehaviour(objects[469], "meshcollider", true)
addbehaviour(objects[469], "rigidbody", 0, false, false, false, false, false, false, false, 0.5, false)

objects[470] = creategameobject("Spotlight", false, -79.698, 28.447, -53.078, 0.7071068, 0, 0, 0.7071068, 1, 1, 1, "", "", false, false)
addbehaviour(objects[470], "light", "spot", 0.5893166, 0.7232133, 0.7352941, 1, 0, 60)
addbehaviour(objects[470], "lightidentifier", 0)

