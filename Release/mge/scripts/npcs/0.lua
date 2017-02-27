if npc0:isenabled() then
	local x,y,z = npc0:getposition()
	print (x)
	print (y)
	print (z)
	npc0:settexture("SHELF_TEXTURE.bmp")
	luautils:playsound("money.wav", 0, 0, 0, false, 1)
	player:carry(npc0)
	npc0:setenabled(false)
end