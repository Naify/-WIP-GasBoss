// Naify


#include "GasBoss/Public/GasBossGameplayTags.h"

namespace GasBossGameplayTags
{
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAxe, "InputTag.EquipAxe");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipAxe, "InputTag.UnequipAxe");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Axe, "InputTag.LightAttack.Axe");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Axe, "InputTag.HeavyAttack.Axe");
    UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Axe, "Player.Ability.Equip.Axe");
    UE_DEFINE_GAMEPLAY_TAG(Player_Ability_UnEquip_Axe, "Player.Ability.Unequip.Axe");
    UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Axe, "Player.Ability.Attack.Light.Axe");
    UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Axe, "Player.Ability.Attack.Heavy.Axe");
    UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");
    UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Axe, "Player.Event.Equip.Axe");
    UE_DEFINE_GAMEPLAY_TAG(Player_Event_UnEquip_Axe, "Player.Event.UnEquip.Axe");
    UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackType_Light, "Player.SetByCaller.AttackType.Light");
    UE_DEFINE_GAMEPLAY_TAG(Enemy_weapon, "Enemy.Weapon");
    UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Meele, "Enemy.Ability.Melee");
    UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeeleHit, "Shared.Event.MeeleHit");
    UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_Damage, "Shared.SetByCaller.Damage");
    UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact, "Shared.Ability.HitReact");
    UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact, "Shared.Event.HitReact");
    UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Death, "Shared.Ability.Death");
    UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Death, "Shared.Status.Death");
    UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_Strafe, "Enemy.Status.Strafe");

}
