--npc 27 elevator button--
if npc21:isenabled() == true and npc22:isenabled() == true then
	if npc20:iselevatorpointa() == true then
		npc20:elevatorpointb()
	else
		npc20:elevatorpointa()
	end
end

