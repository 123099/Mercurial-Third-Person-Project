--NPC First Door
if talkcount == nil then
	talkcount = 0
end

if player ~= nil then
	if player:hasdragon() == false then
		if talkcount == 0 then
			print "Please bring me that juicy looking dragon"
		elseif talkcount == 1 then
			print "In case you didn't hear me, I asked for that dragon over there, to your left, or right.. I'm a door, I can't tell directions very well"
		elseif talkcount == 2 then
			print "You know what.. if you aren't going to bring the dragon, don't bother talking to me"
		elseif talkcount >= 3 then
			print "..."
		end
		
		talkcount = talkcount + 1
	else
		if done == nil then
			done = true
			luautils:startcoroutine(
				function()
					print "Ooohhh! You did it! Great!"
					utils.yieldWaitForSeconds(3)
					print "You're still here? Are you expecting some sort of reward?"
					utils.yieldWaitForSeconds(3)
					print "Well what do you want me to give you? I am a door, if you haven't noticed, I don't do much!"
					utils.yieldWaitForSeconds(5)
					print "Alright, I guess I CAN give you THAT..."
					utils.yieldWaitForSeconds(2)
					print "**Door Opens**"
					utils.yieldWaitForSeconds(1)
					player:teleport(0, 1, 0)
				end
			)
		end
	end
end