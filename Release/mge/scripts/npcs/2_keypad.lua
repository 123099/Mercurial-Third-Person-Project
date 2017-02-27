--npc button--
if npc2:isenabled() == true and npc2:distanceTo(player) < 3 and player:iscarrying(npc3) then
	local x,y,z = npc4:getposition()
	luautils:playsound("Dooropen.wav", x, y, z, false, 1)
	npc4:open()
	npc2:setenabled(false)
end