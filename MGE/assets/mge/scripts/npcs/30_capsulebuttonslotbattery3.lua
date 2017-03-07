--npc 30 capsulebutton slot3--
--start disabled--
if npc30:distanceTo(npc26) < 0.7 then
	npc30:setenabled(true)
	player:log("Slot 2 powered!")
	else
	npc30:setenabled(false)
end

if npc30:distanceTo(npc10) < 0.7 then
	player:log("This battery doesn't work in this slot..")
end

if npc30:distanceTo(npc11) < 0.7 then
	player:log("This battery doesn't work in this slot..")
end
