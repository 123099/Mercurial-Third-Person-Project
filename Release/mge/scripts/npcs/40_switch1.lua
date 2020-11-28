--npc 40 switch1 -- 
----start disabled--

if npc28:isenabled() == true and npc29:isenabled() == true and npc30:isenabled() == true then
	npc40:setenabled(not npc40:isenabled())
	if npc40:isenabled() == true then
		luautils:togglelight(1, true)
		player:log("PowerSwitch 1 enabled")
		npc40:setmesh("ButtonPressed")
	else
		luautils:togglelight(1, false)
		player:log("PowerSwitch 1 disabled")
		npc40:setmesh("Button")
	end
end

	