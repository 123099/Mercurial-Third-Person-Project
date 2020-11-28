--npc 21 elevator battery slot2--
--start disabled--
if npc21:distanceTo(npc10) < 1 and npc21:isenabled() == false then
	npc21:setenabled(true) --enables elevator door--
	player:log("Slot 2 powered!")
	local x,y,z = npc21:getposition()
	if npc22:isenabled() == true then
		player:log("Both slots powered, elevator powered!")
		npc21slotSound = luautils:playsound("BatterySlotLoop2.wav", x, y, z, true, true, 1)
	else
		npc21slotSound = luautils:playsound("BatterySlotLoop.wav", x, y, z, true, true, 1)
	end
elseif npc21:distanceTo(npc10) >= 1 and npc21:isenabled() == true then
	npc21:setenabled(false)
	local x,y,z = npc21:getposition()
	luautils:stopsound(npc21slotSound)
	luautils:playsound("BatterySlotOff.wav", x, y, z, false, true, 1)
end

if npc21testA == nil and npc21:distanceTo(npc11) < 1 then
	player:log("This isn't the proper battery I think, nothing happend..")
	local x,y,z = npc21:getposition()
	luautils:playsound("BatterySlotWrong.wav", x, y, z, false, true, 1)
	npc21testA = true
elseif npc21testA == true and npc21:distanceTo(npc11) >= 1 then
	npc21testA = nil
end

if npc21testB == nil and npc21:distanceTo(npc26) < 1 then
	player:log("This isn't the proper battery I think, nothing happend..")
	local x,y,z = npc21:getposition()
	luautils:playsound("BatterySlotWrong.wav", x, y, z, false, true, 1)
	npc21testB = true
elseif npc21testB == true and npc21:distanceTo(npc26) >= 1 then
	npc21testB = nil
end