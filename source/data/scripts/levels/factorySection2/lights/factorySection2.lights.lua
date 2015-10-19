-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Light Information for factorySection2.
function factorySection2_LIGHTS()
	factory2_lights_spotLightShape1 = Horde:AddLightNode( 0, "factory2_lights_spotLightShape1", LightMat, "LIGHTING", "SHADOWMAP" );
	Horde:SetNodeTransform( factory2_lights_spotLightShape1, -53, 518, -380, -50, 180, 0, 1, 1, 1);
	Horde:SetNodeParamFloat( factory2_lights_spotLightShape1, "FOV", 90 );
	Horde:SetNodeParamFloat( factory2_lights_spotLightShape1, "Radius", 1000 );
	Horde:SetNodeParamInt( factory2_lights_spotLightShape1, "ShadowMapCount", 4 );
	Horde:SetNodeParamFloat( factory2_lights_spotLightShape1, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( factory2_lights_spotLightShape1, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( factory2_lights_spotLightShape1, "Col_R", 1.0 );
	Horde:SetNodeParamFloat( factory2_lights_spotLightShape1, "Col_G", 1.0 );
	Horde:SetNodeParamFloat( factory2_lights_spotLightShape1, "Col_B", 1.0 );
end
