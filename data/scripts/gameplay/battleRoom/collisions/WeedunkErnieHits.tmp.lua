LuaQ  G   @data\scripts\\gameplay\battleRoom\collisions\WeedunkErnieHits.tmp.lua              $      $@  @  $�  �  $�  �  $    $@ @ $� � $� � $    $@ @ $� � $� � $    $@ @ $� �  �    "   WeedunkErnieHitsconveyorForceEast #   WeedunkErnieHitsconveyorForceNorth #   WeedunkErnieHitsconveyorForceSouth "   WeedunkErnieHitsconveyorForceWest    WeedunkErnieHitsconveyorTower    WeedunkErnieHitsdeathMincer    WeedunkErnieHitsdeathTower    WeedunkErnieHitsmincer    WeedunkErnieHitsbreakableWall ,   WeedunkErnieHitsfloatingThenSinkingPlatform    WeedunkErnieHitsweedunkShocker #   WeedunkErnieHitsweedunkShockerEast #   WeedunkErnieHitsweedunkShockerWest    WeedunkErnieHitsmulchPipe %   WeedunkErnieHitsbreakableTunnelGrate                       @@ ��  �  ��  �  @�    A @  �       ODE    ApplyHitForce    conveyorForce            Hit                                                              
      @@ ��  ��  �  @�    A @  �       ODE    ApplyHitForce            conveyorForce    Hit     
                                             	               @@ ��  ��  �   @�    A @  �       ODE    ApplyHitForce            conveyorForce    Hit        
   
   
   
   
   
   
                                    
      @@ ��  ��  �  @�    A @  �       ODE    ApplyHitForce    conveyorForce            Hit     
                                                            @@ @  �       ODE    Hit                                         	      @@  ŀ  ���@  �� �  �@ �@   �A �@   �       ODE    GetPointOfContact    Horde    AddParticleEffect    ErnieDieParticleEffect    killWeedunk 
   KillerHit                                                              x          y          z                        	      @@  ŀ  ���@  �� �  �@ �@   �A �@   �       ODE    GetPointOfContact    Horde    AddParticleEffect    ErnieDieParticleEffect    killWeedunk 
   KillerHit                                                              x          y          z                               @@ @  �       ODE    Hit                                 !   #            @@ @  �       ODE    Hit        "   "   "   #               $   &            @@ @  �       ODE    Hit        %   %   %   &               '   (          �            (               )   .            @@ � E�  @  @ �   �   �    �       ODE    GetDynamicID    GrandoWeedunkODE    GrandoControlingWeedunk    shockerEastFilled        *   *   *   *   *   *   +   +   -   -   .               /   4            @@ � E�  @  @ �   �   �    �       ODE    GetDynamicID    GrandoWeedunkODE    GrandoControlingWeedunk    shockerWestFilled        0   0   0   0   0   0   1   1   3   3   4               5   7            @@ @  �       ODE    Hit        6   6   6   7               8   :            @@ @  �       ODE    Hit        9   9   9   :                             	                                  #   !   &   $   (   '   .   )   4   /   7   5   :   8   :           