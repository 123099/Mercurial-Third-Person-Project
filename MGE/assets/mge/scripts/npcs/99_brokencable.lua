if npc99:isenabled() == true then
	local x,y,z = npc99:getposition()
	luautils:playsound("sparks.wav", x, y, z, true, 1)
	npc99:setenabled(false)
end