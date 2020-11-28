--npc door corridor--
if npc17:isdoormoving() == false then
	if npc17:isopen() == false and npc17:distanceTo(player) < 6 then
		npc17:open()
		local x,y,z = npc17:getposition()
		luautils:playsound("DoorSlide.wav", x, y, z, false, true, 1)
	elseif npc17:isopen() == true and npc17:distanceTo(player) >= 6 then
		npc17:close()
		local x,y,z = npc17:getposition()
		luautils:playsound("DoorSlide.wav", x, y, z, false, true, 1)
	end
end