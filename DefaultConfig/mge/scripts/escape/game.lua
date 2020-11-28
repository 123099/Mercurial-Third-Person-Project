local introductionCoroutine = nil
function start()
	if introductionCoroutine == nil then
		introductionCoroutine = luautils:createcoroutine(
			function()
				print "I want to play a game..."
				utils.yieldWaitForSeconds(1.5)
				print "Let's test how much you value your life..."
				utils.yieldWaitForSeconds(3)
				luaGame:visit("mainroom")
				utils.yieldWaitForSeconds(1)
				print "You have 3 tries to leave this room, but mess up, and you will lose something valuable..."
				utils.yieldWaitForSeconds(1)
				print "Good luck... "; 
				utils.yieldWaitForSeconds(1)
				print (playerName);
			end
		)
	end
end

function mainroom()
	luaGame:image("colors.png", 0, 0)
	if player == nil then
		player = Player.new(playerName)
		playerInventory = player:getinventory()
	end
end