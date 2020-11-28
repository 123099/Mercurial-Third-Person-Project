--npc 901 guidence--
-- update--
if npc901:distanceTo(player) < 25 and timer901 == nil then
	timer901 = luautils:startcoroutine(
	function()
		while true do
			utils.yieldWaitForSeconds(30);
			--No movement--
			if npc901:distanceTo(player) < 25 then
				if npc10batterycarried == nil then
					player:log("The impact of the meteorite seems to have moved\nonly certain crates..")
				elseif npc18:isenabled() == false then
					player:log("Is there a way to move the crane?")
				elseif npc18:isenabled() == false and npc11batterycarried == true then
					player:log("There is a second floor, I should try to explore it")
				end
			end
		end
	end
	)
end

