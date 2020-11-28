--npc 43 switch4 -- 
----start disabled--

if npc28:isenabled() == true and npc29:isenabled() == true and npc30:isenabled() == true then
	npc43:setenabled(not npc43:isenabled())
	if npc43:isenabled() == true then
		luautils:togglelight(4, true)
		player:log("PowerSwitch 4 enabled")
		npc43:setmesh("ButtonPressed")
	else
		luautils:togglelight(4, false)
		player:log("PowerSwitch 4 disabled")
		npc43:setmesh("Button")
	end
end

	