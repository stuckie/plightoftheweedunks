-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

bilgeRoom_SCRIPTED = nil;
bilgeRoom_DYNAMIC = nil;

function bilgeRoom_UPDATE()

	local list = bilgeRoom_DYNAMIC;
	while list do
		Horde:SetNodeTransformODEDynamicNoScale( list.node, list.physics );
		list = list.next;
	end
	local list = bilgeRoom_SCRIPTED;
	while list do
		Horde:SetNodeTransformODEScriptedNoScale( list.node, list.physics );
		list = list.next;
	end
end
