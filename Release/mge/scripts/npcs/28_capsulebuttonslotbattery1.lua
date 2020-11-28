--npc 28 capsulebutton slot1--
--start disabled--
if npc28:distanceTo(npc10) < 1 and npc28:isenabled() == false then
	npc28:setenabled(true)
	player:log("Slot 1 powered!")
	local x,y,z = npc28:getposition()
	if npc28:isenabled() and npc29:isenabled() and npc30:isenabled() then
		npc28slotSound = luautils:playsound("BatterySlotLoop2.wav", x, y, z, true, true, 1)
	else
		npc28slotSound = luautils:playsound("BatterySlotLoop.wav", x, y, z, true, true, 1)
	end
elseif npc28:isenabled() == true and npc28:distanceTo(npc10) >= 1 then
	npc28:setenabled(false)
	local x,y,z = npc28:getposition()
	luautils:stopsound(npc28slotSound)
	luautils:playsound("BatterySlotOff.wav", x, y, z, false, true, 1)
end

if npc28testA == nil and npc28:distanceTo(npc11) < 1 then
	player:log("This isn't the proper battery I think, nothing happend..")
	local x,y,z = npc28:getposition()
	luautils:playsound("BatterySlotWrong.wav", x, y, z, false, true, 1)
	npc28testA = true
elseif npc28testA == true and npc28:distanceTo(npc11) >= 1 then
	npc28testA = nil
end

if npc28testB == nil and npc28:distanceTo(npc26) < 1 then
	player:log("This isn't the proper battery I think, nothing happend..")
	local x,y,z = npc28:getposition()
	luautils:playsound("BatterySlotWrong.wav", x, y, z, false, true, 1)
	npc28testB = true
elseif npc28testB == true and npc28:distanceTo(npc26) >= 1 then
	npc28testB = nil
end