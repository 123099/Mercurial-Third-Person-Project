--npc keycard--

if npc9:distanceTo(player) < 3 and player:iscarrying(npc8) then
	npc9:open()
	local x,y,z = npc9:getposition()
	luautils:playsound("Dooropen.wav", x, y, z, false, 1)
	npc8:setenabled(false)
end

