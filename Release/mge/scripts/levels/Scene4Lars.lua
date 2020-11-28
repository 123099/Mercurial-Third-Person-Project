objects = {}
objects[0] = creategameobject("DoorPrefab", false, -143.5, 22.85, -50.635, 0, 0, 0, 1, 1, 1, 0.5, "", "", true, true)
addbehaviour(objects[0], "npc", 4, false, true)
addbehaviour(objects[0], "door")
objects[1] = creategameobject("DoorLeft", false, 0.15, 0, 0, 0, 0, 0, 1, 1, 1, 1, "DoorLeft.obj", "Door", true, true)
addbehaviour(objects[1], "meshcollider", true)
addbehaviour(objects[1], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[1], "translationanimation")
addchild(objects[0], objects[1], false)
objects[2] = creategameobject("DoorRight", false, -0.15, 0, 0, 0, 0, 0, 1, 1, 1, 1, "DoorRight.obj", "Door", true, true)
addbehaviour(objects[2], "meshcollider", true)
addbehaviour(objects[2], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[2], "translationanimation")
addchild(objects[0], objects[2], false)

objects[3] = creategameobject("Elevator_Cockpit_Beams_tri (1)", true, -180.25, 28.21, -93.5, 0, 0, 0, 1, 1, 1, 1, "elevatorbeam.obj", "elevatorbeam", true, true)

objects[4] = creategameobject("recharger_Tri (4)", true, -195, 25.48, -91.7, 0, 0, 0, 1, 1, 1, 1, "batteryslot.obj", "redbattery", true, true)
addbehaviour(objects[4], "npc", 21, true, true)
addbehaviour(objects[4], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[4], "meshcollider", false)

objects[5] = creategameobject("the_thing_orb_tri", false, -145.1, 22.62, -75.8, 0, 0, 0, 1, 1, 1, 1, "roundthingorb.obj", "roundthing", true, true)
addbehaviour(objects[5], "rotationanimation", 0, 50, 0)
addbehaviour(objects[5], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[5], "meshcollider", true)

objects[6] = creategameobject("WallDoubleSided", true, -148.8, 22.777, -52.799, 0, 0.7071068, 0, 0.7071068, 1, 1, 1, "Walls/WallDoubleSided.obj", "Wall", true, true)
addbehaviour(objects[6], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[6], "meshcollider", true)

objects[7] = creategameobject("Player", false, -202.6, 27.27, -23.1, 0, 0, 0, 1, 1, 1, 1, "", "", true, true)
addbehaviour(objects[7], "player", 8)
addbehaviour(objects[7], "charactercontroller", 45, 0.3, 0.5, 2)
objects[8] = creategameobject("Camera", false, 0, 1.41, 0, 0, 0.5849578, 0, -0.8110638, 1, 1, 1, "", "", true, true)
addbehaviour(objects[8], "camera", 60, 0.3, 1000)
addbehaviour(objects[8], "audiolistener")
addchild(objects[7], objects[8], false)

objects[9] = creategameobject("Bottom_Tri", true, -197, 26, -27.5, 0, 0, 0, 1, 1, 1, 1, "cockpit/cockpitfloor.obj", "cockpitfloor", true, true)
addbehaviour(objects[9], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[9], "meshcollider", false)

objects[10] = creategameobject("crane_Tri", true, -228.29, 32.16, -74.5, 0, 0, 0, 1, 1, 1, 1, "cranesupport.obj", "crane", true, true)

objects[11] = creategameobject("Corridor_Reinfocement_Tri (6)", true, -196.7, 35, 2.3, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[11], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[11], "meshcollider", false)

objects[12] = creategameobject("control_panel (1)", true, -151.2, 24, -95.2, 0, -0.7071068, 0, -0.7071068, 1.2, 1.2, 1.2, "computer.obj", "computer", true, true)
addbehaviour(objects[12], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[12], "meshcollider", true)

objects[13] = creategameobject("Double_Door_Wall_Tri", true, -143.6, 22.75, -50.69, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "doorframe", true, true)
addbehaviour(objects[13], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[13], "meshcollider", false)

