--npc mainframe--
local state = 1
local x,y,z = npc5:getposition()
if state == 1 then --mainframe asks for rank and id
	if textwritten("Lt.Brandon") then
		npc5:settexture("Password.jpg")
		state = 2
		luautils:playsound("example.wav", x, y, z, true, 1)
	end
elseif state == 2 then --mainframe asks for password
	if textwritten("keyboard") then
		npc5:settexture("folders.jpg")
		luautils:playsound("example.wav", x, y, z, true, 1)
		state = 3
	end
elseif state = 3 then --mainframe asks for right folder, enables npc 6
	npc6:setenabled(true)
	luautils:playsound("example.wav", x, y, z, true, 1)
end

