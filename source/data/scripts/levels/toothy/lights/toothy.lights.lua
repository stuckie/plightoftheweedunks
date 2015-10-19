-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Light Information for toothy.
function toothy_LIGHTS()
	spotLightShape8 = Horde:AddLightNode( 0, "spotLightShape8", LightMat, "LIGHTING", "" );
	Horde:SetNodeTransform( spotLightShape8, 0, 13.2166, -89.7824, -80.7024, 180, 180, 1.25027, 1.25028, 1.25028 );
	Horde:SetNodeParamFloat( spotLightShape8, "FOV", 100.661 );
	Horde:SetNodeParamFloat( spotLightShape8, "Radius", 400 );
	Horde:SetNodeParamInt( spotLightShape8, "ShadowMapCount", 1 );
	Horde:SetNodeParamFloat( spotLightShape8, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( spotLightShape8, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( spotLightShape8, "Col_R", 1 );
	Horde:SetNodeParamFloat( spotLightShape8, "Col_G", 1 );
	Horde:SetNodeParamFloat( spotLightShape8, "Col_B", 1 );

	spotLightShape3 = Horde:AddLightNode( 0, "spotLightShape3", LightMat, "LIGHTING", "" );
	Horde:SetNodeTransform( spotLightShape3, 0, 12.7803, 10.7176, -80.7024, 180, 180, 1.25027, 1.25028, 1.25028 );
	Horde:SetNodeParamFloat( spotLightShape3, "FOV", 100.661 );
	Horde:SetNodeParamFloat( spotLightShape3, "Radius", 400 );
	Horde:SetNodeParamInt( spotLightShape3, "ShadowMapCount", 1 );
	Horde:SetNodeParamFloat( spotLightShape3, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( spotLightShape3, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( spotLightShape3, "Col_R", 1 );
	Horde:SetNodeParamFloat( spotLightShape3, "Col_G", 1 );
	Horde:SetNodeParamFloat( spotLightShape3, "Col_B", 1 );

	spotLightShape4 = Horde:AddLightNode( 0, "spotLightShape4", LightMat, "LIGHTING", "" );
	Horde:SetNodeTransform( spotLightShape4, 0, 13.2166, -9.38241, -80.7024, 180, 180, 1.25027, 1.25028, 1.25028 );
	Horde:SetNodeParamFloat( spotLightShape4, "FOV", 100.661 );
	Horde:SetNodeParamFloat( spotLightShape4, "Radius", 400 );
	Horde:SetNodeParamInt( spotLightShape4, "ShadowMapCount", 1 );
	Horde:SetNodeParamFloat( spotLightShape4, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( spotLightShape4, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( spotLightShape4, "Col_R", 1 );
	Horde:SetNodeParamFloat( spotLightShape4, "Col_G", 1 );
	Horde:SetNodeParamFloat( spotLightShape4, "Col_B", 1 );

	spotLightShape5 = Horde:AddLightNode( 0, "spotLightShape5", LightMat, "LIGHTING", "" );
	Horde:SetNodeTransform( spotLightShape5, 0, 13.2166, -29.4824, -80.7024, 180, 180, 1.25027, 1.25028, 1.25028 );
	Horde:SetNodeParamFloat( spotLightShape5, "FOV", 100.661 );
	Horde:SetNodeParamFloat( spotLightShape5, "Radius", 400 );
	Horde:SetNodeParamInt( spotLightShape5, "ShadowMapCount", 1 );
	Horde:SetNodeParamFloat( spotLightShape5, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( spotLightShape5, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( spotLightShape5, "Col_R", 1 );
	Horde:SetNodeParamFloat( spotLightShape5, "Col_G", 1 );
	Horde:SetNodeParamFloat( spotLightShape5, "Col_B", 1 );

	spotLightShape6 = Horde:AddLightNode( 0, "spotLightShape6", LightMat, "LIGHTING", "" );
	Horde:SetNodeTransform( spotLightShape6, 0, 13.2166, -49.5824, -80.7024, 180, 180, 1.25027, 1.25028, 1.25028 );
	Horde:SetNodeParamFloat( spotLightShape6, "FOV", 100.661 );
	Horde:SetNodeParamFloat( spotLightShape6, "Radius", 400 );
	Horde:SetNodeParamInt( spotLightShape6, "ShadowMapCount", 1 );
	Horde:SetNodeParamFloat( spotLightShape6, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( spotLightShape6, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( spotLightShape6, "Col_R", 1 );
	Horde:SetNodeParamFloat( spotLightShape6, "Col_G", 1 );
	Horde:SetNodeParamFloat( spotLightShape6, "Col_B", 1 );

	spotLightShape7 = Horde:AddLightNode( 0, "spotLightShape7", LightMat, "LIGHTING", "" );
	Horde:SetNodeTransform( spotLightShape7, 0, 13.2166, -69.6824, -80.7024, 180, 180, 1.25027, 1.25028, 1.25028 );
	Horde:SetNodeParamFloat( spotLightShape7, "FOV", 100.661 );
	Horde:SetNodeParamFloat( spotLightShape7, "Radius", 400 );
	Horde:SetNodeParamInt( spotLightShape7, "ShadowMapCount", 1 );
	Horde:SetNodeParamFloat( spotLightShape7, "ShadowSplitLambda", 0.9 );
	Horde:SetNodeParamFloat( spotLightShape7, "ShadowMapBias", 0.001 );
	Horde:SetNodeParamFloat( spotLightShape7, "Col_R", 1 );
	Horde:SetNodeParamFloat( spotLightShape7, "Col_G", 1 );
	Horde:SetNodeParamFloat( spotLightShape7, "Col_B", 1 );

end
