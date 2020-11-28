--npc 22 elevator battery slot2--
--start disabled--
if npc22:distanceTo(npc11) < 1 and npc22:isenabled() == false then
	npc22:setenabled(true) --enables elevator door--
	player:log("Slot 2 powered!")
	local x,y,z = npc22:getposition()
	if npc21:isenabled() == true then
		player:log("Both slots powered, elevator powered!")
		npc22slotSound = luautils:playsound("BatterySlotLoop2.wav", x, y, z, true, true, 1)
	else
		npc22slotSound = luautils:playsound("BatterySlotLoop.wav", x, y, z, true, true, 1)
	end
elseif npc22:distanceTo(npc11) >= 1 and npc22:isenabled() == true then
	npc22:setenabled(false)
	local x,y,z = npc22:getposition()
	luautils:stopsound(npc22slotSound)
	luautils:playsound("BatterySlotOff.wav", x, y, z, false, true, 1)
end

if npc22testA == nil and npc22:distanceTo(npc10) < 1 then
	player:log("This isn't the proper battery I think, nothing happend..")
	local x,y,z = npc22:getposition()
	luautils:playsound("BatterySlotWrong.wav", x, y, z, false, true, 1)
	npc22testA = true
elseif npc22testA == true and npc22:distanceTo(npc10) >= 1 then
	npc22testA = nil
end

if npc22testB == nil and npc22:distanceTo(npc26) < 1 then
	player:log("This isn't the proper battery I think, nothing happend..")
	local x,y,z = npc22:getposition()
	luautils:playsound("BatterySlotWrong.wav", x, y, z, false, true, 1)
	npc22testB = true
elseif npc22testB == true and npc22:distanceTo(npc26) >= 1 then
	npc22testB = nil
end