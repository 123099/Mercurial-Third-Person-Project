--npc door corridor--
if npc15:isdoormoving() == false then
	if npc15:isopen() == false and npc15:distanceTo(player) < 6 then
		npc15:open()
		local x,y,z = npc15:getposition()
		luautils:playsound("DoorSlide.wav", x, y, z, false, true, 1)
	elseif npc15:isopen() == true and npc15:distanceTo(player) >= 6 then
		npc15:close()
		local x,y,z = npc15:getposition()
		luautils:playsound("DoorSlide.wav", x, y, z, false, true, 1)
	end
end