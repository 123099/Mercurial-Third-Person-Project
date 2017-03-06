--npc 18 broken lever control room--
if npc18:isenabled() == true then
	local x,y,z = npc18:getposition()
	luautils:playsound("brokenlever.wav", x, y, z, false, 1)
	npc18:setenabled(false)
	luautils:startcoroutine
	(
		function()
			utils.yieldWaitForSeconds(10)
			npc18:setenabled(true)
		end
	)
end