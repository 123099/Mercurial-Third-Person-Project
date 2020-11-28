--npc door corridor--
if npc66:isdoormoving() == false then
	if npc66:isopen() == false and npc66:distanceTo(player) < 6 then
		npc66:open()
		local x,y,z = npc66:getposition()
		luautils:playsound("DoorSlide.wav", x, y, z, false, true, 1)
	elseif npc66:isopen() == true and npc66:distanceTo(player) >= 6 then
		npc66:close()
		local x,y,z = npc66:getposition()
		luautils:playsound("DoorSlide.wav", x, y, z, false, true, 1)
	end
end