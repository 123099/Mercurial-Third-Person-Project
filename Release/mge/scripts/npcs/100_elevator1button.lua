--npc 100 elevator button room 3 bottom elevator--
if npc14:isenabled() == true then
	if npc13:iselevatorpointa() == true then
		npc13:elevatorpointb()
	else
		npc13:elevatorpointa()
	end
end

