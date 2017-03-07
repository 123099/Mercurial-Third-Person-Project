--npc 27 elevator button--
if npc21:isenabled() == true and npc22:isenabled() == true then
   if npc27:isenabled(true) then
     npc20:elevatorpointa()
	 npc27:setenabled(false)
   else
     npc27:setenabled(false)
   end
end


if npc21:isenabled() == true and npc22:isenabled() == true then
   if npc27:isenabled(false) then
     npc20:elevatorpointb()
	 npc27:setenabled(true)
   else
     npc27:setenabled(true)
   end
end

