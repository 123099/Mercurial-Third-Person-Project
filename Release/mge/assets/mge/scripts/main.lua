function start()
	math.randomseed(os.clock())
	
	player = Player.new("John")
	playerInv = player:getinventory()
	luaGame:visit("intro")
end

------------------------------------------------------------------------------------------------------------------------
--														intro()
------------------------------------------------------------------------------------------------------------------------
function doprintIntro()
	print "Hello There!"
		utils.yieldWaitForSeconds(1)
	--hideprintdialog()
		utils.yieldWaitForSeconds(0.3)
	print ("How are you doing today, Sir " .. player:getname() .. "?")
		utils.yieldWaitForSeconds(0.5)
	luaGame:visit("introChoice")
	printCoroutine = nil
end

function doprintCheerUp()
	print "Aww, I am sad to hear that"
		utils.yieldWaitForSeconds(1)
	--hideprintdialog()
		utils.yieldWaitForSeconds(0.3)
	print ("print what, " .. player:getname() .. " how about you\nvisit my shop! There oughta be\nsomething to cheer you up!")
		utils.yieldWaitForSeconds(1)
	luaGame:visit("shop")
end

function intro()
	if (printCoroutine == nil) then
		luautils:createcoroutine(doprintIntro)
		printCoroutine = "active"
	end
end

function introChoice()
	if luaGame:button("Fine.png", 0, 270 + math.cos(luautils:getgametime() * 0.005) * 70) then
		print ("Then come on over to my shop, " .. player:getname() .. "!")
		luaGame:visit("shop")
	elseif luaGame:button("Bad.png", 380 + math.sin(luautils:getgametime()*0.004)*40, 300) then
		if (printCoroutine == nil) then
			luautils:createcoroutine(doprintCheerUp)
			printCoroutine = "active"
		end
	end
end

------------------------------------------------------------------------------------------------------------------------
--														shop()
------------------------------------------------------------------------------------------------------------------------
function doBuyDeadDragon()
	if playerInv:getcurrency() >= 50 then
		playerInv:removecurrency(50)
		playerInv:additem("Dead Dragon", 1)
		print ("Purchased a Dead Dragon!\nYou now have " .. playerInv:getitemcount("Dead Dragon") .. " Dead Dragons\nfor some reason...")
	else
		print "Sorry partner, you have to\nprovide me with 50 Dubloons!"
	end
end

function doBuySword()
	if playerInv:getcurrency() >= 25 then
		playerInv:removecurrency(25)
		playerInv:additem("Sword", 1)
		print ("Purchased Excalibur! You are now\nthe proud owner of " .. playerInv:getitemcount("Sword") .. " Excaliburs,\nOh Mighty " .. player:getname() .. "!")
	else
		print "Sorry, you need to offer me 25 shiny ones!"
	end
end

function doBuyPoison1()
	playerInv:additem("Poison I", 1)
	print ("Acquired Poison Strength I!\nDo not consume! You only have " .. playerInv:getitemcount("Poison I") .. " left!\nBut then again, it's on the house!")
end

function doBuyPoison2()
	if playerInv:getcurrency() >= 5 then
		playerInv:removecurrency(5)
		playerInv:additem("Poison II", 1)
		print ("Purchased Poison Strength II! They\noughta give you that reward now! If " .. playerInv:getitemcount("Poison II") .. "\nain't enough, you know where to find me :)")
	else
		print ("No go, " .. player:getname() .. " no killing without 5 goldies..")
	end
end

function doBuyPoison3()
	if playerInv:hasitem("Poison III", 1) then
		print ("Careful, " .. player:getname() .. " only 1 per customer!")
	else
		if playerInv:getcurrency() >= 500 then
			playerInv:removecurrency(500)
			playerInv:additem("Poison III", 1)
			print ("Purchased the Mighty Poison Bottle!\nIt's so mighty in fact, it cannot be\nperceived by mere mortals.")
		else
			print "People print the price of this item is a\nmystery of its own!"
		end
	end
end

function shop()
	luaGame:image("closet_open.png", 0, 0)
	if luaGame:button("closebutton.png", 10, 10) then
		luaGame:visit("cookie")
	end
	
	if luaGame:button("dragon_dead.png", -50, 250) then
		doBuyDeadDragon()
	elseif luaGame:button("sword.png", 375, 320) then
		doBuySword()
	elseif luaGame:button("poison.png", 220,80) then
		doBuyPoison1()
	elseif luaGame:button("poison.png", 400,80) then
		doBuyPoison2()
	elseif luaGame:button("poison.png", 580,80) then
		doBuyPoison3()
	end
end

local cookieProperties = {}
cookieProperties.x = 300
cookieProperties.y = 200
cookieProperties.soundMuted = false

function cookie()
	if luaGame:button("closebutton.png", 10, 10) then
		luaGame:visit("shop")
	end
	
	local soundButton = "sound.png"
	if cookieProperties.soundMuted == true then soundButton = "soundmuted.png" end
	
	if luaGame:button(soundButton, 750, 10) then
		cookieProperties.soundMuted = not cookieProperties.soundMuted
	end
	
	if luaGame:button("cookie.png", cookieProperties.x, cookieProperties.y) then
		playerInv:addcurrency(math.floor(1 + playerInv:getcurrency() * 0.05))
		cookieProperties.x = math.random(150,450)
		cookieProperties.y = math.random(50,350)
		
		print ("Click Me! ($" .. playerInv:getcurrency() .. ")")
		
		--[[if cookieProperties.soundMuted == false then
			playsound("money.wav")
		end]]
	end
end
