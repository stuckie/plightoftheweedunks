-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile("data/scripts/gameplay/toothy/_update.lua");

toothy_SCRIPTED = nil;
toothy_DYNAMIC = nil;

function toothy_UPDATE()
	toothyUpdate();
	
	local list = toothy_DYNAMIC;
	while list do
		if list.node > 0 then
			Horde:SetNodeTransformODEDynamicWithScale( list.node, list.physics, 0.1 );
		end
		list = list.next;
	end
	local list = toothy_SCRIPTED;
	while list do
		if list.node > 0 then
			Horde:SetNodeTransformODEScriptedWithScale( list.node, list.physics, 0.1 );
		end
		list = list.next;
	end
end
