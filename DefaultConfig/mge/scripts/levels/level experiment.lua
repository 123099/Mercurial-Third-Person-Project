objects = {}
objects[0] = creategameobject("Player (1)", false, -5.94, 0.85, 5.1, 0, 0, 0, 1, 1, 1, 1, "", "")
addbehaviour(objects[0], "player", 8)
addbehaviour(objects[0], "charactercontroller", 45, 0.3, 0.5, 2)
objects[1] = creategameobject("Camera", false, 0, 1.281, -0.013, 0, -1, 0, -4.371139E-08, 1, 1, 1, "", "")
addbehaviour(objects[1], "camera", 60, 0.3, 1000)
addbehaviour(objects[1], "audiolistener")
addchild(objects[0], objects[1], false)

objects[2] = creategameobject("corner4", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "cornerwall.obj", "cornerwall")
addbehaviour(objects[2], "meshcollider", true)
addbehaviour(objects[2], "rigidbody", 0, false, false, false, false, false, false, false)

objects[3] = creategameobject("Wall_20-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[3], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[3], "meshcollider", true)

objects[4] = creategameobject("Drawer_1-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "drawer.obj", "drawer")
addbehaviour(objects[4], "meshcollider", true)
addbehaviour(objects[4], "rigidbody", 0, false, false, false, false, false, false, false)

objects[5] = creategameobject("Plane-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "plane.obj", "lit")
addbehaviour(objects[5], "meshcollider", true)
addbehaviour(objects[5], "rigidbody", 0, false, false, false, false, false, false, false)

objects[6] = creategameobject("polySurface18-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[6], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[6], "meshcollider", true)

objects[7] = creategameobject("Capsule_2_Glass-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")

objects[8] = creategameobject("Wall_9-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[8], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[8], "meshcollider", true)

objects[9] = creategameobject("Wall_5-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[9], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[9], "meshcollider", true)

objects[10] = creategameobject("Wall_16-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[10], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[10], "meshcollider", true)

objects[11] = creategameobject("Crate_5-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[11], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[11], "meshcollider", true)

objects[12] = creategameobject("Generator-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "generator.obj", "generator")
addbehaviour(objects[12], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[12], "meshcollider", true)

objects[13] = creategameobject("Pillar_2-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "pillar.obj", "pillar")
addbehaviour(objects[13], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[13], "meshcollider", true)

objects[14] = creategameobject("Corner_1-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "cornerwall.obj", "cornerwall")
addbehaviour(objects[14], "meshcollider", true)
addbehaviour(objects[14], "rigidbody", 0, false, false, false, false, false, false, false)

objects[15] = creategameobject("Crate_1-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[15], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[15], "meshcollider", true)

objects[16] = creategameobject("Door_Frame_2-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "doorframe")
addbehaviour(objects[16], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[16], "meshcollider", true)

objects[17] = creategameobject("Capsule_1_Glass-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")

objects[18] = creategameobject("Capsule_3_Glass-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")

objects[19] = creategameobject("Wall_6-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[19], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[19], "meshcollider", true)

objects[20] = creategameobject("Drawer_2-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "drawer.obj", "drawer")
addbehaviour(objects[20], "meshcollider", true)
addbehaviour(objects[20], "rigidbody", 0, false, false, false, false, false, false, false)

objects[21] = creategameobject("Pillar_5-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "pillar.obj", "pillar")
addbehaviour(objects[21], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[21], "meshcollider", true)

objects[22] = creategameobject("Crate_3-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[22], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[22], "meshcollider", true)

objects[23] = creategameobject("Capsule4-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "capsule.obj", "capsule")
addbehaviour(objects[23], "meshcollider", true)
addbehaviour(objects[23], "rigidbody", 0, false, false, false, false, false, false, false)

objects[24] = creategameobject("Corner_2-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "cornerwall.obj", "cornerwall")
addbehaviour(objects[24], "meshcollider", true)
addbehaviour(objects[24], "rigidbody", 0, false, false, false, false, false, false, false)

objects[25] = creategameobject("Broken_Cable_Fixed-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "brokencable.obj", "brokencable")

objects[26] = creategameobject("Door_Frame_1-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "doorframe.obj", "doorframe")
addbehaviour(objects[26], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[26], "meshcollider", true)

objects[27] = creategameobject("Table_hibernationroom-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "table.obj", "table")
addbehaviour(objects[27], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[27], "meshcollider", true)

objects[28] = creategameobject("FingerPrintScannerHibernationRoom-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "fingerprintscanner.obj", "fingerprintscanner")
addbehaviour(objects[28], "meshcollider", true)
addbehaviour(objects[28], "rigidbody", 0, false, false, false, false, false, false, false)

objects[29] = creategameobject("Wall_13-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[29], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[29], "meshcollider", true)

objects[30] = creategameobject("Wall_4-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[30], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[30], "meshcollider", true)

objects[31] = creategameobject("Capsule_4_Glass-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")

objects[32] = creategameobject("Wall_14-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[32], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[32], "meshcollider", true)

objects[33] = creategameobject("Capsule_5_Glass-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")

objects[34] = creategameobject("Drawer_5-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "drawer.obj", "drawer")
addbehaviour(objects[34], "meshcollider", true)
addbehaviour(objects[34], "rigidbody", 0, false, false, false, false, false, false, false)

objects[35] = creategameobject("Wall_3-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[35], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[35], "meshcollider", true)

objects[36] = creategameobject("Pillar_3-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "pillar.obj", "pillar")
addbehaviour(objects[36], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[36], "meshcollider", true)

objects[37] = creategameobject("Capsule2-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "capsule.obj", "capsule")
addbehaviour(objects[37], "meshcollider", true)
addbehaviour(objects[37], "rigidbody", 0, false, false, false, false, false, false, false)

objects[38] = creategameobject("Wall_12-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[38], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[38], "meshcollider", true)

objects[39] = creategameobject("Wall_17-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[39], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[39], "meshcollider", true)

objects[40] = creategameobject("Wall_Double_17-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")

objects[41] = creategameobject("Wall_8-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[41], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[41], "meshcollider", true)

objects[42] = creategameobject("Drawer_4-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "drawer.obj", "drawer")
addbehaviour(objects[42], "meshcollider", true)
addbehaviour(objects[42], "rigidbody", 0, false, false, false, false, false, false, false)

objects[43] = creategameobject("Right-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")

objects[44] = creategameobject("Wall_15-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[44], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[44], "meshcollider", true)

objects[45] = creategameobject("Wall_21-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[45], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[45], "meshcollider", true)

objects[46] = creategameobject("Corner_3-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "cornerwall.obj", "cornerwall")
addbehaviour(objects[46], "meshcollider", true)
addbehaviour(objects[46], "rigidbody", 0, false, false, false, false, false, false, false)

objects[47] = creategameobject("Left-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")

objects[48] = creategameobject("Capsule1-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "capsule.obj", "capsule")
addbehaviour(objects[48], "meshcollider", true)
addbehaviour(objects[48], "rigidbody", 0, false, false, false, false, false, false, false)

objects[49] = creategameobject("Capsule6Opened-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")

objects[50] = creategameobject("Corner_5-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "cornerwall.obj", "cornerwall")
addbehaviour(objects[50], "meshcollider", true)
addbehaviour(objects[50], "rigidbody", 0, false, false, false, false, false, false, false)

objects[51] = creategameobject("Drawer_3-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "drawer.obj", "drawer")
addbehaviour(objects[51], "meshcollider", true)
addbehaviour(objects[51], "rigidbody", 0, false, false, false, false, false, false, false)

objects[52] = creategameobject("Pillar_1-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "pillar.obj", "pillar")
addbehaviour(objects[52], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[52], "meshcollider", true)

objects[53] = creategameobject("Drawer_6-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "drawer.obj", "drawer")
addbehaviour(objects[53], "meshcollider", true)
addbehaviour(objects[53], "rigidbody", 0, false, false, false, false, false, false, false)

objects[54] = creategameobject("Crate_4-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "crate.obj", "crate")
addbehaviour(objects[54], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[54], "meshcollider", true)

objects[55] = creategameobject("Wall_7-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[55], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[55], "meshcollider", true)

objects[56] = creategameobject("Pillar_4-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "pillar.obj", "pillar")
addbehaviour(objects[56], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[56], "meshcollider", true)

objects[57] = creategameobject("Capsule3-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "capsule.obj", "capsule")
addbehaviour(objects[57], "meshcollider", true)
addbehaviour(objects[57], "rigidbody", 0, false, false, false, false, false, false, false)

objects[58] = creategameobject("KeypadHibernationRoom-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "keypad.obj", "keypad")
addbehaviour(objects[58], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[58], "meshcollider", true)

objects[59] = creategameobject("Keycard_Frame-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "keycard.obj", "keycard")

objects[60] = creategameobject("Wall_10-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[60], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[60], "meshcollider", true)

objects[61] = creategameobject("Keycard_glass-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")

objects[62] = creategameobject("Wall_2-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[62], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[62], "meshcollider", true)

objects[63] = creategameobject("Capsule_6_Glass-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "", "")

objects[64] = creategameobject("Wall_11-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[64], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[64], "meshcollider", true)

objects[65] = creategameobject("Tv_set-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "Tv's.obj", "tv's")

objects[66] = creategameobject("Wall_22-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[66], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[66], "meshcollider", true)

objects[67] = creategameobject("Capsule5-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "capsule.obj", "capsule")
addbehaviour(objects[67], "meshcollider", true)
addbehaviour(objects[67], "rigidbody", 0, false, false, false, false, false, false, false)

objects[68] = creategameobject("Wall_19-Frame_0", false, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, "straightwall.obj", "straightwall")
addbehaviour(objects[68], "rigidbody", 0, false, false, false, false, false, false, false)
addbehaviour(objects[68], "meshcollider", true)

