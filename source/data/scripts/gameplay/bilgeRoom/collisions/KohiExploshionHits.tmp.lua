function KohiExploshionHitsbreakableWall()
    destroyBreakableWall = true;
    Horde:AddParticleBox(breakableWall_mov_posX, breakableWall_mov_posY, breakableWall_mov_posZ, 31.3137, 25.1905, 0.65, 150, WallParticleEffect);
end
function KohiExploshionHitsbugStairsBreakableBoards()
	bugStairsBreakableBoardsBroken = true;
    Horde:AddParticleBox(bugStairsBreakableBoards_posX, bugStairsBreakableBoards_posY, bugStairsBreakableBoards_posZ, 15.7544, 0.458319, 2.69178, 10, WallParticleEffect);
end

function KohiExploshionHitsbreakableTunnelGrate()
	breakableTunnelGrateBroken = true;
    Horde:AddParticleBox(breakableTunnelGrate_posX, breakableTunnelGrate_posY, breakableTunnelGrate_posZ, 19.2515, 10.6045, 0.308113, 100, WallParticleEffect);
end
