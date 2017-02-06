--NPC Second Door
if player ~= nil then
	if player:haskeycode() == false then
		if doortries == nil then doortries = 1 end
		if doortries == 1 then
			print "Doors nowadays always seem to be locked. When will the developers fix them?"
		elseif doortries == 2 then
			print "Maybe a 6 digit passcode would help the developers get moving? Just a thought..."
		elseif doortries == 3 then
			print "You don't seem to have a series of 6 digits"
		elseif doortries == 4 then
			print "Are you trying to cheat? Or maybe you are hoping that if you knock enough times I may open? That ain't happening!"
		else
			if currentindex ~= nil and currentindex >= 5 then
				math.randomseed(os.time())
				local winchance = math.random()
				if winchance > 0.6 then
					print "ALRIGHT! You uncovered 4 of the 6 numbers in the password! I WILL ACCEPT IT! Talk to me again to input the numbers"
					player:sethaskeycode(true)
					doortries = 1
				else
					print "Knock Knock.."
				end
			end
		end
		
		doortries = doortries + 1
	else
		player:sethaskeycode(false)
		currentindex = nil
		passcode = nil
		
		if wincount == nil then wincount = 1 else wincount = wincount + 1 end
		
		if wincount == 1 then
			print "Ah! Lovely! Codes are my favorite! Password Accepted... I am still locked, though. Sorry!"
		elseif wincount == 2 then
			print "Oh, another passcode! It feels like christmas!"
		elseif wincount == 3 then
			print "Ughhh.. I am starting to not feel so well... I think that my be enough passwords.. please..."
		elseif wincount == 4 then
			print "Pass... word... overload... Can't ... handle.. IT!"
			npc0:destroy()
		end
	end
end