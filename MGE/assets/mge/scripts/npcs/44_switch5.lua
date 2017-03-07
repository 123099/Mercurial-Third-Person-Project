--npc 44 switch5 -- 
----start disabled--

if npc28:isenabled() == true and npc29:isenabled() == true npc30:isenabled() == true then
	npc44:setenabled(not npc44:isenabled())
	if npc44:isenabled() == true then
		luautils:togglelight(5, true)
		player:log("PowerSwitch 5 enabled")
	else
		luautils:togglelight(5, false)
		player:log("PowerSwitch 5 disabled")
	end
end

	