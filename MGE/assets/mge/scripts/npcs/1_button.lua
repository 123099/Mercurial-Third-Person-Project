--npc button--
--start disabled--
if npc1:isenabled() == true then
	npc2:settexture("Keypad/albedo_lit.png") --npc2 = keypad
	local x,y,z = npc2:getposition()
	luautils:playsound("keypadenabled.wav", x, y, z, false, 1)
	npc2:setenabled(true)
	npc1:setenabled(false) --npc1 = button
	player:log("Huh, I heard something turning on..")
else
	if npc2:isenabled() == false then
		player:log("This seems not to be working...")
	else
		player:log("I heard something when I pressed it before..")
	end
end