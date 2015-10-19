-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

weedunkBert = 1;
weedunkErnie = 2;

weedunkBertThrow = 101;
weedunkErnieThrow = 102;

function spawnEntity( which, posX, posY, posZ, forceX, forceY, forceZ, name )
	if which == "KOHI" then
		ODE:RemoveForces(KohiODE);
		ODE:SetDynamicPos(KohiODE, posX, posY, posZ);
		ODE:ApplyForce(KohiODE, forceX, forceY, forceZ);
		ODE:SetDynamicRot(KohiODE, 0.0, 0.0, 0.0);
		nodeHandle = KohiMod;
		physicsHandle = KohiODE;
	end

	if which == "GRANDO" then
		ODE:RemoveForces(GrandoODE);
		ODE:SetDynamicPos(GrandoODE, posX, posY, posZ);
		ODE:ApplyForce(GrandoODE, forceX, forceY, forceZ);
		ODE:SetDynamicRot(GrandoODE, 0.0, 0.0, 0.0);
		nodeHandle = GrandoMod;
		physicsHandle = GrandoODE;
	end

	if which == "WEEDUNK_BERT" then
		nodeHandle = Horde:AddNodes( 0, WeedunkBertRes );
		physicsHandle = ODE:CreateDynamicCapsule( 0.2, 0.45, posX, posY, posZ, 0.1, "WeedunkBert" );
		local aiHandle = AI:AddWeedunk(2, physicsHandle);
		ODE:SetOffset(physicsHandle, 0, 2.25,0);
		ODE:ApplyForce(physicsHandle , forceX, forceY, forceZ );
		ODE:SetDynamicRot(physicsHandle , 0.0, 0.0, 0.0);
		
		Horde:SetupModelAnimStage( nodeHandle , 0, WeedunkAnim_Idle , "", false );
		Horde:SetupModelAnimStage( nodeHandle , 1, WeedunkAnim_Walk , "", false );
		Horde:SetupModelAnimStage( nodeHandle , 2, WeedunkAnim_Work , "", false );
	    WEEDUNKS:append({node = nodeHandle, physics = physicsHandle, spawner = name, weedunk = weedunkBert, ai = aiHandle, animTime = 0.0, soundChan = 0, soundPlay = 0});
	    Horde:SetNodeTransformODEDynamicWithScale( nodeHandle, physicsHandle , 0.1);
	end

	if which == "WEEDUNK_ERNIE" then
		nodeHandle = Horde:AddNodes( 0, WeedunkErnieRes );
		physicsHandle = ODE:CreateDynamicCapsule( 0.2, 0.45, posX, posY, posZ, 0.1, "WeedunkErnie" );
		local aiHandle = AI:AddWeedunk(3, physicsHandle);
		ODE:SetOffset(physicsHandle, 0, 2.25,0);
		ODE:ApplyForce(physicsHandle , forceX, forceY, forceZ );
		ODE:SetDynamicRot(physicsHandle , 0.0, 0.0, 0.0);
		Horde:SetupModelAnimStage( nodeHandle , 0, WeedunkAnim_Idle , "", false );
		Horde:SetupModelAnimStage( nodeHandle , 1, WeedunkAnim_Walk , "", false );
		Horde:SetupModelAnimStage( nodeHandle , 2, WeedunkAnim_Work , "", false );
        WEEDUNKS:append({node = nodeHandle, physics = physicsHandle, spawner = name, weedunk = weedunkErnie, ai = aiHandle, animTime = 0.0, soundChan = 0, soundPlay = 0});
        Horde:SetNodeTransformODEDynamicWithScale( nodeHandle, physicsHandle , 0.1);
	end

	if which == "WEEDUNK_BERT_THROW" then
		nodeHandle = Horde:AddNodes( 0, WeedunkBertRes );
		physicsHandle = ODE:CreateDynamicBox( 0.25, 0.45, 0.25, posX, posY, posZ, 0,0,0, 0.1, "WeedunkBertThrow" );
		ODE:SetOffset(physicsHandle, 0, 2.25,0);
		ODE:TurnOffGravityFor(physicsHandle);
		ODE:ApplyForce(physicsHandle , forceX, forceY, forceZ );
		ODE:SetDynamicRot(physicsHandle , 0.0, 0.0, 0.0);
		Horde:SetupModelAnimStage( nodeHandle , 0, WeedunkAnim_InAir , "", false );
        WEEDUNKS:append({node = nodeHandle, physics = physicsHandle, spawner = name, weedunk = weedunkBertThrow, animTime = 0.0, soundChan = 0, soundPlay = 0});
        Horde:SetNodeTransformODEDynamicWithScale( nodeHandle, physicsHandle , 0.1);
	end

	if which == "WEEDUNK_ERNIE_THROW" then
		nodeHandle = Horde:AddNodes( 0, WeedunkErnieRes );
		physicsHandle = ODE:CreateDynamicBox( 0.25, 0.45, 0.25, posX, posY, posZ, 0,0,0, 0.1, "WeedunkErnieThrow" );
		ODE:SetOffset(physicsHandle, 0, 2.25,0);
		ODE:TurnOffGravityFor(physicsHandle);
		ODE:ApplyForce(physicsHandle , forceX, forceY, forceZ );
		ODE:SetDynamicRot(physicsHandle , 0.0, 0.0, 0.0);
		Horde:SetupModelAnimStage( nodeHandle , 0, WeedunkAnim_InAir , "", false );
        WEEDUNKS:append({node = nodeHandle, physics = physicsHandle, spawner = name, weedunk = weedunkErnieThrow, animTime = 0.0, soundChan = 0, soundPlay = 0});
        Horde:SetNodeTransformODEDynamicWithScale( nodeHandle, physicsHandle , 0.1);
	end

	if which == "WEEDUNK_KOHI" then
		nodeHandle = Horde:AddNodes( 0, WeedunkBertRes );
		physicsHandle = ODE:CreateDynamicCapsule( 0.2, 0.45, posX, posY, posZ, 0.1, "WeedunkBert" );
		KohiWeedunkODE = physicsHandle;
		ODE:SetOffset(physicsHandle, 0, 2.25,0);
		ODE:ApplyForce(physicsHandle , forceX, forceY, forceZ );
		ODE:SetDynamicRot(physicsHandle , 0.0, 0.0, 0.0);
		Horde:SetupModelAnimStage( nodeHandle , 0, WeedunkAnim_Idle , "", false );
		Horde:SetupModelAnimStage( nodeHandle , 1, WeedunkAnim_Walk , "", false );
        WEEDUNKS:append({node = nodeHandle, physics = physicsHandle, spawner = name, weedunk = weedunkKohi, rot=0, animTime = 0.0, soundChan = 0, soundPlay = 0});
        Horde:SetNodeTransformODEDynamicWithScale( nodeHandle, physicsHandle , 0.1);
        Horde:FindNodes( nodeHandle, "Head", "Joint" );
	    KohiWeedunkHead = Horde:GetNodeFindResult( 0 );
	    Horde:RemoveNodes(KohiBellMod);
		KohiBellMod = Horde:AddNodes(KohiWeedunkHead, KohiBellRes);
	end

	if which == "WEEDUNK_GRANDO" then
		nodeHandle = Horde:AddNodes( 0, WeedunkErnieRes );
		physicsHandle = ODE:CreateDynamicCapsule( 0.2, 0.45, posX, posY, posZ, 0.1, "WeedunkErnie" );
		GrandoWeedunkODE = physicsHandle;
		ODE:SetOffset(physicsHandle, 0, 2.25,0);
		ODE:ApplyForce(physicsHandle , forceX, forceY, forceZ );
		ODE:SetDynamicRot(physicsHandle , 0.0, 0.0, 0.0);
		Horde:SetupModelAnimStage( nodeHandle , 0, WeedunkAnim_Idle , "", false );
		Horde:SetupModelAnimStage( nodeHandle , 1, WeedunkAnim_Walk , "", false );
        WEEDUNKS:append({node = nodeHandle, physics = physicsHandle, spawner = name, weedunk = weedunkGrando, rot=0, animTime = 0.0, soundChan = 0, soundPlay = 0});
        Horde:SetNodeTransformODEDynamicWithScale( nodeHandle, physicsHandle , 0.1);
        Horde:FindNodes( nodeHandle, "Head", "Joint" );
	    GrandoWeedunkHead = Horde:GetNodeFindResult( 0 );
	    Horde:RemoveNodes(GrandoBrainMod);
		GrandoBrainMod = Horde:AddNodes(GrandoWeedunkHead, GrandoBrainRes);
		Horde:SetNodeTransform(GrandoBrainMod, -25.0,0.0,0.0, 0,0,-90, 1,1,1); 
	end
		
	if which == "WEEDUNK_REV" then
		nodeHandle = Horde:AddNodes( 0, WeedunkRev );
		physicsHandle = ODE:CreateDynamicCapsule( 0.2, 0.45, posX, posY, posZ, 0.1, "WeedunkRev" );
		ODE:SetOffset(physicsHandle, 0, 2.25,0);
		ODE:ApplyForce(physicsHandle , forceX, forceY, forceZ );
		ODE:SetDynamicRot(physicsHandle , 0.0, 0.0, 0.0);
		Horde:SetupModelAnimStage( nodeHandle , 0, WeedunkAnim_Idle , "", false );
		Horde:SetupModelAnimStage( nodeHandle , 1, WeedunkAnim_Walk , "", false );
        WEEDUNKS:append({node = nodeHandle, physics = physicsHandle, spawner = name, weedunk = weedunkGrando, rot=0, animTime = 0.0});
        Horde:SetNodeTransformODEDynamicWithScale( nodeHandle, physicsHandle , 0.1);
	end
	
	if not CurrentLevel == "Toothy" then
	    --positionSoundXYZ("weedunkSpawner", x,y,z);
	end

	return nodeHandle, physicsHandle;
