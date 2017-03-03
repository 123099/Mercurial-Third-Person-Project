--npc cable--
if npc0:isenabled() == true then
	npc0:translate(5, npc1, 0.5)
	local x,y,z = npc0:getposition()
	luautils:playsound("connectcable.wav", x, y, z, false, 1)
	npc0:setenabled(false)
	npc1:setenabled(true)
	luautils:togglelight(0, true)
	player:log("Cable connected")
end
