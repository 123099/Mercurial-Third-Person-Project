--npc 18 broken lever control room--
--start enabled--
if npc18:isenabled() == true then
	npc19:elevatorpointb() --moves crane down--
	player:log("It sounded like something big has moved..")
	local x,y,z = npc19:getposition()
	luautils:playsound("cranemoving.wav", x, y, z, false, false, 1)
	npc18:setenabled(false)
end