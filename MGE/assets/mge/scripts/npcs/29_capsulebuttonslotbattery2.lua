--npc 29 capsulebutton slot2--
--start disabled--
if npc29:distanceTo(npc11) < 0.7 then
	npc29:setenabled(true)
	player:log("Slot 2 powered!")
	else
	npc29:setenabled(false)
end

if npc29:distanceTo(npc10) < 0.7 then
	player:log("This battery doesn't work in this slot..")
end

if npc29:distanceTo(npc26) < 0.7 then
	player:log("This battery doesn't work in this slot..")
end
