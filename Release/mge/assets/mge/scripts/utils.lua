local M = {}

function M.yieldWaitForSeconds(seconds)
	local currentTime = luautils:getgametime()
	while luautils:getgametime() - currentTime < seconds do
		coroutine.yield()
	end
end

return M