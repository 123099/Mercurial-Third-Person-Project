--npc 45 switch6 -- 
----start disabled--

if npc28:isenabled() == true and npc29:isenabled() == true and npc30:isenabled() == true then
	npc45:setenabled(not npc45:isenabled())
	if npc45:isenabled() == true then
		luautils:togglelight(6, true)
		player:log("PowerSwitch 6 enabled")
		npc45:setmesh("ButtonPressed")
	else
		luautils:togglelight(6, false)
		player:log("PowerSwitch 6 disabled")
		npc45:setmesh("Button")
	end
end

	