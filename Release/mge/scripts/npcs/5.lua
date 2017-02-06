--NPC Bookshelf 5
if player ~= nil then
	if passcode == nil then
		math.randomseed(os.time())
		passcode = ""
		for i = 1, 6 do
			passcode = passcode .. math.random(1, 6)
		end
	end
	
	if currentindex == nil then
		currentindex = 1
	end
	
	if passcode:sub(currentindex, currentindex) ~= "5" then
		if currentindex == 1 then
			print "This is a bookshelf. If you ever feel down, please stare at book."
		else
			print "Wow, what a beautiful book! The stories within it must be amazing! ... What was it I was doing again?"
		end
		currentindex = nil
	else
		if #passcode == currentindex then
			print ("The numbers seem to form some sort of a passcode for a door... " .. passcode)
			player:sethaskeycode(true)
		else
			print "Hmm, a digit yet again... (5)"
			currentindex = currentindex + 1
		end
	end
end