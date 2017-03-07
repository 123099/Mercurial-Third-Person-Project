--npc 43 switch4 -- 
----start disabled--

if npc28:isenabled() == true and npc29:isenabled() == true npc30:isenabled() == true then
	npc43:setenabled(not npc43:isenabled())
	if npc43:isenabled() == true then
		luautils:togglelight(4, true)
		player:log("PowerSwitch 4 enabled")
	else
		luautils:togglelight(4, false)
		player:log("PowerSwitch 4 disabled")
	end
end

	