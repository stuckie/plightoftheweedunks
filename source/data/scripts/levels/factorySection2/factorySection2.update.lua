-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile("data/scripts/gameplay/factorySection2/_update.lua");

factorySection2_SCRIPTED = nil;
factorySection2_DYNAMIC = nil;

function factorySection2_UPDATE()
	factorySection2Update();
	local list = factorySection2_DYNAMIC;
	while list do
		Horde:SetNodeTransformODEDynamicNoScale( list.node, list.physics );
		list = list.next;
	end
	local list = factorySection2_SCRIPTED;
	while list do
		Horde:SetNodeTransformODEScriptedNoScale( list.node, list.physics );
		list = list.next;
	end
end
