--npc 21 elevator battery slot1--
--start disabled--
if npc21:distanceTo(npc10) < 0.7 then
	npc21:setenabled(true)
	player:log("Slot 1 powered!")
	else
	npc21:setenabled(false)
end

if npc21:distanceTo(npc11) < 0.7 then
	player:log("This battery doesn't work in this slot..")
end
