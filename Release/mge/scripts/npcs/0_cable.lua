--npc cable--
--start enabled--
if npc0:isenabled() == true then
	local x,y,z = npc0:getposition()
	luautils:playsound("connectcable.wav", x, y, z, false, false, 1)
	local gx, gy, gz = npc98: getposition() --generator position
	luautils:playsound("generatorhum.wav", gx, gy, gz, true, true, 1)
	npc99:setmesh("brokencablefixed")
	npc0:setenabled(false)
	npc1:setenabled(true)
	luautils:togglelight(0, true)
	luautils:togglelight(1, true)
	luautils:togglelight(2, true)
	luautils:stopsound(npc0SparksSound)
	player:log("Cable is connected!")
end


