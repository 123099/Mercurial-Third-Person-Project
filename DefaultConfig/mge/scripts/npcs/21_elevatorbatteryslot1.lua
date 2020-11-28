--npc 21 elevator battery slot1--
if player:iscarrying(npc10) then --battery1--
	npc10:translate(5, npc21, 0.5) --translate the battery towards the batteryslot--
	local x,y,z = npc21:getposition()
	luautils:playsound("batteryinslot.wav", x, y, z, false, 1)
	npc20:setenabled(false) --disable the battery slot so if picking up again it doesnt start the code--
	npc21:setenabled(false)
end