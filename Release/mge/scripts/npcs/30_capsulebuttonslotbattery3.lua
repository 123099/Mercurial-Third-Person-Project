--npc 30 capsulebutton slot3--
--start disabled--
if npc30:distanceTo(npc26) < 1 and npc30:isenabled() == false then
	npc30:setenabled(true)
	player:log("Slot 3 powered!")
	local x,y,z = npc30:getposition()
	if npc28:isenabled() and npc29:isenabled() and npc30:isenabled() then
		npc30slotSound = luautils:playsound("BatterySlotLoop2.wav", x, y, z, true, true, 1)
	else
		npc30slotSound = luautils:playsound("BatterySlotLoop.wav", x, y, z, true, true, 1)
	end
elseif npc30:isenabled() == true and npc30:distanceTo(npc26) >= 1 then
	npc30:setenabled(false)
	local x,y,z = npc30:getposition()
	luautils:stopsound(npc30slotSound)
	luautils:playsound("BatterySlotOff.wav", x, y, z, false, true, 1)
end

if npc30testA == nil and npc30:distanceTo(npc10) < 1 then
	player:log("This isn't the proper battery I think, nothing happend..")
	local x,y,z = npc30:getposition()
	luautils:playsound("BatterySlotWrong.wav", x, y, z, false, true, 1)
	npc30testA = true
elseif npc30testA == true and npc30:distanceTo(npc10) >= 1 then
	npc30testA = nil
end

if npc30testB == nil and npc30:distanceTo(npc11) < 1 then
	player:log("This isn't the proper battery I think, nothing happend..")
	local x,y,z = npc30:getposition()
	luautils:playsound("BatterySlotWrong.wav", x, y, z, false, true, 1)
	npc30testB = true
elseif npc30testB == true and npc30:distanceTo(npc11) >= 1 then
	npc30testB = nil
end