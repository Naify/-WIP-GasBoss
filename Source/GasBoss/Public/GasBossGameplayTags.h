// Naify

#pragma once

#include "NativeGameplayTags.h"

namespace GasBossGameplayTags
{
    //Input tags
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Axe);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Axe);

    //Player tags
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Axe);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Axe);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Axe);

    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

    //Anim player tags
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_UnEquip_Axe); 

    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_SetByCaller_AttackType_Light);
    //GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_SetByCaller_AttackType_Heavy); // implement later

    //Enemy tags
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_weapon);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Ability_Melee);

    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Status_Strafe);
    
    //Shared tags
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_MeeleHit);

    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_SetByCaller_Damage);

    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_HitReact);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_HitReact);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_Death);
    GASBOSS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_Death);

}
