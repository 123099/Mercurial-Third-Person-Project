--npc button--
if npc1:isenabled() == true then
	npc2:settexture("keypadlit.png") --npc2 = keypad
	local x,y,z = npc2:getposition()
	luautils:playsound("keypadenabled.wav", x, y, z, false, 1)
	npc2:setenabled(true)
	npc1:setenabled(false) --npc1 = button
	player:log("Huh, I heard something turning on..")
end