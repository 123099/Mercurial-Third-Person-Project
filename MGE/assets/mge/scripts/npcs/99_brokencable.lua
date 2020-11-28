if npc0SparksSound == nil then
	local x,y,z = npc0:getposition()
	npc0SparksSound = luautils:playsound("sparks.wav", x, y, z, true, true, 1)
end