--npc 22 elevator battery slot2--
--start disabled--
if npc22:distanceTo(npc11) < 0.7 then
	npc22:setenabled(true) --enables elevator door--
	player:log("Slot 2 powered!")
	player:log("Both slots powered, elevator powered!")
else
	npc22:setenabled(false)
end

if npc22:distanceTo(npc10) < 0.7 then
	player:log("This battery doesn't work in this slot..")
end
