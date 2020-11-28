--npc 14 battery slot controlroom door--
--start disabled--
if npc14:isenabled() == false and npc14:distanceTo(npc10) < 1 then
	npc18:setenabled(true)	--computer--
	npc14:setenabled(true)	-- slot--
	local x,y,z = npc14:getposition()
	npc14slotSound = luautils:playsound("BatterySlotLoop.wav", x, y, z, true, true, 1)
	player:log("Battery inserted, elevator powered on!")
elseif npc14:isenabled() == true and npc14:distanceTo(npc10) >= 1 then
	npc14:setenabled(false)
	npc18:setenabled(false)
	local x,y,z = npc14:getposition()
	luautils:stopsound(npc14slotSound)
	luautils:playsound("BatterySlotOff.wav", x, y, z, false, true, 1)
end

if npc14testA == nil and npc14:distanceTo(npc11) < 1 then
	player:log("This isn't the proper battery I think, nothing happend..")
	local x,y,z = npc14:getposition()
	luautils:playsound("BatterySlotWrong.wav", x, y, z, false, true, 1)
	npc14testA = true
elseif npc14testA == true and npc14:distanceTo(npc11) >= 1 then
	npc14testA = nil
end

if npc14testB == nil and npc14:distanceTo(npc26) < 1 then
	player:log("This isn't the proper battery I think, nothing happend..")
	local x,y,z = npc14:getposition()
	luautils:playsound("BatterySlotWrong.wav", x, y, z, false, true, 1)
	npc14testB = true
elseif npc14testB == true and npc14:distanceTo(npc26) >= 1 then
	npc14testB = nil
end