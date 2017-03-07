--npc 14 battery slot controlroom door--
--start disabled--
if npc14:distanceTo(npc10) < 0.7 then
	npc14:setenabled(true) --slot--
	npc13:open()		--controlroom door--
	local x,y,z = npc14:getposition()
	luautils:playsound("batteryinslotordooropen.wav", x, y, z, false, 1)
	player:log("Battery inserted, door powered on!")
else
	npc14:setenabled(false)
	npc13:close()
		luautils:playsound("batteryioutslotordoorclose.wav", x, y, z, false, 1)
		player:log("Removed battery")
end

if npc14:distanceTo(npc11) < 0.7 then
	player:log("This isn't the proper battery I think, nothing happend..")
end

if npc14:distanceTo(npc26) < 0.7 then
	player:log("This isn't the proper battery I think, nothing happend..")
end