objects[14] = creategameobject("Spotlight", false, -82.4, 36, -106.4, 0.7071068, 0, 0, 0.7071068, 1, 1, 1, "", "", false, false)
addbehaviour(objects[14], "light", "spot", 1, 1, 1, 1, 1, 70)

objects[15] = creategameobject("the_thing", true, -145.5, 22.52, -75.8, 0, 0, 0, 1, 1, 1, 1, "roundthing.obj", "roundthing", true, true)
addbehaviour(objects[15], "meshcollider", true)
addbehaviour(objects[15], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[16] = creategameobject("elevator_outside", true, -170.6, 24.32, -95.55, 0, 0, 0, 1, 1, 1, 1, "adielevatorbottom.obj", "adielevatoroutside", true, true)
addbehaviour(objects[16], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[16], "meshcollider", false)

objects[17] = creategameobject("roof_cables (1)", true, -202.3, 38.6, -22.1, 0, -1, 0, 0, 1, 1, 1, "roofcable.obj", "roofcable", true, true)

objects[18] = creategameobject("roof_cables", true, -191.7, 38.6, -22.1, 0, 0, 0, 1, 1, 1, 1, "roofcable.obj", "roofcable", true, true)

objects[19] = creategameobject("Corridor_Y_Turn_Tri", true, -192.8, 26, -77.8, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "corridors/ycorridor.obj", "ycorridor", false, true)
addbehaviour(objects[19], "meshcollider", false)
addbehaviour(objects[19], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)

objects[20] = creategameobject("cockpit_curved_wall_bottom_tri", true, -197.3, 25, -1.9, 0, 0, 0, 1, 1, 1, 1, "cockpit/bottomwall.obj", "bottomwall", true, true)
addbehaviour(objects[20], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[20], "meshcollider", false)

objects[21] = creategameobject("Elevator_Cockpit_Gears_tri (1)", false, -179.55, 23.35, -93.5, 0, 0, 0, 1, 1, 1, 1, "elevatorgears.obj", "elevatorgears", true, true)
addbehaviour(objects[21], "rotationanimation", 0, 0, 15)

objects[22] = creategameobject("Plane", true, -186, 22.94, -50.3, 0, 0, 0, 1, 50, 1, 50, "plane.obj", "ground", false, false)
addbehaviour(objects[22], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[22], "meshcollider", true)

objects[23] = creategameobject("polySurface12", false, -170.6, 24.27, -95.58, 0, 0, 0, 1, 1, 1, 1, "adielevatorpad.obj", "adielevatorinside", true, true)
addbehaviour(objects[23], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[23], "meshcollider", false)
addbehaviour(objects[23], "elevator", -6.09, 35.79, -95.58, 3.5)
addbehaviour(objects[23], "npc", 20, true, false)
objects[24] = creategameobject("elevator_stuffontop", false, 0.25, 0.03999901, -0.04000092, 0, 0, 0, 1, 1, 1, 1, "adielevatorjunk.obj", "adielevatorinside", true, true)
addchild(objects[23], objects[24], false)

objects[25] = creategameobject("GameObject", false, -6.66, 33.03, -80, 0, 0, 0, 1, 1, 1, 1, "", "", false, false)
addbehaviour(objects[25], "elevator", -6.66, 26.38, -80, 2)
addbehaviour(objects[25], "npc", 19, true, false)
objects[26] = creategameobject("crane_bottom", false, -221.69, -7.66, 5.1, 0, 0, 0, 1, 1, 1, 1, "cranebottom.obj", "crane", true, true)
addchild(objects[25], objects[26], false)
objects[27] = creategameobject("crane_top", false, -221.69, -4.21, 5.1, 0, 0, 0, 1, 1, 1, 1, "cranetop.obj", "crane", true, true)
addchild(objects[25], objects[27], false)

objects[28] = creategameobject("crate (3)", true, -164, 22.77, -16.4, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[28], "meshcollider", true)
addbehaviour(objects[28], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[29] = creategameobject("Corridor_L_Turn_Quad (1)", true, -192.3, 26, -60.4, 0, -1, 0, 0, 1, 1, 1, "corridors/leftcorridor.obj", "leftcorridor", false, true)
addbehaviour(objects[29], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[29], "meshcollider", false)

objects[30] = creategameobject("pasted__pCube85_group", true, -160.4, 22.9, -29.7, 0, -0.4153649, 0, 0.9096549, 1.01999, 1, 1.01999, "pillar.obj", "pillar", true, true)
addbehaviour(objects[30], "meshcollider", true)
addbehaviour(objects[30], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[30], "npc", 71, true, true)

objects[31] = creategameobject("Small Box", false, -161.9, 23.21, -81.39, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallboxpickup", true, true)
addbehaviour(objects[31], "npc", 50, true, false)
addbehaviour(objects[31], "meshcollider", true)
addbehaviour(objects[31], "rigidbody", 1, false, false, false, false, false, false, false, 0.5)

objects[32] = creategameobject("Corridor_Reinfocement_Tri (3)", true, -192.7, 26.1, -65.8, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[32], "meshcollider", false)
addbehaviour(objects[32], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)

objects[33] = creategameobject("capsule (5)", true, -170.3, 22.9, -20.2, 0, -1, 0, 0, 2.043339, 2.043339, 2.043339, "capsule.obj", "capsule", true, true)
addbehaviour(objects[33], "meshcollider", true)
addbehaviour(objects[33], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[34] = creategameobject("WallDoubleSided", true, -69.91, 22.856, -52.61, 0, -0.7071068, 0, -0.7071068, 1, 1, 1, "Walls/walldoublesided.obj", "wall", true, true)
addbehaviour(objects[34], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[34], "meshcollider", true)

objects[35] = creategameobject("Top_Wall_Tri", true, -196.7, 35.7, -7.3, 0, 0, 0, 1, 1, 1, 1, "cockpit/topwall.obj", "topwall", true, true)
addbehaviour(objects[35], "meshcollider", false)
addbehaviour(objects[35], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)

objects[36] = creategameobject("Corridor_Reinfocement_Tri (4)", true, -192.8, 26.1, -72.4, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/reinforcement.obj", "reinforcement", false, true)
addbehaviour(objects[36], "meshcollider", false)
addbehaviour(objects[36], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)

objects[37] = creategameobject("tv_set:polySurface5", true, -160.4, 31.72438, -29.9, 0, 0, 0, 1, 0.5695158, 0.5695158, 0.5695158, "Tv's.obj", "tv's", true, true)
addbehaviour(objects[37], "tv")
objects[38] = creategameobject("Camera", false, 3.99, 0, 5.18, -2.66098E-08, -0.7933534, -0.6087614, -3.467858E-08, 1, 1, 1, "", "", false, false)
addbehaviour(objects[38], "camera", 60, 0.3, 1000)
addchild(objects[37], objects[38], false)

objects[39] = creategameobject("Tablet (1)", false, -144.91, 24.439, -10.27, 0, -0.3007058, 0, 0.953717, 0.18, 0.18, 0.18, "tablet.obj", "tablet", true, true)
addbehaviour(objects[39], "npc", 12, true, false)
addbehaviour(objects[39], "rigidbody", 1, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[39], "meshcollider", true)
objects[40] = creategameobject("TabletScreen", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "tabletscreen.obj", "tabletscreen", false, false)
addchild(objects[39], objects[40], false)

objects[41] = creategameobject("Windows_Tri", true, -197, 34, -30.2, 0, 0, 0, 1, 1, 1, 1, "cockpit/windows.obj", "windows", false, false)
addbehaviour(objects[41], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[41], "meshcollider", false)

objects[42] = creategameobject("Keycard", false, -147.7, 24.54, -10.59, 0.3524841, -0.3524841, -0.6129886, 0.6129886, 0.2039833, 0.2071294, 0.2071294, "KeycardFrame.obj", "KeycardFrame", true, true)
addbehaviour(objects[42], "rigidbody", 1, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[42], "meshcollider", true)
addbehaviour(objects[42], "npc", 25, true, false)
objects[43] = creategameobject("glass", false, 0, 0, 0, 0, 0, -2.235174E-08, 1, 1, 1, 1, "KeycardGlass.obj", "KeycardGlass", true, true)
addchild(objects[42], objects[43], false)

objects[44] = creategameobject("Keypad", true, -69.754, 25.161, -48.967, 0, -1, 0, 0, 1, 1, 1, "keypad.obj", "keypad", true, true)
addbehaviour(objects[44], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[44], "boxcollider", 0.5, 0.5, 0.5)
addbehaviour(objects[44], "npc", 2, false, false)
objects[45] = creategameobject("KeypadSlider", true, -0.2210007, 0, 0.012, 0, 0, 0, 1, 1, 1, 1, "keypadslider.obj", "keypadslider", false, true)
addchild(objects[44], objects[45], false)

objects[46] = creategameobject("Sun_Tri", false, -223.4, 26.55, -143.9, 0, 0, 0, 1, 1, 1, 1, "sun.obj", "sun", false, false)
addbehaviour(objects[46], "sun")

objects[47] = creategameobject("table", true, -146, 22.94, -10.2, 0, 0, 0, 1, 0.4131236, 0.4131236, 0.4131236, "table.obj", "table", true, true)
addbehaviour(objects[47], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[47], "meshcollider", true)

objects[48] = creategameobject("Generator", true, -225.7, 22.901, -25.4, 0, -0.7071068, 0, -0.7071068, 0.8, 0.8, 0.8, "generator.obj", "generator", true, true)
addbehaviour(objects[48], "meshcollider", true)
addbehaviour(objects[48], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[48], "npc", 98, false, false)

objects[49] = creategameobject("crate (11)", true, -162.4, 22.77, -30.3, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate", true, true)
addbehaviour(objects[49], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)
addbehaviour(objects[49], "meshcollider", true)

objects[50] = creategameobject("CeilingLamp_Tri", true, -165.8, 32.82, -45.5, 0, 0, 0, 1, 1, 1, 1, "ceilinglamp.obj", "ceilinglamp", true, true)

objects[51] = creategameobject("PostProcessors", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "", true, true)
addbehaviour(objects[51], "fog")
addbehaviour(objects[51], "vignette")
addbehaviour(objects[51], "contrast", 0.08)

objects[52] = creategameobject("small_box (98)", true, -162, 23.21, -84.33, 0, -1, 0, 0, 1, 1, 1, "smallbox.obj", "smallbox", true, true)
addbehaviour(objects[52], "meshcollider", true)
addbehaviour(objects[52], "rigidbody", 0, false, false, false, false, false, false, false, 0.5)

objects[53] = creategameobject("Floor_Grate_Tri", true, -197.1, 24.1, -31.5, 0, 0, 0, 1, 1, 1, 1, "cockpit/floorgrate.obj", "floorgrate", true, true)
addbehaviour(objects[53], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[53], "meshcollider", true)

objects[54] = creategameobject("Wall (33)", true, -89.44, 29.95, -53.16, -0.1529434, -0.6903682, -0.1529434, 0.6903682, 1, 1, 1, "Walls/Wall.obj", "Wall", false, true)

objects[55] = creategameobject("Elevator_Cockpit_Platform_tri (1)", false, -180.75, 23.74, -93.5, 0, 0, 0, 1, 1, 1, 1, "elevator.obj", "elevator", true, true)
addbehaviour(objects[55], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[55], "meshcollider", true)
addbehaviour(objects[55], "elevator", -80.2, 23.519, -114.24, 3.5)
addbehaviour(objects[55], "npc", 67, false, false)

objects[56] = creategameobject("Corridor_Straight_Tri (1)", true, -192.7, 26, -69.1, 0, -0.7071068, 0, 0.7071068, 1, 1, 1, "corridors/straightcorridor.obj", "straightcorridor", false, true)
addbehaviour(objects[56], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[56], "meshcollider", false)

objects[57] = creategameobject("Directional Light", false, -94.68, 31.26, -164.48, 0.1736482, 0, 0, 0.9848078, 1, 1, 1, "", "", false, false)
addbehaviour(objects[57], "light", "directional", 1, 0.9568627, 0.8392157, 1, 0.5, 30)

objects[58] = creategameobject("Canopy_Tri", true, -197, 34, -30.2, 0, 0, 0, 1, 1, 1, 1, "cockpit/canopy.obj", "canopy", true, false)
addbehaviour(objects[58], "rigidbody", 0, true, false, false, false, false, false, false, 0.5)
addbehaviour(objects[58], "meshcollider", false)

