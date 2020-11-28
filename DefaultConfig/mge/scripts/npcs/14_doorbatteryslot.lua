--npc 14 battery slot controlroom door--
if player:iscarrying(npc10) then --battery1--
	npc10:translate(5, npc14, 0.5) --translate the battery towards the batteryslot--
	local x,y,z = npc14:getposition()
	luautils:playsound("batteryinslot.wav", x, y, z, false, 1)
	npc13:open()
	npc14:setenabled(false) --disable the battery slot so if picking up again it doesnt start the code--
	npc13:setenabled(false)
end