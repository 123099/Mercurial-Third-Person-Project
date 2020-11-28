--npc button--
--start disabled--
if npc2:isenabled() == true and player:iscarrying(npc25) then
	npc4:open()
	npc4:setenabled(true)
	local x,y,z = npc4:getposition()
	luautils:playsound("DoorSlide.wav", x, y, z, false, false, 1)
	npc2:setenabled(false)
	player:log("Keycard accepted!")
	player:carry(nil)
	npc25:destroyself()
elseif npc2:isenabled() == true and player:iscarrying(npc12) then
	player:log("This text looks familiar..")
end

if npc2:isenabled() == false then
	if npc4:isenabled() == false then
		player:log("Keypad is not powered on..")
	else
		player:log("I should probably continue further")
	end
end