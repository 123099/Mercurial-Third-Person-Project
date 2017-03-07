--npc 28 capsulebutton slot1--
--start disabled--
if npc28:distanceTo(npc10) < 0.7 then
	npc28:setenabled(true)
	player:log("Slot 1 powered!")
	else
	npc28:setenabled(false)
end

if npc28:distanceTo(npc11) < 0.7 then
	player:log("This battery doesn't work in this slot..")
end

if npc28:distanceTo(npc26) < 0.7 then
	player:log("This battery doesn't work in this slot..")
end
