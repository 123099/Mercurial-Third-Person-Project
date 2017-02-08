print "Hello! I am a sphere!"

destructionCoroutine = nil
if destructionCoroutine == nil then
	destructionCoroutine = luautils:startcoroutine
	(
		function()
			utils.yieldWaitForSeconds(1)
			print "This is a depressing life..."
			utils.yieldWaitForSeconds(1)
			print "I think I am just gonna go end it all!"
			utils.yieldWaitForSeconds(2)
			player:carry(npc0:gettransform())
		end
	)
end