-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

battleRoom_SCRIPTED = nil;
battleRoom_DYNAMIC = nil;

function battleRoom_UPDATE()

	local list = battleRoom_DYNAMIC;
	while list do
		Horde:SetNodeTransformODEDynamicNoScale( list.node, list.physics );
		list = list.next;
	end
	local list = battleRoom_SCRIPTED;
	while list do
		Horde:SetNodeTransformODEScriptedNoScale( list.node, list.physics );
		list = list.next;
	end
end
