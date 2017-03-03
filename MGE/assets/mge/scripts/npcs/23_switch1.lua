--npc 23 switch1 -- 


npc23:setenabled(not npc23:isenabled())
npc23:settoggled(npc23:isenabled())

if npc23:isenabled() == true then
	light:swaptexture("light.png") 
else
	light swap texture off
end

	