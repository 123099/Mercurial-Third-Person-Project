--npc 29 capsulebutton slot1--
--start disabled--
if npc29:distanceTo(npc11) < 1 and npc29:isenabled() == false then
	npc29:setenabled(true)
	player:log("Slot 2 powered!")
	local x,y,z = npc29:getposition()
	if npc28:isenabled() and npc29:isenabled() and npc30:isenabled() then
		npc29slotSound = luautils:playsound("BatterySlotLoop2.wav", x, y, z, true, true, 1)
	else
		npc29slotSound = luautils:playsound("BatterySlotLoop.wav", x, y, z, true, true, 1)
	end
elseif npc29:isenabled() == true and npc29:distanceTo(npc11) >= 1 then
	npc29:setenabled(false)
	local x,y,z = npc29:getposition()
	luautils:stopsound(npc29slotSound)
	luautils:playsound("BatterySlotOff.wav", x, y, z, false, true, 1)
end

if npc29testA == nil and npc29:distanceTo(npc26) < 1 then
	player:log("This isn't the proper battery I think, nothing happend..")
	local x,y,z = npc29:getposition()
	luautils:playsound("BatterySlotWrong.wav", x, y, z, false, true, 1)
	npc29testA = true
elseif npc29testA == true and npc29:distanceTo(npc26) >= 1 then
	npc29testA = nil
end

if npc29testB == nil and npc29:distanceTo(npc10) < 1 then
	player:log("This isn't the proper battery I think, nothing happend..")
	local x,y,z = npc29:getposition()
	luautils:playsound("BatterySlotWrong.wav", x, y, z, false, true, 1)
	npc29testB = true
elseif npc29testB == true and npc29:distanceTo(npc10) >= 1 then
	npc29testB = nil
end