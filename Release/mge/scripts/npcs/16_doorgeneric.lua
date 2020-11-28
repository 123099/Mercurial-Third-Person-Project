--npc door corridor--
if npc16:isdoormoving() == false then
	if npc16:isopen() == false and npc16:distanceTo(player) < 6 then
		npc16:open()
		local x,y,z = npc16:getposition()
		luautils:playsound("DoorSlide.wav", x, y, z, false, true, 1)
	elseif npc16:isopen() == true and npc16:distanceTo(player) >= 6 then
		npc16:close()
		local x,y,z = npc16:getposition()
		luautils:playsound("DoorSlide.wav", x, y, z, false, true, 1)
	end
end