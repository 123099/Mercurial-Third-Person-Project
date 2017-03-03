--npc 22 elevator battery slot2--
if player:iscarrying(npc11) then --battery1--
	npc10:translate(5, npc22, 0.5) --translate the battery towards the batteryslot--
	local x,y,z = npc22:getposition()
	luautils:playsound("batteryinslot.wav", x, y, z, false, 1)
	npc20:setenabled(false) --disable the battery slot so if picking up again it doesnt start the code--
	npc21:setenabled(false)
	if npc20:isenabled() == false and npc21:isenabled() == false then
	npc20:open()
end