end

function killWeedunk(id,x,y,z,material)
    if id < 0 then
        return
    end
    local spawnerlist = SPAWNERS;
    for i,weedunklist in ipairs(WEEDUNKS) do
		if weedunklist.physics == id then
			while spawnerlist do
				if spawnerlist.name == weedunklist.spawner then
					if weedunklist.weedunk == weedunkBert then
						spawnerlist.bert = spawnerlist.bert - 1;
					elseif weedunklist.weedunk == weedunkErnie then
						spawnerlist.ernie = spawnerlist.ernie - 1;
					end
				elseif weedunklist.spawner == "Grando" then
					GrandoControlingWeedunk = false;
				elseif weedunklist.spawner == "Kohi" then
					KohiControlingWeedunk = false;			    
				end
				spawnerlist = spawnerlist.next;
			end
			ODE:KillDynamic(weedunklist.physics);
			Horde:RemoveNodes(weedunklist.node);
			if weedunklist.ai then
			    AI:KillWeedunk(weedunklist.ai);
			end
			if material == "death" then
--			    positionSoundXYZ("weedunkDeath",x,y,z);
			end
			if material == "toxicDeath" then
			    positionSoundXYZ("weedunkToxicDeath",x,y,z);
			end
			WEEDUNKS:remove(weedunklist);
		end
	end
end
