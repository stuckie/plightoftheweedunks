-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile("data/scripts/gameplay/factorySection1/_update.lua");


factorySection1_SCRIPTED = nil;
factorySection1_DYNAMIC = nil;

function factorySection1_UPDATE()
    factorySection1Update();
	local list = factorySection1_DYNAMIC;
	while list do
        if list.node > 0 then
		    Horde:SetNodeTransformODEDynamicNoScale( list.node, list.physics );
        end
		list = list.next;
	end
	local list = factorySection1_SCRIPTED;
	while list do
        if list.node > 0 then
		    Horde:SetNodeTransformODEScriptedNoScaleNoRot( list.node, list.physics );
        end
		list = list.next;
	end
end
