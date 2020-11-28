--npc door corridor--
if npc23:isdoormoving() == false then
	if npc23:isopen() == false and npc23:distanceTo(player) < 6 then
		npc23:open()
		local x,y,z = npc23:getposition()
		luautils:playsound("DoorSlide.wav", x, y, z, false, true, 1)
	elseif npc23:isopen() == true and npc23:distanceTo(player) >= 6 then
		npc23:close()
		local x,y,z = npc23:getposition()
		luautils:playsound("DoorSlide.wav", x, y, z, false, true, 1)
	end
end