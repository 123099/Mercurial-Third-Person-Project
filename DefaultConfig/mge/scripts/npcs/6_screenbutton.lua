--npc invis button mainframe--
npc7:open()
local x,y,z = npc7:getposition()
luautils:playsound("example.wav", x, y, z, true, 1)
npc7:setenabled(false)
