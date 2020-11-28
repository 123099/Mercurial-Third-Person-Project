--npc 900 guidence--
-- update--
if npc900:distanceTo(player) < 15 and timer900 == nil then
	timer900 = luautils:startcoroutine(
	function()
		while true do
			utils.yieldWaitForSeconds(30);
			--No movement--
			if npc900:distanceTo(player) < 15 then
				if npc0:isenabled() == true then
					player:log("There is no power..")
				elseif npc0:isenabled() == false and npc1:isenabled() == true then
					player:log("I should check where the power cable goes..")
				elseif npc0:isenabled() == false and npc1:isenabled() == false  and npc2:isenabled() == true then
					player:log("I should explore the room..")
				end
			end
		end
	end
	)
end






