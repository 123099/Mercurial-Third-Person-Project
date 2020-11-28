--npc 12 tABLET--
player:carry(npc12)
if tablet12pickedup == nil then
	player:log("Mhm what is this?")
	tablet12pickedup = true
	luautils:startcoroutine(
	function()
		utils.yieldWaitForSeconds(5)
		tablet12pickedup = nil
	end)
end