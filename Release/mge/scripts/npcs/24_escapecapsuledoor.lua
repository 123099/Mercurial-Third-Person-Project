--npc 24 escape door with keycode 98 72 93 84 39 22, false true false false false true--
--start disabled--
if  npc24:isopen() == false and
	npc40:isenabled() == false and 
	npc41:isenabled() == true and 
	npc42:isenabled() == false and 
	npc43:isenabled() == false and 
	npc44:isenabled() == false and 
	npc45:isenabled() == true then 
		npc24:open()
		player:log("Input code accepted!")
end