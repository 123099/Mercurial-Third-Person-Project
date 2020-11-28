--npc 101 elevator button room 3 top elevator--
if npc14:isenabled() == true then
	if npc13:iselevatorpointa() == true then
		npc13:elevatorpointb()
	else
		npc13:elevatorpointa()
	end
end

