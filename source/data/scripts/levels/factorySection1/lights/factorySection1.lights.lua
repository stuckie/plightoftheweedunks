-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Light Information for factorySection1.
function factorySection1_LIGHTS()
	factory1_lights_spotLightShape1 = Horde:AddLightNode( 0, "factory1_lights_spotLightShape1", LightMat, "LIGHTING", "SHADOWMAP" );
	Horde:SetNodeTransform( factory1_lights_spotLightShape1, -53, 518, -380, -50, 180, 0, 1, 1, 1);
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "FOV", 90 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "Radius", 1000 );
	Horde:SetNodeParamInt( factory1_lights_spotLightShape1, "ShadowMapCount", 4 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "Col_R", 1.0 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "Col_G", 1.0 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "Col_B", 1.0 );
--[[	
	factory1_lights_spotLightShape1 = Horde:AddLightNode( 0, "factory1_lights_spotLightShape1", LightMat, "LIGHTING", "SHADOWMAP" );
	Horde:SetNodeTransform( factory1_lights_spotLightShape1, -25.5758, 40.973, 15.0473, -85.8, -179.6, 0, 2.98437, 2.98437, 2.98437 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "FOV", 107.771 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "Radius", 45 );
	Horde:SetNodeParamInt( factory1_lights_spotLightShape1, "ShadowMapCount", 1 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "Col_R", 1 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "Col_G", 1 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape1, "Col_B", 1 );

	factory1_lights_spotLightShape2 = Horde:AddLightNode( 0, "factory1_lights_spotLightShape2", LightMat, "LIGHTING", "SHADOWMAP" );
	Horde:SetNodeTransform( factory1_lights_spotLightShape2, 41.0575, 58.0888, 60.7177, -58.502, -133.339, -42.2232, 2.98437, 2.98437, 2.98437 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape2, "FOV", 101.819 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape2, "Radius", 45 );
	Horde:SetNodeParamInt( factory1_lights_spotLightShape2, "ShadowMapCount", 3 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape2, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape2, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape2, "Col_R", 0.4 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape2, "Col_G", 0.4 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape2, "Col_B", 0.4 );

	factory1_lights_spotLightShape3 = Horde:AddLightNode( 0, "factory1_lights_spotLightShape3", LightMat, "LIGHTING", "SHADOWMAP" );
	Horde:SetNodeTransform( factory1_lights_spotLightShape3, -70.6765, 66.754, 185.541, -64.1623, -163.921, -53.6703, 2.98437, 2.98437, 2.98437 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape3, "FOV", 101.819 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape3, "Radius", 45 );
	Horde:SetNodeParamInt( factory1_lights_spotLightShape3, "ShadowMapCount", 3 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape3, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape3, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape3, "Col_R", 1 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape3, "Col_G", 1 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape3, "Col_B", 1 );

	factory1_lights_spotLightShape4 = Horde:AddLightNode( 0, "factory1_lights_spotLightShape4", LightMat, "LIGHTING", "SHADOWMAP" );
	Horde:SetNodeTransform( factory1_lights_spotLightShape4, -142.428, 48.075, 91.6152, -56.2264, 131.434, -39.1676, 2.98437, 2.98437, 2.98437 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape4, "FOV", 94.3817 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape4, "Radius", 45 );
	Horde:SetNodeParamInt( factory1_lights_spotLightShape4, "ShadowMapCount", 3 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape4, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape4, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape4, "Col_R", 0.6 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape4, "Col_G", 0.6 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape4, "Col_B", 0.6 );

	factory1_lights_spotLightShape5 = Horde:AddLightNode( 0, "factory1_lights_spotLightShape5", LightMat, "LIGHTING", "SHADOWMAP" );
	Horde:SetNodeTransform( factory1_lights_spotLightShape5, -15.8253, 55.2455, 79.1459, -66.705, 139.094, -62.6026, 2.98437, 2.98437, 2.98437 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape5, "FOV", 112.232 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape5, "Radius", 45 );
	Horde:SetNodeParamInt( factory1_lights_spotLightShape5, "ShadowMapCount", 3 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape5, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape5, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape5, "Col_R", 1 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape5, "Col_G", 1 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape5, "Col_B", 1 );

	factory1_lights_spotLightShape7 = Horde:AddLightNode( 0, "factory1_lights_spotLightShape7", LightMat, "LIGHTING", "SHADOWMAP" );
	Horde:SetNodeTransform( factory1_lights_spotLightShape7, 25.4678, 64.7067, 153.539, -63.8026, -132.216, -52.6863, 2.98437, 2.98437, 2.98437 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape7, "FOV", 101.819 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape7, "Radius", 45 );
	Horde:SetNodeParamInt( factory1_lights_spotLightShape7, "ShadowMapCount", 3 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape7, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape7, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape7, "Col_R", 0.2 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape7, "Col_G", 0.2 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape7, "Col_B", 0.2 );

	factory1_lights_spotLightShape8 = Horde:AddLightNode( 0, "factory1_lights_spotLightShape8", LightMat, "LIGHTING", "SHADOWMAP" );
	Horde:SetNodeTransform( factory1_lights_spotLightShape8, -145.787, 60.3364, 164.208, -59.3811, 158.244, -43.5797, 2.98437, 2.98437, 2.98437 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape8, "FOV", 101.819 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape8, "Radius", 45 );
	Horde:SetNodeParamInt( factory1_lights_spotLightShape8, "ShadowMapCount", 3 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape8, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape8, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape8, "Col_R", 0.2 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape8, "Col_G", 0.2 );
	Horde:SetNodeParamFloat( factory1_lights_spotLightShape8, "Col_B", 0.2 );]]--
end
