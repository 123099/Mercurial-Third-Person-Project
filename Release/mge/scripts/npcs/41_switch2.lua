--npc 41 switch2 -- 
----start disabled--

if npc28:isenabled() == true and npc29:isenabled() == true and npc30:isenabled() == true then
	npc41:setenabled(not npc41:isenabled())
	if npc41:isenabled() == true then
		luautils:togglelight(2, true)
		player:log("PowerSwitch 2 enabled")
		npc41:setmesh("ButtonPressed")
	else
		luautils:togglelight(2, false)
		player:log("PowerSwitch 2 disabled")
		npc41:setmesh("Button")
	end
end

	